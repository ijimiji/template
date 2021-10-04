#pragma once

#include <vector>

class Model {
  private:
    std::vector<int> items;

  public:
    Model() {}
    void addItem(int item) { items.push_back(item); };
    void removeItem(int i) { items.erase(items.begin() + i); };
};