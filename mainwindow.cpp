#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    occView = new OccView(this);
    //resize(800,600);
    setCentralWidget(occView);
}

MainWindow::~MainWindow()
{
}
