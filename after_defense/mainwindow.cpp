#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include <info.h>
#include <extra_info.h>
#include <add.h>
#include <opensave.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuBar()->setNativeMenuBar(false);
    model = new QStandardItemModel(0, 13, parent);
    model->setColumnCount(13);
    list = {"World rank", "Name","Country","National rank","Quality of education",
            "Alumni employment","Quality of faculty","Publications","Influence","Citations","Patents","Score","Year"};
    model->setHorizontalHeaderLabels(list);
    proxyModel=new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_2_triggered()
{
    info information;
    information.setWindowTitle("About");
    information.exec();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    proxyModel->setFilterKeyColumn(ui->comboBox->currentIndex());
    proxyModel->setFilterFixedString(ui->lineEdit->text());
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox_2->currentIndex()==0)
        model->insertRow(model->rowCount());
    else
    {
        add Add;
        Add.setWindowTitle("Add row");
        Add.setModelPointer(model);
        Add.setModal(true);
        Add.exec();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    extra_info extraInfo;
    extraInfo.setWindowTitle("Extra info");
    extraInfo.setModelPointer(model);
    extraInfo.setModal(true);
    extraInfo.showInfo();
    extraInfo.exec();
}


void MainWindow::on_actionSave_triggered()
{
    opensave openSave(model,this,list);
    openSave.save();
}


void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();
    QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);
    model->removeRow(modelIndex.row());
}


void MainWindow::on_actionOpen_triggered()
{
    opensave openSave(model,this,list);
    openSave.open();
}


void MainWindow::on_actionClose_triggered()
{
    opensave openSave(model,this,list);
    openSave.save();
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    proxyModel->sort(0, Qt::AscendingOrder);
    proxyModel->sort(ui->comboBox->currentIndex(), Qt::AscendingOrder);
}
