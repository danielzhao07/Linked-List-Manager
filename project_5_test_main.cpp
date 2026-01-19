#include <initializer_list>
#include <iostream>
#include <cassert>

#include "project_5.cpp"

int main() {

  Set A{};
  std::cout << "A: " << A << std::endl;


  A.insert( 1 );
  A.insert( 2 );
  A.insert( 3 );
 
  Set B{2,3,4};
  Set C{3,3,4,4,4,5,5,5,5};

  std::cout << std::endl << "--- Set initialization / insert ---" << std::endl;
  std::cout << "A: " << A << std::endl;
  std::cout << "B: " << B << std::endl; 
  std::cout << "C: " << C << std::endl;

  std::cout << std::endl << "--- size / empty ---" << std::endl;
  std::cout << "size of A:  " << A.size()  << std::endl; 
  std::cout << "is A empty: " << A.empty() << std::endl; 

  assert(A.find(3) != nullptr);
  assert(A.find(4) == nullptr);

  std::cout << std::endl << "--- erase / instert ---" << std::endl;
  std::cout << "erase 3: " << A.erase(3) << std::endl; 
  std::cout << "erase 3: " << A.erase(3) << std::endl;
  std::cout << "A:       " << A << std::endl;      

  int insert_values[5]{1,2,3,4,5};
  std::cout << "insert [1,2,3]: " << A.insert(insert_values, 0, 3) << std::endl;
  std::cout << "A:       " << A << std::endl;   

  std::cout << std::endl << "--- Copy constructor / clear ---" << std::endl;
  Set *D { new Set {A} };
  std::cout << "A:       " <<  A << std::endl;
  std::cout << "B:       " <<  B << std::endl;
  std::cout << "D:       " << *D << std::endl;
  *D = B;
  std::cout << "D = B:   " << *D << std::endl;
  D->clear();
  std::cout << "D clear: " << *D << std::endl;
  assert(D->empty() == true);
  delete D;
  D = nullptr;

  std::cout << std::endl << "--- Set Operations ---" << std::endl;
  std::cout << "A union B: " << ( A | B ) << std::endl;
  std::cout << "A intersect B: " << ( A & B ) << std::endl;
  std::cout << "Symmetric difference of A and B: " << ( A ^ B ) << std::endl;
  std::cout << "A minus B: " << ( A - B ) << std::endl;
  std::cout << std::endl;

  std::cout << "A union C: " << ( A | C ) << std::endl;
  std::cout << "A intersect C: " << ( A & C ) << std::endl;
  std::cout << "Symmetric difference of A and C: " << ( A ^ C ) << std::endl;
  std::cout << "A minus C: " << ( A - C ) << std::endl;
  std::cout << std::endl;
 
  std::cout << "B union C: " << ( B | C ) << std::endl;
  std::cout << "B intersect C: " << ( B & C ) << std::endl;
  std::cout << "Symmetric difference of B and C: " << ( B ^ C ) << std::endl;
  std::cout << "B minus C: " << ( B - C ) << std::endl;
  std::cout << std::endl;

  std::cout << A.merge(B) << std::endl;
  std::cout << A << std::endl;
  std::cout << B << std::endl;

  return 0;
}