#include "triangle.h"

qreal glider_angle;
qreal glider_speed;

Triangle::Triangle(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    glider_angle = 0;
    setRotation(glider_angle);
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;
        polygon << QPoint(0,-20) << QPoint(10,20) << QPoint(-10,20);
        painter->setBrush(Qt::red);
        painter->drawPolygon(polygon);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Triangle::slotGameTimer() {
    setRotation(glider_angle);
    setPos(mapToParent(0, -glider_speed/10));

    /* Check output of bounds. If the subject is beyond the set boundaries, then return it back
     * */
    if(this->x() - 10 < -250){
        this->setX(-240);       // left
    }
    if(this->x() + 10 > 250){
        this->setX(240);        // right
    }

    if(this->y() - 10 < -250){
        this->setY(-240);       // top
    }
    if(this->y() + 10 > 250){
        this->setY(240);        // bottom
    }
}
