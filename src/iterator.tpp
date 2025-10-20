#ifndef CONST_ITERATOR_TPP
#define CONST_ITERATOR_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21
{

  template <typename T>
  s21::Tree<T>::TreeIterator::TreeIterator()
      : current_(nullptr), nil_(nullptr), end_node_(nullptr) {}

  template <typename T>
  s21::Tree<T>::TreeIterator::TreeIterator(BaseNode *node, BaseNode *&nil,
                                           BaseNode *&end_node)
  {
    this->current_ = node;
    this->nil_ = nil;
    this->end_node_ = end_node;
  }

  template <typename T>
  s21::Tree<T>::TreeIterator::TreeIterator(const TreeIterator &other)
  {
    this->current_ = other.current_;
    this->nil_ = other.nil_;
    this->end_node_ = other.end_node_;
  }

  template <typename T>
  s21::Tree<T>::TreeIterator::TreeIterator(TreeIterator &&other) noexcept
      : current_(other.current_)
  {
    other.current_ = nullptr;
  }

  template <typename T>
  const typename s21::Tree<T>::TreeIterator &
  s21::Tree<T>::TreeIterator::operator=(const TreeIterator &other)
  {
    if (this != &other)
    {
      this->current_ = other.current_;
      this->nil_ = other.nil_;
      this->end_node_ = other.end_node_;
    }
    return *this;
  }

  template <typename T>
  bool s21::Tree<T>::TreeIterator::operator==(const TreeIterator &other) const
  {
    bool result = false;
    if (this->current_ == other.current_)
    {
      result = true;
    }
    return result;
  }

  template <typename T>
  bool s21::Tree<T>::TreeIterator::operator!=(const TreeIterator &other) const
  {
    bool result = false;
    if (this->current_ != other.current_)
    {
      result = true;
    }
    return result;
  }

  template <typename T>
  typename s21::Tree<T>::reference s21::Tree<T>::TreeIterator::operator*()
  {
    if (current_ == nullptr || current_ == nil_)
    {
      throw std::out_of_range("Dereferencing end iterator");
    }
    return current_->item;
  }

  template <typename T>
  const typename s21::Tree<T>::reference s21::Tree<T>::TreeIterator::operator*()
      const
  {
    if (current_ == nullptr || current_ == nil_)
    {
      throw std::out_of_range("Dereferencing end iterator");
    }
    return current_->item;
  }

  template <typename T>
  typename s21::Tree<T>::value_type *s21::Tree<T>::TreeIterator::operator->()
  {
    if (current_ == nullptr || current_ == nil_)
    {
      throw std::out_of_range("Accessing end iterator");
    }
    return &(current_->item);
  }

  template <typename T>
  const typename s21::Tree<T>::value_type *
  s21::Tree<T>::TreeIterator::operator->() const
  {
    if (current_ == nullptr || current_ == nil_)
    {
      throw std::out_of_range("Accessing end iterator");
    }
    return &(current_->item);
  }

  // template <typename T>
  // typename s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator++()
  // {
  //   if (TreeSuccessor(this->current_) == this->end_node_)
  //     return *this; // change
  //   this->current_ = TreeSuccessor(this->current_);
  //   return *this;
  // }

  template <typename T>
  typename s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator++()
  {
    if (this->current_ == (this->end_node_))
    {
      *this = iterator(this->end_node_->p, this->nil_, this->end_node_);
    }
    else
    {
      // if (TreeSuccessor(this->current_) == this->end_node_)
      // {
      //   return *this; // change
      // }
      this->current_ = TreeSuccessor(this->current_);
    }
    return *this;
  }

  template <typename T>
  typename s21::Tree<T>::TreeIterator s21::Tree<T>::TreeIterator::operator++(
      int)
  {
    if (TreeSuccessor(this->current_) == this->end_node_)
      return *this; // change
    iterator temp = *this;
    ++(*this);
    return temp;
  }

  template <typename T>
  typename s21::Tree<T>::TreeIterator &s21::Tree<T>::TreeIterator::operator--()
  {
    if (this->current_ == (this->end_node_))
    {
      *this = iterator(this->end_node_->p, this->nil_, this->end_node_);
    }
    else
    {
      if (TreeDescendant(this->current_) == this->nil_)
      {
        return *this; // change
      }
      this->current_ = TreeDescendant(this->current_);
    }
    return *this;
  }

  template <typename T>

  typename s21::Tree<T>::TreeIterator s21::Tree<T>::TreeIterator::operator--(
      int)
  {
    if (TreeDescendant(this->current_) == this->nil_)
    {
      return *this; // change
      // throw std::out_of_range("Going beyond the tree");
    }
    iterator temp = *this;
    --(*this);
    return temp;
  }

  template <typename T>
  typename s21::Tree<T>::BaseNode *s21::Tree<T>::TreeIterator::TreeSuccessor(
      BaseNode *x)
  {
    BaseNode *y;
    BaseNode *current = x;

    if (current->right != nil_)
    {
      return TreeMinimum(current->right, this->nil_);
    }
    y = current->p;
    while (y != nil_ && current == y->right)
    {
      current = y;
      y = y->p;
    }
    return y;
  }

  template <typename T>
  typename s21::Tree<T>::BaseNode *s21::Tree<T>::TreeIterator::TreeDescendant(

      BaseNode *x)
  {
    BaseNode *y;
    BaseNode *current = x;
    if (x->left != nil_)
    {
      return TreeMaximum(current->left, this->nil_);
    }
    y = current->p;
    while (y != nil_ && current == y->left)
    {
      current = y;
      y = y->p;
    }
    return y;
  }

} // namespace s21

#endif // CONST_ITERATOR_TPP