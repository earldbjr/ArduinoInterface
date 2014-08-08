/***************************************************************
 * Name:      ArduinoInterfaceMain.h
 * Purpose:   Defines Application Frame
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-07-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/

#ifndef ARDUINOINTERFACEMAIN_H
#define ARDUINOINTERFACEMAIN_H

//(*Headers(ArduinoInterfaceFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/choice.h>
//*)

class ArduinoInterfaceFrame: public wxFrame
{
    public:

        ArduinoInterfaceFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ArduinoInterfaceFrame();

    private:

        //(*Handlers(ArduinoInterfaceFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnSendTestClick(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OncbDeviceIDSelected(wxCommandEvent& event);
        void OnbtnOnClick(wxCommandEvent& event);
        void OnbtnOffClick(wxCommandEvent& event);
        void OnChoice2Select(wxCommandEvent& event);
        void OnchDevIDSelect(wxCommandEvent& event);
        void closePortThenClose(wxCloseEvent& event);
        void OnchSerialPortSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(ArduinoInterfaceFrame)
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE2;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long ID_CHOICE1;
        static const long ID_BUTTON3;
        static const long ID_PANEL2;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ArduinoInterfaceFrame)
        wxButton* btnSendTest;
        wxChoice* chDevID;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* btnOff;
        wxChoice* chSerialPort;
        wxButton* Button2;
        wxPanel* Panel2;
        wxStaticText* lblDevice;
        wxChoice* Choice1;
        wxButton* btnOn;
        wxStaticText* lblResponse;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ARDUINOINTERFACEMAIN_H
