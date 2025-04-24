/////////////////////////////////////////////////////////////////////////////
// Name:        DialogBlocks_5Win.h
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Wed Apr 16 16:38:01 2025
// RCS-ID:      
// Copyright:   Thackev D.V., Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MWSAPP_H_
#define _MWSAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "greeting.h"
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
////@end control identifiers

/*!
 * MWSApp class declaration
 */

class MWSApp: public wxApp
{    
    DECLARE_CLASS( MWSApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    MWSApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin MWSApp event handler declarations

////@end MWSApp event handler declarations

////@begin MWSApp member function declarations

	wxString GetAnswers() const { return answers ; }
	void SetAnswers(wxString value) { answers = value ; }

	int GetChildhoodIndex() const { return childhoodIndex ; }
	void SetChildhoodIndex(int value) { childhoodIndex = value ; }

	wxString GetDelimiter() const { return delimiter ; }
	void SetDelimiter(wxString value) { delimiter = value ; }

	wxString GetQuestions() const { return questions ; }
	void SetQuestions(wxString value) { questions = value ; }

	int GetSchoolIndex() const { return schoolIndex ; }
	void SetSchoolIndex(int value) { schoolIndex = value ; }

	int GetYouthIndex() const { return youthIndex ; }
	void SetYouthIndex(int value) { youthIndex = value ; }

////@end MWSApp member function declarations
    
// begin custom
    wxString AppendWithDelimiter(
        const wxString &base,
        const wxString &addition = wxEmptyString,
        const wxString &delim = wxEmptyString
    ) const;

    std::vector<wxString> SplitString(
        const wxString& str, 
        const wxString& delim=wxEmptyString
    );
    
    wxString JoinString(
        const std::vector<wxString>& strings, 
        const wxString& 
        delim=wxEmptyString
    );
// end custom

////@begin MWSApp member variables
private:
	wxString answers;
	int childhoodIndex; // question index
	wxString delimiter; // strings separator
	wxString questions;
	int schoolIndex; // question index
	int youthIndex; // question index
////@end MWSApp member variables

};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(MWSApp)
////@end declare app

#endif
    // _MWSAPP_H_
