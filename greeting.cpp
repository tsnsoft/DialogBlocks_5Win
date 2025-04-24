/////////////////////////////////////////////////////////////////////////////
// Name:        greeting.cpp
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 20:30:59 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "childhood.h"
////@end includes

#include "greeting.h"

////@begin XPM images
#include "teacher.xpm"
////@end XPM images


/*
 * Greeting type definition
 */

IMPLEMENT_CLASS( Greeting, wxFrame )


/*
 * Greeting event table definition
 */

BEGIN_EVENT_TABLE( Greeting, wxFrame )

////@begin Greeting event table entries
    EVT_BUTTON( ID_GREETING_BTN_EXIT, Greeting::OnGreetingBtnExitClick )
    EVT_BUTTON( ID_GREETING_BTN_START, Greeting::OnGreetingBtnStartClick )
////@end Greeting event table entries

END_EVENT_TABLE()


/*
 * Greeting constructors
 */

Greeting::Greeting()
{
    Init();
}

Greeting::Greeting( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * Greeting creator
 */

bool Greeting::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Greeting creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("teacher.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end Greeting creation
    return true;
}


/*
 * Greeting destructor
 */

Greeting::~Greeting()
{
////@begin Greeting destruction
////@end Greeting destruction
}


/*
 * Member initialisation
 */

void Greeting::Init()
{
////@begin Greeting member initialisation
    m_btn_exit = NULL;
    m_btn_start = NULL;
////@end Greeting member initialisation
}


/*
 * Control creation for Greeting
 */

void Greeting::CreateControls()
{    
////@begin Greeting content construction
    Greeting* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Вас приветствует система\n быстрого анкетирования!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText3->SetFont(wxFont(18, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monocraft")));
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 25);

    wxStaticText* itemStaticText4 = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Тема - периоды жизни"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText4->SetFont(wxFont(14, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 100);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_btn_exit = new wxButton( itemFrame1, ID_GREETING_BTN_EXIT, wxT("    Выход    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_exit->SetForegroundColour(wxColour(0, 0, 0));
    m_btn_exit->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_exit->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer5->Add(m_btn_exit, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine7 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemStaticLine7->SetName(wxT("Spacer"));
    itemBoxSizer5->Add(itemStaticLine7, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 100);

    m_btn_start = new wxButton( itemFrame1, ID_GREETING_BTN_START, wxT("    Начать    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_start->SetForegroundColour(wxColour(26, 26, 26));
    m_btn_start->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_start->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer5->Add(m_btn_start, 0, wxGROW|wxALL, 5);

////@end Greeting content construction
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT
 */

void Greeting::OnGreetingBtnExitClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT in Greeting.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_EXIT in Greeting. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_START
 */

void Greeting::OnGreetingBtnStartClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_START in Greeting.
    // Before editing this code, remove the block markers.
    Childhood* window = new Childhood(this);
    window->Show(true);
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_START in Greeting. 
    Show(false);
}


/*
 * Should we show tooltips?
 */

bool Greeting::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Greeting::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Greeting bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Greeting bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Greeting::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Greeting icon retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxIcon icon(teacher);
        return icon;
    }
    return wxNullIcon;
////@end Greeting icon retrieval
}
