#include <initializer_list>
#include <iostream>
#include <cassert>


class Set;
class Node;
std::ostream &operator<<( std::ostream &out, Set const &rhs );
 
class Set {
  public:
    Set( std::initializer_list<int> initial_values );
   ~Set();
 
    Set( Set const &orig );
    Set( Set      &&orig );
 
    Set &operator=( Set const &orig );
    Set &operator=( Set      &&orig );
 
    bool        empty() const;
    std::size_t size()  const;
 
    void clear();
 
    Node *find( int const &item ) const;
 
    std::size_t insert( int const &item );
 
    std::size_t insert( int         const array[],
                        std::size_t const begin,
                        std::size_t const end );
 
    std::size_t erase( int const &item );
 
    std::size_t merge( Set &other );

 
    // Set operations
    Set &operator|=( Set const &other );
    Set &operator&=( Set const &other );
    Set &operator^=( Set const &other );
    Set &operator-=( Set const &other );
 
    Set operator|( Set const &other ) const;
    Set operator&( Set const &other ) const;
    Set operator^( Set const &other ) const;
    Set operator-( Set const &other ) const;
 
    // Returns 'true' if the 'other' set
    // is a subset of 'this' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator<=( Set const &other ) const;
    bool operator>=( Set const &other ) const;
    bool operator<( Set const &other ) const;
    bool operator>( Set const &other ) const;
 
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
   
  private:
    Node *p_head_;
    std::size_t size_;
 
  friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};


class Node {
  public:
    Node( int new_value, Node *new_next );
    int   value() const;
    Node *next()  const;
 
  private:
    int   value_;
    Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  
  ///////////////////////////////
 /// Node class Definition   ///

  
}
 
int Node::value() const {
  return value_;
}

Node *Node::next() const {
  return next_;
}


  ///////////////////////////////
 /// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set( std::initializer_list<int> initial_values):
p_head_{nullptr},
size_{0}{
// Destructor
Set::~Set() {
  clear();
}
 
// Copy constructor
Set::Set( Set const &orig ):
  p_head_{nullptr},
  size_{0}{
    for (Node *ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next()){
      insert(ptr->value());
    }
  }

g ):
  p_head_{nullptr},
  size_{0}{
    std::swap(p_head_, orig.p_head_);
    std::swap(size_,orig.size_);
  }

// Copy assignment
Set &Set::operator=( Set const &orig ) {


    clear();
    for (Node *ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next()){
      insert(ptr->value());
    }

    return *this;
  }
}
// Move assignment
Set &Set::operator=( Set &&orig ) {
  if ( this == &orig ) {
        return *this;
  }
    std::swap(p_head_, orig.p_head_);
    std::swap(size_, orig.size_);
    return *this;
}
// Empty
bool Set::empty() const {
  return (p_head_ == nullptr);
}

// Size
std::size_t Set::size() const {
  return size_;
}

void Set::clear() {
  while (!empty()){
    Node *p_old_head{p_head_};


    delete p_old_head;
    p_old_head = nullptr;
    size_ = 0;
  }
}
 
// Find
Node *Set::find( int const &item ) const {

  Node *current_node{p_head_};
(current_node -> value() == item){
      return current_node;
    }

    current_node = current_node -> next();
  }
  
  return nullptr;
}
 
// Insert the item into the set
std::size_t Set::insert( int const &item ) {
  if (find(item) != nullptr){
    return 0;
  } else {

    ++size_;
    return 1;
  }
  
}
 
// Insert all the items in the array
std::size_t Set::insert( int         const array[],
                         std::size_t const begin,
                         std::size_t const end ) {


std::size_t Set::insert( int         const array[],
    count += insert(array[i]);
  }

  return count;
}

 
// Remove the item from the set and
// return the number of items removed.
std::size_t Set::erase( int const &item ) {
  Node *ptr = find(item);
  if (ptr == nullptr){
    return 0;
    --size_;
    return 1;
  }

  for (Node *prev{p_head_}; prev != ptr; prev = prev->next()){
      if (prev->next() == ptr){
          prev->next_ = ptr->next();
          delete ptr;
          --size_;
          return 1;
        }
      }

  return 0;
}
 
// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets. 
std::size_t Set::merge( Set &other ) {
  std::size_t count{0};

    Node *ptr{other.p_head_};

_};
        p_head_ = ptr;
        ptr->next_ = p_old_head;

        other.p_head_ = temp;

        ++size_;
        --other.size_;
        ++count;
      } else if (find(ptr->value()) == nullptr) {
        
        for (Node *prev{other.p_head_}; prev != ptr; prev = prev->next()){
          if (prev->next() == ptr){
            prev->next_ = ptr->next();
            break;
          }
        }

        Node *p_old_head{p_head_};
        p_head_ = ptr;
        ptr->next_ = p_old_head;
        
        ++size_;
        --other.size_;
        ++count;
      }

      
      ptr = temp;
    }

  return count;
}

  //////////////////////
 /// Set operations ///
//////////////////////
Set &Set::operator|=( Set const &other ) {
  for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
    insert(ptr->value());
  }
  
  return *this;
}
 
Set &Set::operator&=( Set const &other ) {
  Node *ptr{p_head_};

    if (other.find(ptr->value()) == nullptr){
      erase(ptr->value());
    }

    ptr = temp;
  }

  return *this;
}
 
et &Set::operator^=( Set const &other ) {
  for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
    if (find(ptr->value()) != nullptr){
      erase(ptr->value());
    } else {
      insert(ptr->value());
    }
  }
  
  return *this;
}
 
Set &Set::operator-=( Set const &other ) {
  for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
      erase(ptr->value());
 }
  
  return *this;
}
 
Set Set::operator|( Set const &other ) const {
  Set result{*this};

  result |= other;

  return result;
}

Set Set::operator&( Set const &other ) const {
  Set result{*this};

  result &= other;

  return result;

 
Set Set::operator^( Set const &other ) const {
  Set result{*this};

  result ^= other;

  return result;

 
Set Set::operator-( Set const &other ) const {
  Set result{*this};

  result -= other;

  return result;


 
// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
ool Set::operator>=( Set const &other ) const {
  
  for (Node *ptr{other.p_head_}; ptr != nullptr; ptr = ptr->next()){
    if (find(ptr->value()) == nullptr){
      return false;
    }
  }
  
  return true;
 
bool Set::operator>( Set const &other ) const {
  
  return (*this >= other && (this->size() != other.size()));
}
 
bool Set::operator<( Set const &other ) const {
  return other > *this;
}
 
bool Set::operator==( Set const &other ) const {
  return ((*this >= other) && (other >= *this));
}
 
ool Set::operator!=( Set const &other ) const {
  return !(*this == other);
}

 ////////////////////////////////////////////
 /// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
 out << "{";
  if ( !rhs.empty() ) {
    out << rhs.p_head_->value();   
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
     out << ", " << ptr->value();
    }
  }
  out << "}";
  
//   Set my_data_1{ 1, 3, 5, 2, 4, 8, 5, 3, 1 };
//   // This should print '6'
//   std::cout << my_data_1.size() << std::endl;
//   // This should print '0' ('false')
//   std::cout << my_data_1.empty() << std::endl;
//   assert( my_data_1.find( 0 ) == nullptr );
//   assert( my_data_1.find( 1 )->value() == 1 );
//   assert( my_data_1.find( 5 )->value() == 5 );
//   assert( my_data_1.find( 6 ) == nullptr );
//   assert( my_data_1.find( 8 )->value() );

//   return 0;
// }