#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"
#include "vector.h"
#include <QtCore>
#include <QFile>
#include <QString>
#include <QBrush>
#include <QPainter>
#include <QApplication>
#include <QPaintDevice>

using namespace std;


/*
 *
Shape::ShapeType convStr(string const& inString)
{
    if(inString == "Line") return Shape::ShapeType::Line;
    if(inString == "Polyline") return Shape::ShapeType::Polyline;
    if(inString == "Polygon") return Shape::ShapeType::Polygon;
    if(inString == "Rectangle") return Shape::ShapeType::Rectangle;
    if(inString == "Square") return Shape::ShapeType::Square;
    if(inString == "Ellipse") return Shape::ShapeType::Ellipse;
    if(inString == "Circle") return Shape::ShapeType::Circle;
    if(inString == "Text") return Shape::ShapeType::Text;
    return Shape::ShapeType::NoShape;
}



void getLineShape()
{

    cout << "inside getlineShape" << endl;

    Line* retLine = new Line;



    QPoint p1(dimension1, dimension2);
    QPoint p2(dimension3, dimension4);

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    retLine->setPoints(p1, p2);
    retLine->setShape(Shape::ShapeType::Line);
    retLine->setId(id);
    retLine->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);



}

Polyline* getPolyLine(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,dimension5, dimension6, dimension7, dimension8,getPenWidth;
    string getPenColor, getPenStyle, getPenCapStyle, getPenJoinStyle;
    Polyline* polyLine = new Polyline;
    
    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;
    fin.ignore(1000, ' ');
    fin >> dimension4;
    fin.ignore(1000, ' ');
    fin >> dimension5;
    fin.ignore(1000, ' ');
    fin >> dimension6;
    fin.ignore(1000, ' ');
    fin >> dimension7;
    fin.ignore(1000, ' ');
    fin >> dimension8;
    fin.ignore(1000, ' ');
    
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QPoint p1(dimension1, dimension2);
    QPoint p2(dimension3, dimension4);
    QPoint p3(dimension5, dimension6);
    QPoint p4(dimension7, dimension8);

    // casting input strings to Qt-enums
    //auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    //Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    //metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    //Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    //metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    //Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    //metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    //Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    polyLine->setPoints(p1);
    polyLine->setPoints(p2);
    polyLine->setPoints(p3);
    polyLine->setPoints(p4);
    polyLine->setShape(Shape::ShapeType::Polyline);
    polyLine->setId(id);
    polyLine->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);

    return polyLine;
}


Polygon* getPolygon(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,dimension5, dimension6, dimension7, dimension8,getPenWidth;
    string getPenColor, getPenStyle, getPenCapStyle, getPenJoinStyle, getBrushColor,getBrushStyle;
    Polygon* polygon = new Polygon;

    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;
    fin.ignore(1000, ' ');
    fin >> dimension4;
    fin.ignore(1000, ' ');
    fin >> dimension5;
    fin.ignore(1000, ' ');
    fin >> dimension6;
    fin.ignore(1000, ' ');
    fin >> dimension7;
    fin.ignore(1000, ' ');
    fin >> dimension8;

    fin.ignore(1000, ' ');
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, ' ');
    fin >> getBrushColor;
    
    fin.ignore(1000, ' ');
    fin >> getBrushStyle;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QPoint p1(dimension1, dimension2);
    QPoint p2(dimension3, dimension4);
    QPoint p3(dimension5, dimension6);
    QPoint p4(dimension7, dimension8);

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

    polygon->setPoints(p1);
    polygon->setPoints(p2);
    polygon->setPoints(p3);
    polygon->setPoints(p4);
    polygon->setShape(Shape::ShapeType::Polygon);
    polygon->setId(id);
    polygon->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
    polygon->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

    return polygon;
}


Rectangle* getRectangle(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    string getPenColor, getPenStyle,getPenCapStyle, getPenJoinStyle, getBrushColor,getBrushStyle;
    Rectangle* rectangle = new Rectangle;
    
    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;
    fin.ignore(1000, ' ');
    fin >> dimension4;

    fin.ignore(1000, ' ');
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, ' ');
    fin >> getBrushColor;
    
    fin.ignore(1000, ' ');
    fin >> getBrushStyle;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QRect r1(QPoint(dimension1, dimension2), QPoint(dimension3, dimension4));

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

    rectangle->setRect(r1);
    rectangle->setShape(Shape::ShapeType::Rectangle);
    rectangle->setId(id);
    rectangle->setPen(fetchColorEnum, fetchPenStyleEnum, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
    rectangle->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

    return rectangle;
}

Rectangle* getSquare(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, getPenWidth;
    string getPenColor, getPenStyle, getPenCapStyle, getPenJoinStyle, getBrushColor,getBrushStyle;
    Rectangle* square = new Rectangle;


    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;

    fin.ignore(1000, ' ');
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, ' ');
    fin >> getBrushColor;
    
    fin.ignore(1000, ' ');
    fin >> getBrushStyle;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');



    QRect s1(QPoint(dimension1, dimension2), QSize(dimension3, dimension3));

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

    square->setRect(s1);
    square->isSquare();
    square->setShape(Shape::ShapeType::Square);
    square->setId(id);
    square->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
    square->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

    return square;
}


Ellipse* getEllipse(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    string getPenColor, getPenStyle, getPenCapStyle, getPenJoinStyle, getBrushColor, getBrushStyle;
    Ellipse* ellipse = new Ellipse;
    
    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;
    fin.ignore(1000, ' ');
    fin >> dimension4;

    fin.ignore(1000, ' ');
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, ' ');
    fin >> getBrushColor;
    
    fin.ignore(1000, ' ');
    fin >> getBrushStyle;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QRect r1(QPoint(dimension1, dimension2), QPoint(dimension3, dimension4));

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

    ellipse->setEllipse(r1);
    ellipse->setShape(Shape::ShapeType::Ellipse);
    ellipse->setId(id);
    ellipse->setPen(fetchColorEnum, fetchPenStyleEnum, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
    ellipse->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

    return ellipse;
}


Ellipse* getCircle(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, getPenWidth;
    string getPenColor, getPenStyle, getPenCapStyle, getPenJoinStyle, getBrushColor,getBrushStyle;
    Ellipse* square = new Ellipse;
    
    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;

    fin.ignore(1000, ' ');
    fin >> getPenColor;

    fin.ignore(1000, ' ');
    fin >> getPenWidth;

    fin.ignore(1000, ' ');
    fin >> getPenStyle;
    
    fin.ignore(1000, ' ');
    fin >> getPenCapStyle;

    fin.ignore(1000, ' ');
    fin >> getPenJoinStyle;

    fin.ignore(1000, ' ');
    fin >> getBrushColor;
    
    fin.ignore(1000, ' ');
    fin >> getBrushStyle;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QRect r1(QPoint(dimension1, dimension2), QSize(dimension3, dimension3));

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
    Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

    square->setEllipse(r1);
    square->isCircle();
    square->setShape(Shape::ShapeType::Square);
    square->setId(id);
    square->setPen(fetchColorEnum, fetchPenStyleEnum, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
    square->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

    return square;
}

void getText(ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getTextPointSize;
    string getTextString, getTextColor, getTextAlignment, getTextFontFamily, getTextFontStyle, getTextFontWeight;
    // Text* text = new Text;
    
    fin.ignore(1000, ' ');
    fin >> dimension1;
    fin.ignore(1000, ' ');
    fin >> dimension2;
    fin.ignore(1000, ' ');
    fin >> dimension3;
    fin.ignore(1000, ' ');
    fin >> dimension4;

    fin.ignore(1000, ' ');
    fin >> getTextString;

    
    fin.ignore(1000, ' ');
    fin >> getTextColor;

    fin.ignore(1000, ' ');
    fin >> getTextAlignment;
    
    fin.ignore(1000, ' ');
    fin >> getTextPointSize;
    
    fin.ignore(1000, ' ');
    fin >> getTextFontFamily;

    fin.ignore(1000, ' ');
    fin >> getTextFontStyle;

    fin.ignore(1000, ' ');
    fin >> getTextFontWeight;
    
    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QRect r1(QPoint(dimension1, dimension2), QPoint(dimension3, dimension4));

    // casting input strings to Qt-enums
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getTextColor.c_str()));

    // metaEnum = QMetaEnum::fromType<Qt::AlignmentFlag>();
    // Qt::AlignmentFlag fetchAlignmentEnum = static_cast<Qt::AlignmentFlag>(metaEnum.keyToValue(getTextAlignment.c_str()));
    
    metaEnum = QMetaEnum::fromType<QFont::Style>();
    QFont::Style fetchFontStyleEnum = static_cast<QFont::Style>(metaEnum.keyToValue(getTextFontStyle.c_str()));

    metaEnum = QMetaEnum::fromType<QFont::Weight>();
    QFont::Weight fetchFontWeightEnum = static_cast<QFont::Weight>(metaEnum.keyToValue(getTextFontWeight.c_str()));

    // text->setText(r1, QString(getTextString.c_str()), QColor(fetchColorEnum),
    // fetchAlignmentEnum, getTextPointSize, QString(getTextFontFamily.c_str()),
    // fetchFontStyleEnum, fetchFontWeightEnum);
    // text->setShape(Shape::ShapeType::Text);
    // text->setId(id);

    //return text;
}

*/





void inputShape(myVector<Shape*>& shapeVector)
{
    ifstream fin;
    //string line;
    //int shapeId;
    //Shape::ShapeType shape;
    //string shapeType;


      Line *linePtr = nullptr;
      Polyline *polylinePtr = nullptr;
      Polygon *polygonPtr = nullptr;
      Rectangle *rectanglePtr = nullptr;
      Rectangle *squarePtr = nullptr;
      Ellipse *ellipsePtr = nullptr;
      Ellipse *circlePtr = nullptr;
      Text *textPtr = nullptr;





      int getShapeID = 0;
      string getShapeType = "NOT SET";
      int dimension1 = 0;
      int dimension2 = 0;
      int dimension3 = 0;
      int dimension4 = 0;
      int dimension5 = 0;
      int dimension6 = 0;
      int dimension7 = 0;
      int dimension8 = 0;
      string getPenColor = "NOT SET";
      int getPenWidth = 0;
      string getPenStyle = "NOT SET";
      string getPenCapStyle = "NOT SET";
      string getPenJoinStyle = "NOT SET";
      string getBrushColor = "NOT SET";
      string getBrushStyle = "NOT SET";
      string getTextString = "NOT SET";
      string getTextColor = "NOT SET";
      string getTextAlignment = "NOT SET";
      int getTextPointSize = 0;
      string getTextFontFamily = "NOT SET";
      string getTextFontStyle = "NOT SET";
      string getTextFontWeight = "NOT SET";

      string garbage;
      int counter = 0;

      QPoint p1;
      QPoint p2;
      QPoint p3;
      QPoint p4;
      QPen pen;
      QBrush brush;
      QPainter rectanglePainter;
      QRect tempRectangle;
      QRect tempSquare;
      QRect tempEllipse;
      QRect tempCircle;


      // casting input strings to Qt-enums
      auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
      // following line converts string to proper enum type
      Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
      Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
      Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
      Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
      Qt::GlobalColor fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
      Qt::BrushStyle fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

      //metaEnum = QMetaEnum::fromType<Qt::AlignmentFlag>();
      //Qt::AlignmentFlag fetchAlignmentEnum = static_cast<Qt::AlignmentFlag>(metaEnum.keyToValue(getTextAlignment.c_str()));

      metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
      fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getTextColor.c_str()));

      metaEnum = QMetaEnum::fromType<QFont::Style>();
      QFont::Style fetchFontStyleEnum = static_cast<QFont::Style>(metaEnum.keyToValue(getTextFontStyle.c_str()));

      metaEnum = QMetaEnum::fromType<QFont::Weight>();
      QFont::Weight fetchFontWeightEnum = static_cast<QFont::Weight>(metaEnum.keyToValue(getTextFontWeight.c_str()));


    cout << "inside shape parser" << endl;

    fin.open("/home/f/CS1C-qt/qt-shapes-new/CS1C-qt-shapes/shapes.txt");
    if (fin)
    {
        cout << "file opened" << endl;
    }
    else
    {
        cout << "file was not opened" << endl;
    }

    fin >> garbage;
      fin >> getShapeID;

      fin >> garbage;
      fin >> getShapeType;


      while (!fin.eof())
      {


        if (fin)
        {
          switch (getShapeID)
          {
            case 1:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              //cout << "finished fin " << endl;
              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "DIMENSION4: " << dimension4 << endl;
              cout << endl;


              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));


              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);


              linePtr = new Line;
              linePtr->setPoints(p1, p2);
              linePtr->setShape(Shape::ShapeType::Line);
              linePtr->setId(getShapeID);
              linePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);

              shapeVector.push_back(linePtr);




              break;


            case 2:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;
              fin.ignore(1);
              fin >> dimension5;
              fin.ignore(1);
              fin >> dimension6;
              fin.ignore(1);
              fin >> dimension7;
              fin.ignore(1);
              fin >> dimension8;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "DIMENSION4: " << dimension4 << endl;
              cout << "DIMENSION5: " << dimension5 << endl;
              cout << "DIMENSION6: " << dimension6 << endl;
              cout << "DIMENSION7: " << dimension7 << endl;
              cout << "DIMENSION8: " << dimension8 << endl;
              cout << endl;

              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);
              p3.setX(dimension5);
              p3.setY(dimension6);
              p4.setX(dimension7);
              p4.setY(dimension8);

              polylinePtr = new Polyline;

              polylinePtr->setPoints(p1);
              polylinePtr->setPoints(p2);
              polylinePtr->setPoints(p3);
              polylinePtr->setPoints(p4);
              polylinePtr->setShape(Shape::ShapeType::Polyline);
              polylinePtr->setId(getShapeID);
              polylinePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);


              shapeVector.push_back(polylinePtr);
              break;

            case 3:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;
              fin.ignore(1);
              fin >> dimension5;
              fin.ignore(1);
              fin >> dimension6;
              fin.ignore(1);
              fin >> dimension7;
              fin.ignore(1);
              fin >> dimension8;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              fin >> garbage;
              fin >> getBrushColor;

              fin >> garbage;
              fin >> getBrushStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "DIMENSION4: " << dimension4 << endl;
              cout << "DIMENSION5: " << dimension5 << endl;
              cout << "DIMENSION6: " << dimension6 << endl;
              cout << "DIMENSION7: " << dimension7 << endl;
              cout << "DIMENSION8: " << dimension8 << endl;
              cout << "BRUSH COLOR: " << getBrushColor << endl;
              cout << "BRUSH STYLE: " << getBrushStyle << endl;
              cout << endl;
              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);
              p3.setX(dimension5);
              p3.setY(dimension6);
              p4.setX(dimension7);
              p4.setY(dimension8);

              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
              fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));


              polygonPtr = new Polygon;


              polygonPtr->setPoints(p1);
              polygonPtr->setPoints(p2);
              polygonPtr->setPoints(p3);
              polygonPtr->setPoints(p4);

              polygonPtr->setShape(Shape::ShapeType::Polygon);

              polygonPtr->setId(getShapeID);

              polygonPtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);

              polygonPtr->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

              shapeVector.push_back(polygonPtr);

              break;

            case 4:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              fin >> garbage;
              fin >> getBrushColor;

              fin >> garbage;
              fin >> getBrushStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "DIMENSION4: " << dimension4 << endl;
              cout << "BRUSH COLOR: " << getBrushColor << endl;
              cout << "BRUSH STYLE: " << getBrushStyle << endl;
              cout << endl;

              p1.setX(dimension1);
              p1.setY(dimension2);

              p2.setX(dimension3);
              p2.setY(dimension4);


              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
              fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));


              rectanglePtr = new Rectangle;
              tempRectangle.setTopLeft(p1);
              tempRectangle.setWidth(dimension4);
              tempRectangle.setHeight(dimension3);
              rectanglePtr->setRect(tempRectangle);




              rectanglePtr->setShape(Shape::ShapeType::Rectangle);
              rectanglePtr->setId(getShapeID);
              rectanglePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
              rectanglePtr->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

              shapeVector.push_back(rectanglePtr);

              break;

            case 5:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              fin >> garbage;
              fin >> getBrushColor;

              fin >> garbage;
              fin >> getBrushStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "BRUSH COLOR: " << getBrushColor << endl;
              cout << "BRUSH STYLE: " << getBrushStyle << endl;
              cout << endl;


              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
              fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));


              p1.setX(dimension1);
              p1.setY(dimension2);



              squarePtr = new Rectangle;


              tempSquare.setTopLeft(p1);
              tempSquare.setHeight(dimension3);
              squarePtr->setRect(tempSquare);

              squarePtr->setShape(Shape::ShapeType::Rectangle);
              squarePtr->setId(getShapeID);
              squarePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
              squarePtr->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);


              shapeVector.push_back(squarePtr);
              break;

            case 6:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              fin >> garbage;
              fin >> getBrushColor;

              fin >> garbage;
              fin >> getBrushStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "DIMENSION4: " << dimension4 << endl;
              cout << "BRUSH COLOR: " << getBrushColor << endl;
              cout << "BRUSH STYLE: " << getBrushStyle << endl;
              cout << endl;

              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
              fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);

              ellipsePtr = new Ellipse;

              tempEllipse.setTopLeft(p1);
              tempEllipse.setWidth(dimension3);
              tempEllipse.setHeight(dimension4);


              ellipsePtr->setEllipse(tempEllipse);

              ellipsePtr->setShape(Shape::ShapeType::Ellipse);
              ellipsePtr->setId(getShapeID);
              ellipsePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
              ellipsePtr->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

              shapeVector.push_back(ellipsePtr);

              break;

            case 7:


              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;

              fin >> garbage;
              fin >> getPenColor;

              fin >> garbage;
              fin >> getPenWidth;

              fin >> garbage;
              fin >> getPenStyle;

              fin >> garbage;
              fin >> getPenCapStyle;

              fin >> garbage;
              fin >> getPenJoinStyle;

              fin >> garbage;
              fin >> getBrushColor;

              fin >> garbage;
              fin >> getBrushStyle;

              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "PEN JOIN STYLE" << getPenJoinStyle << endl;
              cout << "DIMENSION1: " << dimension1 << endl;
              cout << "DIMENSION2: " << dimension2 << endl;
              cout << "DIMENSION3: " << dimension3 << endl;
              cout << "BRUSH COLOR: " << getBrushColor << endl;
              cout << "BRUSH STYLE: " << getBrushStyle << endl;
              cout << endl;

              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
              fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
              fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
              fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchBrushColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getBrushColor.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::BrushStyle>();
              fetchBrushStyleEnum = static_cast<Qt::BrushStyle>(metaEnum.keyToValue(getBrushStyle.c_str()));

              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);


              circlePtr = new Ellipse;


              tempCircle.setTopLeft(p1);
              tempCircle.setWidth(dimension3);
              tempCircle.setHeight(dimension4);
              circlePtr->setEllipse(tempCircle);

              circlePtr->setShape(Shape::ShapeType::Circle);
              circlePtr->setId(getShapeID);
              circlePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
              circlePtr->setBrush(fetchBrushColorEnum, fetchBrushStyleEnum);

              shapeVector.push_back(circlePtr);

              break;

            case 8:
              fin >> garbage;
              fin >> dimension1;
              fin.ignore(1);
              fin >> dimension2;
              fin.ignore(1);
              fin >> dimension3;
              fin.ignore(1);
              fin >> dimension4;


              fin >> garbage;
              fin.ignore();
              getline(fin, getTextString, '\n');

              fin >> garbage;
              fin >> getTextColor;

              fin >> garbage;
              fin >> getTextAlignment;

              fin >> garbage;
              fin >> getTextPointSize;

              fin >> garbage;
              fin.ignore();
              getline(fin, getTextFontFamily, '\n');

              fin >> garbage;
              fin >> getTextFontStyle;

              fin >> garbage;
              fin >> getTextFontWeight;


              cout << endl;
              cout << "SHAPE ID: " << getShapeID << endl;
              cout << "SHAPE TYPE: " << getShapeType << endl;
              cout << "PEN COLOR: " << getPenColor << endl;
              cout << "PEN WIDTH: " << getPenWidth << endl;
              cout << "PEN STYLE: " << getPenStyle << endl;
              cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
              cout << "TEXT STRING: " << getTextString << endl;
              cout << "TEXT COLOR: " << getTextColor << endl;
              cout << "TEXT ALIGNMENT: " << getTextAlignment << endl;
              cout << "TEXT POINT SIZE: " << getTextAlignment << endl;
              cout << "TEXT FONT FAMILY: " << getTextFontFamily << endl;
              cout << "TEXT FONT STYLE: " << getTextFontStyle << endl;
              cout << "TEXT FONT WEIGHT: " << getTextFontWeight << endl;
              cout << endl;
              p1.setX(dimension1);
              p1.setY(dimension2);
              p2.setX(dimension3);
              p2.setY(dimension4);

              //metaEnum = QMetaEnum::fromType<Qt::AlignmentFlag>();
              //fetchAlignmentEnum = static_cast<Qt::AlignmentFlag>(metaEnum.keyToValue(getTextAlignment.c_str()));
              metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
              fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getTextColor.c_str()));
              metaEnum = QMetaEnum::fromType<QFont::Style>();
              fetchFontStyleEnum = static_cast<QFont::Style>(metaEnum.keyToValue(getTextFontStyle.c_str()));
              metaEnum = QMetaEnum::fromType<QFont::Weight>();
              fetchFontWeightEnum = static_cast<QFont::Weight>(metaEnum.keyToValue(getTextFontWeight.c_str()));


              textPtr = new Text;
              shapeVector.push_back(textPtr);
              break;

          }


          dimension1 = 0;
          dimension2 = 0;
          dimension3 = 0;
          dimension4 = 0;
          dimension5 = 0;
          dimension6 = 0;
          dimension7 = 0;
          dimension8 = 0;


        } // end if (fin)



        counter++;
        cout << "Counter - how many shapes read in: " << counter << endl << endl << endl;
        fin >> garbage;
        fin >> getShapeID;

        fin >> garbage;
        fin >> getShapeType;

      }  // end while loop








    //**********************************************************************************

    fin.close();

}
