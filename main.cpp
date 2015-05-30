#include <QApplication>
#include <QPushButton>
#include <QOpenGLWindow>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QOpenGLWidget>
class OpenglWindow : public QOpenGLWindow
{
protected:
    void paintGL()
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
    }
};

class OpenglWidget : public QOpenGLWidget {
public:
    OpenglWidget(QWidget *parent) : QOpenGLWidget(parent) { }
protected:
    void paintGL()
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
    }
};

class MainWindow : public QMainWindow
{
public:
    MainWindow()
    {
        QWidget * mainWdg = new QWidget(this);
        QVBoxLayout *vlay = new QVBoxLayout(mainWdg);
        OpenglWidget * openglWdg = new OpenglWidget(mainWdg);
        vlay->addWidget(openglWdg);

        QPushButton *btn1 = new QPushButton("btn1");
        vlay->addWidget(btn1);
        setCentralWidget(mainWdg);
    }
};

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    OpenglWindow window;
    window.show();

    MainWindow window2;
    window2.show();

    return app.exec();
}
