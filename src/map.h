#ifndef MAP_H
#define MAP_H

#include <string.h>

#include <initializer_list>
#include <iostream>
#include <map>

// #include <map>

#include "tree.h"

// #define RED 0
// #define BLACK 1
// #define ROOT 0
// #define NIL 1

namespace s21 {

template <typename Key, typename T>
class Map : public Tree<std::pair<const Key, T>> {
 public:
  //  private:
  class MapIterator;

  // typedef MapIterator iterator;
  using iterator = typename Tree<std::pair<const Key, T>>::TreeIterator;
  using typename Tree<std::pair<const Key, T>>::size_type;
  using key_type = Key;
  using value_type = std::pair<const Key, T>;
  using mapped_type = T;
  // using Key = Key;

  // using typename TreeIterator<Key, T>::iterator;
  // using iterator = MapIterator;  //` or `BinaryTree::iterator`
  // as internal iterator of tree subclass;
  // defines the type for iterating through the
  // container using Node = typename
  // Tree<std::pair<const Key, T>>::TreeNode;

  // typedef Key key_type;
  // typedef T mapped_type;
  // typedef std::pair<const key_type, mapped_type> value_type;

  // using Tree<std::pair<const Key, T>>::Tree;  // constructors

  // using Tree<std::pair<const Key, T>>::operator=;  //??

  // Map &operator=(const Map &other) = default;
  // Map &operator=(Map &&other) noexcept = default;

  struct Node : public Tree<std::pair<const Key, T>>::BaseNode {
    // value_type item;  // это надо?
    // using Tree<std::pair<const Key, T>>::BaseNode::item;

    Node() : Tree<std::pair<const Key, T>>::BaseNode() {  //,
      // item(key_type(), mapped_type()) {
      // this->right = nullptr;
      // this->left = nullptr;
      // this->p = nullptr;
    }
    explicit Node(const value_type &val)
        : Tree<std::pair<const Key, T>>::BaseNode() {
      // this->right = nullptr;
      // this->left = nullptr;
      // this->p = nullptr;
    }
  };

 public:
  class MapIterator : public Tree<std::pair<const Key, T>>::TreeIterator {
   private:  // remove
    s21::Map<Key, T>::Node *current_;

   public:
    MapIterator() : Tree<std::pair<const Key, T>>::TreeIterator() {}
    explicit MapIterator(Node *node)
        : Tree<std::pair<const Key, T>>::TreeIterator(node) {}
  };

 public:
  // operators
  // MapIterator &operator=(const MapIterator &other);
  // // typename Map<Key, T>::MapIterator &Map<Key, T>::MapIterator::operator+(
  // //     const MapIterator &other);
  // bool operator==(const MapIterator &other) const;
  // bool operator!=(const MapIterator &other) const;
  // T &operator[](const Key &key);

  // Map &operator=(const Map &other) {
  //   // Явное преобразование к базовому типу
  //   Tree<std::pair<const Key, T>>::operator=(
  //       static_cast<const Tree<std::pair<const Key, T>> &>(other));
  //   return *this;
  // }

  // Map &operator=(Map &&other) {
  //   // Явное преобразование к базовому типу
  //   Tree<std::pair<const Key, T>>::operator=(
  //       static_cast<Tree<std::pair<const Key, T>> &&>(std::move(other)));
  //   return *this;
  // }

  Map &operator=(Map &other) {
    Tree<std::pair<const Key, T>>::operator=(other);
    return *this;
  }

  Map &operator=(Map &&other) {
    Tree<std::pair<const Key, T>>::operator=(std::move(other));
    return *this;
  }

  using Tree<std::pair<const Key, T>>::clear;
  using Tree<std::pair<const Key, T>>::begin;
  using Tree<std::pair<const Key, T>>::end;

  // Map &operator=(Map &other) {
  //   std::cout << "operator=" << std::endl;  // не срабатывает
  //   if (this == &other) return *this;
  //   // s21::Tree<T> temp;
  //   if (this->tree_size_ != 0) this->clear();
  //   std::cout << "operator=" << std::endl;  // не срабатывает
  //   if (other.tree_root_ != other.tree_nil_)

  //   {
  //     this->tree_nil_ = new Node();
  //     this->tree_nil_->color = BLACK;
  //     this->tree_nil_->left = this->tree_nil_;
  //     this->tree_nil_->right = this->tree_nil_;
  //     this->tree_nil_->p = this->tree_nil_;
  //     iterator iter = other.begin();
  //     while (*(iter) != *(other.end())) {
  //       this->insert(*iter);

  //       iter++;
  //     }
  //   }
  //   std::cout << "operator=" << std::endl;  // не срабатывает
  //   return *this;
  //   return *this;
  // }

  // Map &operator=(Map &&other) {
  //   // if (this != &other) {
  //   Tree<std::pair<const Key, T>>::operator=(std::move(other));
  //   // }
  //   return *this;
  // }

  Map() : Tree<std::pair<const Key, T>>() {};

  Map(std::initializer_list<value_type> const &items)
      : Tree<std::pair<const Key, T>>(items) {}
  Map(const Map &m) : Tree<std::pair<const Key, T>>(m) {};
  Map(Map &&m) : Tree<std::pair<const Key, T>>(m) {};

  using Tree<std::pair<const Key, T>>::find;

  using Tree<std::pair<const Key, T>>::insert;

  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return this->insert(value_type(key, obj));  // BO вынести
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

  // using Tree<std::pair<const Key, T>>::size;
  // using Tree<std::pair<const Key, T>>::empty;
  // using Tree<std::pair<const Key, T>>::merge;
  // using Tree<std::pair<const Key, T>>::max_size;
  // using Tree<std::pair<const Key, T>>::erase;

  // using Tree<std::pair<const Key, T>>::print_start;
  // size_type max_size;

  T &at(const Key &key);

  bool contains(const Key &key);

  T &operator[](const Key &key);  // access or insert specified element

  // const T& at(const Key& key) const;
};
}  // namespace s21

#include "map.tpp"

#endif  // MAP_H