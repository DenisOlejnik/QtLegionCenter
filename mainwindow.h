#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QFile>
#include <QTextStream>

#include <QMessageBox>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void applyChanges();

private:
    void initWindow();
    bool setConservationMode(int chargeMode);

private:
    QWidget* mainWidget;
    QPushButton* btnApply;
    QSlider* sliderChargeMode;

    QFile* fileConservation;
    QMessageBox* messageBox;

    QString pathConservation = "/sys/bus/platform/drivers/ideapad_acpi/VPC2004:00/conservation_mode";
};
#endif // MAINWINDOW_H
