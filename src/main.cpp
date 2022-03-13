#include "webcam_settings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    webcam_settings w;
    w.show();
    return a.exec();
}
