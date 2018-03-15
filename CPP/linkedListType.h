#ifndef linkedListType_H
#define linkedListType_H

//Definition of the node

template<class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link;
};

template<class Type>
class linkedListType
{
  friend ostream& operator<<(ostream&, const linkedListType<Type>&);
  //Overload the stream insertion operator.
public:
  const linkedListType<Type>& operator=(const linkedListType(Type>&);
  //Overload the assignment operator.
                                        
  void initializeList();
  //Function to initialize the list to an empty state.
  //Postcondition: first = NULL; last = NULL;
  //               count = 0.
  
  //Funtion to print the list
  //All items should be printed out to the screen 					
  void print();                                      
                                        
  bool isEmptyList();
  //Function to determine whether the list is empty.
  //Postcondition: Returns true if the list is empty;
  //               otherwise, returns false.
  
  int length();
  //Function to return the number of nodes in the
  //list.
  //Postcondition: The value of count is returned.
                                        
  void destroyList();
  //Function to delete all the nodes from the list.
  //Postcondition: first = NULL; last = NULL;
  //               count = 0.   
                                        
  Type front();
  //Function to return the first element of the list.
  //Precondition: The list must exist and nust not
  //be empty.
  //Postcondition: If the list is empty, then the 
  //               program terminates, otherwise, the first
  //               element of the list is returned.  
                                        
  Type back();
  //Function to return the last element of the list.
  //Precondition: The list must exist and nust not
  //be empty.
  //Postcondition: If the list is empty, then the 
  //               program terminates, otherwise, the last
  //               element of the list is returned.   
                                        
  bool search(const Type& searchItem);
  //Function to determine whether searchItem is in
  //the list.
  //Postcondition: Returns true if searchItem is found 
  //in the list; otherwise, returns false.  
                                        
  void insertFirst(const Type& newItem);
  //Function to insert newItem in the beginning
  //of the list.
  //Postcondition: first points to the new list,
  //               newItem is inserted at the beginning
  //               of the list, last points to the last node, 
  //               and count is incremented by 1.
                                        
  void insertLast(const Type& newItem);
  //Function to insert newItem at the end
  //of the list.
  //Postcondition: first points to the new list,
  //               newItem is inserted at the end
  //               of the list, last points to the last node 
  //               in the list, and count is incremented by 1.                                       
  
  void deleteNode(const Type& deleteItem);
  //Function to delete deleteItem from the list.
  //Postcondition: If found, the node containing
  //               deleteItem is deleted from the list, first points
  //               to the first node, last points to the last
  //               node of the updated list, and count is decremented 
  //               by one.  
                                        
  linkedListType();
  //Default constructor.
  //Initializes the list to an empty state.
  //Postcondition: first = NULL; last = NULL;
  //               count = 0.
                                        
  linkedListType(const linkedListType<Type>& otherList);
  //Copy constructor.
                                        
  ~linkedListType();
  //Destructor
  //Delete all the nodes from the list.
  //Postcondition: The list object is destroyed.
                                        
protected:
  int count;                           //variable to store the number of
                                       //elements in the list
  nodeType<Type> *first;               //pointer to the first node of
                                       //the list
  nodeType<Type> *last;                //pointer to the last node of
                                       //the list 
private:
  void copyList(const linkedListType<Type>& otherList);
  //Function to make a copy of otherList.
  //Postcondition: A copy of otherList  is created
  //               and assigned to the list.                                      
};

template<class Type>
linkedListType<Type>::linkedListType()
{
  first = NULL;
  last = NULL;
  count = 0; 
}
                                        
template<class Type>
void linkedListType<Type>::destroyList()
{
  nodeType<Type> *temp;                   //pointer to deallocate
                                          //the memory occupied by
                                          //the node
  
  while(first != NULL)                    //while there are nodes in the list
  {
    temp = first;                         //set temp to the current node
    first = first->link;                  //advance first to the next node    
    delete temp;                          //deallocate the memory occupied 
                                          //by temp
  }
  
  last = NULL;                            //initialize last to NULL; first has
                                          //already been set to NULL by the
                                          //while loop
  count = 0;
}

template <class Type>
void linkedListType<Type>::print()
{
	nodeType<Type>* temp = first;

	if (temp == NULL)
	{
		cout << "";
	}

	if (temp->link == NULL)
	{
		cout << temp->info;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->info;
			temp = temp->link;
			cout << ", ";
		}
	}
}
                                        
template<class Type>
void linkedListType<Type>::initializeList()
{
  destroyList();                          //if the list has any nodes,
                                          //delete them
}  

template<class Type>
ostream& operator<<(ostream& osObject, cosnt linkeListType<Type>& list)
{
  nodeType<Type> *current;                //pointer to traverse the list
  
  current = list.first;                   //set current so that it points
                                          //to the first node
  
  while(current != NULL)                  //while more data to output
  {
    osObject << current->info << " ";
    current = current->link;
  }
  
  return osObject;
}
                                        
template<class Type>
int linkedListType<Type>::length()
{
  return count;
}
                                        
template<class Type>
Type linkedListType<Type>::front()
{
  assert(last != NULL);                   
  return first->info;                       //return the info of the
                                            //first node
}

template<class Type>
Type linkedListType<Type>::back()
{
  assert(last != NULL);                   
  return back->info;                       //return the info of the
                                           //last node
}
                                        
template<class Type>
bool linkedListType<Type>::search(const Type& searchItem)
{
  modeType<Type> *current;                 //pointer to traverse the list
  bool found;
  
  current = first;                        //set current to point to the 
                                          //first node in the list
  found = false;                          //set found to false
  
  while(current != NULL && !found)        //search the list
  {
    if(current->info == searchItem)       //the item is found
       found = true;
    else
       current = current->link;           //make current point 
                                          //to the next node
  }
  
  return found;
}
                                        
template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
  nodeType<Type> *newNode;                 //pointer to create the new node
  
  newNode = new nodeType<Type>;            //create the new node
  
  assert(newNode != NULL);                 //if unable to allocate
                                           //memory, terminate 
                                           //the program
  
  newNode->info = newItem;                 //store newItem in the node
  
  newNode->link = first;                   //insert newnode before first
  
  first = newNode;                         //make first point to the actual 
                                           //first node
  
  if(last == NULL)                         //if the list was empty, newNode is
     last = newNode;                       //also the last node in the list
}  
                                        
template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
  nodeType<Type> *newNode;                 //pointer to create the new node
  
  newNode = new nodeType<Type>;            //create the new node
  
  assert(newNode != NULL);                 //if unable to allocate
                                           //memory, terminate 
                                           //the program
  
  newNode->info = newItem;                 //store newItem in the node
  
  newNode->link = NULL;                    //insert newnode before first
  
  if(first == NULL)                        //if the list is empty, newNode is
  {                                        //newNode is both the first and last one
     first = newNode;
     last = newNode;
     count++;
  } else
  {
    last->link = newNode;                  //insert newNode after last
    last = newNode;                        //make last point to the actual last node
    count++;
  }  
}
                                        
template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
  nodeType<Type> *current;                 //pointer to traverse the list
  nodeType<Type> *trailCurrent;            //pointer just before current
  bool found;
  
  if(first == NULL)                        //Case 1; list is empty
     cerr << "Cannot delete from an empty lsit." << endl;
  else
  {
    if(first->info == deleteNode)          //Case 2; the list is not empty.
    {                                      //The node to be deleted is the first one 
      current = first;
      first = first->link;
      count--;
      if(first == NULL)                    //list has only one node
         last = NULL;
      delete current;      
    }
    else                                   //search the list for the node with the given info
    {
      found = false;
      trailCurrent = first;                //set trailCurrento to point to the first node
      current = first->link;               //set current to point to the second node
      
      while(current != NULL && !found)
      {
        if(current->info != deleItem)
        {
           trailCurrent = current;
           current = currelnt->link; 
        } else
           found = true;        
      }
      
      if(found)                             //Case 3; if found, delete the node 
      {
         trailCurrent->link = current->link;
         count--;
        
         if(last == current)                //node to be deleted was the last node
            last = trailCurrent; 
         
         delete current; 
      } else
         cout << "Item to be  deleted is not in the list." << endl;
    }
  }    
}
                                        
template<class Type>
void linkedListType<Type>::~linkeListType()  //destructor
{    
  destroiList();
}
                                        
template<class Type>
void linkedListType<Type>::linkeListType(const linkedListType<Type>& otherList)  //copy constructor
{  
  first = NULL;
  copyList(otherList);
}
                                        
template<class Type>
const linkedListType<Type>& linkeListType::operator=(const linkedListType<Type>& otherList)  //copy constructor
{                                          
  if(this != &otherList)                    //avoid self-copy
    copyList(otherList);
  
  return *this;
}
#endif
