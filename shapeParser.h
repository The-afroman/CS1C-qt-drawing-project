#include <iostream>
#include <fstream>
//#include "shape.h"

using std::cout;
using std::endl;

enum shapes
{
   NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text
};

shapes convStr(std::string const& inString) 
{
    if(inString == "Line") return Line;
    if(inString == "Polyline") return Polyline;
    if(inString == "Polygon") return Polygon;
    if(inString == "Rectangle") return Rectangle;
    if(inString == "Square") return Square;
    if(inString == "Ellipse") return Ellipse;
    if(inString == "Circle") return Circle;
    if(inString == "Text") return Text;
    return NoShape;
}

void getLine(std::ifstream& fin, int id)
{
    int dimension1, dimension2, dimension3, dimension4;
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

    /*  TESTING
    cout << endl;
    cout << "SHAPE ID: " << id << endl;
    cout << "SHAPE TYPE: " << endl;
    cout << "DIMENSION1: " << dimension1 << endl;
    cout << "DIMENSION2: " << dimension2 << endl;
    cout << "DIMENSION3: " << dimension3 << endl;
    cout << "DIMENSION4: " << dimension4 << endl;
    cout << "PEN COLOR: " << getPenColor << endl;
    cout << "PEN WIDTH: " << getPenWidth << endl;
    cout << "PEN STYLE: " << getPenStyle << endl;
    cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
    cout << "PEN JOIN SYLE: " << getPenJoinStyle << endl;
    */
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
    shapes shape;
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
    /*
    cout << shapeId << endl;
    cout << shapeType << endl;
    */

    shape = convStr(shapeType);

    switch(shape)
    {
        case NoShape: break;
        case Line: getLine(fin, shapeId); break;
        case Polyline: getPolyLine(fin, shapeId); break;
        case Polygon: getPolygon(fin, shapeId); break;
        case Rectangle: getRectangle(fin, shapeId); break;
        case Square: getSquare(fin, shapeId); break;
        case Ellipse: getEllipse(fin, shapeId); break;
        case Circle: getCircle(fin, shapeId); break;
        case Text: getText(fin, shapeId); break;
    };
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
