﻿// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 2 – Doubly Linked List

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

#ifndef UTILLIST_CPP
#define UTILLIST_CPP

#include <iostream>

/**
 * namespace util to contain the Class list
 */
namespace util {

/**
 * Template to make the list generic such that any type can be stored.
 * T represents the actual type
 */
template <class T>
/**
 * @brief Implementation of of own doubly linked list class
 *
 * This class presents own list class implementation which organizes stored
 * objects with a so-called doubly linked list.
 * A doubly linked list is basically a list of nodes which are connected among
 * each other in both directions.
 *
 * This util::list is a container that supports adding, insertion, removal,
 * and moving of elements from anywhere in the container. It provides also
 * bidirectional iteration capability. This class behavior will be similar (but
 * simplified) to the std::list.
 */
class list {
    /**
     * @brief nested class representing a node and its data element in the list
     *
     * Each node has a data item, a pointer to the previous node, and
     * a pointer to the next node.
     */
    struct Node {
        T data;      ///< date element (object type) to store in the node
        Node* prev;  ///< pointer to predecessor node
        Node* next;  ///< pointer to successor node

        /** default constructor create a stand-alone node. */
        Node() : next(nullptr), prev(nullptr) {}

        /** constructor of the node fills the data element unset its
         * predecessor and successor node pointers as they will be
         * adjusted later
         */
        Node(const T& element, Node* next_node_ptr = nullptr, Node* prev_node_ptr = nullptr)
            : next(next_node_ptr),
              prev(prev_node_ptr),
              data(element) {}
    };

    Node *head, *tail;  ///< pointers to first and last nodes respectively

    /** a placeholder node after the list tail node
     * note that the data member of this node is not initialized as it is not needed
     * this will rresult in an undefined behavior when accessing it (as expected).
     */
    Node* beyond_tail;

   public:
    /** default constructor creates an empty list */
    list() : head(nullptr), tail(nullptr), beyond_tail(nullptr) {}

    /** destructor */
    ~list();

    list(const list<T>& other_doubly_linked_list) = delete;
    list& operator=(list const&) = delete;

    /** Gives access to the first element of the list */
    T& front() { return head->data; }

    /** Gives access to the last element of the list */
    T& back() { return tail->data; }

    /** Adds element to the front of the list */
    void push_front(const T& element) {
        Node* node = new Node(element);

        if (head == nullptr) {
            head = node;
            tail = head;
            return;
        }

        head->prev = node;
        node->next = head;
        head = node;
    }

    void pop_front() throw(char*);

    /** removes the last element from the list */
    void pop_back();

    /** Adds element to the end of the list */
    void push_back(const T& element) {
        Node* node = new Node(element);
        if (tail == nullptr) {
            tail = node;
            head = tail;
            return;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    /** Clears the list */
    void clear();

    /** Returns the amount of stored objects */
    size_t size() const;

    /** Returns true, if the list does not contain elements */
    bool empty() const { return size() ? false : true; }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const list<U>& theList);

   private:
    void display(std::ostream& out = std::cout) const;

   public:
    /**  To allow iterating your list, a simplified version of the iterator
     * concept is implemented as a nested class
     */
    class iterator {
        friend class list;

        Node* m_pNode;  ///< pointer to the node this iterator associated to

       public:
        /** constructor create the iterator and associate it to a node. */
        iterator(Node* pNode) : m_pNode(pNode) {}

        /**  Two iterators are equal if they point to the same node. */
        inline bool operator==(const iterator& it) const { return this->m_pNode == it.m_pNode; }

        /**  Two iterators are not equal if they point to different nodes. */
        inline bool operator!=(const iterator& it) const { return this->m_pNode != it.m_pNode; }

        /**  advance the iterator to the next node. */
        iterator& operator++() {
            // Point/Go to the next value of m_pNode
            m_pNode = static_cast<Node*>(m_pNode)->next;
            return *this;
        }

        /**  advance the iterator to the next node (Postfix variant). */
        iterator operator++(int) {
            iterator tmp(*this);
            ++*this;
            return tmp;
        }

        /**  Return a reference to the object stored in the current node. */
        T& operator*() const { return static_cast<Node*>(m_pNode)->data; }

        /**  Return a pointer to the object stored in the current node. */
        T* operator->() const { return &(static_cast<Node*>(m_pNode)->data); }
    };

    /**  Returns an iterator which points to the first element of your list. */
    iterator begin() { return iterator(head); }

    /**
     *  @brief Returns a special iterator which points to a placeholder node which is the
     * successor of the last node stored in the list.
     * Calling method end() of any STL container never returns an iterator pointing
     * to the last object but an iterator which does not point to a valid object.
     * As this element acts as a placeholder any attempt to access its object
     * results in undefined behavior.
     */
    iterator end() {
        // create a circular link between the the tail and beyond_tail nodes
        //  tail <=> beyond_tail
        tail->next = beyond_tail;

        return iterator(beyond_tail);
    }

    /**
     * Adds element one position before the object iterator is currently pointing to.
     * iterator may be the end() iterator. Returns an iterator pointing to the newly
     * added element.
     */
    iterator insert(iterator position, const T& element) {
        // check if it is the end iterator
        if (position == end()) {
            push_back(element);
            return iterator(tail);
        }

        /**
         * create a new node with the contents given.
         * Its next is the current position next node, and
         * its previous is the node at current position.
         */
        Node* newNode = new Node(element, position.m_pNode->next, position.m_pNode);
        if (position.m_pNode == tail) tail = newNode;
        position.m_pNode->next = newNode;
        position.m_pNode->next->prev = newNode;
        return iterator(newNode);
    }

    /**
     *  @brief  Remove element at given position.
     *  @param  position  Iterator pointing to element to be erased.
     *                    Iterator must be valid and de-referencible.
     *                    For that reason, the end() iterator cannot be
     *                    used as a parameter.
     *  @return An iterator pointing to the next element (the successor
     *                    of the erased object) or end().
     *
     *  @description
     *  This function will erase the element at the given position and thus
     *  shorten the %list by one.
     */
    iterator erase(iterator position) throw(char*) {
        // the end() iterator cannot be used as a parameter
        if (position == end()) {
            // return end();
            throw "Exception from util::list::erase(): iterator must be valid and dereferenceable. end() iterator cannot be used as a parameter";
        }

        if (position.m_pNode != head && position.m_pNode != tail->next) {
            Node* successor = position.m_pNode->next;
            position.m_pNode->prev->next = successor;
            position.m_pNode->next->prev = position.m_pNode->prev;
            delete position.m_pNode;
            return (successor == tail) ? end() : iterator(successor);
        }

        if (position.m_pNode == head) {
            this->pop_front();
            return iterator(head);
        }

        this->pop_back();
        return end();
    }

};  // end class list

}  // end namespace util

#endif /* UTILLIST_CPP */
