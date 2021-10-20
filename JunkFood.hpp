/****************************************************************************************************************************
Title         :   JunkFood.hpp
Auhor         :   Kelly Camacho
Description   :   header/interface file a of polymorphic child class of Grocery
****************************************************************************************************************************/

#ifndef JunkFood_
#define JunkFood_

#include <iostream>
#include <string>

#include "Grocery.hpp"

class JunkFood: public Grocery //inherit from Grocery
{
    public:
      /** 
          unit of price: dollars
          unit of weight: pounds (lb)
          Set the quantity_ to 1 and total_price_ to 0
          Set name_, unit_price_, and unit_weight_ to what was given by the user.
      */
      JunkFood(std::string name, double price, double weight);
      virtual void updateCost() override;
}; // end JunkFood

#endif
