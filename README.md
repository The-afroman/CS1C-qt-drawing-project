# **Qt-Killas README final submission**

## github repo:

**https://github.com/The-afroman/CS1C-qt-shapes**

# Basic Requirements

    in the shape.h file composition is used line #s: 87, 124, 214, 247 ,276
    in the shape.h file inheritence is used line #s: 96, 129, 219, 251
    in the shapeParser.h exception handlers are used line: 87, 100, 784
    vector class contains pointers line: 17, 35
    vector class uses templates line: 13
    overloaded [] operator used in canvas.cpp line 70-84
    overloaded = operator in vector.h line: 33
    copy constructor of vector used and tested in canvas.cpp line: 70
    mtVector iterator used savefile.h line: 16
    
# Deliverables


## 2 

    contact us is satisfied by contactwindow.h & contactwindow.cpp & contactwindow.ui

## 3

    the graphics are diplayed properly using the draw function in shape.cpp which is 
    virtual and different for each shape class lines: 102, 134, 165, 202, 235, 282

## 4

    the program reads in the shapes.txt file using inputShape function in shapeParser.h
    line: 23, properties read in according to Shape::ShapeType, line: 10-21

## 5

    shapes are moveable, only when admin is signed in, loginwindow.cpp  line: 41, 
    mainwindow.cpp line: 76, Shapes move using translate method of QPainter in 
    shape.cpp line: 112, 143, 175, 212, 245, 292

## 10

    all changes are saved and writen out to a new file using outFile function in savefile.h,
    updated coordinates are writen to file by adding translated distance in x and y to existing
    coordinates example, line: 26 translated coords passed in with saveShapes function in 
    canvas.cpp line: 44

# NOTES: 

> before running the program change the FILE_PATH global constant located in shape.h line: 13

# FOLDERS: 

- src: all project source code 
- agile: all agile related deliverables
- html: doxygen documentation files
- memoryTest: valgrind check of vector.h
- custom: all custom classes and files made by group
