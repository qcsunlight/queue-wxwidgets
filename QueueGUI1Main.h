/***************************************************************
 * Name:      QueueGUI1Main.h
 * Purpose:   Defines Application Frame
 * Author:    qingcong ()
 * Created:   2016-12-20
 * Copyright: qingcong ()
 * License:
 **************************************************************/

#ifndef QUEUEGUI1MAIN_H
#define QUEUEGUI1MAIN_H

//(*Headers(QueueGUI1Frame)
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class QueueGUI1Frame: public wxFrame
{
    public:

        QueueGUI1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~QueueGUI1Frame();

    private:

        //(*Handlers(QueueGUI1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnfileopenbuttonmClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(QueueGUI1Frame)
        static const long ID_STATICLINE1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE2;
        static const long ID_STATICLINE3;
        static const long ID_STATICLINE4;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_TEXTCTRL1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(QueueGUI1Frame)
        wxButton* upSortbt;
        wxStaticLine* lineend;
        wxStaticLine* lineleft;
        wxStaticLine* linecenter;
        wxPanel* Panel1;
        wxFileDialog* FileDialog1;
        wxStaticLine* linetop;
        wxButton* downSortbt;
        wxTextCtrl* TextCtrl1;
        wxButton* fileopenbuttonm;
        wxButton* buttonhelp;
        wxButton* fileOutbt;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // QUEUEGUI1MAIN_H
