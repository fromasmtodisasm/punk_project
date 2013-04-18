#include "test_create_opengl_window.h"

class MyApp : public Punk::Application
{
public:
};

void CreateOpenGLWindow::Run()
{
    MyApp app;
    try
    {
        app.Init(Punk::Config());
        app.Run();
    }
    catch(...)
    {
        m_result = false;
    }
}

bool CreateOpenGLWindow::Succeed()
{
    return m_result;
}