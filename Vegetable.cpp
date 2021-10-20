/****************************************************************************************************************************
Title          :   Vegetable.cpp
Auhor          :   Kelly Camacho
Description    :   implementation file of a polymorphic child class of Grocery
Dependencies   :   Vegetable.hpp
****************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Vegetable.hpp"

Vegetable::Vegetable(std::string name, double price, double weight) : Grocery(name, price, weight) {
  updateCost();
}

/**
   total_price_ <- product of: quantity, weight per item, and price per pound
*/

void Vegetable::updateCost() {
    total_price_ = quantity_ * unit_weight_ * unit_price_;
}
