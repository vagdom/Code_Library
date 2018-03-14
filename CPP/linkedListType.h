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
