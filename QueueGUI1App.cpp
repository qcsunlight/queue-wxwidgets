/***************************************************************
 * Name:      QueueGUI1App.cpp
 * Purpose:   Code for Application Class
 * Author:    qingcong ()
 * Created:   2016-12-20
 * Copyright: qingcong ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "QueueGUI1App.h"

//(*AppHeaders
#include "QueueGUI1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(QueueGUI1App);

bool QueueGUI1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	QueueGUI1Frame* Frame = new QueueGUI1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
