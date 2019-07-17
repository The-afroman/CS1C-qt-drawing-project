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



void getLine(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getPenWidth;
    std::string getPenColor, getPenStyle, 
                getPenCapStyle, getPenJoinStyle;
    Line retLine;

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
    Qt::PenStyle fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenColor.c_str()));

    metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
    Qt::PenCapStyle fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenColor.c_str()));
    
    metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
    Qt::PenJoinStyle fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenColor.c_str()));

    retLine.setPoints(p1, p2);
    retLine.setShape(Shape::ShapeType::Line);
    retLine.setId(id);
    retLine.setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);

    //return retLine;

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

}

void getPolyLine(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,
        dimension5, dimension6, dimension7, dimension8;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle;
    
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
}

void getPolygon(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4,
        dimension5, dimension6, dimension7, dimension8;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
    
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

}

void getRectangle(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
    
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
}

void getSquare(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
    
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
}

void getEllipse(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
    
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
}

void getCircle(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3;
    std::string getPenColor, getPenStyle, getPenWidth, 
                getPenCapStyle, getPenJoinStyle, getBrushColor,
                getBrushStyle;
    
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
}

void getText(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4, getTextPointSize;
    std::string getTextString, getTextColor, getTextAlignment, 
                getTextFontFamily, getTextFontStyle, getTextFontWeight;
    
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
}


void inputShape(std::string fName)
{
    std::ifstream fin;
    std::string line;
    int shapeId;
    Shape::ShapeType shape;
    std::string shapeType;

    fin.open(fName);

    fin.ignore(1000, '\n');
while(fin)
{
    getline(fin, line);
    shapeId = std::stoi(line.substr(9,1));
    getline(fin, line);
    shapeType = line.substr(11);

    /* testing */

    qDebug() << shapeId << endl;
    qDebug() << shapeType.c_str() << endl;


    shape = convStr(shapeType);

    switch(shape)
    {
        case Shape::ShapeType::NoShape: break;
        case Shape::ShapeType::Line: getLine(fin, shapeId); break;
        case Shape::ShapeType::Polyline: getPolyLine(fin, shapeId); break;
        case Shape::ShapeType::Polygon: getPolygon(fin, shapeId); break;
        case Shape::ShapeType::Rectangle: getRectangle(fin, shapeId); break;
        case Shape::ShapeType::Square: getSquare(fin, shapeId); break;
        case Shape::ShapeType::Ellipse: getEllipse(fin, shapeId); break;
        case Shape::ShapeType::Circle: getCircle(fin, shapeId); break;
        case Shape::ShapeType::Text: getText(fin, shapeId); break;
    }
}
fin.close();
}


// for testing purposes only

/* 
int main()
{
    inputShape("shapes.txt");
}
*/
