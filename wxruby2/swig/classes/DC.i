#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxDC

%ignore wxDC::CacheEnabled;
%ignore wxDC::ClearCache;
%ignore wxDC::EnableCache;

%ignore wxDC::StartPage;

%typemap(in,numinputs=0) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) (wxCoord a, wxCoord b, wxCoord c, wxCoord d) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&d;
}

%typemap(argout) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, INT2NUM(*$4));
}


%include "include/wxDC.h"

%extend wxDC {

    VALUE free() 
    {
        delete self;
        return Qnil;
    }
}
