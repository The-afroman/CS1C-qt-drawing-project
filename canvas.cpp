#include "canvas.h"
#include "shapeParser.h"
#include "savefile.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget widget;

    inputShape(shapeVect);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::updatePoints(int x, int y,
                              int x2, int y2,
                              int x3, int y3,
                              int x4, int y4,
                              int x5, int y5,
                              int x6, int y6,
                              int x7, int y7,
                              int x8, int y8)
{
    changeX = x;
    changeY = y;
    changeX2 = x2;
    changeY2 = y2;
    changeX3 = x3;
    changeY3 = y3;
    changeX4 = x4;
    changeY4 = y4;
    changeX5 = x5;
    changeY5 = y5;
    changeX6 = x6;
    changeY6 = y6;
    changeX7 = x7;
    changeY7 = y7;
    changeX8 = x8;
    changeY8 = y8;
    update();
}

void RenderArea::saveShapes()
{
    outFile(shapeVect);
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    shapeVect[0]->draw(this, changeX, changeY);

    shapeVect[1]->draw(this, changeX2, changeY2);

    shapeVect[2]->draw(this, changeX3, changeY3);

    shapeVect[3]->draw(this, changeX4, changeY4);

    shapeVect[4]->draw(this, changeX5, changeY5);

    shapeVect[5]->draw(this, changeX6, changeY6);

    shapeVect[6]->draw(this, changeX7, changeY7);

    shapeVect[7]->draw(this, changeX8, changeY8);
}
