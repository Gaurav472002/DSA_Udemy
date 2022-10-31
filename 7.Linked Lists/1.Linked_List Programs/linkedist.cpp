#include <iostream>
#include "list.h"

int main(int argc,const char* argv[])
{
  list<int> v;
  
  v.const_iterator(v.end(),2);
  v.const_iterator(v.end(),4);
  v.const_iterator(v.end(),5);
  
  auto iter = v.begin(); // pointing to the head of the list

  iter = v.const_iterator(iter, 1); // Insert 1 before 2
  iter++; // Points to 2
  v.const_iterator(iter++,3); // Insert 3 before 2, advance to 4
  iter++; // Points to 5
  v.const_iterator(iter,10); // Inserting 10 before 5 using the const_iterator_function
    
  iter = v.begin();
  iter++; // Points to 3
  v.erase(iter); // Erase 3

  iter=v.end();

  v.const_iterator(iter,20);  // Inserting 20 after 5 using the const_iterator_function
  iter++;
  
  for(auto itr = v.begin();itr != v.end();itr++) // printing the list
    std::cout << *itr << std::endl;
    
  return 0;
}