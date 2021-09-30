#ifndef LISTCONTOLLER_H
#define LISTCONTOLLER_H
#include <QObject>
#include <QListWidget>

static const QStringList listItems =
 QStringList () << "Яша" << "Бяша" << "Няша";
 //Определили предустановленные элементы списка

class ListContoller : public QObject {
 Q_OBJECT
 QListWidget *listWidget; //Ссылка на родительский виджет
public:
 ListContoller (QListWidget *listWidget) {
  this->listWidget = listWidget;
 }
public slots:
 void onListDoubleClicked (const QModelIndex &i) {
  if (!i.isValid()) return; 
   //Нет индекса выбранного элемента -  ничего не делать
  QListWidget *w = dynamic_cast <QListWidget *>
   (sender());//Узнать, какой виджет послал сигнал          
  if (w) { //Если удалось это сделать,
   QListWidgetItem *item = w->takeItem(i.row());
    //то попытаться получить элемент
   if (item) { //Если и это удалось,
    delete item; //удалить, или Ваша обработка item
   }
  }
 }
 void onListClicked (void) {
  QString item("Hello"); listWidget->addItem(item); 
 }
};

#endif // LISTCONTOLLER_H