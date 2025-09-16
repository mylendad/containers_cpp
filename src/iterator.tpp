#ifndef ITERATOR_TPP
#define ITERATOR_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator()
    : current_(nullptr),
      tree_(nullptr)
// , nil_(nullptr)
{}

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator(BaseNode *node, Tree<T> *tree) {
  this->current_ = node;
  this->tree_ = tree;
}

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator(const TreeIterator &other) {
  this->current_ = other.current_;
  this->tree_ = other.tree_;
}

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator(TreeIterator &&other) noexcept
    : current_(other.current_) {
  other.current_ = nullptr;
}

template <typename T>
const s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator=(
    const TreeIterator &other) {
  if (this != &other) {
    this->current_ = other.current_;
    this->tree_ = other.tree_;
  }
  return *this;
}

// template <typename T>
// const s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator=(
//     const TreeIterator &other) {
//   if (this != &other) {
//     this->current_ = other.current_;
//     this->tree_ = other.tree_;
//   }
//   return *this;
// }

template <typename T>

typename s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator++() {
  this->current_ = tree_->TreeSuccessor(this->current_);

  return *this;
}

template <typename T>
// как это работает??
typename s21::Tree<T>::TreeIterator s21::Tree<T>::TreeIterator::operator++(
    int) {
  iterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>

typename s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator--() {
  this->current_ = tree_->TreeDescendant(this->current_);

  return *this;
}

template <typename T>

typename s21::Tree<T>::TreeIterator s21::Tree<T>::TreeIterator::operator--(
    int) {
  iterator temp = *this;
  --(*this);
  return temp;
}

}  // namespace s21

#endif  // ITERATOR_TPP