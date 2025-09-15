#ifndef S21_ITER_H
#define S21_ITER_H

#include <iostream>

#include "map.h"

namespace s21 {
template <typename K, typename T>
typename map<K, T>::MapIterator& map<K, T>::MapIterator::operator=(
    const MapIterator& other) {
  if (this != &other) {
    current_ = other.current_;
  }
  return *this;
}

// template <typename K, typename T>
// typename map<K, T>::MapIterator& map<K, T>::MapIterator::operator+(
//     const MapIterator& other) {

//   return *this;
// }

template <typename K, typename T>
bool map<K, T>::MapIterator::operator==(const MapIterator& other) const {
  return current_ == other.current_;
}

template <typename K, typename T>
bool map<K, T>::MapIterator::operator!=(const MapIterator& other) const {
  return current_ != other.current_;
}
}  // namespace s21
#endif  // S21_ITER_H
