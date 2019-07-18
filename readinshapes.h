#ifndef READINSHAPES_H
#define READINSHAPES_H

#include <iostream>
#include <fstream>

using namespace std;


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
    
    
    
    /*
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
     */
    /*
     metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
     fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
     metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
     fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
     metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
     fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
     metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
     fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
     
     */
    cout << "inside shape parser" << endl;
    
    fin.open("/Users/ryota/Desktop/shapes/shapes.txt");
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
                    
                    /*
                     metaEnum = QMetaEnum::fromType<Qt::GlobalColor>();
                     fetchColorEnum = static_cast<Qt::GlobalColor>(metaEnum.keyToValue(getPenColor.c_str()));
                     metaEnum = QMetaEnum::fromType<Qt::PenStyle>();
                     fetchPenStyleEnum = static_cast<Qt::PenStyle>(metaEnum.keyToValue(getPenStyle.c_str()));
                     metaEnum = QMetaEnum::fromType<Qt::PenCapStyle>();
                     fetchPenCapStyleEnum = static_cast<Qt::PenCapStyle>(metaEnum.keyToValue(getPenCapStyle.c_str()));
                     metaEnum = QMetaEnum::fromType<Qt::PenJoinStyle>();
                     fetchPenJoinStyleEnum = static_cast<Qt::PenJoinStyle>(metaEnum.keyToValue(getPenJoinStyle.c_str()));
                     */
                    
                    p1.setX(dimension1);
                    p1.setY(dimension2);
                    p2.setX(dimension3);
                    p2.setY(dimension4);
                    
                    cout << "after setX and setY" << endl;
                    
                    
                    //linePtr->setPoints(p1, p2);
                    //linePtr->setShape(Shape::ShapeType::Line);
                    //linePtr->setId(getShapeID);
                    //linePtr->setPen(fetchColorEnum, getPenWidth, fetchPenStyleEnum, fetchPenCapStyleEnum, fetchPenJoinStyleEnum);
                    
                    pen.setColor(Qt::blue);
                    cout << "after setColor" << endl;
                    
                    cout << "before creating new LIne" << endl;
                    // linePtr = new Line;
                    cout << "After creating a new line" << endl;
                    
                    /*
                     cout << "after creating new Line" << endl;
                     linePtr->setId(getShapeID);
                     cout << "after setID" << endl;
                     
                     linePtr->setShape(Shape::ShapeType::Line);
                     cout << "after set shape" << endl;
                     
                     linePtr->setPoints(p1, p2);
                     cout << "after set Points" << endl;
                     
                     cout << "Before set pen" << endl;
                     linePtr->setPen(Qt::blue, getPenWidth, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);
                     */
                    cout << "after setPen" << endl;
                    
                    linePtr = new Line;
                    
                    
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
                    
                    polygonPtr = new Polygon;
                    
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
                    
                    
                    rectanglePtr = new Rectangle;
                    
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
                    
                    squarePtr = new Rectangle;
                    
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
                    p1.setX(dimension1);
                    p1.setY(dimension2);
                    p2.setX(dimension3);
                    p2.setY(dimension4);
                    
                    ellipsePtr = new Ellipse;
                    
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
                    
                    circlePtr = new Ellipse;
                    
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



#endif // READINSHAPES_H
