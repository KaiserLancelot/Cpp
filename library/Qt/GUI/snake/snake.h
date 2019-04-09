//
// Created by kaiser on 19-3-30.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_SNAKE_SNAKE_H_
#define CPP_STUDY_LIBRARY_QT_GUI_SNAKE_SNAKE_H_

#include <cstdint>

#include <QGraphicsItem>
#include <QRectF>

#include "game_controller.h"

class Snake : public QGraphicsItem {
 public:
  enum class Direction { NoMove, MoveLeft, MoveRight, MoveUp, MoveDown };

  explicit Snake(GameController *controller) : controller_(controller) {}

  QRectF boundingRect() const override;
  QPainterPath shape() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
             QWidget *) override;

  void SetMoveDirection(Direction direction);

 protected:
  void advance(int step) override;

 private:
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();

  void HandleCollisions();

  QPointF head_{0, 0};
  std::int32_t growing_{7};
  // 数字越大越慢
  std::int32_t speed_{7};
  QList<QPointF> tail_;
  std::int32_t tick_counter_{};
  Direction move_direction_{Direction::NoMove};
  GameController *controller_;
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_SNAKE_SNAKE_H_
