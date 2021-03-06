#include <QApplication>
#include <QPushButton>
#include <QOpenGLWindow>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QOpenGLWidget>
#include <QDebug>
#include <QTimer>
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
    float angle;
public:
    OpenglWidget(QWidget *parent);
protected:
    void paintGL();
public:
    void Animation();

};

OpenglWidget::OpenglWidget(QWidget *parent) : QOpenGLWidget(parent) {
    angle = 0.0;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(0);
}

void OpenglWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    //qDebug("%f",angle);
    glPopMatrix();
    angle++;
}

void OpenglWidget::Animation()
{

}

class MainWindow : public QMainWindow
{
    OpenglWidget * openglWdg;
public:
    MainWindow()
    {
        QWidget * mainWdg = new QWidget(this);
        QVBoxLayout *vlay = new QVBoxLayout(mainWdg);
        openglWdg = new OpenglWidget(mainWdg);
        vlay->addWidget(openglWdg);
        QPushButton *btn1 = new QPushButton("btn1");
        vlay->addWidget(btn1);
        setCentralWidget(mainWdg);
    }
};

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    //OpenglWindow window;
    //window.show();

    MainWindow window2;
    window2.show();
    return app.exec();
}
