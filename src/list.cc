#include <initializer_list>
#include <iostream>
#include <list>

template <typename T>
class s21_list {
 public:
  using value_type = T;

  //   s21_list();  // default constructor, creates empty

  // listlist(size_type n); // parameterized constructor, creates the list of
  // size n`

  //   s21_list(std::initializer_list<T> const &items);  //`initializer list
  // constructor, creates list initizialized using std::initializer_list`<T>

  // list(const list &l); // `copy constructor`

  // list(list &&l); // `move constructor`

  // ~list(); // `destructor`

  // operator=(list &&l); // assignment operator overload for moving object

  // const_reference front(); // `access the first element`
  // const_reference back(); // `access the last element

  // iterator begin(); // `returns an iterator to the beginning`
  // iterator end(); // `returns an iterator to the end

  // bool empty(); // `checks whether the container is empty`size_type
  // size()`returns the number of elements` size_type max_size(); // `returns
  // the maximum possible number of elements

  // void clear(); // `clears the contents`
  // iterator insert(iterator pos, const_reference value); // `inserts element
  // into concrete pos and returns the iterator that points to the new element`
  // void erase(iterator pos); // `erases element at pos`
  // void push_back(const_reference value); // `adds an element to the end`
  // void pop_back(); // `removes the last element`
  // void push_front(const_reference value); // `adds an element to the head`
  // void pop_front(); // `removes the first element`
  // void swap(list& other); // `swaps the contents`
  // void merge(list& other); // `merges two sorted lists`
  // void splice(const_iterator pos, list& other); // `transfers elements from
  // list other starting from pos` void reverse(); // `reverses the order of the
  // elements` void unique(); // `removes consecutive duplicate elements` void
  // sort(); // `sorts the elements

  struct Node {
    value_type value = 0;
    //   T pointer_value*;
    Node *pointer_next = nullptr;
  };

  std::iterator begin() { return this->begin(); }

  s21_list(std::initializer_list<value_type> const &items) {
    const value_type *begin;
    begin = items.begin();

    const value_type *current = begin;
    int size = (int)items.size();
    Node *node_arr[size];
    node_arr[0] = new Node();
    node_arr[0]->value = *current;

    for (int i = 1; i < size; ++i) {
      // std::cout << "i" << i << "i" << std::endl;
      std::cout << size << std::endl;
      current++;
      node_arr[i] = new Node();  // инициализация
      // std::cout << "i" << i << "i" << std::endl;
      // std::cout << "1" << std::endl;
      node_arr[i]->value = *current;
      // std::cout << "i-1" << node_arr[i - 1]->pointer_next <<
      // &node_arr[i]->value
      // << std::endl;
      // std::cout << "1" << std::endl;

      node_arr[i - 1]->pointer_next = node_arr[i];  // opaa
      // std::cout << "i" << i << "i" << std::endl;
      // std::cout << "2" << std::endl;
      // std::cout << "i" << i << "i" << std::endl;
    }
    // std::cout << "че" << std::endl;
    // node.pointer_next = nullptr;
  }
};

int main() {
  std::list<int> my_list{1, 2, 3, 4, 5};
  s21_list<int> my_list_2{1, 2, 3, 4, 5};
  // for (int i = 0; i < 5; i++){
  //     std::cout << my_list[i] << std::cout;
  // }
  // std::list<int>::iterator iter = my_list.begin();
  // ++iter;
  // std::cout << *iter << std::endl;
}
