//
// Created by Hamidou Wara Ballo on 5/19/20.
//

#include "LINKED_LIST.h"
#include <iostream>
using namespace std;
template<class Type>
D_C_Linked_List<Type>::D_C_Linked_List() //Constructor
{
    current_Iterrator= NULL;
    first = NULL;
    count = 0;
}

template<class Type>
void D_C_Linked_List<Type>::operator=(const D_C_Linked_List<Type>& Another_List) // OVERLOADING OPERATOR TO COPY A LIST INTO ANOTHER ONE USING THE "=" SIGN.
{
    copy(Another_List);
}

template<class Type>
bool D_C_Linked_List<Type>::If_List_Is_Empty() // FUNCTION THAT RETURNS IF THE LIST IS EMPTY OR NOT.
{
    return (first == NULL);
}

template<class Type>
void D_C_Linked_List<Type>::Insert_Begin(Type item) // FUNCTION TO INSERT AN ITEM AT THE BEGINNING OF THE LIST.
{
    node<Type> *temp= new node<Type>;
    temp->info = item;
    if (first == NULL)
    {
        first = temp;
        first->prev = first;
        first->next = first;
    }
    else
    {
        temp-> next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
        first = temp;
    }

    count++;
}
template<class Type>
void D_C_Linked_List<Type>::Insert_End(Type item)  // FUNCTION TO INSERT AN ITEM AT THE END OF THE LIST.
{
    node<Type>* temp = new node<Type>;
    temp->info = item;
    if (first == NULL)
    {
        first = temp;
        first->prev = first;
        first->next = first;
    } else
    {
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
    }
    count++;
}

template<class Type>
bool D_C_Linked_List<Type>::Search_Item(Type item) // FUNCTION TO SEARCH AN ITEM IN THE LIST.
{
    node<Type> *temp;
    temp = first;
    bool found= false;
    if(first == NULL)
    {
        cout << "THE LIST IS EMPTY" << endl;
        found = false;
    }
    else
    {
        for(int i = 0; i<count; i++)
        {
            if(temp->info!=item)
            {
                temp = temp->next;
                found = false;
            } else
            {
                found = true;
            }
        }

    }
    return found;
}

template<class Type>
int D_C_Linked_List<Type>::Length_Of_List() const // FUNCTION THAT RETURNS THE LENGTH OF THE LIST.
{
    return count;
}

template<class Type>
void D_C_Linked_List<Type>::Iterate_Front_To_Back() // FUNCTION ITERATES THROUGH THE LIST FROM FRONT TO BACK TO ACCESS LIST ELEMENT ONE BY ONE.
{
    if (current_Iterrator == NULL)
    {
        current_Iterrator = first;
    }
    else
        current_Iterrator = current_Iterrator->next;
}

template<class Type>
void D_C_Linked_List<Type>::Iterate_Back_To_Front() // FUNCTION ITERATES THROUGH THE LIST FROM BACK TO FRONT TO ACCESS LIST ELEMENT ONE BY ONE.
{
    if (current_Iterrator == NULL)
    {
        current_Iterrator = first->prev;
    }
    else
        current_Iterrator = current_Iterrator->prev;
}

template<class Type>
void D_C_Linked_List<Type>::Delete_Item(Type item) // FUNCTION TO DELETE A GIVEN NODE IN THE LIST
{
    node<Type>* temp;
    temp = first;

    if (first == NULL)
    {
        cout << "THE LIST IS EMPTY, CAN'T DELETE"<< endl;
    }
    else
    {

        for (int i = 0; i < count; i++)
        {
            if (temp->info == item)
            {

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (count == 1)
                {
                    first = NULL;
                }
                else if (first == temp)
                {
                    first = first->next;
                }
                delete temp;
                count--;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

template<class Type>
void D_C_Linked_List<Type>:: Display_List() //FUNCTION TO DISPLAY THE LIST ELEMENTS.
{
    node<Type>* temp;
    temp= first;
    if (first == NULL)
    {
        cout << "THE LIST IS EMPTY" << endl;;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

template<class Type>
void D_C_Linked_List<Type>::Delete_List() //FUNCTION THAT DELETES THE ENTIRE LIST.
{
    for (int i = 0; i < count; i++)
    {
        if(first == NULL)
        {
            cout << "THE LIST IS EMPTY"<< endl;
        }
        else
        if(first->next == first->prev)
        {
            first = NULL;
        }
        else
        {
            node<Type>* temp;
            temp = first;
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
            delete temp;
        }
    }
}

template<class Type>
void D_C_Linked_List<Type>::copy(const D_C_Linked_List<Type>& Another_List) // COPY FUNCTION USED TO COPY ONE LIST INTO ANOTHER ONE IN THE COPY CONSTRUCTOR.
{
    if (Another_List.first == NULL)
    {
        return;
    }
    else
    {
        node<Type>* temp = Another_List.first;

        for (int i = 0; i < Another_List.Length_Of_List(); i++)
        {
            Insert_End(temp->info);
            temp = temp->next;
        }

    }
}

template<class Type>
D_C_Linked_List<Type>::D_C_Linked_List(const D_C_Linked_List<Type>& Another_List) //COPY CONSTRUCTOR TO COPY ONE LIST INTO ANOTHER EMPTY LIST.
{
    current_Iterrator = NULL;
    first = NULL;
    count = 0;

    copy(Another_List);
}

template<class Type>
D_C_Linked_List<Type>::~D_C_Linked_List() //DESTRUCTOR DESTROYS THE LIST AFTER WE ARE DONE WITH THE LIST.
{
    Delete_List();
}