#pragma once

#include "ViewListener.hpp"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVariant>
#include <QWidget>
#include <cstdlib>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qvariant.h>
#include <qwidget.h>
#include <string>

class View : public QWidget {
  private:
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    QPushButton *submitButton = new QPushButton("Push");
    QPushButton *popButton = new QPushButton("Pop");
    QWidget *buttons = new QWidget(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttons);

    QListWidget *listView = new QListWidget();

    QWidget *input = new QWidget(this);
    QHBoxLayout *inputLayout = new QHBoxLayout(input);
    QLabel *inputLabel = new QLabel("Input an element");
    QLineEdit *inputField = new QLineEdit();

    QWidget *controlButtons = new QWidget(this);
    QHBoxLayout *controlButtonsLayout = new QHBoxLayout(controlButtons);
    QPushButton *exitButton = new QPushButton("Exit");
    QPushButton *actionButton = new QPushButton("Visit");

    ViewListener *viewListener;

  public:
    void setListener(ViewListener *viewListener) {
        this->viewListener = viewListener;
    }
    View() {
        buttonLayout->addWidget(submitButton);
        buttonLayout->addWidget(popButton);

        inputLayout->addWidget(inputLabel);
        inputLayout->addWidget(inputField);

        controlButtonsLayout->addWidget(actionButton);
        controlButtonsLayout->addWidget(exitButton);

        verticalLayout->addWidget(listView);
        verticalLayout->addWidget(input);
        verticalLayout->addWidget(buttons);
        verticalLayout->addWidget(controlButtons);

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

        connect(exitButton, &QPushButton::released, [this] { exit(0); });
        connect(actionButton, &QPushButton::released, [this] {
            if (listView->count() == 0) {
                QMessageBox::warning(this, "Error",
                                     "You haven't entered any elements yet.");
            } else {
            }
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