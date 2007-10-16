// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTaskBarIcon
GC_NEVER(wxTaskBarIcon); // Shouldn't be deleted from within Ruby

%{
#include <wx/taskbar.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTaskBarIcon.h"
