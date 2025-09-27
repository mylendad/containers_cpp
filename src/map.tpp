#ifndef MAP_TPP
#define MAP_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

namespace s21 {

template <typename Key, typename T>
s21::map<Key, T>::map(map&& m) {
  *this = std::move(m);
}

template <typename Key, typename T>
s21::map<Key, T>& s21::map<Key, T>::operator=(map& other) {
  Tree<std::pair<const Key, T>>::operator=(other);
  return *this;
}
template <typename Key, typename T>
s21::map<Key, T>& s21::map<Key, T>::operator=(map&& other) {
  Tree<std::pair<const Key, T>>::operator=(std::move(other));
  return *this;
}

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool> s21::map<Key, T>::insert(
    const Key& key, const T& obj) {
  return this->insert(value_type(key, obj));
}

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool>
s21::map<Key, T>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<typename s21::map<Key, T>::iterator, bool> result =
      insert(value_type(key, obj));
  if (result.second == false) {
    result.first->second = obj;
  }
  return result;
}

template <typename Key, typename T>
T& s21::map<Key, T>::at(const Key& key) {
  std::pair<const Key, T> temp = {key, T()};
  std::pair<iterator, bool> result = this->find(temp);
  if (result.second == false) throw std::out_of_range("Key not exist.");
  return result.first->second;
}

template <typename Key, typename T>
T& s21::map<Key, T>::operator[](const Key& key) {
  std::pair<const Key, T> temp = {key, T()};
  std::pair<iterator, bool> result = this->find(temp);
  if (result.second == false) this->insert(key, T());
  return result.first->second;
}

template <typename Key, typename T>
bool s21::map<Key, T>::contains(const Key& key) {
  std::pair<const Key, T> temp = {key, T()};
  std::pair<iterator, bool> result = this->find(temp);
  return result.second;
}
}  // namespace s21

#endif  // MAP_TPP