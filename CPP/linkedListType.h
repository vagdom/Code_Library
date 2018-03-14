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
};
