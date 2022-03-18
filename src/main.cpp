#include "video_capture_devices.h"
#include "webcam_settings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    const Video_capture_devices video_capture_devices;
    const auto video_capture_devices_list{video_capture_devices.get_list()};

    QApplication application(argc, argv);

    Webcam_settings webcam_settings(video_capture_devices_list);
    webcam_settings.show();

    return application.exec();
}
