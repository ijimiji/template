#include "listcontroller.h"
#include <QApplication>
#include <QKeySequence>
#include <QShortcut>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <vector>
using std::vector;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    vector<int> items = {1, 2, 3, 123,141, 1};
    auto x = new ListViewer(items);
    return a.exec();
}