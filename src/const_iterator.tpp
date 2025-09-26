#ifndef ITERATOR_TPP
#define ITERATOR_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

// template <typename T>
// typename s21::Tree<T>::BaseNode *s21::Tree<T>::const_iterator::TreeMinimum(
//     BaseNode *&node) const {
//   BaseNode *x;
//   BaseNode *min;
//   x = node;
//   while (x != this->nil_) {
//     min = x;
//     x = x->left;
//   }
//   return min;
// }

// template <typename T>
// typename s21::Tree<T>::BaseNode *s21::Tree<T>::const_iterator::TreeMaximum(
//     BaseNode *&node) const {
//   BaseNode *x;
//   BaseNode *max;
//   x = node;
//   while (x != this->nil_) {
//     max = x;
//     x = x->right;
//   }
//   return max;
// }

template <typename T>
typename s21::Tree<T>::BaseNode *s21::Tree<T>::const_iterator::TreeSuccessor(

    const BaseNode *&x) const {
  const BaseNode *y;
  if (x->right != nil_) {
    return TreeMinimum(x->right, this->nil_);
  }
  y = x->p;
  while (y != nil_ && x == y->right) {
    x = y;
    y = y->p;
  }
  return y;
}

template <typename T>
typename s21::Tree<T>::BaseNode *s21::Tree<T>::const_iterator::TreeDescendant(

    const BaseNode *&x) const {
  const BaseNode *y;
  if (x->left != nil_) {
    return TreeMaximum(x->left, this->nil_);
  }
  y = x->p;
  while (y != nil_ && x == y->left) {
    x = y;
    y = y->p;
  }
  return y;
}

template <typename T>
s21::Tree<T>::const_iterator::const_iterator()
    : current_(nullptr),
      nil_(nullptr)
// , nil_(nullptr)
{}

// template <typename T>
// s21::Tree<T>::const_iterator::const_iterator()
//     : current_(nullptr),
//       nil_(nullptr)
// // , nil_(nullptr)
// {}

template <typename T>
s21::Tree<T>::const_iterator::const_iterator(BaseNode *node,
                                             //  Tree<T> *tree
                                             const BaseNode *&nil) {
  this->current_ = node;
  this->nil_ = nil;
}

// template <typename T>
// s21::Tree<T>::const_iterator::const_iterator(BaseNode *node,
//                                            //  Tree<T> *tree
//                                            BaseNode *&nil) {
//   this->current_ = node;
//   this->nil_ = nil;
// }

template <typename T>
s21::Tree<T>::const_iterator::const_iterator(const const_iterator &other) {
  this->current_ = other.current_;
  this->nil_ = other.nil_;
}

template <typename T>
s21::Tree<T>::const_iterator::const_iterator(const_iterator &&other) noexcept
    : current_(other.current_) {
  other.current_ = nullptr;
}

template <typename T>
const typename s21::Tree<T>::const_iterator &
s21::Tree<T>::const_iterator::operator=(const const_iterator &other) const {
  if (this != &other) {
    this->current_ = other.current_;
    this->nil_ = other.nil_;
  }
  return *this;
}

template <typename T>
const typename s21::Tree<T>::reference s21::Tree<T>::const_iterator::operator*()
    const {
  if (current_ == nullptr || current_ == nil_) {
    throw std::out_of_range("Dereferencing end iterator");
  }
  return current_->item;
}

// template <typename T>
// const typename s21::Tree<T>::reference
// s21::Tree<T>::const_iterator::operator*()
//     const {
//   if (current_ == nullptr || current_ == nil_) {
//     throw std::out_of_range("Dereferencing end iterator");
//   }
//   return current_->item;
// }

template <typename T>
const typename s21::Tree<T>::value_type *
s21::Tree<T>::const_iterator::operator->() const {
  if (current_ == nullptr || current_ == nil_) {
    throw std::out_of_range("Accessing end iterator");
  }
  return &(current_->item);
}

// template <typename T>
// const typename s21::Tree<T>::value_type *
// s21::Tree<T>::const_iterator::operator->() {
//   if (current_ == nullptr || current_ == nil_) {
//     throw std::out_of_range("Accessing end iterator");
//   }
//   return &(current_->item);
// }

// template <typename T>
// const s21::Tree<T>::const_iterator &s21::Tree<T>::const_iterator::operator=(
//     const const_iterator &other) {
//   if (this != &other) {
//     this->current_ = other.current_;
//     this->tree_ = other.tree_;
//   }
//   return *this;
// }

template <typename T>

typename s21::Tree<T>::const_iterator &
s21::Tree<T>::const_iterator::operator++() const {
  this->current_ = TreeSuccessor(this->current_);

  // BaseNode *x = this->get_node();
  // BaseNode *y;
  // BaseNode *z = x->right;
  // BaseNode *min;
  // if (x->right != nil_) {
  //   // this->current_ = TreeMinimum(x->right);

  //   while (z != this->nil_) {
  //     min = z;
  //     z = z->left;
  //   }
  //   this->current_ = min;

  // } else {
  //   y = x->p;
  //   while (y != nil_ && x == y->right) {
  //     x = y;
  //     y = y->p;
  //   }
  //   this->current_ = y;
  // }
  return *this;
}

template <typename T>
// как это работает??
typename s21::Tree<T>::const_iterator s21::Tree<T>::const_iterator::operator++(
    int) const {
  iterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>

const typename s21::Tree<T>::const_iterator &const
s21::Tree<T>::const_iterator::operator--() const {
  this->current_ = TreeDescendant(this->current_);

  return *this;
}

template <typename T>

const typename s21::Tree<T>::const_iterator
s21::Tree<T>::const_iterator::operator--(int) const {
  iterator temp = *this;
  --(*this);
  return temp;
}

}  // namespace s21

#endif  // CONST_ITERATOR_TPP