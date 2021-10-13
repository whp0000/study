#include "includes.h"

GobangWidget::GobangWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GobangWidget)
{
    ui->setupUi(this);
}

GobangWidget::~GobangWidget()
{
    delete ui;
}
