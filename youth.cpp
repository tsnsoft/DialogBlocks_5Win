/////////////////////////////////////////////////////////////////////////////
// Name:        youth.cpp
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Sun Apr 13 19:30:58 2025
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
#include "results.h"
////@end includes

#include "youth.h"
#include "DialogBlocks_5Win.h"

////@begin XPM images
#include "teacher.xpm"
////@end XPM images


/*
 * Youth type definition
 */

IMPLEMENT_CLASS( Youth, wxFrame )


/*
 * Youth event table definition
 */

BEGIN_EVENT_TABLE( Youth, wxFrame )

////@begin Youth event table entries
    EVT_CLOSE( Youth::OnCloseWindow )
    EVT_LISTBOX( ID_LISTBOX, Youth::OnListboxSelected )
    EVT_BUTTON( ID_YOUTH_BTN_BACK, Youth::OnYouthBtnBackClick )
    EVT_BUTTON( ID_YOUTH_BTN_NEXT, Youth::OnYouthBtnNextClick )
////@end Youth event table entries

END_EVENT_TABLE()


/*
 * Youth constructors
 */

Youth::Youth()
{
    Init();
}

Youth::Youth( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * Youth creator
 */

bool Youth::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Youth creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("teacher.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end Youth creation
    PostInit();
    return true;
}


/*
 * Youth destructor
 */

Youth::~Youth()
{
////@begin Youth destruction
////@end Youth destruction
}


/*
 * Member initialisation
 */

void Youth::Init()
{
////@begin Youth member initialisation
    onBackClicked = false;
    m_question_st = NULL;
    m_listbox = NULL;
    m_selected_st = NULL;
    m_btn_back = NULL;
    m_btn_next = NULL;
////@end Youth member initialisation
}


/*
 * Control creation for Youth
 */

void Youth::CreateControls()
{    
////@begin Youth content construction
    Youth* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    m_question_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Какое у вас образование"), wxDefaultPosition, wxDefaultSize, 0 );
    m_question_st->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_question_st, 0, wxALIGN_LEFT|wxALL, 25);

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_listboxStrings;
    m_listboxStrings.Add(wxT("Неполное среднее"));
    m_listboxStrings.Add(wxT("Среднее"));
    m_listboxStrings.Add(wxT("Среднее-специальное"));
    m_listboxStrings.Add(wxT("Высшее"));
    m_listbox = new wxListBox( itemFrame1, ID_LISTBOX, wxDefaultPosition, wxDefaultSize, m_listboxStrings, wxLB_SINGLE );
    m_listbox->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer2->Add(m_listbox, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 25);

    wxStaticBitmap* itemStaticBitmap4 = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("teacher.xpm")), wxDefaultPosition, wxSize(256, 256), 0 );
    itemBoxSizer2->Add(itemStaticBitmap4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 75);

    m_selected_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Выбрано:"), wxDefaultPosition, wxDefaultSize, 0 );
    m_selected_st->SetForegroundColour(wxColour(0, 0, 0));
    m_selected_st->SetBackgroundColour(wxColour(229, 229, 229));
    m_selected_st->SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_selected_st, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 25);

    wxStaticLine* itemStaticLine3 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer1->Add(itemStaticLine3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 25);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_btn_back = new wxButton( itemFrame1, ID_YOUTH_BTN_BACK, wxT("    Назад    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_back->SetForegroundColour(wxColour(0, 0, 0));
    m_btn_back->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_back->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer4->Add(m_btn_back, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine6 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemStaticLine6->SetName(wxT("Spacer"));
    itemBoxSizer4->Add(itemStaticLine6, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 250);

    m_btn_next = new wxButton( itemFrame1, ID_YOUTH_BTN_NEXT, wxT("    Вперед    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_next->SetForegroundColour(wxColour(26, 26, 26));
    m_btn_next->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_next->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer4->Add(m_btn_next, 0, wxGROW|wxALL, 5);

////@end Youth content construction
}

// begin custom

void Youth::PostInit()
{
    listbox_count = m_listbox->GetCount();
    default_idx_inited = false;
    idx_selected = 0;
    selectedItem = wxEmptyString;
    selectedPrefix = m_selected_st->GetLabel();
    
    // width and height of listbox
    lines_to_show = listbox_count;
    row_height = 30;
    m_listbox->SetMinSize(wxSize(-1, lines_to_show * row_height));
    
    // default selected item is 0 index
    wxCommandEvent dummy;
    OnListboxSelected(dummy);
}

void Youth::BeforeNextWindow()
{
    //if (selectedItem.IsEmpty()) {
        ////wxLogMessage("[%s] [BeforeNextWindow] selected item is empty, skip...", __FUNCTION__);
    //    return;
    //}

    MWSApp& mwsapp = wxGetApp();

    wxString question = m_question_st->GetLabel();
    std::vector<wxString> questions = mwsapp.SplitString(mwsapp.GetQuestions());
    std::vector<wxString> answers = mwsapp.SplitString(mwsapp.GetAnswers());

    size_t idx = mwsapp.GetYouthIndex();

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

bool Youth::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Youth::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Youth bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxBitmap bitmap(teacher);
        return bitmap;
    }
    return wxNullBitmap;
////@end Youth bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Youth::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Youth icon retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxIcon icon(teacher);
        return icon;
    }
    return wxNullIcon;
////@end Youth icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACK
 */

void Youth::OnYouthBtnBackClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACK in Youth.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACK in Youth. 
    this->GetParent()->Show(true);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT
 */

void Youth::OnYouthBtnNextClick( wxCommandEvent& event )
{
    BeforeNextWindow();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in Youth.
    // Before editing this code, remove the block markers.
    Results* window = new Results(this);
    window->Show(true);
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in Youth.
    Show(false);
}


/*
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX
 */

void Youth::OnListboxSelected( wxCommandEvent& event )
{
    if (!default_idx_inited) {
        m_listbox->SetSelection(idx_selected);
        default_idx_inited = true;
        ////wxLogMessage("default idx not inited");
    } else {
        idx_selected = m_listbox->GetSelection();
        ////wxLogMessage("default idx is inited");
    }
    
    if (idx_selected < 0) {
        idx_selected = 0;
    } else if (idx_selected >= listbox_count) {
        idx_selected = listbox_count-1;
    }
    
    selectedItem = m_listbox->GetString(idx_selected);
    selectedMessage = selectedPrefix + " " + selectedItem;
    m_selected_st->SetLabel(selectedMessage);
}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_YOUTH
 */

void Youth::OnCloseWindow( wxCloseEvent& event )
{
    Destroy();
    this->GetParent()->Close(true);
    event.Skip();
}


