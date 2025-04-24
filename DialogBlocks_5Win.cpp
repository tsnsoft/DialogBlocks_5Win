/////////////////////////////////////////////////////////////////////////////
// Name:        DialogBlocks_5Win.cpp
// Purpose:     
// Author:      Thackev D.V., Talipov S.N.
// Modified by: 
// Created:     Wed Apr 16 16:38:01 2025
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
////@end includes

#include "DialogBlocks_5Win.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( MWSApp )
////@end implement app


/*
 * MWSApp type definition
 */

IMPLEMENT_CLASS( MWSApp, wxApp )


/*
 * MWSApp event table definition
 */

BEGIN_EVENT_TABLE( MWSApp, wxApp )

////@begin MWSApp event table entries
////@end MWSApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for MWSApp
 */

MWSApp::MWSApp()
{
    Init();
}


/*
 * Member initialisation
 */

void MWSApp::Init()
{
////@begin MWSApp member initialisation
	childhoodIndex = 0;
	delimiter = ",";
	schoolIndex = 1;
	youthIndex = 2;
////@end MWSApp member initialisation
}

/*
 * Initialisation for MWSApp
 */

bool MWSApp::OnInit()
{    
////@begin MWSApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	Greeting* mainWindow = new Greeting( NULL );
	mainWindow->Show(true);
////@end MWSApp initialisation
    return true;
}

// begin custom
wxString MWSApp::AppendWithDelimiter(
	const wxString &base, 
	const wxString &addition, 
	const wxString &delim
) const
{
	wxString result = wxEmptyString;

	if (base.IsEmpty())
	{
		return result;
	}

	wxString effective_delim = wxEmptyString;
	if (delim.IsEmpty())
	{
		effective_delim = this->delimiter;
	}
	else
	{
		effective_delim = delim;
	}

	if (base.Last() == effective_delim)
	{
		effective_delim = wxEmptyString;
	}

	result = base + effective_delim + addition;

	////wxLogMessage("[DialogBlocks_5Win.h] [AppendWithDelimiter] [%s] [%s] [%s]", base, effective_delim, addition);

	return result;
}

std::vector<wxString> MWSApp::SplitString(
	const wxString &str, 
	const wxString &delim
)
{

	std::vector<wxString> result;

	if (str.IsEmpty())
	{
		return result;
	}

	wxString effective_delim;
	if (delim.IsEmpty())
	{
		effective_delim = this->delimiter;
	}
	else
	{
		effective_delim = delim;
	}

	size_t start = 0;
	size_t delim_pos = 0;
	wxString token;

	////wxLogMessage("[stringsplit] start | string [%s] | size [%zu]", str, str.size());

	while ((delim_pos = str.find(effective_delim, start)) != wxString::npos)
	{
		token = str.substr(start, delim_pos - start);
		if (!token.IsEmpty()) {
			result.push_back(token);
		}
		start = delim_pos + effective_delim.length();
	}

	if (start <= str.length())
	{
		token = str.substr(start);
		if (!token.IsEmpty()) {
			result.push_back(token);
		}
	}

	////wxLogMessage("[stringsplit] finish | tokens total: %zu | string %s | length %zu", result.size(), (wxString)str, str.size());
	return result;
}

wxString MWSApp::JoinString(
	const std::vector<wxString> &strings, 
	const wxString &delim
)
{

	////wxLogMessage("[JoinString] start for strings size [%zu]", strings.size());

	wxString effective_delim;
	if (delim.IsEmpty())
	{
		effective_delim = this->delimiter;
	}
	else
	{
		effective_delim = delim;
	}

	wxString result;
	for (size_t i = 0; i < strings.size(); ++i)
	{
		////wxLogMessage("[JoinString] [AppendWithDelimiter] to [%s]", strings[i]);
		result += this->AppendWithDelimiter(strings[i]);
	}

	////wxLogMessage("[JoinString] result [%s]", result);
	return result;
}

// end custom

/*
 * Cleanup for MWSApp
 */

int MWSApp::OnExit()
{    
////@begin MWSApp cleanup
	return wxApp::OnExit();
////@end MWSApp cleanup
}

