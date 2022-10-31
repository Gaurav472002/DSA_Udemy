// The node class for the  linked list
template <typename T>
class node {
  public:
    T data;
    node<T> *next;
    
    node() : next(nullptr) {}
    node(const T& item, node<T> *ptr = nullptr) :
      data(item), next(ptr) {}
};

// Linked list class
template <typename T>
class list {
  public:
    list() {
      head = tail = new node<T>();
    }
    list(const list<T>& other) = delete;
    list(list<T>&& other) = delete;
    ~list() {
      while (head->next != nullptr) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
      }
      delete head;
    }
    
    list<T>& operator=(const list<T>& other) = delete;
    list<T>& operator=(list<T>&& other) = delete;
    
    // Inner class iterator
    class iterator {
    friend class list;  // making the class friend so that inherited classes can use its fucntions
    private:
      node<T> *nodePtr;
      
      iterator(node<T> *newPtr) : nodePtr(newPtr) {}
    public:
      iterator() : nodePtr(nullptr) {} 

    
      bool operator!=(const iterator& itr) const {     // Overload for the comparison operator !=
        return nodePtr != itr.nodePtr;
      } 

      
      T& operator*() const {
        return nodePtr->next->data;   // Overload for the dereference operator *
      }

      
      iterator operator++(int) {
        iterator temp = *this;        // Overload for the postincrement operator ++
        nodePtr = nodePtr->next;
        return temp;
      }
    }; 
    
    iterator begin() const {
      return iterator(head);
    }
    
    iterator end() const {
      return iterator(tail);
    }
    
    iterator const_iterator (iterator position,const T& value) {  // Function for Const_iterator which enters node befor and after a giving position
      node<T>* newNode = new node<T>(value, position.nodePtr->next);
      if (position.nodePtr == tail) tail = newNode;
      position.nodePtr->next = newNode;
      return position;
    }

    iterator erase(iterator position) {  // function to delete the Node
      node<T> *toDelete = position.nodePtr->next;
      position.nodePtr->next = position.nodePtr->next->next;
      if (toDelete == tail) tail = position.nodePtr;
      delete toDelete;
      return position;
    }
  private:
    node<T>* head;
    node<T>* tail;
};
