#include "WxWidgetsTemplateApp.hpp"

TemplateApp::TemplateApp()
{

}

bool TemplateApp::OnInit()
{
    if( !wxApp::OnInit() )
        return false;

    TemplateFrame* frame = new TemplateFrame();
    frame->SetSize( wxSize( 1200, 800 ) );
    frame->Show();
    return true;
}

TemplateFrame::TemplateFrame():
    wxFrame( nullptr, wxID_ANY, "TempalteApp" )
{
    wxButton* button = new wxButton( this, wxID_ANY, "Click Me" );
}
