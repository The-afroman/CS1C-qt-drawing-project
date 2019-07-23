#ifndef CANVAS_H
#define CANVAS_H
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "vector.h"
#include "shape.h"

class RenderArea : public QWidget
{
    Q_OBJECT

    myVector<Shape*> shapeVect;
    int changeX=0;
    int changeY=0;
    int changeX2=0;
    int changeY2=0;
    int changeX3=0;
    int changeY3=0;
    int changeX4=0;
    int changeY4=0;
    int changeX5=0;
    int changeY5=0;
    int changeX6=0;
    int changeY6=0;
    int changeX7=0;
    int changeY7=0;
    int changeX8=0;
    int changeY8=0;
    int shapeId;
public:
    void saveShapes();

    RenderArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void updatePoints(int x, int y,
                      int x2, int y2,
                      int x3, int y3,
                      int x4, int y4,
                      int x5, int y5,
                      int x6, int y6,
                      int x7, int y7,
                      int x8, int y8);
};

#endif // CANVAS_H
