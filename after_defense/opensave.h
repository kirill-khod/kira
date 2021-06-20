#ifndef OPENSAVE_H
#define OPENSAVE_H

#include "QStandardItemModel"
#include "QFileDialog"

class opensave
{
public:
    opensave(QStandardItemModel* model, QWidget* w, QStringList l);

    void open();

    void save();

private:
    QStandardItemModel* pointerToModel;
    QWidget* window;
    QStringList list;
};

#endif // OPENSAVE_H
