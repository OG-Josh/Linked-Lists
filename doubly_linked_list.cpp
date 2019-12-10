/*
 * doubly_linked_list.cpp
 *	By Joshua Yang
 *  Created on: Apr 26, 2019
 *  Implement for doubly linked list
 */

#include "doubly_linked_list.h"

/**
 * Constructor
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    _head = NULL;
    _size = 0;
}

/**
 * Copy Constructor
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{
    _head = NULL;
    _size = 0;
    Node<T>* current_node = other._head;
    // Read other list and insert to current list
    while (current_node != NULL)
    {
        insert(current_node->_data);
        current_node = current_node->_next;
    }

}

/**
 * Destructor
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* current_node = _head;
    while (current_node != NULL)
    {
        _head = current_node->_next;
        delete current_node;
        current_node = _head;
    }
    _head = NULL;
}

/**
 * Copy assignment
 */
template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
    // check for self-assignment
    if (&other == this)
        return *this;
    // Clean current node first
    Node<T>* current_node = _head;
    while (current_node != NULL)
    {
        _head = current_node->next;
        delete current_node;
        current_node = _head;
    }
    _head = NULL;
    // Insert data
    current_node = other._head;
    // Read other list and insert to current list
    while (current_node != NULL)
    {
        insert(current_node->_data);
        current_node = current_node->next;
    }
    return *this;
}

/**
 * Insert node to last
 */
template <class T>
void DoublyLinkedList<T>::insert(T value)
{
    // Create new node
    Node<T>* new_node = new Node<T>(value);
    if(_head == NULL)
    {
        _head = new_node;
        _size++;
        return;
    }

    Node<T>* current = _head;
    while(current->_next != NULL)
    {
        current = current->_next;
    }
    current->_next = new_node;
    new_node->_prev = current;


//
//    // Make next of new node as head and previous as NULL
//    new_node->_next = _head;
//    new_node->_prev = NULL;
//    // change prev of head node to new node
//    if (_head != NULL)
//        _head->_prev = new_node;
//    // move the head to point to the new node
//    _head = new_node;
//    // Increate size of linked list
    _size++;
}

/**
 * Insert node to middle. If list is empty. Just insert to the head
 */
template <class T>
void DoublyLinkedList<T>::insert_middle(T value)
{
    // Create new node
    Node<T>* new_node = new Node<T>(value);

    // If this list is empty or list just have one node. Insert to head
    if (_head == NULL)
    {
        new_node->_next = _head;
        new_node->_prev = NULL;
        // move the head to point to the new node
        _head = new_node;
        // Increase size
        _size++;
        return;
    }

    // If list is not empty. Insert to midle
    int pos = _size / 2;
    int index = 1;
    Node<T> *current = _head;
    while (index < pos)
    {
        current = current->_next;
        index++;
    }
    // next of current will be next of new node
    new_node->_next = current->_next;

    if (current->_next != NULL)
        current->_next->_prev = new_node;

    // prev of new node will be current
    new_node->_prev = current;
    current->_next = new_node;
    // Increase size
    _size++;
}

/**
 * Remove node at position
 */
template <class T>
void DoublyLinkedList<T>::remove(int pos)
{
    // If list is empty or invalid position. no action
    if (_head == NULL || pos > _size || pos <= 0)
        return;
    // If pos is head
    Node<T> *current = _head;
    if (pos == 1)
    {
        _head = _head->_next;
        delete current;
        _size--;
        return;
    }
    int index = 0;
    // Find node to delete
    while (index < pos)
    {
        current = current->_next;
        index++;
    }
    if (current->_prev != NULL)
    {
        // point next of prev to current next
        current->_prev->_next = current->_next;
    }
    if (current->_next != NULL)
    {
        // point prev of current next to current prev
        current->_next->_prev = current->_prev;
    }
    // delete current
    delete current;
    // Decrease size
    _size--;
}

/**
 * Revert the linked list
 */
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::revert()
{
    DoublyLinkedList<T> result;
    // If this is empty. Just return
    if (_head == NULL)
        return result;
    Node<T> *current = _head;
    // Find the tail of linked list
    while (current->_next != NULL)
    {
        current = current->_next;
    }
    while (current != NULL)
    {
        result.insert(current->_data);
        current = current->_prev;
    }
    return result;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const DoublyLinkedList<T>& list)
{
    Node<T> *current = list._head;
    // Find the tail of linked list
    while (current != NULL)
    {
        os << current->_data << " ";
        current = current->_next;
    }
    return os;
}
