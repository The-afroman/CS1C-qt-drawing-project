#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QBrush>
#include <QPen>

class Shape
{
public:
    enum class ShapeType { NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);

    virtual ~Shape() {}

    /*******GETTERS*********/
    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    /*******SETTERS*********/
    void setShape(ShapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);


    virtual void draw(const int translate_x, const int translate_y) = 0;
    virtual void move() = 0;



protected:
    QPainter& getQpainter();

private:
    QPainter qpainter;

    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};


class Line: public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device,id, ShapeType::Line}{}

    ~Line() override {}

    void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);

    void draw(const int translate_x, const int translate_y) = 0;


private:
    QPoint pointBegin;
    QPoint pointEnd;





};

#endif // SHAPE_H
