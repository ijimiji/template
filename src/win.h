#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
using namespace std;

class MyWindow : public QWidget {
    Q_OBJECT
  public slots:
    void foo(string name) { cout << "Pressed " << name << endl; }

  public:
    MyWindow() {
        auto a = new QPushButton("Нажми на меня");
        auto b = new QPushButton("B");
        auto c = new QPushButton("C");
        auto aLabel = new QLabel();
        auto bLabel = new QLabel();
        auto cLabel = new QLabel();
        aLabel->setNum(1);
        bLabel->setNum(1);
        cLabel->setNum(1);
        connect(a, &QPushButton::released,
                [this, aLabel] { aLabel->setNum(aLabel->text().toInt() + 1); });
        connect(b, &QPushButton::released, [this] { foo("B"); });
        connect(c, &QPushButton::released, [this] { foo("C"); });
        auto v = new QVBoxLayout();
        auto buttonLayout = new QHBoxLayout();
        auto labelLayout = new QHBoxLayout();
        buttonLayout->addWidget(a);
        buttonLayout->addWidget(b);
        buttonLayout->addWidget(c);
        labelLayout->addWidget(aLabel);
        labelLayout->addWidget(bLabel);
        labelLayout->addWidget(cLabel);
        v->addLayout(buttonLayout);
        v->addLayout(labelLayout);
        this->setLayout(v);
        this->show();
    }
};
