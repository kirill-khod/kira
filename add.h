#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "QStandardItemModel"

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

    void setModelPointer(QStandardItemModel* model);

private slots:
    void on_pushButton_clicked();

private:
    Ui::add *ui;
    QStandardItemModel* pointerToModel;

};

#endif // ADD_H
