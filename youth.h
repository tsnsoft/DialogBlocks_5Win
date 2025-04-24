/////////////////////////////////////////////////////////////////////////////
// Name:        youth.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 19:30:58 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _YOUTH_H_
#define _YOUTH_H_


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
#define ID_YOUTH 10000
#define ID_LISTBOX 10004
#define ID_YOUTH_BTN_BACK 10002
#define ID_YOUTH_BTN_NEXT 10003
#define SYMBOL_YOUTH_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_YOUTH_TITLE wxT("Юность")
#define SYMBOL_YOUTH_IDNAME ID_YOUTH
#define SYMBOL_YOUTH_SIZE wxSize(650, 530)
#define SYMBOL_YOUTH_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Youth class declaration
 */

class Youth: public wxFrame
{    
    DECLARE_CLASS( Youth )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Youth();
    Youth( wxWindow* parent, wxWindowID id = SYMBOL_YOUTH_IDNAME, const wxString& caption = SYMBOL_YOUTH_TITLE, const wxPoint& pos = SYMBOL_YOUTH_POSITION, const wxSize& size = SYMBOL_YOUTH_SIZE, long style = SYMBOL_YOUTH_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_YOUTH_IDNAME, const wxString& caption = SYMBOL_YOUTH_TITLE, const wxPoint& pos = SYMBOL_YOUTH_POSITION, const wxSize& size = SYMBOL_YOUTH_SIZE, long style = SYMBOL_YOUTH_STYLE );

    /// Destructor
    ~Youth();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Youth event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_YOUTH
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX
    void OnListboxSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_YOUTH_BTN_BACK
    void OnYouthBtnBackClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_YOUTH_BTN_NEXT
    void OnYouthBtnNextClick( wxCommandEvent& event );

////@end Youth event handler declarations

////@begin Youth member function declarations

    bool GetOnBackClicked() const { return onBackClicked ; }
    void SetOnBackClicked(bool value) { onBackClicked = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Youth member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Youth member variables
    wxStaticText* m_question_st;
    wxListBox* m_listbox;
    wxStaticText* m_selected_st;
    wxButton* m_btn_back;
    wxButton* m_btn_next;
private:
    bool onBackClicked;
////@end Youth member variables

// begin custom
    wxString selectedPrefix;
    wxString selectedItem;
    wxString selectedMessage;
    int idx_selected;
    bool default_idx_inited;
    int listbox_count;
    
    int lines_to_show;
    int row_height;

    void PostInit();
    void BeforeNextWindow();
// end custom
};

#endif
    // _YOUTH_H_
