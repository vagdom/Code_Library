#ifndef orderedLinkedListType_H
#define orderedLinkedListType_H

template<class Type> 
class orderedLinkedListType: public linkedListType<Type>
{
public:
  //Function to determine whether searchItem is in the list.
  //Postcondition: Returns true if searchItem is found in
  //               the list; otherwise, it returns false.
  bool search(const Type& searchItem);
  
  //Function to insert newItem in the list.
  //Postcondition: first points to the new lsit and newItem is
  //               inserted at the proper place in the list, and
  //               count is incremented by 1.      
  void insertNode(const Type& newItem);
  
  //Function to delete deleteItem from the list.
  //Postcondition: If found, the node containing deleteItem
  //               is deleted from the list; first points
  //               to the first node of the new list, and 
  //               count is decremented by 1.
  //               If deleteItem is not in the list, an
  //               appropiate message is printed.
  void deleteNode(const Type& deleteItem);
};

template<class Type>
bool orderedLinkedListType<Type>::search(const Type& searchItem)
{
  bool found;
  nodeType<Type> *current;               //pointer to traverse the list
  
  found = false;                         //initialize found to false
  current = first;                       //start the search at the first node
  
  while(current != NULL && !found)
  {
    if(current->info >= searchItem)
      found = true;
    else
      current = current->link;
  }
  
  if(found)
    found = current (current->info == searchItem);    //test for equality
  
  return found;
}



#endid
