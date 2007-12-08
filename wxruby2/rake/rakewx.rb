# rakewx.rb
#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

# Skim all the SWIG sources to detect import/include dependencies that
# should force recompiles
here = File.expand_path( File.dirname(__FILE__) ) + File::SEPARATOR
here_rx = Regexp.new( Regexp.escape(here) )
SWIG_DEPENDS = Hash.new { | h, k | h[k] = [] }

Dir.glob('swig/**/*.i') do | i |
  File.read(i).scan(/^%(?:import|include) ["'](.*?)["']\s*$/) do | dep |
    dep_file = File.expand_path( dep[0], File.dirname(i) )
    dep_file.sub!(here_rx, '')
    SWIG_DEPENDS[i] << dep_file
  end
end

$have_good_swig = false
def check_swig
  begin
    version = `#{SWIG_CMD} -version`[/\d+\.\d+\.\d+/]
  rescue
    raise "Could not run SWIG; check that SWIG's installed in PATH"
  end

  # Very old versions put --version on STDERR, not STDOUT
  unless version
    raise "Could not get info from SWIG; is a very old version  installed?"
  end

  if version < SWIG_MINIMUM_VERSION
    raise "SWIG version '#{version}' installed, " +
          "#{SWIG_MINIMUM_VERSION} required"
  end
  $have_good_swig = true
end

# Returns the plain names of all normal Wx classes to be built
def all_build_classes
  ALL_CLASSES - $excluded_classes
end

# Returns the plain names of every .i file to be built
def all_build
  all_build_classes + HELPER_CLASSES + [ MAIN_MODULE ]
end

def all_obj_files
  all_build.map { | f | "#{OBJ_DIR}/#{f}.#{OBJ_EXT}" } 
end

def all_cpp_files
  all_build.map { | f | "#{SRC_DIR}/#{f}.cpp" } 
end

def all_swig_files
  all_build_classes.map { | f | "#{CLASSES_DIR}/#{f}.i" } +
    HELPER_CLASSES.map { | f | "#{SWIG_DIR}/#{f}.i" } +
    [ 'swig/wx.i' ]
end

def do_swig(source, target)
  check_swig if not $have_good_swig
  sh "#{SWIG_CMD} #{$wx_cppflags} " + 
    "-w401 -w801 -w515 -c++ -ruby " + 
    "-o #{target} #{source}"
end

def post_process(file, *processors)
  processors.each do | p |
    sh "ruby swig/#{p}.rb #{file}"
  end
end

file TARGET_LIB => all_obj_files do | t |
  objs = $extra_objs + " " + all_obj_files.join(' ')
  sh "#{$ld} #{$ldflags} #{objs} #{$libs} #{$link_output_flag}#{t.name}"
end

# The main source module - which needs to initialize all the other modules
file 'src/wx.cpp' => all_swig_files do | t |
  do_swig("swig/wx.i", "src/wx.cpp")
  post_process(t.name, 'renamer', 'fixmainmodule')
  # RubyStockObjects are loaded later, after App has been started
  need_init = all_build_classes + HELPER_CLASSES - [ 'RubyStockObjects']
  File.open(t.name, "a") do | out |
    out.puts
    out.puts 'extern "C" void InitializeOtherModules()'
    out.puts '{'
    # Set up an initializer for all the other compiled classes
    need_init.each do | c |
      init = "Init_wx#{c}()"
      out.puts "    extern void #{init};"
      out.puts "    #{init};"
    end
    out.puts '}'
  end
end

# Generate cpp source from helper SWIG files - RubyConstants, Functions,
# RubyStockObjects etc
HELPER_CLASSES.each do | helper |
  swig_file = "#{SWIG_DIR}/#{helper}.i"
  file "#{SRC_DIR}/#{helper}.cpp" => [ swig_file,
                                       *SWIG_DEPENDS[swig_file] ] do | t |
    force_mkdir(SRC_DIR)
    do_swig(swig_file, t.name)
    post_process(t.name, 'renamer', 'fixmodule')
  end
end

# Generate a C++ source file from a SWIG .i source file for a core class
all_build_classes.each do | cls |
  swig_file = "#{CLASSES_DIR}/#{cls}.i"
  file "#{SRC_DIR}/#{cls}.cpp" => [ swig_file,
                                    *SWIG_DEPENDS[swig_file] ] do | t |
    force_mkdir(SRC_DIR)
    do_swig(swig_file, t.name)
    post_process(t.name, 'renamer', 'fixplatform', 'fixmodule')
  end
end

# Compile an object file from a generated c++ source
cpp_src = lambda do | tn |
  tn.sub(/#{OBJ_DIR}\/(\w+)\.#{OBJ_EXT}$/) { "#{SRC_DIR}/#{$1}.cpp" }
end

rule ".#{OBJ_EXT}" => cpp_src do | t |
  force_mkdir(OBJ_DIR)
  sh "#{$cpp} -c #{$verbose_flag} #{$cppflags} " +
     "#{$cpp_out_flag}#{t.name} #{t.source}"
end

# Recursive dependencies
SWIG_DEPENDS.keys.grep(/swig\/\w+\.i$/).each do | dep |
  file dep => [ *SWIG_DEPENDS[dep] ]
end

desc "Install the WxRuby library to Ruby's lib directories"
task :install => [ :default, *ALL_RUBY_LIB_FILES ] do | t |
  dest_dir = Config::CONFIG['sitelibdir']
  force_mkdir File.join(dest_dir, 'wx')
  force_mkdir File.join(dest_dir, 'wx', 'classes')
  cp TARGET_LIB, Config::CONFIG['sitearchdir']
  all_ruby_lib_files.each do | lib_file |
    dest = lib_file.sub(/^lib/, dest_dir)
    cp lib_file, dest
    chmod 0755, dest
  end
end

desc "Removes installed library files from site_ruby"
task :uninstall do | t |
  rm_rf File.join(Config::CONFIG['sitearchdir'], $dl_lib)
  rm_rf File.join(Config::CONFIG['sitelibdir'], 'wx.rb')
  rm_rf File.join(Config::CONFIG['sitelibdir'], 'wx')
end

desc "Generate C++ source and header files using SWIG"
task :swig   => all_cpp_files

desc "Force generate C++ source and header files using SWIG"
task :reswig => [ :clean_src, :swig ]

desc "Create a makefile"
file "Makefile" => all_swig_files do
  object_rules = ""
  
  all_obj_files_and_extra_obj = all_obj_files + $extra_objs.split(' ')  
  all_obj_files_and_extra_obj.each do | o |
    obj_no_dir = o.sub('obj/','')
    rule = "#{o}: src/#{obj_no_dir.sub('.o','.cpp')}\n\t#{$cpp} -c #{$verbose_flag} #{$cppflags} #{$cpp_out_flag}$@ $^\n\n"
    object_rules << rule
  end

file_data = 
%{#This is generated by rake do not edit by hand!  

OBJ = #{all_obj_files_and_extra_obj.join(' ')}

rakemake: $(OBJ)

#{object_rules}
}
  
  file = File.new("Makefile","w+")
  file.write(file_data)
end
