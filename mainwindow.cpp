#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initWindow();
    connect(btnApply, &QPushButton::clicked, this, &MainWindow::applyChanges);

    messageBox = new QMessageBox();
}

MainWindow::~MainWindow()
{
    disconnect(btnApply, &QPushButton::clicked, this, &MainWindow::applyChanges);

    delete sliderChargeMode;
    delete btnApply;
    delete mainWidget;
}

void MainWindow::applyChanges()
{
    setConservationMode(sliderChargeMode->value());
}

void MainWindow::initWindow()
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

bool MainWindow::setConservationMode(int chargeMode)
{
    fileConservation = new QFile(pathConservation);

    if (!fileConservation->exists()) {
        messageBox->setWindowTitle("Error: file not found!");
        messageBox->setText("File \"conservation_mode\" not found!");
        messageBox->show();
        return false;
    }

    if (!fileConservation->open(QFile::WriteOnly | QFile::Text)) {
        messageBox->setWindowTitle("Error: file unavailable!");
        messageBox->setText("File \"conservation_mode\" cannot be written!");
        messageBox->show();
        return false;
    }
    else {
        QTextStream stream(fileConservation);

        switch (chargeMode) {
        case 0:
            stream << QString::number(1);
            break;
        case 1:
            stream << QString::number(0);
            break;
        case 2:
            messageBox->setWindowTitle("Not implemented");
            messageBox->setText("The selected value has no effect at this time.");
            messageBox->show();
            break;
        default:
            messageBox->setWindowTitle("That's weird.");
            messageBox->setText("Strangely, you were able to choose an unusual value.\n\n"
                                "But luckily for me, there's nothing here.");
            messageBox->show();
            break;
        }
    }

    fileConservation->close();
    return true;
}

