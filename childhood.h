/////////////////////////////////////////////////////////////////////////////
// Name:        childhood.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 19:29:16 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _CHILDHOOD_H_
#define _CHILDHOOD_H_


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
#define ID_CHILDHOOD 10000
#define ID_RADIOBOX 10003
#define ID_CHILDHOOD_BTN_BACK 10001
#define ID_CHILDHOOD_BTN_NEXT 10004
#define SYMBOL_CHILDHOOD_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_CHILDHOOD_TITLE wxT("Детство")
#define SYMBOL_CHILDHOOD_IDNAME ID_CHILDHOOD
#define SYMBOL_CHILDHOOD_SIZE wxSize(830, 500)
#define SYMBOL_CHILDHOOD_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Childhood class declaration
 */

class Childhood: public wxFrame
{    
    DECLARE_CLASS( Childhood )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Childhood();
    Childhood( wxWindow* parent, wxWindowID id = SYMBOL_CHILDHOOD_IDNAME, const wxString& caption = SYMBOL_CHILDHOOD_TITLE, const wxPoint& pos = SYMBOL_CHILDHOOD_POSITION, const wxSize& size = SYMBOL_CHILDHOOD_SIZE, long style = SYMBOL_CHILDHOOD_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CHILDHOOD_IDNAME, const wxString& caption = SYMBOL_CHILDHOOD_TITLE, const wxPoint& pos = SYMBOL_CHILDHOOD_POSITION, const wxSize& size = SYMBOL_CHILDHOOD_SIZE, long style = SYMBOL_CHILDHOOD_STYLE );

    /// Destructor
    ~Childhood();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Childhood event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_CHILDHOOD
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX
    void OnRadioboxSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CHILDHOOD_BTN_BACK
    void OnChildhoodBtnBackClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CHILDHOOD_BTN_NEXT
    void OnChildhoodBtnNextClick( wxCommandEvent& event );

////@end Childhood event handler declarations

////@begin Childhood member function declarations

    bool GetOnBackClicked() const { return onBackClicked ; }
    void SetOnBackClicked(bool value) { onBackClicked = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Childhood member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Childhood member variables
    wxStaticText* m_question_st;
    wxRadioBox* m_radio_items;
    wxStaticText* m_selected_st;
    wxButton* m_btn_back;
    wxButton* m_btn_next;
private:
    bool onBackClicked;
////@end Childhood member variables

// begin custom
    wxString selectedPrefix;
    wxString selectedItem;
    wxString selectedMessage;
    int idx_selected;

    void PostInit();
    void BeforeNextWindow();
// end custom
};

#endif
    // _CHILDHOOD_H_
