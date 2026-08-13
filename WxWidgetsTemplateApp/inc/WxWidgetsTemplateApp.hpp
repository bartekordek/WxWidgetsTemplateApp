#pragma once

#include "wx/wx.h"
#include <wx/artprov.h>
#include "wx/filepicker.h"

class TemplateFrame final: public wxFrame
{
public:
    TemplateFrame();

protected:
private:
};

class TemplateApp: public wxApp
{
public:
    TemplateApp();
    bool OnInit() override;

protected:
private:
};