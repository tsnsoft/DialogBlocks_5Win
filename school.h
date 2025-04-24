/////////////////////////////////////////////////////////////////////////////
// Name:        school.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 19:30:17 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _SCHOOL_H_
#define _SCHOOL_H_


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
#define ID_SCHOOL 10000
#define ID_CHECKLISTBOX 10002
#define ID_SCHOOL_BTN_BACK 10001
#define ID_SCHOOL_BTN_NEXT 10004
#define SYMBOL_SCHOOL_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_SCHOOL_TITLE wxT("Школа")
#define SYMBOL_SCHOOL_IDNAME ID_SCHOOL
#define SYMBOL_SCHOOL_SIZE wxSize(750, 510)
#define SYMBOL_SCHOOL_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * School class declaration
 */

class School: public wxFrame
{    
    DECLARE_CLASS( School )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    School();
    School( wxWindow* parent, wxWindowID id = SYMBOL_SCHOOL_IDNAME, const wxString& caption = SYMBOL_SCHOOL_TITLE, const wxPoint& pos = SYMBOL_SCHOOL_POSITION, const wxSize& size = SYMBOL_SCHOOL_SIZE, long style = SYMBOL_SCHOOL_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SCHOOL_IDNAME, const wxString& caption = SYMBOL_SCHOOL_TITLE, const wxPoint& pos = SYMBOL_SCHOOL_POSITION, const wxSize& size = SYMBOL_SCHOOL_SIZE, long style = SYMBOL_SCHOOL_STYLE );

    /// Destructor
    ~School();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin School event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_SCHOOL
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_CHECKLISTBOX_TOGGLED event handler for ID_CHECKLISTBOX
    void OnChecklistboxToggled( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SCHOOL_BTN_BACK
    void OnSchoolBtnBackClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SCHOOL_BTN_NEXT
    void OnSchoolBtnNextClick( wxCommandEvent& event );

////@end School event handler declarations

////@begin School member function declarations

    bool GetOnBackClicked() const { return onBackClicked ; }
    void SetOnBackClicked(bool value) { onBackClicked = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end School member function declarations
    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin School member variables
    wxStaticText* m_question_st;
    wxCheckListBox* m_check_lb;
    wxStaticText* m_selected_st;
    wxButton* m_btn_back;
    wxButton* m_btn_next;
private:
    bool onBackClicked;
////@end School member variables

// begin custom
    wxString selectedPrefix;
    wxString selectedItem;
    wxString selectedMessage;
    int curr_idx_selected;
    int checkboxes_count;

    void PostInit();
    void BeforeNextWindow();
// end custom
};

#endif
    // _SCHOOL_H_
