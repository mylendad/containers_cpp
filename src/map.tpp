#ifndef MAP_TPP
#define MAP_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "map.h"

namespace s21 {
template <typename Key, typename T, int AllowDuplicate>

std::pair<typename map<Key, T, AllowDuplicate>::iterator, bool>
map<Key, T, AllowDuplicate>::insert(const Key& key, const T& obj) {
  return this->insert(value_type(key, obj));
}

template <typename Key, typename T, int AllowDuplicate>
std::pair<typename map<Key, T, AllowDuplicate>::iterator, bool>
map<Key, T, AllowDuplicate>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<typename s21::map<Key, T, AllowDuplicate>::iterator, bool> result =
      insert(value_type(key, obj));
  if (result.second == false) {
    result.first->second = obj;
  }
  return result;
}

template <typename Key, typename T, int AllowDuplicate>
map<Key, T, AllowDuplicate>::map(map&& m) {
  *this = std::move(m);
}

template <typename Key, typename T, int AllowDuplicate>
map<Key, T, AllowDuplicate>& s21::map<Key, T, AllowDuplicate>::operator=(
    map& other) {
  Tree<std::pair<const Key, T>>::operator=(other);
  return *this;
}
template <typename Key, typename T, int AllowDuplicate>
s21::map<Key, T, AllowDuplicate>& s21::map<Key, T, AllowDuplicate>::operator=(
    map&& other) {
  Tree<std::pair<const Key, T>>::operator=(std::move(other));
  return *this;
}

// template <typename Key, typename T, int AllowDuplicate>
// std::pair<typename s21::map<Key, T, AllowDuplicate>::iterator, bool>
// map<Key, T, AllowDuplicate>::insert(const Key& key, const T& obj) {
//   return this->insert(value_type(key, obj));
// }

template <typename Key, typename T, int AllowDuplicate>
T& s21::map<Key, T, AllowDuplicate>::at(const Key& key) {
  std::pair<const Key, T> temp = {key, T()};
  std::pair<iterator, bool> result = this->find_node(temp);
  if (result.second == false) throw std::out_of_range("Key not exist.");
  return result.first->second;
}

// template <typename Key, typename T, int AllowDuplicate>
// T& s21::map<Key, T, AllowDuplicate>::operator[](const Key& key) {
//   std::pair<const Key, T> temp = {key, T()};
//   std::pair<iterator, bool> result =
//       this->find_node(temp);  // если не находит, в результат пишется отец!!!
//       а
//                               // temp что там во втором аргументе?
//   if (result.second == false) {
//     result.first = this->end();
//     result = this->insert(temp);
//   }
//   return result.first->second;  // куда
// }

template <typename Key, typename T, int AllowDuplicate>
T& s21::map<Key, T, AllowDuplicate>::operator[](const Key& key) {
  std::pair<iterator, bool> result = this->insert({key, T()});
  return result.first->second;
}

template <typename Key, typename T, int AllowDuplicate>
bool s21::map<Key, T, AllowDuplicate>::contains(const Key& key) {
  std::pair<const Key, T> temp = {key, T()};
  std::pair<iterator, bool> result = this->find_node(temp);
  return result.second;
}
}  // namespace s21

#endif  // MAP_TPP
