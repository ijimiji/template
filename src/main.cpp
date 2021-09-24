#include <QApplication>
#include "win.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWindow a;
    a.setWindowTitle("Контрольная работа");
    a.show();
    return app.exec();
}
