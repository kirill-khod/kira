#include "logo.h"
#include <QPainter>
#include <QPainterPath>

QPaintWidget::QPaintWidget(QWidget *parent) : QWidget(parent)
{

}

void QPaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::darkRed);
    painter.drawRect(100,180,200,10);
    painter.drawRect(116,175,168,5);
    painter.drawRect(116,167,168,5);
    painter.drawRect(125,75,15,88);
    painter.drawRect(158,75,15,88);
    painter.drawRect(191,75,15,88);
    painter.drawRect(225,75,15,88);
    painter.drawRect(260,75,15,88);
    painter.drawRect(116,63,168,8);
    painter.drawRect(100,52,200,8);
    QPointF *points=new QPointF[3];
    points[0]=QPointF(100,52);
    points[1]=QPointF(300,52);
    points[2]=QPointF(200,15);
    painter.drawPolygon(points,3);

    QPainter painter2(this);
    painter2.setBrush(Qt::black);
    painter2.drawRect(50,200,300,5);
    painter2.drawRect(50,240,300,5);
    painter2.drawRect(100,205,200,35);

    QPainter painter3(this);
    QRect rec=QRect(104,200,197,35);
    painter3.setPen(Qt::white);
    painter3.setFont(QFont("PHOSPHATE",37));
    painter3.drawText(rec,"UNIVERSITY");
}
