# The-Art-Of-The-Cart

Implement a high level shopping simulator using iinheritance to model a class, ShoppingCart, after another class, DynamicArray, that you 
will modify to make functional. You will proceed to create an abstract Grocery class and to create its concrete children Vegetable, Drink, 
and JunkFood, which will collectively represent every type of item with which you can populate a ShoppingCart object. For this project you 
will use separate compilation with g++ to link multiple classes into one executable, and, in order to successfully complete this project, 
you must understand the concept of an abstract data type, template classes, dynamic memory allocation, and polymorphism.

## Implementation:

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

Now that you have your Bicycle(), your parents want you to run some errands. Today you must go grocery shopping. What your parents don’t realize is 
that now you’re in charge. You have the money and the list! The list… how do you make a list again?

Modify the DynamicArray.cpp file to implement the following methods (I highly suggest that you complete them in the presented order). The prototypes 
have already been written for you.

i)

```
template<typename ItemType> void DynamicArray<ItemType>::resize()
//carries out the dynamic sizing mentioned in the definition
```

*Hint*: You must dynamically allocate a new array of the appropriate altered size, and then you must copy all elements from the initial array into this 
new one. Finally, you must update and reassign the private members of the caller.







