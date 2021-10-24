# The-Art-Of-The-Cart

Implement a high level shopping simulator using iinheritance to model a class, ```ShoppingCart```, after another class, ```DynamicArray```, 
that you will modify to make functional. You will proceed to create an abstract ```Grocery``` class and to create its concrete children 
```Vegetable```, ```Drink```, and ```JunkFood```, which will collectively represent every type of item with which you can populate a ShoppingCart 
object. For this project you will use separate compilation with g++ to link multiple classes into one executable, and, in order to successfully 
complete this project, you must understand the concept of an abstract data type, template classes, dynamic memory allocation, and polymorphism.

## Implementation

Work incrementally! Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous 
one has been completed correctly. Remember that the names of function prototypes and member variables must exactly match those declared in the 
respective header file when implementing a class.

### Definition:

Let a dynamically resizable array be an array whose maximum capacity increases by a factor of 2 in the event that an insertion is attempted 
when it is already at maximum capacity and whose maximum capacity decreases by a factor of 2 when the number of elements within it drops below 
a quarter of its maximum capacity.

*Examples*:

```
arr1 <- {1, 2, 3, 4}                (capacity == 4)
arr1.add(5)
arr1 == {1, 2, 3, 4, 5, _, _, _}    (capacity == 8)

arr2 <- {1, 2, 3, 4, 5, _, _, _}    (capacity == 8)
arr2.remove(5)
arr2.remove(4)
arr2.remove(3)
arr2.remove(2)
arr2 == {1, _, _, _}                (capacity == 4)
```

*Addendum*: removal in this fashion ensures the efficient execution of future anticipated insertions by minimizing the amount of resize() operations 
that need to be called later.

___
Task 1: The Grocery List
___

*Now that you have your Bicycle(), your parents want you to run some errands. Today you must go grocery shopping. What your parents don’t realize is 
that now you’re in charge. You have the money and the list! The list...how do you make a list again?*

Modify the ```DynamicArray.cpp``` file to implement the following methods (I highly suggest that you complete them in the presented order). The prototypes 
have already been written for you.

i)

```
template<typename ItemType> void DynamicArray<ItemType>::resize()
//carries out the dynamic sizing mentioned in the definition
```

*Hint*: You must dynamically allocate a new array of the appropriate altered size, and then you must copy all elements from the initial array into this 
new one. Finally, you must update and reassign the private members of the caller.

ii)

```
template<typename ItemType> bool DynamicArray::add(const ItemType &new_entry)
// inserts an item into the last position of the caller 
//    it must call resize(), and it must allow for the  
//    the pointer to the caller array to be == nullptr
```

iii)

```
template<typename ItemType> bool DynamicArray::remove(const ItemType &an_item)
// removes the first instance of an item from the caller
//    it must check whether the element to be removed is within 
//    the array and it must call resize()
```

*Hint*: Before you call resize you could copy all of the items except the one to be removed into a new dynamically allocated array.

___
Task 2: FOOD!
___

*That’s right; you heard me! FOOD! Everything you could ever want! Grab whatever your heart desires!*

Define and implement the ```Vegetable```, ```Drink```, and ```JunkFood``` classes as polymorphic children of the ```Grocery``` class.

Class ```Vegetable``` must contain the following methods:

```
/**
   unit of price: dollars
   unit of weight: pounds (lb)
*/
Vegetable(std::string name, double price, double weight)

/**
   total_price_ <- product of: quantity, weight per item, and price per pound
*/
void updateCost()    // updates total_price_
```

Class ```Drink``` must contain the following methods:

```
/**
   unit of price: dollars
   unit of weight: pounds (lb)
*/
Drink(std::string name, double price, double weight)

/**
   total_price_ <- product of: quantity, weight per liter, and price per liter
*/
void updateCost()    // updates total_price_
```

*Note*: weight / liter == unit_weight_ * 16 / FLOZ_PER_LITER

*Note*: 1 liter == 33.814 fluid ounces

Class ```JunkFood``` must contain the following methods:

```
/**
   unit of price: dollars
   unit of weight: pounds (lb)
*/
JunkFood(std::string name, double price, double weight)

/**
   total_price_ <- product of: quantity and price per unit
*/
void updateCost() which updates total_price_
```

___
Task 3: Bringing It Home
___

*Did you get everything you wanted? Great! Time to check out and head back home. Hope you remembered to get the bread...*

Define the ```ShoppingCart``` class as a child of the DynamicArray class in a file entitled ```ShoppingCart.hpp```. All shopping carts have a maximum 
carrying capacity of 350 pounds. Implement the class in a file entitled ```ShoppingCart.cpp```. You must include but are not limited to the following 
methods and members:

```
public: 

   /* Default Constructor */
   ShoppingCart();
   
   /** 
      must call the destructor of DynamicArray
   */
   ~ShoppingCart();

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
   bool add(Grocery * new_entry);
        
   /**  
      removes the first instance of an_item from the caller; 
      if the entry already exists in the caller, decrement
      quantity_ in the object, and decrement the 
      curr_contents_weight_ of the caller by the 
      unit_weight_ of the added item.
      --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
      
      @return :   true if the addition is successful            
   */
   bool remove(Grocery * an_item);

   /** 
      displays shopping cart contents in required format 
   */
   double checkout();

   /** 
      iterates through caller and removes items whose quantity_ == 0
      --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
      
      @post   :   every item in the caller has quantity_ >= 1
   */
   void garbageClear();

   /* 
      Getter: curr_contents_weight_ 
   */
   double getCurrentWeight();

private:

   double curr_contents_weight_;
```

Here is a freebie implementation of method checkout() to put in ```ShoppingCart.cpp```:

```
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
```

___

**Testing**

How to compile:

```
g++ ShoppingCart.cpp Grocery.cpp Vegetable.cpp JunkFood.cpp Drink.cpp <test main file> -std=c++17
```

You must always implement and test you programs INCREMENTALLY!!! What does this mean? Implement and test one method at a time. **For each class**

* Implement one function/method and test it thoroughly (multiple test cases + edge cases if applicable).
* Implement the next function/method and test in the same fashion.
  * **How do you do this?**  Write your own main() function to test your classes. In this course you will never submit your test program, but you 
    must always write one to test your classes. Choose the order in which you implement your methods so that you can test incrementally: 
    i.e. implement mutator functions before accessor functions. Sometimes functions depend on one another. If you need to use a function you 
    have not yet implemented, you can use stubs: a dummy implementation that always returns a single value for testing Don’t forget to go back 
    and implement the stub!!! If you put the word STUB in a comment, some editors will make it more visible.





