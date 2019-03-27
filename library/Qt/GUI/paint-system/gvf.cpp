//
// Created by kaiser on 19-3-27.
//

#include <QApplication>
#include <QGraphicsView>

// Graphics View 提供了一种接口, 用于管理大量自定义的 2D 图形元素
// 并与之进行交互;还提供了用于将这些元素进行可视化显示的观察组件,
// 并支持缩放和旋转.包含了一套完整的事件体系,
// 可以用于与场景中的元素进行双精度的交互

// Graphics View 是一个基于元素的(每一个组件都是一个独立的元素) MV 架构的框架.
// 所谓模型(model)就是我们添加的种种对象;所谓视图(view)就是我们观察这些对象的视口
// 它可以分成三个部分:元素 item 场景 scene 视图 view

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  // 注意它不是 QWidget 的子类
  QGraphicsScene scene;
  scene.addLine(0, 0, 150, 150);
  // 定义 Scene 的默认大小
  scene.setSceneRect(0, 0, 300, 300);

  QGraphicsView view{&scene};
  view.setWindowTitle("Graphics View");
  // view.resize(800, 600);
  view.show();

  return QApplication::exec();
}