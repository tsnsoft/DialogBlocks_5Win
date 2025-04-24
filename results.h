/////////////////////////////////////////////////////////////////////////////
// Name:        results.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Mon Apr 14 12:38:49 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _RESULTS_H_
#define _RESULTS_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/statline.h"
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_RESULTS 10000
#define ID_LISTCTRL 10001
#define ID_RESULTS_BTN_BACK 10002
#define ID_RESULTS_BTN_EXIT 10003
#define SYMBOL_RESULTS_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_RESULTS_TITLE wxT("Результаты")
#define SYMBOL_RESULTS_IDNAME ID_RESULTS
#define SYMBOL_RESULTS_SIZE wxSize(650, 575)
#define SYMBOL_RESULTS_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Results class declaration
 */

class Results: public wxFrame
{    
    DECLARE_CLASS( Results )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Results();
    Results( wxWindow* parent, wxWindowID id = SYMBOL_RESULTS_IDNAME, const wxString& caption = SYMBOL_RESULTS_TITLE, const wxPoint& pos = SYMBOL_RESULTS_POSITION, const wxSize& size = SYMBOL_RESULTS_SIZE, long style = SYMBOL_RESULTS_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_RESULTS_IDNAME, const wxString& caption = SYMBOL_RESULTS_TITLE, const wxPoint& pos = SYMBOL_RESULTS_POSITION, const wxSize& size = SYMBOL_RESULTS_SIZE, long style = SYMBOL_RESULTS_STYLE );

    /// Destructor
    ~Results();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Results event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_RESULTS
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_BACK
    void OnResultsBtnBackClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_EXIT
    void OnResultsBtnExitClick( wxCommandEvent& event );

////@end Results event handler declarations

////@begin Results member function declarations

    bool GetOnBackClicked() const { return onBackClicked ; }
    void SetOnBackClicked(bool value) { onBackClicked = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Results member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Results member variables
    wxListCtrl* m_listctrl;
    wxButton* m_btn_back;
    wxButton* m_btn_exit;
private:
    bool onBackClicked;
////@end Results member variables

// begin custom
private:
    const static size_t kDefaultColumnWidth = 260;
    const static size_t kAnswersColumnIndex = 1;
    wxString CleanText(const wxString& text);

    const std::vector<wxString> columns = {wxT("Вопросы"), wxT("Ответы")};
    std::vector<wxString> questions;
    std::vector<wxString> answers;

    void PostInit();
    bool FillTable();
// end custom
};

#endif
    // _RESULTS_H_
