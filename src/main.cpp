#include <QApplication>

#include "View.hpp"
#include "Controller.hpp"
#include "Model.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    View v;
    Model m;
    Controller c(&v, &m);
    v.setListener(&c);
    return a.exec();
}