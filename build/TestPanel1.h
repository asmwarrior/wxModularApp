#ifndef TESTPANEL1_H
#define TESTPANEL1_H

#include <wxGuiPluginWindowBase.h>

//(*Headers(TestPanel1)
#include <wx/panel.h>
class wxBoxSizer;
class wxButton;
//*)

class TestPanel1: public wxGuiPluginWindowBase
{
    public:
        TestPanel1(){}
        TestPanel1( wxGuiPluginBase * plugin, wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~TestPanel1();

        //(*Declarations(TestPanel1)
        wxButton* Button1;
        wxButton* Button2;
        //*)

    protected:

        //(*Identifiers(TestPanel1)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

    private:

        //(*Handlers(TestPanel1)
        //*)

        DECLARE_DYNAMIC_CLASS( SampleGuiPluginWindow1 )

        DECLARE_EVENT_TABLE()
};

#endif
