#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 
using namespace std; 
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  vector<T> my_vec; 
  int my_size; 
  int ary; 
  PComparator my_comp; 

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error("top of an empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return my_vec[0]; 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error("popping an empty heap");

  }

  my_vec[0] = my_vec[my_size -1];
  my_vec.pop_back(); 
  my_size--; 
  int parent = 0; 
  while((parent * ary + 1) < my_size ){
    T the_parent = my_vec[parent]; 
    int best_child = parent * ary + 1; 

    for(int i = 0; i < ary; i++){
      if((parent * ary + i + 1 )< my_size && my_comp(my_vec[parent * ary + 1 + i], my_vec[best_child])){
        best_child = parent * ary + 1 + i; 
      }
    }

    T the_best = my_vec[best_child];
    if(my_comp(the_best, the_parent)){
      my_vec[parent] = the_best;
      my_vec[best_child] = the_parent; 
      parent = best_child; 
    }
    else{
      return; 
    }
  }

  return; 
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return (my_size == 0); 
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c )

{
  ary = m;
  my_comp = c;
  my_size = 0; 
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  my_size++; 
  my_vec.push_back(item);
  if(my_size == 1){
    return; 
  }
  int child = my_size - 1; 
  int parent = (child - 1) / ary; 
  while(my_comp(my_vec[child], my_vec[parent])){
    T temp = my_vec[child];
    my_vec[child] = my_vec[parent];
    my_vec[parent] = temp; 
    child = parent;
    parent = (child - 1)/ary; 
    if(child == 0){
      return; 
    }
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return my_size; 
}

#endif

