#ifndef MAP_H
#define MAP_H

#include <string.h>

#include <initializer_list>
#include <iostream>
#include <map>

#include "tree.h"

// #define RED 0
// #define BLACK 1
// #define ROOT 0
// #define NIL 1

namespace s21 {

template <typename K, typename T>
class Map : public Tree<std::pair<const K, T>> {
 public:
  //  private:
  class MapIterator;

  // typedef MapIterator iterator;
  using typename Tree<std::pair<const K, T>>::size_type;
  using key_type = K;
  using value_type = std::pair<const K, T>;
  using mapped_type = T;

  // using typename TreeIterator<K, T>::iterator;
  // internal class `MapIterator<K, T>` or `BinaryTree::iterator`
  // as internal iterator of tree subclass; defines the type for
  // iterating through the container
  // using Node = typename Tree<std::pair<const K, T>>::TreeNode;

  // typedef K key_type;
  // typedef T mapped_type;
  // typedef std::pair<const key_type, mapped_type> value_type;

  using Tree<std::pair<const K, T>>::operator=;  //??

  using Tree<std::pair<const K, T>>::Tree;  // constructors

  struct Node : public Tree<std::pair<const K, T>>::BaseNode {
    value_type item;

    Node()
        : Tree<std::pair<const K, T>>::BaseNode(),
          item(key_type(), mapped_type()) {
      this->right = nullptr;
      this->left = nullptr;
      this->p = nullptr;
    }
    explicit Node(const value_type &val)
        : Tree<std::pair<const K, T>>::BaseNode() {
      this->right = nullptr;
      this->left = nullptr;
      this->p = nullptr;
    }

    const key_type &get_key() const { return item.first; }
    mapped_type &get_value() { return item.second; }
  };

 private:
  Node *tree_root_ = nullptr;

  Node *tree_nil_ = nullptr;

  size_type size_ = 0;

 public:
  class MapIterator : public Tree<std::pair<const K, T>>::TreeIterator {
    // friend class MapConstIterator;

   private:
    s21::Map<K, T>::Node *current_;

   public:
    MapIterator() : Tree<std::pair<const K, T>>::TreeIterator() {}
    explicit MapIterator(Node *node)
        : Tree<std::pair<const K, T>>::TreeIterator(node) {}
    // MapIterator(const MapIterator &other) : current_(other.current_) {}
    // MapIterator(MapIterator &&other) noexcept : current_(other.current_) {
    //   other.current_ = nullptr;
  };

 public:
  // operators
  // MapIterator &operator=(const MapIterator &other);
  // // typename Map<K, T>::MapIterator &Map<K, T>::MapIterator::operator+(
  // //     const MapIterator &other);
  // bool operator==(const MapIterator &other) const;
  // bool operator!=(const MapIterator &other) const;
  // T &operator[](const K &key);
  Map() = default;
  // default constructor, creates empty Map

  Map(std::initializer_list<value_type> const &items)
      : Tree<std::pair<const K, T>>(items) {}
  Map(const Map &m) = default;  // copy constructor
  Map(Map &&m) = default;       // moTe constructor
  ~Map() = default;             // destructor
  // // operator=(Map &&m)
  // // assignment operator oTerload for moTing object

  using Tree<std::pair<const K, T>>::size;
  using Tree<std::pair<const K, T>>::empty;
  using Tree<std::pair<const K, T>>::create_node;
  using Tree<std::pair<const K, T>>::erase;

  using Tree<std::pair<const K, T>>::print_start;
  // size_type max_size;

 private:
  Node create_node(const value_type &item);
  bool is_zero(size_type value);
};
}  // namespace s21

#include "map.tpp"

#endif  // MAP_H