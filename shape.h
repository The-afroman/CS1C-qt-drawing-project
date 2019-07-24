#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <Qt>
#include "vector.h"

const char FILE_PATH[60] = "/Users/ryota/Desktop/2dShapes/shapes.txt";

class Shape
{

public:
    enum ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

    Shape();
    //Constructor
    Shape(QPaintDevice* device);
    //Constructor

    virtual ~Shape();
    //Destructor

    /*******GETTERS*********/
    int getId() const;
    //Function to return the id of the object
    //Postcondition: Returns the id

    ShapeType getShape() const;
    //Function to return the shapeType of the object
    //Postcondition: returns a shapeType

    QRect idBox;

    const QPen& getPen() const;
    //Function to return and use the QPen pen
    //Postcondition: Returns the QPen of the object
    
    const QBrush& getBrush() const;
    //Function to return and use the QBrush brush
    //Postcondition: Returns the QBrush of the object

    /*******SETTERS*********/
    void setId(const int i);
    //Function to set a shapes id
    //Precondition: An integer value must be passed into the function
    //Postcondition: Sets id = i

    void setShape(ShapeType s);
    //Function To set the shapeType
    //Precondition: A valid ShapeType must be passed in
    //Postcondition: Sets shape = s

    void setPen(Qt::GlobalColor c, int width, Qt::PenStyle ps, Qt::PenCapStyle  pcs, Qt::PenJoinStyle pjs);
    //Function to set QPen
    //Precondition: A valid Qt::GlobalColor c, int width, Qt::PenStyle ps,
    //              Qt::PenCapStyle  pcs, Qt::PenJoinStyle pjs must be passed in
    //Postcondition: Uses values passed in for the QPen setters to set pen.

    void setBrush(Qt::GlobalColor c, Qt::BrushStyle bs);
    //Function to set the Qbrush in the class
    //Precondition: A valid Qt::GlobalColor c and Qt::BrushStyle bs must be passed in
    //Postcondition: Uses values passed in for the QBrush setters to set brush

    void defaultStyle();
    //Function that makes the qpainter's pen and brush a default Qt::SolidLine and NoBrush
    //Postcondition: pen = Qt::SolidLine,  brush = Qt::NoBrush, qpainter user setters for pen and brush

    virtual void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) = 0;
    //Pure Virtual function that will draw the shape

    virtual QPoint getPointBegin(){return QPoint(0,0);}
    virtual QPoint getPointEnd(){return QPoint(0,0);}
    virtual myVector<QPoint>& getPoints(){myVector<QPoint> vect;
                                          return vect;}
    virtual QRect getRect(){return QRect();}

protected:
    QPainter& getQpainter();

private:
    QPainter qpainter;

    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

/***********LINE CLASS************/
class Line: public Shape
{
public:
    Line() : Shape() {}
    //Constructor
    Line(QPaintDevice* device) : Shape(device) {}
    //Constructor

    ~Line() override {}
    //Destructor

    void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);
    //Function to set two points needed to draw a line
    //Precondition: Two valid QPoint objects must be passed in
    //Postcondition: Sets pointBegin = pB, pointEnd = pE

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw the line shape
    QPoint getPointBegin() override
    {
        return pointBegin;
    }
    QPoint getPointEnd() override
    {
        return pointEnd;
    }

private:
    QPoint pointBegin;
    QPoint pointEnd;
};

/***********POLYLINE CLASS************/
class Polyline: public Shape
{
public:
    Polyline() : Shape() {}
    //Constructor
    Polyline(QPaintDevice* device) : Shape(device) {}
    //Constructor

    ~Polyline() override {}
    //Destructor

    void setPoints(const QPoint& point);
    //Function that adds a point the a vector<QPoint> that is used to make a polyline
    //Precondition: A valid QPoint must be passed in
    //Postcondition: adds the QPoint to the vector

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw the polyline shape

    myVector<QPoint>& getPoints() override
    {return points;}

private:
    myVector<QPoint> points;
};

/***********POLYGON CLASS************/
class Polygon : public Shape
{
public:
    Polygon() : Shape() {}
    //Constructor
    Polygon(QPaintDevice* device) : Shape(device) {}
    //Constructor

    ~Polygon() override {}
    //Destructor

    void setPoints(const QPoint& points);
    //Function that adds a point the a vector<QPoint> that is used to make a polygon
    //Precondition: A valid QPoint must be passed in
    //Postcondition: adds the QPoint to the vector

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw the polygon

    myVector<QPoint>& getPoints() override
    {return points;}

private:
    myVector<QPoint> points;
};

/***********RECTANGLE CLASS************/
//Also related to square shape
class Rectangle : public Shape
{
public:
    Rectangle() : Shape() {}
    //Constructor
    Rectangle(QPaintDevice* device) : Shape(device) {}
    //Constructor

    ~Rectangle() override {}
    //Destructor

    bool isSquare() const;
    //Function that checks if the height and and width are the same making it a square
    //Postcondition: returns true if rect.height() is equal to rect.width()
    //               returns false if they are not equal

    void setRect(const QRect& rect);
    //Function to set rect
    //Precondition: A valid QRect object must be passed
    //Postcondition: sets rect = r

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw the rectangle or square shape

    QRect getRect() override
    {
        return rect;
    }

private:
    QRect rect;
};

/***********Ellipse CLASS************/
//Also related to circle shape
class Ellipse : public Shape
{
public:
    Ellipse() : Shape() {}
    //Constructor
    Ellipse(QPaintDevice* device) : Shape(device) {}
    //Constructor

    ~Ellipse() override {}
    //Destructor

    bool isCircle() const;
    //Function that checks if the height and and width are the same making it a circle
    //Postcondition: returns true if ellipse.height() is equal to ellipse.width()
    //               returns false if they are not equal

    void setEllipse(const QRect& e);
    //Function to set ellipse
    //Precondition: A valid QRect object must be passed
    //Postcondition: sets ellipse = e

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw an ellipse or circle shape

    QRect getRect() override
    {return ellipse;}

private:
    QRect ellipse;
};

/***********TEXT CLASS************/
class Text : public Shape
{
public:
    Text() : Shape() {}

    Text(QPaintDevice* device) :Shape(device) {}


//    Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device,id, ShapeType::Text){}
    //Constructor

    ~Text() override {}
    //Destructor

    void setText(const QRect& tO, const QString text, const QColor c, const Qt::AlignmentFlag a,
                 const int pS, const QString f, const QFont::Style s, const QFont::Weight w);
   //Function to set all data members in text class

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) override;
    //Function to draw the text

    QRect getRect() override
    {return textObj;}

private:
    QRect textObj;
    QString text;
    QColor color;
    Qt::AlignmentFlag align;
    int pointSize;
    QString family;
    QFont::Style style;
    QFont::Weight weight;
    QFont font;
};


#endif // SHAPE_H
