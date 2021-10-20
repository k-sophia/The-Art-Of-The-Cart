/****************************************************************************************************************************
Title          :   ShoppingCart.cpp
Auhor          :   Kelly Camacho
Description    :   implementation file of a dynamically resizeable array class
Dependencies   :   ShoppingCart.hpp
****************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.hpp"

using namespace std;


/****************************************************** Public Methods *****************************************************/

/* Default Constructor */
ShoppingCart::ShoppingCart():DynamicArray<Grocery*>() {
  item_count_ = 0;
}

ShoppingCart::~ShoppingCart() {
    DynamicArray::clear();    /* clear() releases dynamically allocated
                   memory - we want to repeat this behavior
                   in other methods, which is why the code 
                   in clear() is in its own function as 
                   opposed to simply being in the destructor */
}

/**
    adds new_entry to the caller; if the entry
    already exists in the caller, increment
    quantity_ in the object, and increment 
    the curr_contents_weight_ of the caller
    by the unit_weight_ of the added item.
    
    @pre    :   the addition of the weight of 
                new_entry does not bring the
                curr_contents_weight_ over the 
                carrying capacity
        
    @return :   true if the addition is successful            
*/
bool ShoppingCart::add(Grocery * new_entry) {
  
    try
    {
        double weight_ = new_entry->getUnitWeight();
        if (OverMaxWeight(weight_)) {
          return false;
        }
        
        if(DynamicArray::contains(new_entry)) {
            int where_ = DynamicArray::getIndexOf(new_entry);
            items_[where_]->incrementQuantity();
        }
        else {
            DynamicArray::add(new_entry);
            item_count_++; 
            
        }
        update_weight(weight_);

        return true;

    }
    catch (...)
    {
        return false;
    }
        
}

/**  
    removes the first instance of an_item from the caller;
    if the entry already exists in the caller, decrement
    quantity_ in the object, and decrement the 
    curr_contents_weight_ of the caller by the 
    unit_weight_ of the added item.
    --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
    @return :   true if the addition is successful            
*/
bool ShoppingCart::remove(Grocery * an_item) {

    try
    {
        if(DynamicArray::contains(an_item)) {
            int where_ = DynamicArray::getIndexOf(an_item);
            items_[where_]->decrementQuantity();
        }

        double minus_ = -1 * an_item->getUnitWeight();
        update_weight(minus_);
        garbageClear();

        return true;

    }
    catch (...)
    {
        return false;
    }

}

double ShoppingCart::checkout()
{
   if (item_count_ == 0)
   {
      std::cout << "Your cart is empty!" << std::endl;
      return 0;
   }

   double total = 0;
   for (size_t i = 0; i < item_count_; i++)
   {
      std::cout << "\n" << std::setw(10) << std::left << 
            items_[i]->getName() << "\t" << items_[i]->getQuantity() 
            << "\t" << std::fixed << std::setprecision(2) 
            << items_[i]->getTotalPrice();
      total += items_[i]->getTotalPrice();
   }
   std::cout << std::setfill('-') << std::setw(40) << "\n" 
         << std::endl << "Total:                  " 
         << total << std::endl << std::endl;
   clear();
   return total;
}

/** 
     iterates through caller and removes items whose quantity_ == 0
    --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
    @post   :   every item in the caller has quantity_ >= 1
*/
void ShoppingCart::garbageClear() {
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getQuantity() == 0) {
            DynamicArray::remove(items_[i]);
            item_count_--;
        }
    }

}

bool ShoppingCart::OverMaxWeight(double compare) {
    double w_capacity_ = 350.0; //shopping carts have a max carrying capacity of 350 lb

    double add_of = compare + getCurrentWeight();
    
    if (w_capacity_ < compare) {
      return true;
    }
    return false;
}

void ShoppingCart::update_weight(double w_) {
    curr_contents_weight_ += w_;
}

double ShoppingCart::getCurrentWeight() {
    return curr_contents_weight_;
}
