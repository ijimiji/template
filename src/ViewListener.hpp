#pragma once

class ViewListener {
  public:
    virtual void addItem(int) = 0;
    virtual void removeItem(int) = 0;
};