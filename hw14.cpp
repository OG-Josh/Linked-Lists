/*
 * hw14.cpp
 *	By Joshua Yang
 *  Created on: Apr 27, 2019
 *  Test Driver for HW14
 */

#include "doubly_linked_list.h"
#include "doubly_linked_list.cpp"
#include <iostream>

using namespace std;

int main(int agrc, char* agrv[])
{
    cout << "======TEST WITH DOUBLE LINKED LIST TYPE INT===============" << endl;
    DoublyLinkedList<int> intList;
    intList.insert(88);
    intList.insert(78);
    intList.insert(62);
    intList.insert(143);
    intList.insert(60);
    cout << "Part 1: " << endl;
    cout << "Linked list 1: " << intList << endl;
    cout << endl << "Part 2: " << endl;
    DoublyLinkedList<int> intList1(intList);
    DoublyLinkedList<int> intList2 = intList;
    cout << "Linked 1 copy constructor: " << intList1 << endl;
    cout << "Linked 1 copy assignment: " << intList2 << endl;

    cout << endl << "Part 3: " << endl;
    DoublyLinkedList<int> intList3 = intList.revert();
    cout << "Linked list 2: " << intList3 << endl;
    cout << endl << "Part 4 (after deleting the third node): " << endl;
    intList3.remove(3);
    intList.remove(3);
    cout << "Linked list 1: " << intList << endl;
    cout << "Linked list 2: " << intList3 << endl;
    cout << endl << "Part 5 (after adding a node in the middle of the list: " << endl;
    intList.insert_middle(70);
    intList3.insert_middle(70);
    cout << "Linked list 1: " << intList << endl;
    cout << "Linked list 2: " << intList3 << endl;

    cout << "==========================================================" << endl << endl;

    cout << "======TEST WITH DOUBLE LINKED LIST TYPE DOUBLE ===========" << endl;
    DoublyLinkedList<double> doubleList;
    doubleList.insert(60.1);
    doubleList.insert(143.2);
    doubleList.insert(62.3);
    doubleList.insert(78.4);
    doubleList.insert(80.5);
    doubleList.insert(200.6);
    cout << "Part 1: " << endl;
    cout << "Linked list 1: " << doubleList << endl;
    cout << endl << "Part 2: " << endl;
    DoublyLinkedList<double> doubleList1(doubleList);
    DoublyLinkedList<double> doubleList2 = doubleList;
    cout << "Linked 1 copy constructor: " << doubleList1 << endl;
    cout << "Linked 1 copy assignment: " << doubleList2 << endl;

    cout << endl << "Part 3: " << endl;
    DoublyLinkedList<double> doubleList3 = doubleList.revert();
    cout << "Linked list 2: " << doubleList3 << endl;
    cout << "Part 4 (after deleting the third node): " << endl;
    doubleList3.remove(3);
    doubleList.remove(3);
    cout << "Linked list 1: " << doubleList << endl;
    cout << "Linked list 2: " << doubleList3 << endl;
    cout << endl << "Part 5 (after adding a node in the middle of the list: " << endl;
    doubleList.insert_middle(70);
    doubleList3.insert_middle(70);
    cout << "Linked list 1: " << doubleList << endl;
    cout << "Linked list 2: " << doubleList3 << endl;
    cout << "==========================================================" << endl << endl;
    return 1;
}

