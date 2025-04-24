/////////////////////////////////////////////////////////////////////////////
// Name:        results.cpp
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Mon Apr 14 12:38:49 2025
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
#include "wx/imaglist.h"
////@end includes

#include "DialogBlocks_5Win.h"

#include "results.h"

#include <string>
#include <vector>
#include <sstream>

////@begin XPM images
#include "teacher.xpm"
////@end XPM images


/*
 * Results type definition
 */

IMPLEMENT_CLASS( Results, wxFrame )


/*
 * Results event table definition
 */

BEGIN_EVENT_TABLE( Results, wxFrame )

////@begin Results event table entries
    EVT_CLOSE( Results::OnCloseWindow )
    EVT_BUTTON( ID_RESULTS_BTN_BACK, Results::OnResultsBtnBackClick )
    EVT_BUTTON( ID_RESULTS_BTN_EXIT, Results::OnResultsBtnExitClick )
////@end Results event table entries

END_EVENT_TABLE()


/*
 * Results constructors
 */

Results::Results()
{
    Init();
}

Results::Results( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * Results creator
 */

bool Results::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Results creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("teacher.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end Results creation
    PostInit();
    FillTable();
    return true;
}


/*
 * Results destructor
 */

Results::~Results()
{
////@begin Results destruction
////@end Results destruction
}


/*
 * Member initialisation
 */

void Results::Init()
{
////@begin Results member initialisation
    onBackClicked = false;
    m_listctrl = NULL;
    m_btn_back = NULL;
    m_btn_exit = NULL;
////@end Results member initialisation
}


/*
 * Control creation for Results
 */

void Results::CreateControls()
{    
////@begin Results content construction
    Results* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    wxStaticText* itemStaticText1 = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Спасибо что воспользовались \n      нашей системой!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText1->SetFont(wxFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(itemStaticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 25);

    wxStaticLine* itemStaticLine2 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer1->Add(itemStaticLine2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 25);

    m_listctrl = new wxListCtrl( itemFrame1, ID_LISTCTRL, wxDefaultPosition, wxSize(520, 250), wxLC_REPORT );
    m_listctrl->SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_listctrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticLine* itemStaticLine5 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer1->Add(itemStaticLine5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 25);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_btn_back = new wxButton( itemFrame1, ID_RESULTS_BTN_BACK, wxT("    Назад    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_back->SetForegroundColour(wxColour(0, 0, 0));
    m_btn_back->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_back->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer6->Add(m_btn_back, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine8 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemStaticLine8->SetName(wxT("Spacer"));
    itemBoxSizer6->Add(itemStaticLine8, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 250);

    m_btn_exit = new wxButton( itemFrame1, ID_RESULTS_BTN_EXIT, wxT("    Выход    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_exit->SetForegroundColour(wxColour(26, 26, 26));
    m_btn_exit->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_exit->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer6->Add(m_btn_exit, 0, wxGROW|wxALL, 5);

////@end Results content construction  
}

// begin custom
void Results::PostInit()
{
    MWSApp &mwsapp = wxGetApp();
    wxString answersStr = mwsapp.GetAnswers();
    wxString questionsStr = mwsapp.GetQuestions();

    ////wxLogMessage("[Global] [PostInit] => [%s] [%s] [%s]", mwsapp.GetQuestions(), mwsapp.GetDelimiter(), mwsapp.GetAnswers());

    // fill questions from global questions
    questions = mwsapp.SplitString(questionsStr);
    ////wxLogMessage("answers str before str split calling is [%s]", answersStr);
    answers = mwsapp.SplitString(answersStr);
}

wxString Results::CleanText(const wxString& text) {
    static const wxString disallowed = "&";
    wxString result;
    for (wxUniChar c : text) {
        if (disallowed.find(c) == wxString::npos) {
            result += c;
        }
    }
    return result;
}

bool Results::FillTable() 
{
    if (questions.empty() || answers.empty()) {
        ////wxLogMessage("Questions or answers are empty. Skipping PostInit.");
        return false;
    }
    
    // if (questions.size() != answers.size()) {
        // ////wxLogMessage("Mismatch between nubmer of questions and answers: [%zu] vs [%zu]", questions.size(), answers.size());
    // }

    // ////wxLogMessage("%s %s %s", questions[0], questions[1], questions[2]);
    // ////wxLogMessage("%s %s %s", answers[0], answers[1], answers[2]);

    size_t itemsSize = std::min(answers.size(), questions.size());

    for (size_t i = 0; i < columns.size(); ++i)
    {
        m_listctrl->InsertColumn(i, columns[i]);
    }

    for (size_t i = 0; i < itemsSize; ++i)
    {
        const wxString& q_raw = questions[i];
        const wxString& a_raw = answers[i];

        const wxString q = CleanText(q_raw);
        const wxString a = CleanText(a_raw);

        if (!q.empty() && !a.empty()) {
            size_t idx = m_listctrl->InsertItem(i, q);
            m_listctrl->SetItem(idx, kAnswersColumnIndex, a);
        }
    }

    
    for (size_t i = 0; i < columns.size(); ++i) {
        m_listctrl->SetColumnWidth(i, kDefaultColumnWidth);
    }
    return true;
}

// end custom

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_BACK
 */

void Results::OnResultsBtnBackClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_BACK in Results.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_BACK in Results. 
    this->GetParent()->Show(true);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_EXIT
 */

void Results::OnResultsBtnExitClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_EXIT in Results.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESULTS_BTN_EXIT in Results. 

    this->GetParent()->Close(true);
}


/*
 * Should we show tooltips?
 */

bool Results::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Results::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Results bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Results bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Results::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Results icon retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxIcon icon(teacher);
        return icon;
    }
    return wxNullIcon;
////@end Results icon retrieval
}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_RESULTS
 */

void Results::OnCloseWindow( wxCloseEvent& event )
{
    Destroy();
    this->GetParent()->Close(true);
}
