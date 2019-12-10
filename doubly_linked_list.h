/*
 * doubly_linked_list.h
 *	By Joshua Yang
 *  Created on: Apr 26, 2019
 *  Define doubly linked list
 */

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <iostream>

/**
 * Node class. Each node contain data, next and prev point to next and previous node
 */
template <class T>
class Node
{
    public:
        T _data;
        Node *_next;
        Node *_prev;
        Node(T data = 0, Node<T>* next = NULL, Node<T>* prev = NULL)
        {
            _data = data;
            _next = next;
            _prev = prev;
        }
};

template <class T>
class DoublyLinkedList
{
    public:
        // Constructor
        DoublyLinkedList();
        // Copy Constructor
        DoublyLinkedList(const DoublyLinkedList<T>& other);
        // Destructor
        ~DoublyLinkedList();
        // Copy assignment
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
        // Add node
        void insert(T value);
        // Add node with pos
        void insert_middle(T value);
        // Remove at pos
        void remove(int pos);
        // Revert list
        DoublyLinkedList revert();
        // display list
        template <class U>
        friend std::ostream & operator<<(std::ostream &os, const DoublyLinkedList<U>& list);
    private:
        Node<T> *_head;
        int _size;
};

#endif /* DOUBLY_LINKED_LIST_H_ */
