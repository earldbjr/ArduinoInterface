/***************************************************************
 * Name:      ArduinoInterfaceApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-07-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ArduinoInterfaceApp.h"

//(*AppHeaders
#include "ArduinoInterfaceMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ArduinoInterfaceApp);

bool ArduinoInterfaceApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ArduinoInterfaceFrame* Frame = new ArduinoInterfaceFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
