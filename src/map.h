#ifndef MAP_H
#define MAP_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

template <typename Key, typename T>
class map : public Tree<std::pair<const Key, T>> {
 public:
  class MapIterator;

  // map Member type
  using iterator = typename Tree<std::pair<const Key, T>>::TreeIterator;
  using typename Tree<std::pair<const Key, T>>::size_type;
  using key_type = Key;
  using value_type = std::pair<const Key, T>;
  using reference = value_type &;
  using const_reference = const reference;
  using mapped_type = T;
  using const_iterator = const iterator;

  struct Node : public Tree<std::pair<const Key, T>>::BaseNode {
    Node() : Tree<std::pair<const Key, T>>::BaseNode() {}

    explicit Node(const value_type &val)
        : Tree<std::pair<const Key, T>>::BaseNode() {}
  };

 public:
  class MapIterator : public Tree<std::pair<const Key, T>>::TreeIterator {
   public:
    MapIterator() : Tree<std::pair<const Key, T>>::TreeIterator() {}
    MapIterator(Node *node, Node *&nil)
        : Tree<std::pair<const Key, T>>::TreeIterator(node) {}

   private:
    s21::map<Key, T>::Node *current_;
  };

  // map Member functions
  map() : Tree<std::pair<const Key, T>>() {};
  map(std::initializer_list<value_type> const &items)
      : Tree<std::pair<const Key, T>>(items) {}
  map(const map &m) : Tree<std::pair<const Key, T>>(m) {};
  map(map &&m);
  map &operator=(map &other);
  map &operator=(map &&other);

  // map Element access
  T &at(const Key &key);
  T &operator[](const Key &key);

  // Map Modifiers
  using Tree<std::pair<const Key, T>>::insert;
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

  // Map Lookup
  bool contains(const Key &key);
};
}  // namespace s21

#include "map.tpp"

#endif  // MAP_H