//
// Created by kaiser on 19-3-30.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_SNAKE_FOOD_H_
#define CPP_STUDY_LIBRARY_QT_GUI_SNAKE_FOOD_H_

#include <QGraphicsItem>

class Food : public QGraphicsItem {
 public:
  Food(qreal x, qreal y);

  // 返回一个包含图形元素的矩形, 也就是这个图形元素的范围
  // 这个矩形必须能够完全包含图形元素, 否则会被剪切
  // 如果范围太大会影响性能
  QRectF boundingRect() const override;
  // 使用 QPainter 将图形元素绘制出来
  // 这两个函数是必须要覆盖的, 而 shape() 不是必须的
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
             QWidget *) override;

  QPainterPath shape() const override;
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_SNAKE_FOOD_H_
