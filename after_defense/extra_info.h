#ifndef EXTRA_INFO_H
#define EXTRA_INFO_H

#include <QDialog>
#include "QStandardItemModel"

namespace Ui {
class extra_info;
}

class extra_info : public QDialog
{
    Q_OBJECT

public:
    explicit extra_info(QWidget *parent = nullptr);
    ~extra_info();

    void setModelPointer(QStandardItemModel* model);

    void showInfo();

private:
    Ui::extra_info *ui;
    QStandardItemModel* pointerToModel;
};


#endif // EXTRA_INFO_H
