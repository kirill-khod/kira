#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include <info.h>
#include <extra_info.h>
#include <add.h>

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
//    model->setHorizontalHeaderLabels(QStringList() << "World rank" << "Name" << "Country" << "National rank" << "Quality of education"
//<< "Alumni employment" << "Quality of faculty" << "Publications" << "Influence" << "Citations" << "Patents" << "Score" << "Year");
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
    QString fileName = QFileDialog::getSaveFileName(this,"Save File",".csv");
    QFile outFile(fileName);
    outFile.open(QIODevice::WriteOnly);
    QTextStream out(&outFile);
    for (int j=0;j<model->columnCount();j++)
    {
        out<<list[j];
        if(j<model->columnCount()-1)
            out<<";";
    }
    out<<"\n";
    for (int i=0;i<model->rowCount();i++)
    {
        for(int j=0;j<model->columnCount();j++)
        {
            QModelIndex idx=model->index(i,j);
            out<<model->data(idx).toString();
            if(j<model->columnCount()-1)
                out<<";";

        }
        out<<"\n";
    }
    outFile.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();
    QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);
    model->removeRow(modelIndex.row());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open File","*.csv");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    file.readLine();
    file.readLine();

    int row=0;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QList<QByteArray> vectorLine = line.split(';');
        model->insertRows(row, 1);
        model->setData(model->index(row,0), vectorLine.at(0).toInt());
        model->setData(model->index(row,1), QString(vectorLine.at(1)));
        model->setData(model->index(row,2), QString(vectorLine.at(2)));
        model->setData(model->index(row,3), vectorLine.at(3).toInt());
        model->setData(model->index(row,4), vectorLine.at(4).toInt());
        model->setData(model->index(row,5), vectorLine.at(5).toInt());
        model->setData(model->index(row,6), vectorLine.at(6).toInt());
        model->setData(model->index(row,7), vectorLine.at(7).toInt());
        model->setData(model->index(row,8), vectorLine.at(8).toInt());
        model->setData(model->index(row,9), vectorLine.at(9).toInt());
        model->setData(model->index(row,10), vectorLine.at(10).toInt());
        model->setData(model->index(row,11), vectorLine.at(11).toDouble());
        model->setData(model->index(row,12), vectorLine.at(12).toInt());
        row++;
    }
}


void MainWindow::on_actionClose_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save File",".csv");
    QFile outFile(fileName);
    outFile.open(QIODevice::WriteOnly);
    QTextStream out(&outFile);
    for (int j=0;j<model->columnCount();j++)
    {
        out<<list[j];
        if(j<model->columnCount()-1)
            out<<";";
    }
    out<<"\n";
    for (int i=0;i<model->rowCount();i++)
    {
        for(int j=0;j<model->columnCount();j++)
        {
            QModelIndex idx=model->index(i,j);
            out<<model->data(idx).toString();
            if(j<model->columnCount()-1)
                out<<";";

        }
        out<<"\n";
    }
    outFile.close();
    this->close();
}

