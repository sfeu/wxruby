// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSizer
GC_MANAGE_AS_SIZER(wxSizer);

%feature("nodirector") wxSizer::CalcMin;
%ignore wxSizer::IsShown;

// shared functions
%include "../shared/sizers.i"

%import "include/wxObject.h"

%include "include/wxSizer.h"
