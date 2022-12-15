// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 2 � Doubly Linked List

/**========================================================================
 * @file        utillist.h
 * @brief       implementation of own doubly linked list class.
 * @author      Nour Ahmed
 * @email       nahmed@stud.hs-bremen.de, nourbrm02@gmail.com
 * @repo        https://github.com/nouremara/my_cpp_doubly_linked_list
 * @createdOn   08.12.2022
 * @version     1.0.0
 * @description implementation of own Doubly Linked List class
 *
 * This file presents an implementation of a class named list.
 * Class list represents a container which organizes stored objects with
 * a so-called doubly linked list. A doubly linked list is basically
 * a list of nodes which are connected among each other
 * This class behavior will be similar to the std::list (for the implemented
 * part of its functionality).
 *========================================================================**/

#include "utillist.h"

// namespace util to contain the Class list
namespace util {

// destructor
template <class T>
list<T>::~list() {
    Node* tmp = nullptr;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

template <class T>
void list<T>::pop_front() {
    // check whether the doubly linked list is empty or not.
    // If it is empty, then do nothing.
    if (head == nullptr) {
        return;
    }

    // check whether the doubly linked List has just one node.If it does, 
    // we just delete that node and set the head and tail pointers to NULL.
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // create a temporary node to be the current head (before deletion)
    // Create a new node, current, which is the second node in the list.
    Node* current = head->next;

    // delete the front node
    delete head;

    // Make head point to the second node, i.e., current.
    // point the head pointer to the previous node
    head = current;

    // adjust the next pointer of the head node
    // Set this node's prev to NULL.
    head->prev = nullptr;
}

// removes the last element from the list
template <class T>
void list<T>::pop_back() {
    Node* current = tail->prev;
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Node* current = tail->prev;
    delete tail;
    tail = current;
    tail->next = nullptr;
}

// Clears the list
template <class T>
void list<T>::clear() {
    Node* tmp = tail;

    while (tail->prev != nullptr) {
        tmp = tail->prev;
        delete tail;
        tail = tmp;
    }
    head = nullptr;
    tail = nullptr;
}

// Returns the amount of stored objects
template <class T>
size_t list<T>::size() const {
    size_t count = 0;
    if (head == nullptr) {
        return count;
    }

    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

template <class T>
void list<T>::display(std::ostream& out) const {
    out << " [size: " << size() << "], contents: ";

    if (head == nullptr) {
        out << " <empty list> ";
        return;
    }

    Node* node = head;
    while (node != nullptr) {
        out << node->data << " ";
        node = node->next;
    }
}

template <class U>
std::ostream& operator<<(std::ostream& os, const util::list<U>& theList) {
    theList.display(os);
    return os;
}

} /* namespace util */