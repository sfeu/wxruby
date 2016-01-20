require 'rake'

Gem::Specification.new do |spec|
  spec.name = 'wxruby'
  if RUBY_VERSION >= "1.9.0"
    spec.name << "-ruby19"
  end

  spec.version = '2.0.1'

  spec.require_path = 'lib'
  spec.summary  = 'Ruby interface to the wxWidgets GUI library'
  spec.author   = 'wxRuby development team'
  spec.homepage = 'http://wxruby.org/'
  spec.email    = 'support@wxruby.org'

  spec.rubyforge_project = 'wxruby'
  spec.description = <<-DESC
  wxRuby allows the creation of graphical user interface (GUI)
  applications via the wxWidgets library. wxRuby provides native-style
  GUI windows, dialogs and controls on platforms including Windows, OS X
  and Linux.
  DESC

  spec.require_path = 'lib'
  # Platform specific binaries are added in later
  spec.files        = FileList[ 'lib/**/*' ].to_a +
                      FileList[ 'art/**/*' ].to_a +
                      FileList[ 'samples/**/*' ].to_a +
                      FileList[ 'README.md', 'INSTALL', 'LICENSE' ].to_a

  spec.has_rdoc = false
end
