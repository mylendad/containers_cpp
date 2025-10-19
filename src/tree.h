#ifndef TREE_H
#define TREE_H

#include <string.h>

#include <initializer_list>
#include <iostream>
#include <limits>
#include <type_traits>

#include <set>

#define RED false
#define BLACK true

namespace s21
{

  template <typename T>
  struct is_pair : std::false_type
  {
  };

  template <typename Key, typename Value>
  struct is_pair<std::pair<Key, Value>> : std::true_type
  {
  };

  template <typename T>
  inline constexpr bool value_is_pair = is_pair<T>::value;

  template <typename T>
  class Tree
  {
  public:
    class TreeIterator;
    using size_type = size_t;
    using key_type = size_type;
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = TreeIterator;
    using const_iterator = const TreeIterator;

    struct BaseNode;

  public:
    struct BaseNode
    {
      value_type item;
      bool color;
      BaseNode *right;
      BaseNode *left;
      BaseNode *p;

      BaseNode()
          : item(value_type()), // создать временный объект типа value_type,
                                // инициализированный значением по умолчанию, и
                                // передать его в качестве аргумента
            color(BLACK),
            right(nullptr),
            left(nullptr),
            p(nullptr)
      {
      }

      explicit BaseNode(const value_type &val)
          : item(val), color(false), right(nullptr), left(nullptr), p(nullptr) {}
    };

  public:
    class TreeIterator
    {
    public:
      friend class Tree<T>;
      TreeIterator();
      TreeIterator(BaseNode *node, BaseNode *&nil, BaseNode *&end_node);
      TreeIterator(const TreeIterator &other);
      TreeIterator(TreeIterator &&other) noexcept;
      BaseNode *get_node() const { return current_; }
      const TreeIterator &operator=(const TreeIterator &other);
      bool operator==(const TreeIterator &other) const;
      bool operator!=(const TreeIterator &other) const;
      reference operator*();
      const reference operator*() const;
      value_type *operator->();
      const value_type *operator->() const;
      BaseNode *TreeSuccessor(BaseNode *x);
      BaseNode *TreeDescendant(BaseNode *x);
      TreeIterator &operator++();
      TreeIterator operator++(int);
      TreeIterator operator--();
      TreeIterator operator--(int);

    private:
      BaseNode *current_;
      BaseNode *nil_;
      BaseNode *end_node_;
    };

    //  public:
    //   class const_iterator {
    //    public:
    //     friend class Tree<T>;

    //     const_iterator();

    //     const_iterator(BaseNode *node, const BaseNode *&nil);

    //     const_iterator(const const_iterator &other);

    //     const_iterator(const_iterator &&other) noexcept;

    //     const const_iterator &operator=(const const_iterator &other) const;

    //     // const reference operator*();

    //     const reference operator*() const;

    //     //  const value_type *operator->() const ;

    //     const value_type *operator->() const;

    //     BaseNode *TreeSuccessor(const BaseNode *&x) const;

    //     BaseNode *TreeDescendant(const BaseNode *&x) const;

    //     // bool operator==(const TreeIterator &other) const;

    //     // bool operator!=(const TreeIterator &other) const;

    //     const_iterator &operator++() const;

    //     const_iterator operator++(int) const;

    //     const const_iterator &operator--() const;

    //     const const_iterator operator--(int) const;

    //    private:
    //     const BaseNode *current_;

    //     const BaseNode *nil_;
    //   };

    // Map Member functions

    Tree();
    Tree(std::initializer_list<value_type> const &items);
    Tree(const Tree &m);
    Tree(Tree &&m);
    ~Tree();
    Tree &operator=(const Tree &other);
    Tree &operator=(Tree &&other);

    // Tree Iterators
    iterator begin();
    iterator end();
    bool empty();

    // Tree Capacity
    size_type size();
    size_type max_size();

    // Tree Modifiers
    void clear();
    void clear_support(BaseNode *node);
    std::pair<iterator, bool> insert(const value_type &value);
    // vector<std::pair<iterator, bool>> insert_many(Args &&...args);
    void erase(iterator pos);
    void swap(Tree &other);
    void merge(Tree &other);

    // Helpers Functions
    static BaseNode *TreeMinimum(BaseNode *node, BaseNode *nil);
    static BaseNode *TreeMaximum(BaseNode *node, BaseNode *nil);
    void HasTwoDescedants(BaseNode *&x, BaseNode *&y, BaseNode *z);
    BaseNode *repainting_red_uncle_n_dad(BaseNode *&y, BaseNode *&z);
    BaseNode *left_descendants(BaseNode *&y, BaseNode *&z);
    BaseNode *right_desdendants(BaseNode *&y, BaseNode *&z);
    bool dad_is_left_son(BaseNode *&z);
    void son_is_left_descendants(BaseNode *x);
    void son_is_right_descendants(BaseNode *x);
    void left_rotate(BaseNode *x);
    void right_rotate(BaseNode *y);
    BaseNode *insert_fixup(BaseNode *&y, BaseNode *&z);
    std::pair<Tree<T>::iterator, bool> find_node(const T &obj);
    void transplant(BaseNode *&u, BaseNode *&v);
    void delete_fixup(BaseNode *&x);
    void copy_tree(BaseNode *src_node, BaseNode *src_nil);

    void print_tree(BaseNode *base_node, bool is_right, int depth);
    void print_start();

  protected:
    BaseNode *tree_nil_;
    BaseNode *tree_root_;
    BaseNode *end_node_;

    size_type tree_size_ = 0;
  };
} // namespace s21
#include "iterator.tpp"
#include "tree.tpp"

#endif // TREE_H
