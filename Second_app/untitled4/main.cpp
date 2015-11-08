#include <QApplication>

#include "mywindow.h"

int main(int argc, char ** argv)
{
QApplication app(argc,argv);
MyWindow *a= new MyWindow();
a->show();
return app.exec();
}
