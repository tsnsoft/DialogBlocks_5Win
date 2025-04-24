/////////////////////////////////////////////////////////////////////////////
// Name:        school.cpp
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 19:30:17 2025
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
#include "youth.h"
////@end includes

#include "school.h"
#include "DialogBlocks_5Win.h"

////@begin XPM images
#include "teacher.xpm"
#include "arm.xpm"
////@end XPM images


/*
 * School type definition
 */

IMPLEMENT_CLASS( School, wxFrame )


/*
 * School event table definition
 */

BEGIN_EVENT_TABLE( School, wxFrame )

////@begin School event table entries
    EVT_CLOSE( School::OnCloseWindow )
    EVT_CHECKLISTBOX( ID_CHECKLISTBOX, School::OnChecklistboxToggled )
    EVT_BUTTON( ID_SCHOOL_BTN_BACK, School::OnSchoolBtnBackClick )
    EVT_BUTTON( ID_SCHOOL_BTN_NEXT, School::OnSchoolBtnNextClick )
////@end School event table entries

END_EVENT_TABLE()


/*
 * School constructors
 */

School::School()
{
    Init();
}

School::School( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * School creator
 */

bool School::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin School creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("teacher.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end School creation
    PostInit();
    return true;
}


/*
 * School destructor
 */

School::~School()
{
////@begin School destruction
////@end School destruction
}


/*
 * Member initialisation
 */

void School::Init()
{
////@begin School member initialisatio
    m_question_st = NULL;
    m_check_lb = NULL;
    m_selected_st = NULL;
    m_btn_back = NULL;
    m_btn_next = NULL;
////@end School member initialisation
}


/*
 * Control creation for School
 */

void School::CreateControls()
{    
////@begin School content construction
    School* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    m_question_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Как вы учились в 5 классе"), wxDefaultPosition, wxDefaultSize, 0 );
    m_question_st->SetFont(wxFont(18, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_question_st, 0, wxALIGN_LEFT|wxALL, 25);

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxArrayString m_check_lbStrings;
    m_check_lbStrings.Add(wxT("Отлично"));
    m_check_lbStrings.Add(wxT("Хорошо"));
    m_check_lbStrings.Add(wxT("Удовлетворительно"));
    m_check_lbStrings.Add(wxT("Неудовлетворительно"));
    m_check_lb = new wxCheckListBox( itemFrame1, ID_CHECKLISTBOX, wxDefaultPosition, wxDefaultSize, m_check_lbStrings, wxLB_SINGLE );
    m_check_lb->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer2->Add(m_check_lb, 0, wxALIGN_CENTER_VERTICAL|wxTOP, 25);

    wxStaticBitmap* itemStaticBitmap4 = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("arm.xpm")), wxDefaultPosition, wxSize(256, 256), 0 );
    itemBoxSizer2->Add(itemStaticBitmap4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 75);

    m_selected_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Выбрано:"), wxDefaultPosition, wxDefaultSize, 0 );
    m_selected_st->SetForegroundColour(wxColour(0, 0, 0));
    m_selected_st->SetBackgroundColour(wxColour(229, 229, 229));
    m_selected_st->SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_selected_st, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 25);

    wxStaticLine* itemStaticLine3 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer1->Add(itemStaticLine3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_btn_back = new wxButton( itemFrame1, ID_SCHOOL_BTN_BACK, wxT("    Назад    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_back->SetForegroundColour(wxColour(0, 0, 0));
    m_btn_back->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_back->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer3->Add(m_btn_back, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine5 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemStaticLine5->SetName(wxT("Spacer"));
    itemBoxSizer3->Add(itemStaticLine5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 250);

    m_btn_next = new wxButton( itemFrame1, ID_SCHOOL_BTN_NEXT, wxT("    Вперед    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_next->SetForegroundColour(wxColour(26, 26, 26));
    m_btn_next->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_next->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer3->Add(m_btn_next, 0, wxGROW|wxALL, 5);

////@end School content construction
}

// begin custom

void School::PostInit()
{
    selectedItem = wxEmptyString;
    selectedPrefix = m_selected_st->GetLabel();
    curr_idx_selected = 0;
    checkboxes_count = m_check_lb->GetCount();

    if (checkboxes_count > 0) {
        m_check_lb->Check(curr_idx_selected, true);

        wxCommandEvent fakeEvent(wxEVT_CHECKLISTBOX, m_check_lb->GetId());
        fakeEvent.SetInt(curr_idx_selected); 
        
        OnChecklistboxToggled(fakeEvent); 
    }
}

void School::BeforeNextWindow()
{
    //if (selectedItem.IsEmpty()) {
        ////wxLogMessage("[%s] [BeforeNextWindow] selected item is empty, skip...", __FUNCTION__);
        //return;
    //}

    MWSApp& mwsapp = wxGetApp();

    wxString question = m_question_st->GetLabel();
    std::vector<wxString> questions = mwsapp.SplitString(mwsapp.GetQuestions());
    std::vector<wxString> answers = mwsapp.SplitString(mwsapp.GetAnswers());

    size_t idx = mwsapp.GetSchoolIndex();  

    bool questionRepeat = false;
    bool answerRepeat = false;

    for (const auto& q : questions) {
        if (q == question) {
            questionRepeat = true;
            ////wxLogMessage("[%s] Question repeat detected: [%s]", __FUNCTION__, q);
            break;
        }
    }

    for (const auto& a : answers) {
        if (a == selectedItem) {
            answerRepeat = true;
            ////wxLogMessage("[%s] Answer repeat detected: [%s]", __FUNCTION__, a);
            break;
        }
    }

    if (questionRepeat && !answerRepeat) {
        if (idx < answers.size()) {
            answers[idx] = selectedItem;
        }
    }
    else if (!questionRepeat && !answerRepeat) {
        // Обновить или добавить answer
        if (idx <= answers.size()) {
            if (idx < answers.size())
                answers[idx] = selectedItem;
            else
                answers.push_back(selectedItem);
        }

        // Обновить или добавить question
        if (idx <= questions.size()) {
            if (idx < questions.size())
                questions[idx] = question;
            else
                questions.push_back(question);
        }
    }

    mwsapp.SetQuestions(mwsapp.JoinString(questions));
    mwsapp.SetAnswers(mwsapp.JoinString(answers));

    ////wxLogMessage("[%s] State synced -> Q: [%s] | A: [%s]", __FUNCTION__, mwsapp.GetQuestions(), mwsapp.GetAnswers());
}

// end custom

/*
 * Should we show tooltips?
 */

bool School::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap School::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin School bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("arm.xpm"))
    {
        wxBitmap bitmap(arm_50);
        return bitmap;
    }
    return wxNullBitmap;
////@end School bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon School::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin School icon retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxIcon icon(teacher);
        return icon;
    }
    return wxNullIcon;
////@end School icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACK
 */

void School::OnSchoolBtnBackClick( wxCommandEvent& event )
{
    Destroy();
    this->GetParent()->Show(true);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT
 */

void School::OnSchoolBtnNextClick( wxCommandEvent& event )
{
    BeforeNextWindow();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in School.
    // Before editing this code, remove the block markers.
    Youth* window = new Youth(this);
    window->Show(true);
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in School.
    Show(false);
}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_SCHOOL
 */

void School::OnCloseWindow( wxCloseEvent& event )
{
    Destroy();
    this->GetParent()->Close(true);
}


/*
 * wxEVT_COMMAND_CHECKLISTBOX_TOGGLED event handler for ID_CHECKLISTBOX
 */

void School::OnChecklistboxToggled( wxCommandEvent& event )
{
    int toggled_idx = event.GetInt();  
    
    for (size_t i = 0; i < m_check_lb->GetCount(); ++i) {
        if (i != static_cast<size_t>(toggled_idx) && m_check_lb->IsChecked(i)) {
            m_check_lb->Check(i, false);
        }
    }

    if (m_check_lb->IsChecked(toggled_idx)) {
        curr_idx_selected = toggled_idx;
        selectedItem = m_check_lb->GetString(curr_idx_selected);
    } else {
        //curr_idx_selected = toggled_idx;
        //selectedItem = m_check_lb->GetString(curr_idx_selected);
        m_check_lb->Check(toggled_idx, true);
    }
    selectedMessage = selectedPrefix + " " + selectedItem;
    m_selected_st->SetLabel(selectedMessage);
}

