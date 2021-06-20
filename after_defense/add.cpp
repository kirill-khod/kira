#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::setModelPointer(QStandardItemModel *model)
{
    pointerToModel=model;
}

void add::on_pushButton_clicked()
{
    int row = pointerToModel->rowCount();
    pointerToModel->insertRows(row,1);

    pointerToModel->setData(pointerToModel->index(row,0,QModelIndex()),ui->lineEdit->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,1,QModelIndex()),QString(ui->lineEdit_2->text()));
    pointerToModel->setData(pointerToModel->index(row,2,QModelIndex()),QString(ui->lineEdit_3->text()));
    pointerToModel->setData(pointerToModel->index(row,3,QModelIndex()),ui->lineEdit_4->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,4,QModelIndex()),ui->lineEdit_5->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,5,QModelIndex()),ui->lineEdit_6->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,6,QModelIndex()),ui->lineEdit_7->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,7,QModelIndex()),ui->lineEdit_8->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,8,QModelIndex()),ui->lineEdit_9->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,9,QModelIndex()),ui->lineEdit_10->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,10,QModelIndex()),ui->lineEdit_11->text().toInt());
    pointerToModel->setData(pointerToModel->index(row,11,QModelIndex()),ui->lineEdit_12->text().toDouble());
    pointerToModel->setData(pointerToModel->index(row,12,QModelIndex()),ui->lineEdit_13->text().toInt());

}

