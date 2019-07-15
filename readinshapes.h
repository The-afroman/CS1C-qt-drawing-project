#ifndef READINSHAPES_H
#define READINSHAPES_H

#include <iostream>
#include <fstream>

using namespace std;


void readInShapes()
{
  ifstream fin;

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
  string getPenWidth = "NOT SET";
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

  fin.open("shapes.txt");


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
          break;
      }


      if (getShapeID != 8)
      {
        cout << endl;
        cout << "SHAPE ID: " << getShapeID << endl;
        cout << "SHAPE TYPE: " << getShapeType << endl;
        cout << "DIMENSION1: " << dimension1 << endl;
        cout << "DIMENSION2: " << dimension2 << endl;
        cout << "DIMENSION3: " << dimension3 << endl;
        cout << "DIMENSION4: " << dimension4 << endl;
        cout << "DIMENSION5: " << dimension5 << endl;
        cout << "DIMENSION6: " << dimension6 << endl;
        cout << "DIMENSION7: " << dimension7 << endl;
        cout << "DIMENSION8: " << dimension8 << endl;
        cout << "PEN COLOR: " << getPenColor << endl;
        cout << "PEN WIDTH: " << getPenWidth << endl;
        cout << "PEN STYLE: " << getPenStyle << endl;
        cout << "PEN CAP STYLE: " << getPenCapStyle << endl;
        cout << "PEN JOIN SYLE: " << getPenJoinStyle << endl;
        cout << "BRUSH COLOR: " << getBrushColor << endl;
        cout << "BRUSH STYLE: " << getBrushStyle << endl;
      }

      if (getShapeID == 8)
      {
        cout << endl;
        cout << "SHAPE ID: " << getShapeID << endl;
        cout << "SHAPE TYPE: " << getShapeType << endl;
        cout << "DIMENSION1: " << dimension1 << endl;
        cout << "DIMENSION2: " << dimension2 << endl;
        cout << "DIMENSION3: " << dimension3 << endl;
        cout << "DIMENSION4: " << dimension4 << endl;
        cout << "TEXT STRING: " << getTextString << endl;
        cout << "TEXT COLOR: " << getTextColor << endl;
        cout << "TEXT ALIGNMENT: " << getTextAlignment << endl;
        cout << "TEXT POINT SIZE: " << getTextPointSize << endl;
        cout << "TEXT FONT FAMILY: " << getTextFontFamily << endl;
        cout << "TEXT FONT STYLE: " << getTextFontStyle << endl;
        cout << "TEXT FONT WEIGHT: " << getTextFontWeight << endl;
      }

      dimension1 = 0;
      dimension2 = 0;
      dimension3 = 0;
      dimension4 = 0;
      dimension5 = 0;
      dimension6 = 0;
      dimension7 = 0;
      dimension8 = 0;


    }



    counter++;
    fin >> garbage;
    fin >> getShapeID;

    fin >> garbage;
    fin >> getShapeType;

  }




  fin.close();

}


#endif // READINSHAPES_H
