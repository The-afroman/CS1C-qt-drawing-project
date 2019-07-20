#ifndef CANVAS_H
#define CANVAS_H
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
/*
class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Polyline, Polygon, Rect, Ellipse, Text };

    RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};
*/
#endif // CANVAS_H
