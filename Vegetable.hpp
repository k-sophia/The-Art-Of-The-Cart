/****************************************************************************************************************************
Title         :   Vegetable.hpp
Auhor         :   Kelly Camacho
Description   :   header/interface file a of polymorphic child class of Grocery
****************************************************************************************************************************/

#ifndef VEGETABLE_
#define VEGETABLE_

#include <iostream>
#include <string>

#include "Grocery.hpp"

class Vegetable: public Grocery  //inherit from Grocery
{
    public:
        /** 
            unit of price: dollars
            unit of weight: pounds (lb)
            Set the quantity_ to 1 and total_price_ to 0
            Set name_, unit_price_, and unit_weight_ to what was given by the user.
        */
        Vegetable(std::string name, double price, double weight); //constructor
        virtual void updateCost() override;
}; // end Vegetable

#endif
