#pragma once

#include <vector>
#include <iostream>
class Model {
  private:
    std::vector<int> items;
  public:
    Model(){
    }
    void addItem(int item){
        items.push_back(item);
        for (auto &item : items){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    };
    void removeItem(int i){
        items.erase(items.begin()+i);
    };
};