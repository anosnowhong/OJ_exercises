#include <iostream>

template<typename Object>
class mList{
 public:
  mList(){}
  mList(const mList& rhs){}
  ~mList(){}
  mList(mList&& rhs){}
  mList& operator= (List & rhs){}

  int size() const { return theSize; }
  bool empty() const { return size()==0; }

 private:
  struct Node{
    Object data;
    Node* next;
  };

};
