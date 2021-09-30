#include <QApplication>
#include "listcontroller.h"
#include <QKeySequence>
#include <QShortcut>

int main(int argc, char *argv[]) {
 QApplication a(argc, argv);
 QListWidget listWidget; //будущий список
 listWidget.addItems (listItems); 
  //будущие предустановленные элементы списка
 listWidget.resize (640,480); 
 listWidget.show(); //запуск и отображение виджета
 ListContoller listController(&listWidget);
 QObject::connect(&listWidget, SIGNAL(doubleClicked(QModelIndex)),
  &listController,SLOT(onListDoubleClicked(QModelIndex)));
  //Сигнал "двойной щелчок" списка связали со слотом 
QShortcut *shortcut = new
  QShortcut(QKeySequence(Qt::Key_1),&listWidget);
  //Создали хоткей для клавиши Insert
QObject::connect(shortcut, SIGNAL(activated()),
  &listController,SLOT(onListClicked()));
  //И заставили его вызвать второй слот контроллера
 /* Здесь будет настройка сигналов виджета */
 return a.exec();
}