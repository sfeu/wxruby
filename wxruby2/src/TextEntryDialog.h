/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxTextEntryDialog_WRAP_H_
#define SWIG_WxTextEntryDialog_WRAP_H_

class Swig::Director;


class SwigDirector_wxTextEntryDialog : public wxTextEntryDialog, public Swig::Director {

public:
    SwigDirector_wxTextEntryDialog(VALUE self, wxWindow *parent, wxString const &message, wxString const &caption = wxT("Please"), wxString const &defaultValue = wxT(""), long style = wxOK, wxPoint const &pos = wxDefaultPosition, bool disown = false);
};


#endif