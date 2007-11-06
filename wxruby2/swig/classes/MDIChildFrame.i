// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMDIChildFrame;
GC_MANAGE_AS_FRAME(wxMDIChildFrame);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxMDIChildFrame);

%{
#include <wx/mdi.h>
%}

%ignore wxMDIChildFrame::wxMDIChildFrame();

//
// Doesn't work on wxMac. We need a better workaround.
//
%ignore wxMdiChildFrame::GetWindowMenu;
%ignore wxMdiChildFrame::SetWindowMenu;

# under GTK, it requires a bool parameter
#ifndef SWIGMAC
 #ifndef SWIGWIN
  %ignore Maximize;
 #endif
#endif

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxFrame.h"

%include "include/wxMDIChildFrame.h"
