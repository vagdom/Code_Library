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

};
