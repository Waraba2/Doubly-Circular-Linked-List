#include<iostream>
#include<cstdlib>
#include "LINKED_LIST.h"
#include "LINKED_LIST.cpp"
using namespace std;
int main()
{
    int choice;
    int List_Element;
    D_C_Linked_List<int> DCLL;

    while (1) {
        cout << "1.INSERT AT THE BEGINNING OF THE LIST." << endl;
        cout << "2.INSERT AT THE END OF THE LIST." << endl;
        cout << "3.DELETE AN ITEM IN THE LIST." << endl;
        cout << "4.ACCESS LIST ELEMENTS FROM FRONT TO BACK." << endl;
        cout << "5.ACCESS LIST ELEMENTS FROM BACK TO FRONT." << endl;
        cout << "6.SEARCH AN ELEMENT IN THE LITS." << endl;
        cout << "7.DISPLAY THE LIST." << endl;
        cout << "8.DISPLAY THE LENGTH OF THE LIST" << endl;
        cout << "9.KNOW IF THE LIST IS EMPTY" << endl;
        cout << "10.DELETE THE ENTIRE LIST." << endl;
        cout << "11.COPY ONE LIST IN ANOTHER ONE." << endl;
        cout << "12.OVERLOADED OPERATOR." << endl;
        cout << "13.EXIT" << endl;
        cout << "ENTER YOUR CHOICE: "<< endl;
        cin >> choice;
        switch (choice) {
            case 1:
            {
                cout <<"ENTER NUMBER TO BE INSERTED AT THE BEGINNING OF THE LIST: ";
                cin >> List_Element;
                DCLL.Insert_Begin(List_Element);
                break;
            }
            case 2:
            {
                cout <<"ENTER NUMBER TO BE INSERTED AT THE END OF THE LIST: ";
                cin >> List_Element;
                DCLL.Insert_End(List_Element);;
                break;
            }
            case 3:
            {
                cout <<"ENTER NUMBER TO BE DELETED FROM THE LIST: ";
                cin >> List_Element;
                DCLL.Delete_Item(List_Element);
                break;
            }
            case 4:
            {
                DCLL.Iterate_Front_To_Back();
                break;
            }
            case 5:
            {
                DCLL.Iterate_Back_To_Front();
                break;
            }
            case 6:
            {
                cout <<"ENTER NUMBER TO BE SEARCHED IN THE LIST: ";
                cin >> List_Element;
                if(DCLL.Search_Item(List_Element))
                    cout<<"ITEM IS IN THE LIST"<< endl;
                else
                    cout<<"ITEM IS NOT IN THE LIST"<<endl;
                break;
            }
            case 7:
            {
                cout <<"THE LIST IS:" <<endl;
                DCLL.Display_List();
                break;
            }
            case 8:
            {
                cout<< "THE LIST HAS "<< DCLL.Length_Of_List() <<" ELEMENTS." << endl;
                break;
            }
            case 9:
            {
                if(DCLL.If_List_Is_Empty())
                    cout <<"THE LIST IS EMPTY" << endl;
                else
                    cout <<"THE LIST IS NOT EMPTY" << endl;
                break;
            }
            case 10:
            {
                DCLL.Delete_List();
                break;
            }
            case 11:
            {
                D_C_Linked_List<int>d1(DCLL);
                d1.Display_List();
                break;
            }
            case 12:
            {
                D_C_Linked_List<int> d1 = DCLL;
                d1.Display_List();
                break;
            }
            case 13:
            {
                exit(1);
            }
            default:
                cout << "Wrong choice" << endl;
        }
    }
}
