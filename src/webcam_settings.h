#ifndef WEBCAM_SETTINGS_H
#define WEBCAM_SETTINGS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class webcam_settings; }
QT_END_NAMESPACE

class webcam_settings : public QMainWindow
{
    Q_OBJECT

public:
    webcam_settings(QWidget *parent = nullptr);
    ~webcam_settings();

private:
    Ui::webcam_settings *ui;
};
#endif // WEBCAM_SETTINGS_H
