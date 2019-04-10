//Project 3b CSCI 235
//By Benjamin Gur

//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  Removed Exception Handling becuse not yet covered and
// Student will add project-specific methods

/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.hpp"  // Header file


template<class T>
LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& a_list) : item_count_(a_list.item_count_)
{
   Node<T>* orig_chain_pointer = a_list.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_pointer == nullptr)
      head_ptr_ = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_pointer->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_pointer = orig_chain_pointer->getNext();     // Advance original-chain pointer
      while (orig_chain_pointer != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_pointer->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_pointer = orig_chain_pointer->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedList<T>::~LinkedList()
{
   clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
   return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
   return item_count_;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int new_position, const T& new_entry)
{
   bool able_to_insert = (new_position >= 1) && (new_position <= item_count_ + 1);
   if (able_to_insert)
   {
      // Create a new node containing the new entry
      Node<T>* new_node_ptr = new Node<T>(new_entry);

      // Attach new node to chain
      if (new_position == 1)
      {
         // Insert new node at beginning of chain
         new_node_ptr->setNext(head_ptr_);
         head_ptr_ = new_node_ptr;
      }
      else
      {
         // Find node that will be before new node
         Node<T>* prev_ptr = getNodeAt(new_position - 1);

         // Insert new node after node to which prev_ptr points
         new_node_ptr->setNext(prev_ptr->getNext());
         prev_ptr->setNext(new_node_ptr);
      }  // end if

      item_count_++;  // Increase count of entries
   }  // end if

   return able_to_insert;
}  // end insert

template<class T>
bool LinkedList<T>::remove(int position)
{
   bool able_to_remove = (position >= 1) && (position <= item_count_);
   if (able_to_remove)
   {
      Node<T>* cur_ptr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         cur_ptr = head_ptr_; // Save pointer to node
         head_ptr_ = head_ptr_->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T>* prev_ptr = getNodeAt(position - 1);

         // Point to node to delete
         cur_ptr = prev_ptr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prev_ptr->setNext(cur_ptr->getNext());
      }  // end if

      // Return node to system
      cur_ptr->setNext(nullptr);
      delete cur_ptr;
      cur_ptr = nullptr;

      item_count_--;  // Decrease count of entries
   }  // end if

   return able_to_remove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const
{
    T dummy;
   // Check precondition
   bool able_to_get = (position >= 1) && (position <= item_count_);
   if (able_to_get)
   {
      Node<T>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
    else
        return dummy; //PROBLEM!!!! may return uninitialized object - will fix later with Exception Handling

}  // end getEntry



/************* PROJECT-SPECIFIC PUBLIC METHODS ************/

template<class T>
void LinkedList<T>::invert(){
      
   if(isEmpty() == true){ //incase of empty list
      return;
   }

   invertRest(head_ptr_);
   getNodeAt(item_count_)->setNext(nullptr); //sets last node to 0.
}

template<class T>
void LinkedList<T>::testFunc(){
   //std::cout << getNodeAt(2)->getItem() << " is item 2 \n\n";
   nodeSwap(head_ptr_, getNodeAt(3), getNodeAt(2));
}


template<class T>
void LinkedList<T>::selectionSort(){
   if(head_ptr_ == nullptr){ //incase of empty list.
      return;
   }
   head_ptr_ = recursiveSelectionSort(head_ptr_);
}




/************* PRIVATE ************/



template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= item_count_) );

   // Count from the beginning of the chain
   Node<T>* cur_ptr = head_ptr_;
   for (int skip = 1; skip < position; skip++)
      cur_ptr = cur_ptr->getNext();

   return cur_ptr;
}  // end getNodeAt



       /***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/

template<class T>
void LinkedList<T>::invertRest(Node<T>* current_first_ptr){
   
   head_ptr_ = nullptr;
   if (current_first_ptr->getNext() != nullptr){
      invertRest(current_first_ptr->getNext());
      current_first_ptr->getNext()->setNext(current_first_ptr);
   }
   else
      head_ptr_ = current_first_ptr;
   return;
}


//Swaps the head_of_list with min_node
template<class T>
void LinkedList<T>::nodeSwap(Node<T>* head_of_list, Node<T>* min_node, Node<T>* node_before_min_node){
   head_ptr_ = min_node;
   node_before_min_node->setNext(head_of_list);
   Node<T>* temp = min_node->getNext();
   min_node->setNext(head_of_list->getNext());
   head_of_list->setNext(temp);
}


template<class T>
Node<T>* LinkedList<T>::recursiveSelectionSort(Node<T>* current_first_ptr){
   //case of only single node
   if(current_first_ptr->getNext() == nullptr)
      return current_first_ptr;
   
   Node<T>* min_node = current_first_ptr; // will hold the minimum value.
   Node<T>* node_before_min_node = nullptr;
   Node<T>* cursor = nullptr;

   for(cursor = current_first_ptr; cursor->getNext() != nullptr; cursor = cursor->getNext()){
      if(cursor->getNext()->getItem() < min_node->getItem()){
         min_node = cursor->getNext();
         node_before_min_node = cursor;
      }
   } //end for
   if(min_node != current_first_ptr)
      nodeSwap(current_first_ptr, min_node, node_before_min_node);
      
   
   //recursion
   //if(min_node->getNext() != nullptr)
      //current_first_ptr->setNext(recursiveSelectionSort(min_node->getNext()));
   //current_first_ptr->setNext(recursiveSelectionSort(current_first_ptr->getNext()));
   min_node->setNext(recursiveSelectionSort(min_node->getNext()));

   //return current_first_ptr;
   return min_node;
}

//  End of implementation file.
