#include "shape.h"

/***********SHAPE CLASS************/

Shape::Shape(QPaintDevice *device, int id, ShapeType shape)
      : qpainter(device), id{id}, shape{shape}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

/********SETTERS*********/
void Shape::setShape(ShapeType s)
{
    shape = s;
    return;
}

void Shape::setPen(Qt::GlobalColor c, int width, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs)
{
    pen.setColor(c);
    pen.setWidth(width);
    pen.setStyle(ps);
    pen.setCapStyle(pcs);
    pen.setJoinStyle(pjs);
    return;
}

void Shape::setBrush(Qt::GlobalColor c, Qt::BrushStyle bs)
{
    brush.setColor(c);
    brush.setStyle(bs);
    return;
}

/********GETTERS*********/
Shape::ShapeType Shape::getShape() const
{
    return shape;
}

const QPen& Shape::getPen() const
{
    return pen;
}

const QBrush& Shape::getBrush() const
{
    return brush;
}

QPainter& Shape::getQpainter()
{
    return qpainter;
}


/***********LINE CLASS************/




