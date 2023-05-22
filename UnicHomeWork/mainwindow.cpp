#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << this->menuBar()->size().width() << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

