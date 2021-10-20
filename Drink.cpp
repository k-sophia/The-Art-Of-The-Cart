/****************************************************************************************************************************
Title          :   Drink.cpp
Auhor          :   Kelly Camacho
Description    :   implementation file of a polymorphic child class of Grocery
Dependencies   :   Drink.hpp
****************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Drink.hpp"

Drink::Drink(std::string name, double price, double weight) : Grocery(name, price, weight) {
  updateCost();
}

/**
   total_price_ <- product of: quantity, weight per liter, 
                                                and price per liter
*/

void Drink::updateCost() {
    double liter_ =  33.814; //1 liter == 33.814 fluid ounces
    double weight_per_liter_ = (unit_weight_ * 16)/ liter_; //weight / liter == unit_weight_ * 16 / FLOZ_PER_LITER

    total_price_ = quantity_ * weight_per_liter_ * unit_price_;
}

