#include "extra_info.h"
#include "ui_extra_info.h"

extra_info::extra_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::extra_info)
{
    ui->setupUi(this);
    ui->label->setText("");
}

extra_info::~extra_info()
{
    delete ui;
}

void extra_info::setModelPointer(QStandardItemModel *model)
{
    pointerToModel=model;
}

void::extra_info::showInfo()
{
    int count1=0;
    int count2=0;
    QModelIndex idx;
    ui->label->setText("Number of universities");
    ui->label_2->setText("Average number of patents");
    ui->label_5->setText("Average number of publications");
    ui->label_3->setText(QString::number(pointerToModel->rowCount()));
    for (int i=0;i<pointerToModel->rowCount();i++)
    {

            idx=pointerToModel->index(i,10);
            count1+=pointerToModel->data(idx).toInt();
            idx=pointerToModel->index(i,7);
            count2+=pointerToModel->data(idx).toInt();
    }
    count1/=pointerToModel->rowCount();
    count2/=pointerToModel->rowCount();
    ui->label_4->setText(QString::number(count1));
    ui->label_6->setText(QString::number(count2));
}
