#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxStatusBar;

%{
#include <wx/mdi.h>
%}

%typemap(in,numinputs=1) (int n, int *widths) (int *arr){
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = 0;
    $2 = NULL;
  }
  else
  {
    arr = new int[RARRAY($input)->len];
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
        arr[i] = NUM2INT(rb_ary_entry($input,i));
    }
    $1 = RARRAY($input)->len;
    $2 = arr;
  }
}

%typemap(freearg,numinputs=1) (int n, int *widths)
{
  if ($2 != NULL)
    delete [] $2;
}

%include "include/wxStatusBar.h"
