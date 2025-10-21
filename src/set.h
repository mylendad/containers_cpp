#ifndef SET_H
#define SET_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

template <typename Key, int AllowDuplicate = Set>
class set : public tree<Key, AllowDuplicate> {
 public:
  //   class SetIterator;

  // set Member type
  using iterator = typename tree<Key, AllowDuplicate>::treeIterator;
  using typename tree<Key, AllowDuplicate>::size_type;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const reference;
  using mapped_type = Key;
  using const_iterator = const iterator;

  struct Node : public tree<Key, AllowDuplicate>::BaseNode {
    Node() : tree<Key, AllowDuplicate>::BaseNode() {}

    explicit Node(const value_type& val)
        : tree<Key, AllowDuplicate>::BaseNode() {}
  };

  //  public:
  //   class SetIterator : public tree<Key, AllowDuplicate>::treeIterator {
  //    public:
  //     SetIterator() : tree<Key, AllowDuplicate>::treeIterator() {}
  //     SetIterator(Node* node, Node*& nil)
  //         : tree<Key, AllowDuplicate>::treeIterator(node) {}

  //    private:
  //     s21::set<Key, AllowDuplicate>::Node* current_;
  //   };

  // set Member functions
  set() : tree<Key, AllowDuplicate>() {};
  set(std::initializer_list<value_type> const& items)
      : tree<Key, AllowDuplicate>(items) {}
  set(const set& m) : tree<Key, AllowDuplicate>(m) {};
  set(set&& m);
  set& operator=(set& other);
  set& operator=(set&& other);

  // set Element access
  // Key &at(const Key &key);s
  // Key &operator[](const Key &key);

  // Map Modifiers
  // std::pair<iterator, bool> insert(const value_type &value);
  // using tree<Key, AllowDuplicate>::insert;
  // std::pair<iterator, bool> insert(const Key &key, const Key &obj);
  // std::pair<iterator, bool> insert_or_assign(const Key &key, const Key &obj);

  // Map Lookup
  iterator find(const Key& key);
  bool contains(const Key& key);
};
}  // namespace s21

#include "set.tpp"

#endif  // SET_H