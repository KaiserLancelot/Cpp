//
// Created by kaiser on 19-3-30.
//

#include "game_controller.h"

#include <cstdint>
#include <cstdlib>
#include <random>

#include <QMessageBox>

#include "consts.h"
#include "snake.h"

GameController::GameController(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene_(scene), snake_(new Snake(this)) {
  // 定时间隔为 1000 / 33 毫秒
  timer_.start(1000 / 33);

  scene->addItem(new Food(0, -50));
  scene->addItem(snake_);

  scene->installEventFilter(this);

  Resume();
}

void GameController::SnakeAteFood(Food *food) {
  scene_->removeItem(food);
  delete food;
  AddNewFood();
}

void GameController::HandleKeyPressed(QKeyEvent *event) {
  if (!is_pause_) {
    switch (event->key()) {
      case Qt::Key_Left:
        snake_->SetMoveDirection(Snake::Direction::MoveLeft);
        break;
      case Qt::Key_Right:
        snake_->SetMoveDirection(Snake::Direction::MoveRight);
        break;
      case Qt::Key_Up:
        snake_->SetMoveDirection(Snake::Direction::MoveUp);
        break;
      case Qt::Key_Down:
        snake_->SetMoveDirection(Snake::Direction::MoveDown);
        break;
      case Qt::Key_Space:
        Pause();
        break;
    }
  } else {
    Resume();
  }
}

void GameController::AddNewFood() {
  std::int32_t x, y;
  std::default_random_engine e{std::random_device{}()};
  std::uniform_int_distribution<std::int32_t> uid{-100, 100};

  do {
    // 需要是 TILE_SIZE 的整数倍
    x = uid(e) / TILE_SIZE * TILE_SIZE;
    y = uid(e) / TILE_SIZE * TILE_SIZE;
  } while (
      // shape() 返回的是元素坐标系的坐标, 而计算的 x, y 为场景坐标
      snake_->shape().contains(
          snake_->mapFromScene({x + TILE_SIZE / 2.0, y + TILE_SIZE / 2.0})));

  scene_->addItem(new Food(x, y));
}

void GameController::GameOver() {
  disconnect(&timer_, &QTimer::timeout, scene_, &QGraphicsScene::advance);

  if (QMessageBox::Yes ==
      QMessageBox::information(nullptr, tr("Game Over"), tr("Again?"),
                               QMessageBox::Yes | QMessageBox::No,
                               QMessageBox::Yes)) {
    connect(&timer_, &QTimer::timeout, scene_, &QGraphicsScene::advance);
    scene_->clear();

    snake_ = new Snake(this);
    scene_->addItem(snake_);
    AddNewFood();
  } else {
    std::exit(EXIT_SUCCESS);
  }
}

// 断开定时器的信号
void GameController::Pause() {
  disconnect(&timer_, &QTimer::timeout, scene_, &QGraphicsScene::advance);
  is_pause_ = true;
}

// 连接定时器的信号
// resume -- 恢复
void GameController::Resume() {
  connect(&timer_, &QTimer::timeout, scene_, &QGraphicsScene::advance);
  is_pause_ = false;
}

bool GameController::eventFilter(QObject *object, QEvent *event) {
  if (auto e{dynamic_cast<QKeyEvent *>(event)}) {
    HandleKeyPressed(e);
    return true;
  } else {
    return QObject::eventFilter(object, event);
  }
}
