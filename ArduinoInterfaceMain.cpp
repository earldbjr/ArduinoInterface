/***************************************************************
 * Name:      ArduinoInterfaceMain.cpp wireless?
 * Purpose:   Code for Application Frame
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-07-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/
//Serial instructions follow the format:
//Device# - To differentiate between listening wireless devices
//Primary Task - Choose between major tasks of the device
//Primary Instruction - Choose function to call
//Arg1
//Arg2

#include "wx_pch.h"
#include "ArduinoInterfaceMain.h"
#include <wx/msgdlg.h>
#include "arduinoserial.h"

//#define PORT "/dev/ttyACM0"
//#define PORT1 "/dev/ttyACM1"
char PORT = '0';
using namespace  std;
int fd;
//(*InternalHeaders(ArduinoInterfaceFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

ArduinoSerial serial;

enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(ArduinoInterfaceFrame)
const long ArduinoInterfaceFrame::ID_STATICTEXT2 = wxNewId();
const long ArduinoInterfaceFrame::ID_CHOICE2 = wxNewId();
const long ArduinoInterfaceFrame::ID_BUTTON2 = wxNewId();
const long ArduinoInterfaceFrame::ID_BUTTON4 = wxNewId();
const long ArduinoInterfaceFrame::ID_PANEL1 = wxNewId();
const long ArduinoInterfaceFrame::ID_CHOICE1 = wxNewId();
const long ArduinoInterfaceFrame::ID_BUTTON3 = wxNewId();
const long ArduinoInterfaceFrame::ID_PANEL2 = wxNewId();
const long ArduinoInterfaceFrame::ID_BUTTON1 = wxNewId();
const long ArduinoInterfaceFrame::ID_STATICTEXT1 = wxNewId();
const long ArduinoInterfaceFrame::ID_CHOICE3 = wxNewId();
const long ArduinoInterfaceFrame::idMenuQuit = wxNewId();
const long ArduinoInterfaceFrame::idMenuAbout = wxNewId();
const long ArduinoInterfaceFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ArduinoInterfaceFrame,wxFrame)
//(*EventTable(ArduinoInterfaceFrame)
//*)
END_EVENT_TABLE()

ArduinoInterfaceFrame::ArduinoInterfaceFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ArduinoInterfaceFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxFlexGridSizer* FlexGridSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer2 = new wxFlexGridSizer(4, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    FlexGridSizer2->AddGrowableRow(1);
    lblDevice = new wxStaticText(this, ID_STATICTEXT2, _("Device  #:"), wxDefaultPosition, wxSize(79,17), 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(lblDevice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chDevID = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    chDevID->SetSelection( chDevID->Append(_("1")) );
    chDevID->Append(_("2"));
    FlexGridSizer2->Add(chDevID, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("LED"));
    FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
    btnOn = new wxButton(Panel1, ID_BUTTON2, _("On"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer5->Add(btnOn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOff = new wxButton(Panel1, ID_BUTTON4, _("Off"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer5->Add(btnOff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(StaticBoxSizer1);
    StaticBoxSizer1->Fit(Panel1);
    StaticBoxSizer1->SetSizeHints(Panel1);
    FlexGridSizer3->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->Hide();
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("IunnoYet"));
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    Choice1 = new wxChoice(Panel2, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer4->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel2, ID_BUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel2->SetSizer(StaticBoxSizer2);
    StaticBoxSizer2->Fit(Panel2);
    StaticBoxSizer2->SetSizeHints(Panel2);
    FlexGridSizer3->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(3, 3, 0, 0);
    btnSendTest = new wxButton(this, ID_BUTTON1, _("Send Test"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(btnSendTest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lblResponse = new wxStaticText(this, ID_STATICTEXT1, _("Response"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(lblResponse, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chSerialPort = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    chSerialPort->Append(_("0"));
    chSerialPort->Append(_("1"));
    chSerialPort->Append(_("2"));
    chSerialPort->Append(_("3"));
    chSerialPort->Append(_("4"));
    FlexGridSizer1->Add(chSerialPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnchDevIDSelect);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnbtnOnClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnbtnOffClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnbtnSendTestClick);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnchSerialPortSelect);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ArduinoInterfaceFrame::OnAbout);
    //*)
}


ArduinoInterfaceFrame::~ArduinoInterfaceFrame()
{
    //(*Destroy(ArduinoInterfaceFrame)
    //*)
}



void ArduinoInterfaceFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void ArduinoInterfaceFrame::OnbtnSendTestClick(wxCommandEvent& event)
{
}

void ArduinoInterfaceFrame::OncbDeviceIDSelected(wxCommandEvent& event)
{

}

void ArduinoInterfaceFrame::OnbtnOnClick(wxCommandEvent& event)
{
    serial.setFunction(1); //Select LED
    serial.setInstruction(1); //ON
    serial.setOpt1(0);
    serial.setOpt2(0);
    serial.transmit();
}

void ArduinoInterfaceFrame::OnbtnOffClick(wxCommandEvent& event)
{
    serial.setFunction(1); //Select LED
    serial.setInstruction(2); //OFF
    serial.setOpt1(0);
    serial.setOpt2(0);
    serial.transmit();
}

void ArduinoInterfaceFrame::OnQuit(wxCommandEvent& event)
{
    serial.closePort();
    Close();
}

void ArduinoInterfaceFrame::OnchDevIDSelect(wxCommandEvent& event)
{
   int device = chDevID->GetCurrentSelection()+1;
serial.setDevice(device); //+1 to reserve 0
serial.transmit();

    //lblResponse->SetLabel(wxString::Format(wxT("%i"), chrInstruction[0])); //Uncomment to test
    switch(serial.getDevice())
    {
    case '1':
        Panel2->Hide();
        Panel1->Show();
        GetSizer()->Layout();//Resizes the Sizer around the Objects
        Fit();//Resizes the Window around the Sizer
        break;
    case '2':
        Panel1->Hide();
        Panel2->Show();
        GetSizer()->Layout();
        Fit();
        break;
    }
}

void ArduinoInterfaceFrame::closePortThenClose(wxCloseEvent& event)
{
    serial.closePort();
    Destroy();
}

void ArduinoInterfaceFrame::OnchSerialPortSelect(wxCommandEvent& event)
{
    int newPort = chSerialPort->GetCurrentSelection();
    serial.changePort(newPort);
}
