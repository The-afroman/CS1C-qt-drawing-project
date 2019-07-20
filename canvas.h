#ifndef CANVAS_H
#define CANVAS_H
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
};

#endif // CANVAS_H
