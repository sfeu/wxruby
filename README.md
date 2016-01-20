# wxruby svn import (19/07/2012)

* https://github.com/sfeu/wxruby

## DESCRIPTION

wxRuby is a cross-platform GUI library for creating desktop applications. It has a comprehensive widget set, and provides native look and feel on Windows, OS X and Linux. It's based on the mature and liberally-licensed wxWidgets framework.

I was unable to use wxruby with ruby 1.9 on a
Ubuntu 12.04 intel machine, because of an incompatibility
of the oficial  wxruby-ruby19 binary gem with the 
libxw_gtku version of ubuntu.

in `require': /home/ron/.rvm/gems/ruby-1.9.3-p125@wxgui/gems/wxruby-ruby19-2.0.1-x86-linux/lib/wxruby2.so:
symbol _ZN16wxStyledTextCtrl7SendMsgEill, version WXU_2.8 not defined in file libwx_gtk2u_stc-2.8.so.0 with link time reference - /home/ron/.rvm/gems/ruby-1.9.3-p125@wxgui/gems/wxruby-ruby19-2.0.1-x86-linux lib/wxruby2.so (LoadError)

This problem can also be tracked in launchpad

https://bugs.launchpad.net/ubuntu/+source/wxwidgets2.8/+bug/995518
 
To compile your own version you can clone this repository and
follow the installation instructions that worked for me.

Unfortunately the last release (2.0.1) is already 2,5 years
old...

http://rubygems.org/gems/wxruby-ruby19

## INSTALL

```
wget http://sourceforge.net/projects/swig/files/swig/swig-1.3.38/swig-1.3.38.tar.gz/download -O swig-1.3.38.tar.gz
tar xzf swig-*.tar.gz
cd swig-*
./configure
make
sudo make install

cd wxruby
rake
RUBYOPT='-rpsych' WXRUBY_VERSION=2.0.2 rake gem 
```

## LICENSE

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

