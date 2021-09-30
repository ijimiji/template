#pragma once

#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <qabstractitemmodel.h>
#include <qabstractspinbox.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qvariant.h>

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
        connect(submitButton, &QPushButton::released, [this] {
            auto item = inputField->text();
            listView->addItem(item);
            inputField->clear();
        });

        connect(popButton, &QPushButton::released,
                [this] { delete listView->currentItem(); });
        this->show();
    }
};