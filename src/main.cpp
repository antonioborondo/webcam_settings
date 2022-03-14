#include "video_capture_devices.h"
#include "webcam_settings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Video_capture_devices video_capture_devices;

    QApplication a(argc, argv);
    webcam_settings w;
    w.show();
    return a.exec();
}
