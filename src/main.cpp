#include <QApplication>

#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

class Visitor {
  public:
    virtual void visit() = 0;
};

class ConcreteVisitor : Visitor {
  public:
    void visit() override {}
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    View v;
    Model m;
    Controller c(&v, &m);
    v.setListener(&c);
    return a.exec();
}