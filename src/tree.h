#ifndef TREE_H
#define TREE_H

#include <string.h>

#include <initializer_list>
#include <iostream>
#include <type_traits>

#define RED false
#define BLACK true

namespace s21 {

template <typename T>
struct is_pair : std::false_type {};

template <typename Key, typename Value>
struct is_pair<std::pair<Key, Value>> : std::true_type {};

template <typename T>
inline constexpr bool value_is_pair = is_pair<T>::value;

template <typename T>
class Tree {
 public:
  class TreeIterator;

  using size_type = size_t;

  using key_type = size_type;

  using value_type = T;

  using reference = value_type &;

  using const_reference = const value_type &;

  using iterator = TreeIterator;

  using const_iterator = const key_type *;

  struct BaseNode;

 public:
  struct BaseNode {
    value_type item;

    bool color;

    BaseNode *right;

    BaseNode *left;

    BaseNode *p;

    BaseNode()
        : item(value_type()),  // создать временный объект типа value_type,
                               // инициализированный значением по умолчанию, и
                               // передать его в качестве аргумента
          color(BLACK),
          right(nullptr),
          left(nullptr),
          p(nullptr) {}

    BaseNode(const value_type &val)
        : item(val), color(false), right(nullptr), left(nullptr), p(nullptr) {}
  };

 public:
  class TreeIterator {
   public:
    friend class Tree<T>;

    TreeIterator();

    TreeIterator(BaseNode *node, BaseNode *&nil);

    TreeIterator(const TreeIterator &other);

    TreeIterator(TreeIterator &&other) noexcept;

    BaseNode *get_node() const { return current_; }

    const TreeIterator &operator=(const TreeIterator &other);

    reference operator*();

    const reference operator*() const;

    value_type *operator->();

    const value_type *operator->() const;

    BaseNode *TreeSuccessor(BaseNode *&x) const;

    BaseNode *TreeDescendant(BaseNode *&x) const;

    bool operator==(const TreeIterator &other) const;

    bool operator!=(const TreeIterator &other) const;

    TreeIterator &operator++();

    TreeIterator operator++(int);

    TreeIterator &operator--();

    TreeIterator operator--(int);

   private:
    BaseNode *current_;

    BaseNode *nil_;
  };

  // Map Member functions
  Tree();

  Tree(std::initializer_list<value_type> const &items);

  Tree(const Tree &m);

  Tree(Tree &&m);

  ~Tree();

  Tree &operator=(const Tree &other);

  Tree &operator=(Tree &&other);

  // Map Iterators
  iterator begin();

  iterator end();

  bool empty();

  // Map Capacity
  size_type size();

  size_type max_size();

  // Map Modifiers
  void clear();

  void clear_support(BaseNode *node);

  std::pair<iterator, bool> insert(const value_type &node);

  void erase(iterator pos);

  void swap(Tree &other);

  void merge(Tree &other);

  // Helpers Functions
  static BaseNode *TreeMinimum(BaseNode *node, BaseNode *nil);

  static BaseNode *TreeMaximum(BaseNode *node, BaseNode *nil);

  void repainting_red_uncle_n_dad(BaseNode *&y, BaseNode *&z);

  void left_descendants(BaseNode *&y, BaseNode *&z);

  void right_desdendants(BaseNode *&y, BaseNode *&z);

  bool dad_is_left_son(BaseNode *&z);

  void left_rotate(BaseNode *x);

  void right_rotate(BaseNode *y);

  void insert_fixup(BaseNode *&y, BaseNode *&z);

  std::pair<Tree<T>::iterator, bool> find(T &obj);

  void transplant(BaseNode *&u, BaseNode *&v);

  void delete_fixup(BaseNode *&x);

  void print_tree(BaseNode *base_node, bool is_right, int depth);  // del

  void print_start();  // del

 protected:
  BaseNode *tree_nil_;

  BaseNode *tree_root_;

  size_type tree_size_ = 0;
};
}  // namespace s21

#include "iterator.tpp"
#include "tree.tpp"

#endif  // TREE_H
