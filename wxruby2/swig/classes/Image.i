#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxImage

%{
#include <wx/wx.h>
#include <wx/image.h>
%}

%feature("nodirector") wxImage;

%ignore wxImage(int  width , int  height , bool clear = true) ;
%ignore wxImage::Create();
%ignore wxImage::HasAlpha;
%ignore wxImage::AddHandler(const wxString&  filename );
%ignore wxImage::SetAlpha(unsigned char *);
%ignore wxImage::SetAlpha(int, int, unsigned char);
%ignore wxImage::GetImageExtWildcard();
%ignore wxImage::GetAlpha(int  x , int  y ) const;
%ignore wxImage::GetAlpha() const;


%include "include/wxImage.h"