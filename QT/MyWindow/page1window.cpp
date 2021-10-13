#include "includes.h"
#include "page1window.h"
Page1Window::Page1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Page)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
