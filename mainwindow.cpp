#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    QVBoxLayout* vMainLayout = new QVBoxLayout(mainWidget);
    QFormLayout* formLayout = new QFormLayout();

    // Charging control slider
    sliderChargeMode = new QSlider(Qt::Horizontal);
    sliderChargeMode->setRange(0, 2);
    sliderChargeMode->setTickInterval(1);
    sliderChargeMode->setSingleStep(1);
    sliderChargeMode->setPageStep(1);
    sliderChargeMode->setTickPosition(QSlider::TicksBelow);

    // Labels for tick on the slider
    QGridLayout* gridSliderLayout = new QGridLayout();
    QLabel* labelConservation = new QLabel("Conservation");
    QLabel* labelCharge = new QLabel("Default");
    QLabel* labelRapidCharge = new QLabel("Rapid");

    gridSliderLayout->addWidget(sliderChargeMode, 0, 0, 1, 3);
    gridSliderLayout->addWidget(labelConservation, 1, 0, Qt::AlignLeft);
    gridSliderLayout->addWidget(labelCharge, 1, 1, Qt::AlignCenter);
    gridSliderLayout->addWidget(labelRapidCharge, 1, 2, Qt::AlignRight);

    formLayout->addRow("Charge mode:", gridSliderLayout);
    vMainLayout->addLayout(formLayout);
    btnApply = new QPushButton("Apply");
    vMainLayout->addWidget(btnApply);
    mainWidget->setLayout(vMainLayout);
}

MainWindow::~MainWindow()
{
}

