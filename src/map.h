#ifndef MAP_H
#define MAP_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

template <typename Key, typename T, int AllowDuplicate = Map>
class map : public tree<std::pair<const Key, T>, AllowDuplicate> {
 public:
  // class MapIterator;

  // map Member type
  using iterator =
      typename tree<std::pair<const Key, T>, AllowDuplicate>::treeIterator;
  using typename tree<std::pair<const Key, T>, AllowDuplicate>::size_type;
  using key_type = Key;
  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using const_reference = const reference;
  using mapped_type = T;
  using const_iterator = const iterator;

  struct Node : public tree<std::pair<const Key, T>, AllowDuplicate>::BaseNode {
    Node() : tree<std::pair<const Key, T>, AllowDuplicate>::BaseNode() {}

    explicit Node(const value_type& val)
        : tree<std::pair<const Key, T>, AllowDuplicate>::BaseNode() {}
  };

  map() : tree<std::pair<const Key, T>, AllowDuplicate>() {};
  map(std::initializer_list<value_type> const& items)
      : tree<std::pair<const Key, T>, AllowDuplicate>(items) {}
  map(const map& m) : tree<std::pair<const Key, T>, AllowDuplicate>(m) {};
  map(map&& m);
  map& operator=(map& other);
  map& operator=(map&& other);

  // map Element access
  T& at(const Key& key);
  T& operator[](const Key& key);

  // Map Modifiers
  using tree<std::pair<const Key, T>, AllowDuplicate>::insert;
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);

  // Map Lookup
  bool contains(const Key& key);
};
}  // namespace s21

#include "map.tpp"

#endif  // MAP_H
