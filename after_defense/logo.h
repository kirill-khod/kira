#ifndef LOGO_H
#define LOGO_H

#include <QWidget>
#include <QPainter>

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:

    QPaintWidget(QWidget *parent = 0);

protected:

    void paintEvent(QPaintEvent *event);

};

#endif // LOGO_H
