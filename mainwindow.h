#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* mainWidget;
    QPushButton* btnApply;
    QSlider* sliderChargeMode;

};
#endif // MAINWINDOW_H
