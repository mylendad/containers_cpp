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
inline constexpr bool is_pair_v = is_pair<T>::value;

template <typename T>
class Tree {
 public:
  class TreeIterator;

  typedef size_t size_type;
  typedef size_type key_type;
  typedef T value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef TreeIterator iterator;
  // using iterator = TreeIterator;
  typedef const key_type *const_iterator;
  struct BaseNode;

 protected:
  BaseNode *tree_nil_;
  BaseNode *tree_root_;
  size_type size_ = 0;

 public:
  struct BaseNode {
    value_type item;
    bool color;
    BaseNode *right;
    BaseNode *left;
    BaseNode *p;

    BaseNode()
        : item(value_type()),
          color(BLACK),
          right(nullptr),
          left(nullptr),
          p(nullptr) {}

    BaseNode(const value_type &val)
        : item(val), color(false), right(nullptr), left(nullptr), p(nullptr) {}
  };

  static BaseNode *TreeMinimum(BaseNode *node, BaseNode *nil);
  static BaseNode *TreeMaximum(BaseNode *node, BaseNode *nil);

  // BaseNode *TreeSuccessor(BaseNode *&x) const;

  // BaseNode *TreeDescendant(BaseNode *&x) const;

  void repainting_red_uncle_n_dad(BaseNode *&y, BaseNode *&z);

  void left_descendants(BaseNode *&y, BaseNode *&z);

  void right_desdendants(BaseNode *&y, BaseNode *&z);

  bool dad_is_left_son(BaseNode *&z);

  void left_rotate(BaseNode *x);

  void right_rotate(BaseNode *y);

  void insert_fixup(BaseNode *&y, BaseNode *&z);

  // std::pair<iterator, bool> simple_insert(const value_type &node);

  std::pair<Tree<T>::iterator, bool> find(T &obj);

  std::pair<iterator, bool> insert(const value_type &node);

  // std::pair<iterator, bool> insert(const Key &key, const T &obj);

  void transplant(BaseNode *&u, BaseNode *&v);

  void erase(iterator pos);

  void swap(Tree &other);

  bool empty();

  void delete_fixup(BaseNode *&x);

  iterator begin();

  iterator end();

  void print_tree(BaseNode *base_node, bool is_right, int depth);

  void print_start();

 public:
  class TreeIterator {
   private:  // back
    BaseNode *current_;
    // Tree<T> *tree_;  //
    BaseNode *nil_;

   public:
    friend class Tree<T>;
    TreeIterator();

    TreeIterator(BaseNode *node,
                 // , Tree<T> *tree
                 BaseNode *&nil);

    TreeIterator(const TreeIterator &other);

    TreeIterator(TreeIterator &&other) noexcept;

    BaseNode *get_node() const { return current_; }

    const TreeIterator &operator=(const TreeIterator &other);

    value_type &operator*();

    const value_type &operator*() const;

    value_type *operator->();

    const value_type *operator->() const;

    // typename Tree<K, T>::TreeIterator &Tree<K,
    // T>::TreeIterator::operator+(
    //     const TreeIterator &other);

    // operator BaseNode *() const { return current; }

    // BaseNode *TreeMinimum(BaseNode *&node) const;

    // BaseNode *TreeMaximum(BaseNode *&node) const;

    BaseNode *TreeSuccessor(BaseNode *&x) const;

    BaseNode *TreeDescendant(BaseNode *&x) const;

    bool operator==(const TreeIterator &other) const;
    bool operator!=(const TreeIterator &other) const;

   public:
    TreeIterator &operator++();

    TreeIterator operator++(int);

    TreeIterator &operator--();

    TreeIterator operator--(int);
  };

  Tree &operator=(const Tree &other);

  Tree &operator=(Tree &&other);

  // Tree(const Tree &m);

  // operator=(Tree && m);

  // Tree(map &&m);

  // Tree(std::initializer_list<value_type> const &items);

  //   // void Basenode_insert(BaseNode &arr, const value_type &item);

  size_type size();
  // bool empty();
  void clear();

  size_type max_size();

  Tree();  // default constructor, creates empty Tree
  Tree(std::initializer_list<value_type> const &items);
  Tree(const Tree &m);  // copy constructor
  Tree(Tree &&m);       // moTe constructor
  ~Tree();              // destructor
                        // operator=(Tree &&m)
                        // assignment operator oTerload for moTing object

 protected:
  bool is_zero(size_type value);
  BaseNode *create_node(const value_type item);
};
}  // namespace s21

#include "iterator.tpp"
#include "tree.tpp"

#endif  // TREE_H
