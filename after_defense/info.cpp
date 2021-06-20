#include "info.h"
#include "ui_info.h"
#include "QtWidgets/QHBoxLayout"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);

    logo = new QPaintWidget(this);

    ui->verticalLayout->addWidget(logo);
}

info::~info()
{
    delete ui;
}


