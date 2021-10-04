#pragma once
#include "Model.hpp"
#include "View.hpp"
#include "ViewListener.hpp"

class Controller : public ViewListener {
  public:
    Controller(View *view, Model *model) : view(view), model(model) {}
    View *view;
    Model *model;
    virtual void addItem(int item) override { model->addItem(item); };
    virtual void removeItem(int i) override { model->removeItem(i); };
};