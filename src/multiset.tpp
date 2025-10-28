#ifndef multiset_TPP
#define multiset_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "multiset.h"

namespace s21
{

  template <typename Key, int AllowDuplicate>
  s21::multiset<Key, AllowDuplicate>::multiset(multiset &&m)
  {
    *this = std::move(m);
  }

  template <typename Key, int AllowDuplicate>
  s21::multiset<Key, AllowDuplicate> &
  s21::multiset<Key, AllowDuplicate>::operator=(multiset &other)
  {
    tree<Key, AllowDuplicate>::operator=(other);
    return *this;
  }
  template <typename Key, int AllowDuplicate>
  s21::multiset<Key, AllowDuplicate> &
  s21::multiset<Key, AllowDuplicate>::operator=(multiset &&other)
  {
    tree<Key, AllowDuplicate>::operator=(std::move(other));
    return *this;
  }

  template <typename Key, int AllowDuplicate>
  typename s21::multiset<Key, AllowDuplicate>::iterator
  s21::multiset<Key, AllowDuplicate>::find(const Key &key)
  {
    // Node node = Node();
    std::pair<typename s21::multiset<Key, AllowDuplicate>::iterator, bool>
        result =
            // std::make_pair(iterator(node, this->tree_nil_, this->end_node_),
            // false);
        result = this->find_node(key);
    return result.first;
  }

  // template <typename Key, int AllowDuplicate>
  // std::pair<typename s21::multiset<Key, AllowDuplicate>::iterator, bool>
  // s21::multiset<Key, AllowDuplicate>::insert_or_assign(const Key &key, const
  // Key &obj)
  // {
  //     std::pair<typename s21rator, bool> result =
  //         insert(value_type(key, obj));
  //     if (result.second == false)
  //     {
  //         result.first->second = obj;
  //     }
  //     return result;
  // }

  // template <typename Key, int AllowDuplicate>
  // Key &s21::multiset<Key, AllowDuplicate>::at(const Key &key)
  // {
  //     std::<Key>temp = {key, Key()};
  //     std::pair<iterator, bool> result = this->find_node(temp);
  //     if (result.second == false)
  //         throw std::out_of_range("Key not exist.");
  //     return result.first->second;
  // }

  // template <typename Key, int AllowDuplicate>
  // Key &s21::multiset<Key, AllowDuplicate>::operator[](const Key &key)
  // {
  //     Key temp = {key, Key()};
  //     std::pair<iterator, bool> result =
  //         this->find_node(temp); // если не находит, в результат пишется
  //         отец!!! а temp
  //                           // что там во втором аргументе?
  //     if (result.second == false)
  //     {
  //         result.first = this->end();
  //         result = this->insert(temp);
  //     }
  //     return result.first->second; // кудаs
  // }

  // template <typename Key, int AllowDuplicate>
  // Key& s21::multiset<Key, AllowDuplicate>::operator[](const Key& key) {
  //   std::pair<iterator, bool> result = this->insert({key, Key()});
  //   return result.first->second;
  // }

  template <typename Key, int AllowDuplicate>
  bool s21::multiset<Key, AllowDuplicate>::contains(const Key &key)
  {
    Key temp = {key};
    std::pair<iterator, bool> result = this->find_node(temp);
    return result.second;
  }
} // namespace s21

#endif // multiset_TPP