/////////////////////////////////////////////////////////////////////////////
// Name:        childhood.cpp
// Purpose:
// Author:      Thackev D.V., Talipov S.N.
// Modified by:
// Created:     Sun Apr 13 19:29:16 2025
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
#include "greeting.h"
#include "school.h"
////@end includes

#include "childhood.h"
#include "DialogBlocks_5Win.h"

////@begin XPM images
#include "teacher.xpm"
#include "smile.xpm"
////@end XPM images

/*
 * Childhood type definition
 */

IMPLEMENT_CLASS(Childhood, wxFrame)

/*
 * Childhood event table definition
 */

BEGIN_EVENT_TABLE(Childhood, wxFrame)

////@begin Childhood event table entries
    EVT_CLOSE( Childhood::OnCloseWindow )
    EVT_RADIOBOX( ID_RADIOBOX, Childhood::OnRadioboxSelected )
    EVT_BUTTON( ID_CHILDHOOD_BTN_BACK, Childhood::OnChildhoodBtnBackClick )
    EVT_BUTTON( ID_CHILDHOOD_BTN_NEXT, Childhood::OnChildhoodBtnNextClick )
////@end Childhood event table entries

END_EVENT_TABLE()

/*
 * Childhood constructors
 */

Childhood::Childhood()
{
    Init();
}

Childhood::Childhood(wxWindow *parent, wxWindowID id, const wxString &caption, const wxPoint &pos, const wxSize &size, long style)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

/*
 * Childhood creator
 */

bool Childhood::Create(wxWindow *parent, wxWindowID id, const wxString &caption, const wxPoint &pos, const wxSize &size, long style)
{
    ////@begin Childhood creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("teacher.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
    ////@end Childhood creation
    PostInit();
    return true;
}

/*
 * Childhood destructor
 */

Childhood::~Childhood()
{
    ////@begin Childhood destruction
    ////@end Childhood destruction
}

/*
 * Member initialisation
 */

void Childhood::Init()
{
    ////@begin Childhood member initialisation  
    onBackClicked = false;
    m_question_st = NULL;
    m_radio_items = NULL;
    m_selected_st = NULL;
    m_btn_back = NULL;
    m_btn_next = NULL;
    ////@end Childhood member initialisation
}

/*
 * Control creation for Childhood
 */

void Childhood::CreateControls()
{
    ////@begin Childhood content construction
    Childhood* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer2);

    m_question_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Выберите любимую кашу"), wxDefaultPosition, wxDefaultSize, 0 );
    m_question_st->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer2->Add(m_question_st, 0, wxALIGN_LEFT|wxALL, 30);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxArrayString m_radio_itemsStrings;
    m_radio_itemsStrings.Add(wxT("&Манная"));
    m_radio_itemsStrings.Add(wxT("&Рисовая"));
    m_radio_itemsStrings.Add(wxT("&Гороховая"));
    m_radio_itemsStrings.Add(wxT("&Гречневая"));
    m_radio_items = new wxRadioBox( itemFrame1, ID_RADIOBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_radio_itemsStrings, 1, wxRA_SPECIFY_ROWS );
    m_radio_items->SetSelection(0);
    m_radio_items->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer1->Add(m_radio_items, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 25);

    wxStaticBitmap* itemStaticBitmap1 = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("smile.xpm")), wxDefaultPosition, wxSize(236, 236), 0 );
    itemBoxSizer1->Add(itemStaticBitmap1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 75);

    m_selected_st = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Выбрано:"), wxDefaultPosition, wxDefaultSize, 0 );
    m_selected_st->SetForegroundColour(wxColour(0, 0, 0));
    m_selected_st->SetBackgroundColour(wxColour(229, 229, 229));
    m_selected_st->SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Monospace")));
    itemBoxSizer2->Add(m_selected_st, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 25);

    wxStaticLine* itemStaticLine6 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_btn_back = new wxButton( itemFrame1, ID_CHILDHOOD_BTN_BACK, wxT("    Назад    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_back->SetForegroundColour(wxColour(0, 0, 0));
    m_btn_back->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_back->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer3->Add(m_btn_back, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine5 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemStaticLine5->SetName(wxT("Spacer"));
    itemBoxSizer3->Add(itemStaticLine5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 200);

    m_btn_next = new wxButton( itemFrame1, ID_CHILDHOOD_BTN_NEXT, wxT("    Вперед    "), wxDefaultPosition, wxDefaultSize, 0 );
    m_btn_next->SetForegroundColour(wxColour(26, 26, 26));
    m_btn_next->SetBackgroundColour(wxColour(173, 216, 230));
    m_btn_next->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace")));
    itemBoxSizer3->Add(m_btn_next, 0, wxGROW|wxALL, 5);

    ////@end Childhood content construction
}

// begin custom
void Childhood::PostInit()
{
    idx_selected = 0;
    selectedItem = wxEmptyString;

    // Init variables to handle
    selectedPrefix = m_selected_st->GetLabel();
    
    wxCommandEvent dummy;
    OnRadioboxSelected(dummy);
}

void Childhood::BeforeNextWindow()
{
    //if (selectedItem.IsEmpty()) {
        ////wxLogMessage("[%s] [BeforeNextWindow] selected item is empty, skip...", __FUNCTION__);
    //    return;
    //}

    MWSApp& mwsapp = wxGetApp();

    wxString question = m_question_st->GetLabel();
    std::vector<wxString> questions = mwsapp.SplitString(mwsapp.GetQuestions());
    std::vector<wxString> answers = mwsapp.SplitString(mwsapp.GetAnswers());

    size_t idx = mwsapp.GetChildhoodIndex();  

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

bool Childhood::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Childhood::GetBitmapResource(const wxString &name)
{
    // Bitmap retrieval
    ////@begin Childhood bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("smile.xpm"))
    {
        wxBitmap bitmap(f1e7b23cce114568b1ed2bf6de04ff6dic4QXBwfTfJPnqIn);
        return bitmap;
    }
    return wxNullBitmap;
    ////@end Childhood bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Childhood::GetIconResource(const wxString &name)
{
    // Icon retrieval
    ////@begin Childhood icon retrieval
    wxUnusedVar(name);
    if (name == wxT("teacher.xpm"))
    {
        wxIcon icon(teacher);
        return icon;
    }
    return wxNullIcon;
    ////@end Childhood icon retrieval
}

void Childhood::OnChildhoodBtnBackClick(wxCommandEvent &event)
{
    Destroy();
    this->GetParent()->Show(true);
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT
 */

void Childhood::OnChildhoodBtnNextClick(wxCommandEvent &event)
{
    BeforeNextWindow();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in Childhood.
    // Before editing this code, remove the block markers.
    School *window = new School(this);
    window->Show(true);
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_NEXT in Childhood.
    Show(false);
}

/*
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX
 */

void Childhood::OnRadioboxSelected(wxCommandEvent &event)
{
    idx_selected = m_radio_items->GetSelection();
    selectedItem = m_radio_items->GetString(idx_selected);
    selectedMessage = wxString::Format("%s %s", selectedPrefix, selectedItem);
    m_selected_st->SetLabel(selectedMessage);
}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_CHILDHOOD
 */

void Childhood::OnCloseWindow( wxCloseEvent& event )
{
    Destroy();
    this->GetParent()->Close(true);
}
