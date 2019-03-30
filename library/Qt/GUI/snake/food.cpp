//
// Created by kaiser on 19-3-30.
//

#include "food.h"

#include <QPainter>

#include "consts.h"

Food::Food(qreal x, qreal y) {
  setPos(x, y);
  // 为该图形元素添加额外的数据信息
  setData(GD_Type, GO_Food);
}

QRectF Food::boundingRect() const {
  // 以元素为中心
  return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *) {
  painter->fillPath(shape(), Qt::red);
}

// 返回元素的实际路径(轮廓线)
QPainterPath Food::shape() const {
  QPainterPath p;
  // 添加一个椭圆(后两个参数相等为圆), 第一个参数为圆心
  p.addEllipse(QPointF(TILE_SIZE / 2.0, TILE_SIZE / 2.0), FOOD_RADIUS,
               FOOD_RADIUS);
  return p;
}
