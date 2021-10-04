#pragma once

#include "ViewListener.hpp"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVariant>
#include <QWidget>

class View : public QWidget {
  private:
    QPushButton *submitButton = new QPushButton("Push");
    QPushButton *popButton = new QPushButton("Pop");
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(this);
    QListWidget *listView = new QListWidget();
    QLineEdit *inputField = new QLineEdit();
    ViewListener *viewListener;

  public:
    void setListener(ViewListener *viewListener) {
        this->viewListener = viewListener;
    }
    View() {
        QStringList items = QStringList();
        listView->addItems(items);
        buttonLayout->addWidget(submitButton);
        buttonLayout->addWidget(popButton);
        verticalLayout->addWidget(listView);
        verticalLayout->addWidget(inputField);
        verticalLayout->addLayout(buttonLayout);
        connect(submitButton, &QPushButton::released, [this] {
            auto item = inputField->text();
            int parsedNumber = item.toInt();
            if (parsedNumber == 0 && item != "0") {
                QMessageBox::warning(this, "Error",
                                     "Your input is not an integer number.");
            } else {
                listView->addItem(item);
                viewListener->addItem(parsedNumber);
            }
            inputField->clear();
        });

        connect(popButton, &QPushButton::released, [this] {
            if (listView->count() == 0) {
                QMessageBox::warning(this, "Error",
                                     "You haven't entered any elements yet.");
            } else {
                viewListener->removeItem(listView->currentRow());
                delete listView->currentItem();
            }
        });
        this->setWindowTitle("MVC exam");
        this->show();
    }
};