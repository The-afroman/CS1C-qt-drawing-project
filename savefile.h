#ifndef SAVEFILE_H
#define SAVEFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore>
#include "shape.h"
#include "vector.h"

using std::cout;
using std::endl;

void outFile(myVector<Shape*> shapeVect)
{
    std::ofstream oFile;
    myVector<Shape*>::iterator p;
    oFile.open("/home/f/CS1C-qt/qt-shapes-new/CS1C-qt-shapes/test.txt", std::ofstream::out | std::ofstream::trunc);
    for(p = shapeVect.begin(); p < shapeVect.end(); p++)
    {
        oFile << endl;
        switch((*p)->getShape())
        {
            case Shape::ShapeType::Line:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Line\n";
                oFile << "ShapeDimensions: " << (*p)->getPointBegin().x() << ", "
                                             << (*p)->getPointBegin().y() << ", "
                                             << (*p)->getPointEnd().x() << ", "
                                             << (*p)->getPointEnd().y()
                                             << endl;
                oFile << "PenColor: blue\n";
                oFile << "PenWidth: 2\n";
                oFile << "PenStyle: DashDotLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                break;
            case Shape::ShapeType::Polyline:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Polyline\n";
                oFile << "ShapeDimensions: " << (*p)->getPoints()[0].x() << ", "
                                             << (*p)->getPoints()[0].y() << ", "
                                             << (*p)->getPoints()[1].x() << ", "
                                             << (*p)->getPoints()[1].y() << ", "
                                             << (*p)->getPoints()[2].x() << ", "
                                             << (*p)->getPoints()[2].y() << ", "
                                             << (*p)->getPoints()[3].x() << ", "
                                             << (*p)->getPoints()[3].y()
                                             << endl;
                oFile << "PenColor: green\n";
                oFile << "PenWidth: 6\n";
                oFile << "PenStyle: SolidLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                break;
            case Shape::ShapeType::Polygon: break;
            case Shape::ShapeType::Rectangle: break;
            case Shape::ShapeType::Square: break;
            case Shape::ShapeType::Ellipse: break;
            case Shape::ShapeType::Circle: break;
            case Shape::ShapeType::Text: break;
        }
    }
    oFile.close();
    cout << "closed!!!!!!!!!!!!";
}



#endif // SAVEFILE_H
