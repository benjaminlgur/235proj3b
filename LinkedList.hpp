//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  Removed Exception Handling becuse not yet covered and
// Student will add project-specific methods

/** ADT list: Singly linked list implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "Node.hpp"
#include <cassert>

template<class T>
class LinkedList
{

public:
   LinkedList();
   LinkedList(const LinkedList<T>& a_list);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int new_position, const T& new_entry);
   bool remove(int position);
   void clear();
   T getEntry(int position) const;


   /***************** PROJECT-SPECIFIC PUBLIC METHODS ****************/

   void invert();
   void selectionSort();
   void testFunc();


private:
    Node<T>* head_ptr_; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int item_count_;           // Current count of list items

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= item_count_.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<T>* getNodeAt(int position) const;


   /***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/
   void invertRest(Node<T>* current_first_ptr);
   void nodeSwap(Node<T>* head_of_list,Node<T>* min_node,Node<T>* node_before_min_node);
   Node<T>* recursiveSelectionSort(Node<T>* current_first_ptr);
   

}; // end LinkedList

#include "LinkedList.cpp"
#endif
