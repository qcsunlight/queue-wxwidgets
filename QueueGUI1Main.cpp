/***************************************************************
 * Name:      QueueGUI1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    qingcong ()
 * Created:   2016-12-20
 * Copyright: qingcong ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "QueueGUI1Main.h"
#include <wx/msgdlg.h>

#include <wx/textfile.h>

//(*InternalHeaders(QueueGUI1Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(QueueGUI1Frame)
const long QueueGUI1Frame::ID_STATICLINE1 = wxNewId();
const long QueueGUI1Frame::ID_BUTTON1 = wxNewId();
const long QueueGUI1Frame::ID_STATICLINE2 = wxNewId();
const long QueueGUI1Frame::ID_STATICLINE3 = wxNewId();
const long QueueGUI1Frame::ID_STATICLINE4 = wxNewId();
const long QueueGUI1Frame::ID_BUTTON2 = wxNewId();
const long QueueGUI1Frame::ID_BUTTON3 = wxNewId();
const long QueueGUI1Frame::ID_BUTTON4 = wxNewId();
const long QueueGUI1Frame::ID_BUTTON5 = wxNewId();
const long QueueGUI1Frame::ID_TEXTCTRL1 = wxNewId();
const long QueueGUI1Frame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(QueueGUI1Frame,wxFrame)
    //(*EventTable(QueueGUI1Frame)
    //*)
END_EVENT_TABLE()

QueueGUI1Frame::QueueGUI1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(QueueGUI1Frame)
    Create(parent, wxID_ANY, _("活动场所租赁"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(815,486));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(248,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    linetop = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(10,59), wxSize(392,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    fileopenbuttonm = new wxButton(Panel1, ID_BUTTON1, _("打 开 文 件"), wxPoint(64,8), wxSize(96,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    linecenter = new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(407,63), wxSize(1,381), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    lineleft = new wxStaticLine(Panel1, ID_STATICLINE3, wxPoint(5,64), wxSize(1,381), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    lineend = new wxStaticLine(Panel1, ID_STATICLINE4, wxPoint(10,450), wxSize(392,1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    buttonhelp = new wxButton(Panel1, ID_BUTTON2, _("帮 助 信 息"), wxPoint(256,8), wxSize(96,48), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    upSortbt = new wxButton(Panel1, ID_BUTTON3, _("升 序 排 序"), wxPoint(456,96), wxSize(96,48), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    downSortbt = new wxButton(Panel1, ID_BUTTON4, _("降 序 排 序"), wxPoint(456,200), wxSize(96,48), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    fileOutbt = new wxButton(Panel1, ID_BUTTON5, _("输 出 数 据"), wxPoint(456,296), wxSize(96,48), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,64), wxSize(396,384), wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&QueueGUI1Frame::OnfileopenbuttonmClick);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&QueueGUI1Frame::OnPanel1Paint,0,this);
    //*)
}

QueueGUI1Frame::~QueueGUI1Frame()
{
    //(*Destroy(QueueGUI1Frame)
    //*)
}

void QueueGUI1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void QueueGUI1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void QueueGUI1Frame::OnPanel1Paint(wxPaintEvent& event)
{
}

void QueueGUI1Frame::OnfileopenbuttonmClick(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;

    int result;
    result = FileDialog1->ShowModal();
    if(result == wxID_OK)
    {
        file.Open(FileDialog1->GetPath());
        for(size_t i=0; i<file.GetLineCount(); i++)
        {
            text << file.GetLine(i) ;//<< _T("\r\n");
            text << _T("   \r\n");
            //TextCtrl1->SetValue("\n");
        }
        file.Close();
        TextCtrl1->SetValue(text);
    }


}
