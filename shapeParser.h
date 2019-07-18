#include <iostream>
#include <fstream>
#include "shape.h"
#include <QDebug>

using std::cout;
using std::endl;

Shape::ShapeType convStr(std::string const& inString) 
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



Line* getLine(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle;
    Line* retLine = new Line;

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

    fin.ignore(1000, '\n');
    fin.ignore(1000, '\n');

    QPoint p1(dimension1, dimension2);
    QPoint p2(dimension3, dimension4);

    /* casting input strings to Qt-enums */
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

    /*  TESTING */

    qDebug() << endl;
    qDebug() << "SHAPE ID: " << id << endl;
    qDebug() << "SHAPE TYPE: " << endl;
    qDebug() << "DIMENSION1: " << dimension1 << endl;
    qDebug() << "DIMENSION2: " << dimension2 << endl;
    qDebug() << "DIMENSION3: " << dimension3 << endl;
    qDebug() << "DIMENSION4: " << dimension4 << endl;
    qDebug() << "PEN COLOR: " << getPenColor.c_str() << endl;
    qDebug() << "PEN WIDTH: " << getPenWidth << endl;
    qDebug() << "PEN STYLE: " << getPenStyle.c_str() << endl;
    qDebug() << "PEN CAP STYLE: " << getPenCapStyle.c_str() << endl;
    qDebug() << "PEN JOIN SYLE: " << getPenJoinStyle.c_str() << endl;

    return retLine;
}

Polyline* getPolyLine(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,
        dimension5, dimension6, dimension7, dimension8,
        getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle;
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

    /* casting input strings to Qt-enums */
    auto&& metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
    // following line converts string to proper enum type
    Qt::GlobalColor fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));

    polyLine->setPoints(p1);
    polyLine->setPoints(p2);
    polyLine->setPoints(p3);
    polyLine->setPoints(p4);
    polyLine->setShape(Shape::ShapeType::Polyline);
    polyLine->setId(id);
    polyLine->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);

    return polyLine;
}

Polygon* getPolygon(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,
        dimension5, dimension6, dimension7, dimension8,
        getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
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

    /* casting input strings to Qt-enums */
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

Rectangle* getRectangle(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    std::string getPenColor, getPenStyle,
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
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

    /* casting input strings to Qt-enums */
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

Rectangle* getSquare(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
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

    ;

    QRect s1(QPoint(dimension1, dimension2), QSize(dimension3, dimension3));

    /* casting input strings to Qt-enums */
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

Ellipse* getEllipse(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
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

    /* casting input strings to Qt-enums */
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

Ellipse* getCircle(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
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

    /* casting input strings to Qt-enums */
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

void getText(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getTextPointSize;
    std::string getTextString, getTextColor, getTextAlignment, 
                getTextFontFamily, getTextFontStyle, getTextFontWeight;
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

    /* casting input strings to Qt-enums */
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


vector<Shape*> inputShape(std::string fName)
{
    std::ifstream fin;
    std::string line;
    int shapeId;
    Shape::ShapeType shape;
    std::string shapeType;
    vector<Shape*> shapeVector;

    fin.open(fName);

    fin.ignore(1000, '\n');
while(fin)
{
    getline(fin, line);
    shapeId = std::stoi(line.substr(9,1));
    getline(fin, line);
    shapeType = line.substr(11);

    /* testing */

    cout << shapeId << endl;
    cout << shapeType.c_str() << endl;

    shape = convStr(shapeType);

    switch(shape)
    {
        case Shape::ShapeType::NoShape: break;
        case Shape::ShapeType::Line:
                    shapeVector.push_back(getLine(fin, shapeId)); break;
        case Shape::ShapeType::Polyline:
                    shapeVector.push_back(getPolyLine(fin, shapeId)); break;
        case Shape::ShapeType::Polygon:
                    shapeVector.push_back(getPolygon(fin, shapeId)); break;
        case Shape::ShapeType::Rectangle:
                    shapeVector.push_back(getRectangle(fin, shapeId)); break;
        case Shape::ShapeType::Square:
                    shapeVector.push_back(getSquare(fin, shapeId)); break;
        case Shape::ShapeType::Ellipse:
                    shapeVector.push_back(getEllipse(fin, shapeId)); break;
        case Shape::ShapeType::Circle:
                    shapeVector.push_back(getCircle(fin, shapeId)); break;
        case Shape::ShapeType::Text:
                    getText(fin, shapeId); break;
    }
}
fin.close();
return shapeVector;
}


// for testing purposes only

/* 
int main()
{
    inputShape("shapes.txt");
}
*/
