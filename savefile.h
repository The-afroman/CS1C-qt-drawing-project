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

void outFile(myVector<Shape*> shapeVect, int ofsetAr[][2])
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
                oFile << "ShapeDimensions: " << (*p)->getPointBegin().x()+ofsetAr[0][0] << ", "
                                             << (*p)->getPointBegin().y()+ofsetAr[0][1] << ", "
                                             << (*p)->getPointEnd().x()+ofsetAr[0][0] << ", "
                                             << (*p)->getPointEnd().y()+ofsetAr[0][1]
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
                oFile << "ShapeDimensions: " << (*p)->getPoints()[0].x()+ofsetAr[1][0] << ", "
                                             << (*p)->getPoints()[0].y()+ofsetAr[1][1] << ", "
                                             << (*p)->getPoints()[1].x()+ofsetAr[1][0] << ", "
                                             << (*p)->getPoints()[1].y()+ofsetAr[1][1] << ", "
                                             << (*p)->getPoints()[2].x()+ofsetAr[1][0] << ", "
                                             << (*p)->getPoints()[2].y()+ofsetAr[1][1] << ", "
                                             << (*p)->getPoints()[3].x()+ofsetAr[1][0] << ", "
                                             << (*p)->getPoints()[3].y()+ofsetAr[1][1]
                                             << endl;
                oFile << "PenColor: green\n";
                oFile << "PenWidth: 6\n";
                oFile << "PenStyle: SolidLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                break;
            case Shape::ShapeType::Polygon:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Polygon\n";
                oFile << "ShapeDimensions: " << (*p)->getPoints()[0].x()+ofsetAr[2][0] << ", "
                                             << (*p)->getPoints()[0].y()+ofsetAr[2][1] << ", "
                                             << (*p)->getPoints()[1].x()+ofsetAr[2][0] << ", "
                                             << (*p)->getPoints()[1].y()+ofsetAr[2][1] << ", "
                                             << (*p)->getPoints()[2].x()+ofsetAr[2][0] << ", "
                                             << (*p)->getPoints()[2].y()+ofsetAr[2][1] << ", "
                                             << (*p)->getPoints()[3].x()+ofsetAr[2][0] << ", "
                                             << (*p)->getPoints()[3].y()+ofsetAr[2][1]
                                             << endl;
                oFile << "PenColor: cyan\n";
                oFile << "PenWidth: 6\n";
                oFile << "PenStyle: DashDotDotLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                oFile << "BrushColor: yellow\n";
                oFile << "BrushStyle: SolidPattern\n";
                break;
            case Shape::ShapeType::Rectangle:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Rectangle\n";
                oFile << "ShapeDimensions: " << (*p)->getRect().topLeft().x()+ofsetAr[3][0] << ", "
                                             << (*p)->getRect().topLeft().y()+ofsetAr[3][1] << ", "
                                             << (*p)->getRect().width() << ", "
                                             << (*p)->getRect().height()
                                             << endl;
                oFile << "PenColor: blue\n";
                oFile << "PenWidth: 0\n";
                oFile << "PenStyle: DashLine\n";
                oFile << "PenCapStyle: RoundCap\n";
                oFile << "PenJoinStyle: RoundJoin\n";
                oFile << "BrushColor: red\n";
                oFile << "BrushStyle: VerPattern\n";
                break;
            case Shape::ShapeType::Square:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Square\n";
                oFile << "ShapeDimensions: " << (*p)->getRect().topLeft().x()+ofsetAr[4][0] << ", "
                                             << (*p)->getRect().topLeft().y()+ofsetAr[4][1] << ", "
                                             << (*p)->getRect().width() << ", "
                                             << endl;
                oFile << "PenColor: red\n";
                oFile << "PenWidth: 0\n";
                oFile << "PenStyle: SolidLine\n";
                oFile << "PenCapStyle: RoundCap\n";
                oFile << "PenJoinStyle: RoundJoin\n";
                oFile << "BrushColor: blue\n";
                oFile << "BrushStyle: HorPattern\n";
                break;
            case Shape::ShapeType::Ellipse:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Ellipse\n";
                oFile << "ShapeDimensions: " << (*p)->getRect().topLeft().x()+ofsetAr[5][0] << ", "
                                             << (*p)->getRect().topLeft().y()+ofsetAr[5][1] << ", "
                                             << (*p)->getRect().width() << ", "
                                             << (*p)->getRect().height()
                                             << endl;
                oFile << "PenColor: black\n";
                oFile << "PenWidth: 12\n";
                oFile << "PenStyle: SolidLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                oFile << "BrushColor: white\n";
                oFile << "BrushStyle: NoBrush\n";
                break;
            case Shape::ShapeType::Circle:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Circle\n";
                oFile << "ShapeDimensions: " << (*p)->getRect().topLeft().x()+ofsetAr[6][0] << ", "
                                             << (*p)->getRect().topLeft().y()+ofsetAr[6][1] << ", "
                                             << (*p)->getRect().width()
                                             << endl;
                oFile << "PenColor: black\n";
                oFile << "PenWidth: 12\n";
                oFile << "PenStyle: SolidLine\n";
                oFile << "PenCapStyle: FlatCap\n";
                oFile << "PenJoinStyle: MiterJoin\n";
                oFile << "BrushColor: magenta\n";
                oFile << "BrushStyle: SolidPattern\n";
                break;
            case Shape::ShapeType::Text:
                oFile << "ShapeId: " << (*p)->getId() << endl;
                oFile << "ShapeType: Text\n";
                oFile << "ShapeDimensions: " << (*p)->getRect().topLeft().x()+ofsetAr[7][0] << ", "
                                             << (*p)->getRect().topLeft().y()+ofsetAr[7][1] << ", "
                                             << (*p)->getRect().width() << ", "
                                             << (*p)->getRect().height()
                                             << endl;
                oFile << "TextString: Class Project 2 - 2D Graphics Modeler\n";
                oFile << "TextColor: blue\n";
                oFile << "TextAlignment: AlignCenter\n";
                oFile << "TextPointSize: 10\n";
                oFile << "TextFontFamily: Comic Sans MS\n";
                oFile << "TextFontStyle: FlatCap\n";
                oFile << "TextFontWeight: Normal\n";
         break;
            case Shape::ShapeType::NoShape: break;


        }
    }
    oFile.close();
    cout << "closed!!!!!!!!!!!!";
}



#endif // SAVEFILE_H
