/****************************************************************************************************************************
Title         :   ShoppingCart.hpp
Auhor         :   Kelly Camacho
Description   :   header/interface file of a dynamically resizeable array class
****************************************************************************************************************************/

#ifndef SHOPPING_CART_
#define SHOPPING_CART_

#include <string>
#include "DynamicArray.hpp"
#include "Grocery.hpp"

class ShoppingCart: public DynamicArray<Grocery*>//child of DynamicArray
{
    public:
        ShoppingCart(); //contructor
        ~ShoppingCart(); //destrcutor
        bool add(Grocery * new_entry);
        bool remove(Grocery * an_item);

        /** displays shopping cart contents in required format */
        double checkout();
        void garbageClear();

        /* Getter: curr_contents_weight_ */
        double getCurrentWeight();

    private:
        bool OverMaxWeight(double compare);
        double curr_contents_weight_ = 0.0;
        void update_weight(double w_);
        double item_count_;
}; //end ShoppingCart

#endif
