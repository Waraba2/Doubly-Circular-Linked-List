//
// Created by Hamidou Wara Ballo on 5/19/20.
//

#ifndef DOUBLY_CIRCULAR_LINKED_LIST_LINKED_LIST_H
#define DOUBLY_CIRCULAR_LINKED_LIST_LINKED_LIST_H
template<class Type>
struct node {
    Type info;
    node<Type>* next;
    node<Type>* prev;
};
template<class Type>
class D_C_Linked_List
{
private:
    node<Type>*first;
    node<Type>* current_Iterrator;
    int count;
public:
    D_C_Linked_List();//Constructor

    void operator=(const D_C_Linked_List<Type>& Another_List); // Overloading operator.

    bool If_List_Is_Empty() ;// Function that finds out if the list is empty

    void Insert_Begin(Type item); // Insert an item at the beginning of the list.

    void Insert_End(Type item); //Insert an item at the end of the list.

    bool Search_Item(Type item); // Search an item in the list

    int Length_Of_List() const; //Return the length of the list.

    void Iterate_Front_To_Back(); //Iterate through the list from the front to the Back to access items in the list one after the other.

    void Iterate_Back_To_Front();//Iterate through the list from the back to the front to access items in the list one after the other.

    void Delete_Item(Type item); // Delete a given item

    void Display_List();// Displays the list

    void Delete_List(); // Function that delete the hole list.

    void copy(const D_C_Linked_List<Type>& Another_List); //Copy function

    D_C_Linked_List(const D_C_Linked_List<Type>& Another_List);//Copy Constructor.
    ~D_C_Linked_List();
};
#endif //DOUBLY_CIRCULAR_LINKED_LIST_LINKED_LIST_H
