#ifndef MAP_H
#define MAP_H

#include <string.h>

#include <initializer_list>
#include <iostream>
// #include <map>

// #include <map>

#include "tree.h"

// #define RED 0
// #define BLACK 1
// #define ROOT 0
// #define NIL 1

namespace s21 {

template <typename Key, typename T>
class Map : public Tree<std::pair<const Key, T>> {
 public:
  //  private:
  class MapIterator;

  // typedef MapIterator iterator;
  using iterator = typename Tree<std::pair<const Key, T>>::TreeIterator;
  using typename Tree<std::pair<const Key, T>>::size_type;
  using key_type = Key;
  using value_type = std::pair<const Key, T>;  // из-за такая не прокатит: const
                                               // Key //   value.first = key;
  //   value.second = obj;
  using mapped_type = T;
  // using Key = Key;

  // using typename TreeIterator<Key, T>::iterator;
  // using iterator = MapIterator;  //` or `BinaryTree::iterator`
  // as internal iterator of tree subclass;
  // defines the type for iterating through the
  // container using Node = typename
  // Tree<std::pair<const Key, T>>::TreeNode;

  // typedef Key key_type;
  // typedef T mapped_type;
  // typedef std::pair<const key_type, mapped_type> value_type;

  using Tree<std::pair<const Key, T>>::operator=;  //??

  using Tree<std::pair<const Key, T>>::Tree;  // constructors

  struct Node : public Tree<std::pair<const Key, T>>::BaseNode {
    value_type item;

    Node()
        : Tree<std::pair<const Key, T>>::BaseNode(),
          item(key_type(), mapped_type()) {
      this->right = nullptr;
      this->left = nullptr;
      this->p = nullptr;
    }
    explicit Node(const value_type &val)
        : Tree<std::pair<const Key, T>>::BaseNode() {
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
  class MapIterator : public Tree<std::pair<const Key, T>>::TreeIterator {
    // friend class MapConstIterator;

   private:  // remove
    s21::Map<Key, T>::Node *current_;

   public:
    MapIterator() : Tree<std::pair<const Key, T>>::TreeIterator() {}
    explicit MapIterator(Node *node)
        : Tree<std::pair<const Key, T>>::TreeIterator(node) {}
    // MapIterator(const MapIterator &other) : current_(other.current_) {}
    // MapIterator(MapIterator &&other) noexcept : current_(other.current_) {
    //   other.current_ = nullptr;
  };

 public:
  // operators
  // MapIterator &operator=(const MapIterator &other);
  // // typename Map<Key, T>::MapIterator &Map<Key, T>::MapIterator::operator+(
  // //     const MapIterator &other);
  // bool operator==(const MapIterator &other) const;
  // bool operator!=(const MapIterator &other) const;
  // T &operator[](const Key &key);
  Map() = default;
  // default constructor, creates empty Map

  Map(std::initializer_list<value_type> const &items)
      : Tree<std::pair<const Key, T>>(items) {}
  Map(const Map &m) = default;  // copy constructor
  Map(Map &&m) = default;       // moTe constructor
  ~Map() = default;             // destructor
  // // operator=(Map &&m)
  // // assignment operator oTerload for moTing object

  // std::pair<iterator, bool> insert(const Key &key, const T &obj); // dthy?

  using Tree<std::pair<const Key, T>>::insert;

  std::pair<iterator, bool> insert(const Key &key, const T &value) {
    return this->insert(value_type(key, value));  // BO вынести
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    std::pair<iterator, bool> result = this->insert(value_type(key, obj));
    // Node *x;
    if (result.second == false) {
      result.first->second = obj;
    }
    return result;
  }

  using Tree<std::pair<const Key, T>>::size;
  using Tree<std::pair<const Key, T>>::empty;
  using Tree<std::pair<const Key, T>>::create_node;
  using Tree<std::pair<const Key, T>>::erase;

  using Tree<std::pair<const Key, T>>::print_start;
  // size_type max_size;

  T &at(const Key &key);

  // T &at(const Key &key);

  T &operator[](const Key &key);
  // const T& at(const Key& key) const;

 private:
  Node create_node(const value_type &item);
  bool is_zero(size_type value);
};
}  // namespace s21

#include "map.tpp"

#endif  // MAP_H