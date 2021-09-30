#pragma once

#include <QListWidget>
#include <QObject>
#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qabstractspinbox.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qvariant.h>
#include <QLineEdit>

class ListViewer : public QWidget {
    Q_OBJECT
  private:
    QPushButton *submitButton = new QPushButton("Push");
    QPushButton *popButton = new QPushButton("Pop");
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(this);
    QListWidget *listView = new QListWidget();
    QLineEdit *inputField = new QLineEdit();
  public:
    ListViewer(std::vector<int> rawItems) {
        QStringList items = QStringList();
        for (auto &item : rawItems) {
            items << QVariant(item).toString();
        }
        listView->addItems(items);
        buttonLayout->addWidget(submitButton);
        buttonLayout->addWidget(popButton);
        verticalLayout->addWidget(listView);
        verticalLayout->addWidget(inputField);
        verticalLayout->addLayout(buttonLayout);
        connect(submitButton, &QPushButton::released,
        [this]{
            auto item = inputField->text();
            listView->addItem(item);
            inputField->clear();
        });

        QObject::connect(listView, SIGNAL(doubleClicked(QModelIndex)), this,
                         SLOT(onListDoubleClicked(QModelIndex)));
        this->show();
    }
  public slots:
    void onListDoubleClicked(const QModelIndex &i) {
        if (!i.isValid())
            return;
        //Нет индекса выбранного элемента -  ничего не делать
        QListWidget *w = dynamic_cast<QListWidget *>(
            sender()); //Узнать, какой виджет послал сигнал
        if (w) { //Если удалось это сделать,
            QListWidgetItem *item = w->takeItem(i.row());
            //то попытаться получить элемент
            if (item) { //Если и это удалось,
                delete item; //удалить, или Ваша обработка item
            }
        }
    }

};