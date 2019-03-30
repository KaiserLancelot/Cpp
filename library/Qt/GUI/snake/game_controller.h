//
// Created by kaiser on 19-3-30.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_
#define CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_

#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "food.h"

class Snake;

class GameController : public QObject {
  Q_OBJECT
 public:
  explicit GameController(QGraphicsScene *scene, QObject *parent = nullptr);

  void SnakeAteFood(Food *food);
  void SnakeAteItself();

 protected:
  bool eventFilter(QObject *object, QEvent *event) override;

 private:
  void HandleKeyPressed(QKeyEvent *event);
  void AddNewFood();

  // 由定时器实现游戏循环, 每一帧都应该调用 advance() 函数
  // 它会调用场景里每一个元素自己的 advance(), 所以图形元素
  // 想做些什么事必须覆盖该函数
  QTimer timer_;
  QGraphicsScene *scene_;
  Snake *snake_;
  bool is_pause_{false};

 private slots:
  void Pause();
  void Resume();
  void GameOver();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_
