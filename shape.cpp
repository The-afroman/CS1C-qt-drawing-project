#include "shape.h"

/***********SHAPE CLASS************/

Shape::Shape(QPaintDevice *device, int id, ShapeType shape)
      : qpainter(device), id{id}, shape{shape}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

/********SETTERS*********/
void Shape::setId(const int i)
{
    id = i;
    return;
}

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


/**********Other***********/
void Shape::defaultStyle()
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;

    qpainter.setPen(pen);
    qpainter.setBrush(brush);
    return;
}

/********GETTERS*********/
int Shape::getId() const
{
    return id;
}

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
void Line::setPoints(const QPoint& pB, const QPoint& pE)
{
    pointBegin = pB;
    pointEnd = pE;
    return;
}

void Line::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(getPen());

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    getQpainter().drawLine(pointBegin, pointEnd);

    getQpainter().restore();

    getQpainter().end();
}

/***********POLYLINE CLASS************/
void Polyline::setPoints(const QPoint& p)
{
    points.push_back(p);
    return;
}

void Polyline::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(getPen());

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    getQpainter().drawPolyline(points.begin(), points.size());

    getQpainter().restore();

    getQpainter().end();
}

/***********POLYGON CLASS************/
void Polygon::setPoints(const QPoint &p)
{
    points.push_back(p);
    return;
}

void Polygon::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    getQpainter().drawPolygon(points.begin(), points.size());

    getQpainter().restore();

    getQpainter().end();
}

/***********RECTANGLE CLASS************/
void Rectangle::setRect(const QRect &r)
{
    rect = r;
    return;
}

bool Rectangle::isSquare() const
{
    return(rect.height() == rect.width());
}

void Rectangle::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    getQpainter().drawRect(rect);

    getQpainter().restore();

    getQpainter().end();
}

/***********ELLIPSE CLASS************/
bool Ellipse::isCircle() const
{
    return (ellipse.height() == ellipse.width());
}

void Ellipse::setEllipse(const QRect &e)
{
    ellipse = e;
}

void Ellipse::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    getQpainter().drawEllipse(ellipse);

    getQpainter().restore();

    getQpainter().end();
}

/***********TEXT CLASS************/
void Text::setText(const QRect& tO, const QString t, const QColor c, const Qt::AlignmentFlag aF,
                   const int pS, const QString f, const QFont::Style s, const QFont::Weight w)

{
    textObj = tO;
    text = t;
    color = c;
    align = aF;
    pointSize = pS;
    family = f;
    style = s;
    weight = w;

    font.setFamily(family);
    font.setStyle(style);
    font.setPointSize(pointSize);
    font.setWeight(weight);

    return;
}

void Text::draw(QPaintDevice* device, const int translate_x, const int translate_y)
{
    getQpainter().begin(device);

    getQpainter().setPen(color);
    getQpainter().setFont(font);

    getQpainter().save();
    getQpainter().translate(translate_x, translate_y);

    //Not sure what parameters to use
    getQpainter().drawText(textObj, align, text);

    getQpainter().restore();

    getQpainter().end();
}
