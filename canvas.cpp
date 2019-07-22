#include "canvas.h"
#include "shape.h"
#include "shapeParser.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget widget;


    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    myVector<Shape*> shapeVect;
    myVector<Shape*>::iterator p;
    inputShape(shapeVect);
    for (p = shapeVect.begin(); p < shapeVect.end(); p++)
    {
        (*p)->draw(this);
    }
}
