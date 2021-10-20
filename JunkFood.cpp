/****************************************************************************************************************************
Title          :   JunkFood.cpp
Auhor          :   Kelly Camacho
Description    :   implementation file of a polymorphic child class of Grocery
Dependencies   :   JunkFood.hpp
****************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "JunkFood.hpp"

JunkFood::JunkFood(std::string name, double price, double weight) : Grocery(name, price, weight) {
  updateCost();
}

/**
   total_price_ <- product of: quantity and price per unit
*/

void JunkFood::updateCost() {
    total_price_ = quantity_ * unit_price_;
}
