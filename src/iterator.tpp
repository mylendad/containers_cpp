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
      nil_(nullptr)
// , nil_(nullptr)
{}

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator(BaseNode *node,
                                         //  Tree<T> *tree
                                         BaseNode *&nil) {
  this->current_ = node;
  this->nil_ = nil;
}

template <typename T>
s21::Tree<T>::TreeIterator::TreeIterator(const TreeIterator &other) {
  this->current_ = other.current_;
  this->nil_ = other.nil_;
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
    this->nil_ = other.nil_;
  }
  return *this;
}

template <typename T>
const typename s21::Tree<T>::BaseNode &s21::Tree<T>::TreeIterator::operator*() {
  return this->current_;
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
  // this->current_ = tree_->TreeSuccessor(this->current_);

  BaseNode *x = this->get_node();
  BaseNode *y;
  BaseNode *z = x->right;
  BaseNode *min;
  if (x->right != nil_) {
    // this->current_ = TreeMinimum(x->right);

    while (z != this->nil_) {
      min = z;
      z = z->left;
    }
    this->current_ = min;

  } else {
    y = x->p;
    while (y != nil_ && x == y->right) {
      x = y;
      y = y->p;
    }
    this->current_ = y;
  }
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