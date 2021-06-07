#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include <logo.h>

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

private:
    Ui::info *ui;
    QPaintWidget *logo;

};

#endif // INFO_H
