//
// Created by kaiser on 19-3-30.
//

#include "snake.h"

#include <QPainter>
#include <QTimer>

#include "consts.h"

QRectF Snake::boundingRect() const {
  auto min_x{head_.x()};
  auto min_y{head_.y()};
  auto max_x{head_.x()};
  auto max_y{head_.y()};

  for (const auto &p : tail_) {
    max_x = p.x() > max_x ? p.x() : max_x;
    max_y = p.y() > max_y ? p.y() : max_y;
    min_x = p.x() < min_x ? p.x() : min_x;
    min_y = p.y() < min_y ? p.y() : min_y;
  }

  // 从场景坐标转换为元素的坐标
  auto tl{mapFromScene({min_x, min_y})};
  auto br{mapFromScene({max_x, max_y})};

  return {tl.x(), tl.y(), br.x() - tl.x() + SNAKE_SIZE,
          br.y() - tl.y() + SNAKE_SIZE};
}

QPainterPath Snake::shape() const {
  QPainterPath path;

  path.addRect(0, 0, SNAKE_SIZE, SNAKE_SIZE);

  for (const auto &p : tail_) {
    auto item{mapFromScene(p)};
    path.addRect(item.x(), item.y(), SNAKE_SIZE, SNAKE_SIZE);
  }

  return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                  QWidget *) {
  painter->fillPath(shape(), Qt::yellow);
}

void Snake::SetMoveDirection(Direction direction) {
  if (move_direction_ == Direction::MoveLeft &&
      direction == Direction::MoveRight)
    return;
  if (move_direction_ == Direction::MoveRight &&
      direction == Direction::MoveLeft)
    return;
  if (move_direction_ == Direction::MoveUp && direction == Direction::MoveDown)
    return;
  if (move_direction_ == Direction::MoveDown && direction == Direction::MoveUp)
    return;
  move_direction_ = direction;
}

// 该函数 1 秒会调用 30 次, 这是在 GameController 的定时器中决定的
// 该函数会被 QGraphicsScene::advance() 函数调用两次, 第一次时这个 int 为
// 0, 代表即将开始调用;第二次这个 int 为 1, 代表已经开始调用
// 只使用不为 0 的阶段, 因此当 step 为 0 时, 函数直接返回
void Snake::advance(int step) {
  if (!step) {
    return;
  }

  // 使用 speed_ 作为蛇两次动作的间隔事件
  if (tick_counter_++ % speed_ != 0) {
    return;
  }
  if (move_direction_ == Direction::NoMove) {
    return;
  }

  // growing 为正在增长的方格数
  if (growing_ > 0) {
    tail_ << head_;
    growing_ -= 1;
  } else {
    tail_.removeFirst();
    tail_ << head_;
  }

  switch (move_direction_) {
    case Direction::MoveLeft:
      MoveLeft();
      break;
    case Direction::MoveRight:
      MoveRight();
      break;
    case Direction::MoveUp:
      MoveUp();
      break;
    case Direction::MoveDown:
      MoveDown();
      break;
    default:;
  }

  setPos(head_);
  HandleCollisions();
}

void Snake::MoveLeft() {
  head_.rx() -= SNAKE_SIZE;
  if (head_.rx() < -100) {
    QTimer::singleShot(0, controller_, &GameController::GameOver);
  }
}

void Snake::MoveRight() {
  head_.rx() += SNAKE_SIZE;
  if (head_.rx() >= 100) {
    QTimer::singleShot(0, controller_, &GameController::GameOver);
  }
}

void Snake::MoveUp() {
  head_.ry() -= SNAKE_SIZE;
  if (head_.ry() < -100) {
    QTimer::singleShot(0, controller_, &GameController::GameOver);
  }
}

void Snake::MoveDown() {
  head_.ry() += SNAKE_SIZE;
  if (head_.ry() >= 100) {
    QTimer::singleShot(0, controller_, &GameController::GameOver);
  }
}

// 碰撞处理
void Snake::HandleCollisions() {
  // 返回与这个元素碰撞的所有元素
  // 默认情况是如果被检测物的形状与检测物有交集算做碰撞
  for (auto collidingItem : collidingItems()) {
    if (collidingItem->data(GD_Type) == GO_Food) {
      controller_->SnakeAteFood(dynamic_cast<Food *>(collidingItem));
      growing_ += 1;
    }
  }

  if (tail_.contains(head_)) {
    QTimer::singleShot(0, controller_, &GameController::GameOver);
  }
}
