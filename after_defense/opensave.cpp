#include "opensave.h"

opensave::opensave(QStandardItemModel *model, QWidget* w, QStringList l)
{
    pointerToModel=model;
    window=w;
    list=l;
}

void opensave::open()
{
    QString fileName = QFileDialog::getOpenFileName(window,"Open File","*.csv");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    file.readLine();
    file.readLine();

    int row=0;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QList<QByteArray> vectorLine = line.split(';');
        pointerToModel->insertRows(row, 1);
        pointerToModel->setData(pointerToModel->index(row,0), vectorLine.at(0).toInt());
        pointerToModel->setData(pointerToModel->index(row,1), QString(vectorLine.at(1)));
        pointerToModel->setData(pointerToModel->index(row,2), QString(vectorLine.at(2)));
        pointerToModel->setData(pointerToModel->index(row,3), vectorLine.at(3).toInt());
        pointerToModel->setData(pointerToModel->index(row,4), vectorLine.at(4).toInt());
        pointerToModel->setData(pointerToModel->index(row,5), vectorLine.at(5).toInt());
        pointerToModel->setData(pointerToModel->index(row,6), vectorLine.at(6).toInt());
        pointerToModel->setData(pointerToModel->index(row,7), vectorLine.at(7).toInt());
        pointerToModel->setData(pointerToModel->index(row,8), vectorLine.at(8).toInt());
        pointerToModel->setData(pointerToModel->index(row,9), vectorLine.at(9).toInt());
        pointerToModel->setData(pointerToModel->index(row,10), vectorLine.at(10).toInt());
        pointerToModel->setData(pointerToModel->index(row,11), vectorLine.at(11).toDouble());
        pointerToModel->setData(pointerToModel->index(row,12), vectorLine.at(12).toInt());
        row++;
    }
}

void opensave::save()
{
    QString fileName = QFileDialog::getSaveFileName(window,"Save File",".csv");
    QFile outFile(fileName);
    outFile.open(QIODevice::WriteOnly);
    QTextStream out(&outFile);
    for (int j=0;j<pointerToModel->columnCount();j++)
    {
        out<<list[j];
        if(j<pointerToModel->columnCount()-1)
            out<<";";
    }
    out<<"\n";
    for (int i=0;i<pointerToModel->rowCount();i++)
    {
        for(int j=0;j<pointerToModel->columnCount();j++)
        {
            QModelIndex idx=pointerToModel->index(i,j);
            out<<pointerToModel->data(idx).toString();
            if(j<pointerToModel->columnCount()-1)
                out<<";";

        }
        out<<"\n";
    }
    outFile.close();
}
