/////////////////////////////////////////////////////////////////////////////
// Name:        greeting.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 20:30:59 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _GREETING_H_
#define _GREETING_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_GREETING 10000
#define ID_GREETING_BTN_EXIT 10002
#define ID_GREETING_BTN_START 10003
#define SYMBOL_GREETING_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_GREETING_TITLE wxT("Приветствие")
#define SYMBOL_GREETING_IDNAME ID_GREETING
#define SYMBOL_GREETING_SIZE wxSize(500, 350)
#define SYMBOL_GREETING_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Greeting class declaration
 */

class Greeting: public wxFrame
{    
    DECLARE_CLASS( Greeting )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Greeting();
    Greeting( wxWindow* parent, wxWindowID id = SYMBOL_GREETING_IDNAME, const wxString& caption = SYMBOL_GREETING_TITLE, const wxPoint& pos = SYMBOL_GREETING_POSITION, const wxSize& size = SYMBOL_GREETING_SIZE, long style = SYMBOL_GREETING_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_GREETING_IDNAME, const wxString& caption = SYMBOL_GREETING_TITLE, const wxPoint& pos = SYMBOL_GREETING_POSITION, const wxSize& size = SYMBOL_GREETING_SIZE, long style = SYMBOL_GREETING_STYLE );

    /// Destructor
    ~Greeting();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Greeting event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GREETING_BTN_EXIT
    void OnGreetingBtnExitClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GREETING_BTN_START
    void OnGreetingBtnStartClick( wxCommandEvent& event );

////@end Greeting event handler declarations

////@begin Greeting member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Greeting member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Greeting member variables
    wxButton* m_btn_exit;
    wxButton* m_btn_start;
////@end Greeting member variables
};

#endif
    // _GREETING_H_
