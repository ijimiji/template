#include <QApplication>

#include <QWidget>

class Layouts : public QWidget {

  public:
    Layouts(QWidget *parent = 0);
};
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

Layouts::Layouts(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QListWidget *lw = new QListWidget(this);
    std::vector<QString> xss = {"The Omen", "The Exorcist",
                                "Notes on a scandal", "Fargo", "Capote"};
    for (auto &x : xss) {
        lw->addItem(x);
    }

    QPushButton *add = new QPushButton("Add", this);
    QPushButton *rename = new QPushButton("Rename", this);
    QPushButton *remove = new QPushButton("Remove", this);
    QPushButton *removeall = new QPushButton("Remove All", this);

    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeall);
    vbox->addStretch(1);

    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Layouts window;

    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}