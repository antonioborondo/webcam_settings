#include "video_capture_devices.h"
#include "webcam_settings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Video_capture_devices video_capture_devices;
    const auto video_capture_devices_list{video_capture_devices.get_list()};


    QApplication a(argc, argv);
    webcam_settings w(video_capture_devices_list);
    w.show();
    return a.exec();
}
