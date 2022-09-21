//https://www.tomdalling.com/blog/software-design/solid-class-design-the-interface-segregation-principle/

/*
The problem with this design is that SomeButton and SomeWindow both have a SomeController pointer.
SomeButton does need to call the onButton[X] methods of the controller object, but it also has access
to the onWindow[X] methods (i.e. _controller->onWindowClose ) which are useless to the button.
The presence of useless onWindow[X] methods is a violation of the ISP.
There is also a cyclic dependency, which is another hint that something is amiss.

"fat interfaces" — interfaces with additional useless methods — lead to inadvertent coupling between classes

*/

namespace before
{
class SomeButton;
class SomeController;
class SomeWindow;

class SomeButton {
private:
    SomeController* _controller;
public:
    void setController(SomeController* controller);
};

class SomeWindow {
private:
    SomeController* _controller;
public:
    void setController(SomeController* controller);
};

class SomeController {
private:
    SomeWindow* _window;
    SomeButton* _okButton;
    SomeButton* _cancelButton;
public:
    void onButtonDown(SomeButton* button);
    void onButtonUp(SomeButton* button);
    void onWindowOpen(SomeWindow* window);
    void onWindowClose(SomeWindow* window);
    void onWindowMoved(SomeWindow* window);
};

}//before

namespace after
{

class SomeButtonController;
class SomeButton;
class SomeWindowController;
class SomeWindow;

// The Button ///////////////////////////////////////////////////////

class SomeButtonController {
public:
    virtual void onButtonDown(SomeButton* button) = 0;
    virtual void onButtonUp(SomeButton* button) = 0;
};

class SomeButton {
private:
    SomeButtonController* _controller;
public:
    void setController(SomeButtonController* controller);
};

// The Window ///////////////////////////////////////////////////////

class SomeWindowController {
public:
    virtual void onWindowOpen(SomeWindow* window) = 0;
    virtual void onWindowClose(SomeWindow* window) = 0;
    virtual void onWindowMoved(SomeWindow* window) = 0;
};

class SomeWindow {
private:
    SomeWindowController* _controller;
public:
    void setController(SomeWindowController* controller);
};

// The Controller ///////////////////////////////////////////////////////

class SomeController : public SomeButtonController, public SomeWindowController {
private:
    SomeWindow* _window;
    SomeButton* _okButton;
    SomeButton* _cancelButton;
public:
    void onButtonDown(SomeButton* button);
    void onButtonUp(SomeButton* button);
    void onWindowOpen(SomeWindow* window);
    void onWindowClose(SomeWindow* window);
    void onWindowMoved(SomeWindow* window);
};

}// after

int main()
{

}









//worked example

#include <iostream>
#include <string.h>
#include <fmt/core.h>
using namespace std;
// using fmt::print;
namespace after
{

    class SomeButtonController;
    class SomeButton;
    class SomeWindowController;
    class SomeWindow;

    // The Button ///////////////////////////////////////////////////////

    class SomeButtonController
    {
    public:
        virtual void onButtonDown() = 0;
        virtual void onButtonUp() = 0;
    };

    class SomeButton
    {
    private:
        SomeButtonController *_controller;

    public:
        void setController(SomeButtonController *controller)
        {
            _controller = controller;
        }
        void runButton()
        {
            _controller->onButtonUp();
            _controller->onButtonDown();
        }
    };

    // The Window ///////////////////////////////////////////////////////

    class SomeWindowController
    {
    public:
        virtual void onWindowOpen() = 0;
        virtual void onWindowClose() = 0;
        virtual void onWindowMoved() = 0;
    };

    class SomeWindow
    {
    private:
        SomeWindowController *_controller;

    public:
        void setController(SomeWindowController *controller)
        {
            _controller = controller;
        }
        void runWindows()
        {
            _controller->onWindowOpen();
            _controller->onWindowMoved();
            _controller->onWindowClose();
        }
    };

    // The Controller ///////////////////////////////////////////////////////

    class SomeController : public SomeButtonController, public SomeWindowController
    {
    private:
        SomeWindow *_window;
        SomeButton *_okButton;
        SomeButton *_cancelButton;

    public:
        void onButtonDown()
        {
            cout << " frome onButtonDown \n";
        }
        void onButtonUp()
        {
            cout << " frome onButtonUp \n";
        }
        void onWindowOpen()
        {
            cout << " frome onWindowOpen \n";
        }
        void onWindowClose()
        {
            cout << " frome onWindowClose \n";
        }
        void onWindowMoved()
        {
            cout << " frome onWindowMoved \n";
        }
    };

} // after

int main()
{
    after::SomeController _SomeController;

    after::SomeButton newButton;
    newButton.setController(&_SomeController);
    newButton.runButton();

    fmt::print("test");
    after::SomeWindow newwindow;
    newwindow.setController(&_SomeController);
    newwindow.runWindows();
}

