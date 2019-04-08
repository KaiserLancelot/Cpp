//
// Created by kaiser on 19-3-30.
//

#include "main_window.h"

#include <QTimer>

#include "consts.h"

MainWindow::MainWindow()
    : scene_{new QGraphicsScene(this)},
      view_{new QGraphicsView(scene_, this)},
      controller_{new GameController(scene_, this)} {
  setCentralWidget(view_);
  resize(2000, 2000);

  InitScene();

  // QTimer::singleShot() 的作用是将其放到事件列表中
  // 等到下一次事件循环开始指定的毫秒后去调用这个函数, 也就是绘制完成之后调用
  // 这样做是为了避免在绘制没有完成之前就调整了大小, 导致显示异常
  // 如果 override resizeEvent(), 则在调整大小之前, view 的缩放是不合适的
  // 但是每一次改变大小都会进行缩放, 而使用下面的方式不会
  QTimer::singleShot(0, this, &MainWindow::AdjustViewSize);
}

// Graphics View Framework 为每一个元素维护三个不同的坐标系:
// 场景坐标,元素自己的坐标以及其相对于父组件的坐标.
// 除了元素在场景中的位置, 其它几乎所有位置都是相对于元素坐标系
void MainWindow::InitScene() {
  scene_->setSceneRect(-100, -100, 200, 200);

  QPixmap bg{TILE_SIZE, TILE_SIZE};
  QPainter p{&bg};
  p.setBrush(Qt::gray);
  p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

  view_->setBackgroundBrush(bg);
}

void MainWindow::AdjustViewSize() {
  view_->fitInView(scene_->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
  // 缩放 view 确保 view 适合 scene
  // KeepAspectRatioByExpanding -- 通过扩展保持纵横比
  view_->fitInView(scene_->sceneRect(), Qt::KeepAspectRatioByExpanding);
  QWidget::resizeEvent(event);
}
