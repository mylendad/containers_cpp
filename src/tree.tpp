#ifndef TREE_TPP
#define TREE_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21 {

template <typename T>
s21::Tree<T>::Tree() {
  tree_nil_ = new BaseNode();
  tree_nil_->color = BLACK;
  tree_nil_->left = tree_nil_;
  tree_nil_->right = tree_nil_;
  tree_nil_->p = tree_nil_;
  tree_root_ = tree_nil_;
  tree_size_ = 0;
}

template <typename T>
s21::Tree<T>::Tree(std::initializer_list<value_type> const &items) : Tree() {
  for (auto &item : items) {
    this->insert(item);
  }
}

// template <typename T>
// s21::Tree<T>::Tree(const Tree &m) {
//   if (this == &m) return;
//   if (this->tree_size_ != 0) this->clear();
//   if (m.tree_root_ != m.tree_nil_)

//   {
//     const const_iterator iter = m.const_begin();
//     while (*(iter) != *(m.const_end())) {
//       this->insert(*iter);

//       iter++;
//     }
//     this->insert(*iter);  // change?
//   }
// }

template <typename T>
s21::Tree<T>::Tree(const Tree &m) : Tree() {
  if (m.tree_root_ != m.tree_nil_) {
    copy_tree(m.tree_root_, m.tree_nil_);
  }
  this->tree_size_ = m.tree_size_;
}

template <typename T>
s21::Tree<T>::Tree(Tree &&m) {
  this->tree_root_ = m.tree_root_;
  this->tree_nil_ = m.tree_nil_;
  this->tree_size_ = m.tree_size_;
  m.tree_root_ = nullptr;
  m.tree_nil_ = nullptr;
  m.tree_size_ = 0;
}

template <typename T>
s21::Tree<T>::~Tree() {
  if (this->size() != 0) this->clear();
  if (this->tree_nil_ != nullptr) delete this->tree_nil_;
}

template <typename T>

s21::Tree<T> &s21::Tree<T>::operator=(Tree<T> &other) {
  if (this == &other) return *this;
  if (this->tree_size_ != 0) this->clear();
  if (other.tree_root_ != other.tree_nil_)

  {
    iterator iter = other.begin();
    while (*iter != *(other.end())) {
      this->insert(*iter);

      iter++;
    }
    this->insert(*iter);  // change?
  }
  return *this;
}

template <typename T>
s21::Tree<T> &s21::Tree<T>::operator=(Tree<T> &&other) {
  if (this == &other) return *this;

  this->clear();
  delete this->tree_nil_;

  this->tree_root_ = other.tree_root_;
  this->tree_nil_ = other.tree_nil_;
  this->tree_size_ = other.tree_size_;

  other.tree_root_ = nullptr;
  other.tree_nil_ = nullptr;
  other.tree_size_ = 0;

  return *this;
}

template <typename T>
void s21::Tree<T>::repainting_red_uncle_n_dad(BaseNode *&y, BaseNode *&z) {
  z->p->color = BLACK;   // перекрашиаем отца в черный
  y->color = BLACK;      // перекрашиаем дядю в черный
  z->p->p->color = RED;  // перекрашиаем деда в черный
  z = z->p->p;           // ставим зет на место деда
}

template <typename T>
void s21::Tree<T>::left_descendants(BaseNode *&y, BaseNode *&z) {
  {                                                 // для левого потомков деда
    y = z->p->p->right;                             //  устанавливаем Y (дядя)
    if (y != this->tree_nil_ && y->color == RED) {  // Случай 1 (красный
                                                    // дядя)
      repainting_red_uncle_n_dad(y, z);
    } else {
      if (z == z->p->right && z != this->tree_nil_) {  // Случай 2 (черный дядя
                                                       // и зэт - правый сын)
        z = z->p;                                      // двигаем зет наверх
        left_rotate(z);
      }
      if (z->p != this->tree_nil_ &&
          z->p->p !=
              this->tree_nil_) {  // Случай 3 (черный дядя и зэт - левый сын)
        z->p->color = BLACK;      // // перекрашиаем отца в черный
        z->p->p->color = RED;     // // перекрашиаем деда в красный
        right_rotate(z->p->p);
      }
    }
  }
}

template <typename T>
void s21::Tree<T>::right_desdendants(
    BaseNode *&y, BaseNode *&z) {  // для правых потомков деда
  y = z->p->p->left;
  if (y != this->tree_nil_ && y->color == RED) {  // Случай 1
    repainting_red_uncle_n_dad(y, z);
  } else {
    if (z == z->p->left && z != this->tree_nil_) {  // Случай 2
      z = z->p;
      right_rotate(z);
    }
    if (z->p != this->tree_nil_ && z->p->p != this->tree_nil_) {  // Случай 3
      z->p->color = BLACK;
      z->p->p->color = RED;
      left_rotate(z->p->p);
    }
  }
}

template <typename T>
bool s21::Tree<T>::dad_is_left_son(BaseNode *&z) {
  bool result = false;
  if (z->p == z->p->p->left) result = true;
  return result;
}

template <typename T>
void s21::Tree<T>::left_rotate(BaseNode *x) {
  BaseNode *y;

  y = x->right;
  if (y != nullptr) {
    x->right = y->left;
    if (y->left != this->tree_nil_) y->left->p = x;
    y->p = x->p;
  }
  if (x->p == this->tree_nil_) {
    if (y != nullptr && y != tree_nil_) this->tree_root_ = y;
  } else if (x == x->p->left)
    x->p->left = y;
  else
    x->p->right = y;
  if (y != nullptr) y->left = x;
  x->p = y;
}

template <typename T>
void s21::Tree<T>::right_rotate(BaseNode *y) {
  BaseNode *x;
  x = y->left;
  if (x != nullptr) {
    y->left = x->right;
    if (x->right != this->tree_nil_) x->right->p = y;
    x->p = y->p;
  }
  if (y->p == this->tree_nil_) {
    // корнем
    if (x != nullptr && x != tree_nil_) this->tree_root_ = x;
  }  // то делаем корнем X
  else if (y == y->p->left) {
    // если Y все еще равен правому потомку Y
    y->p->left = x;
  } else {
    y->p->right = x;
  }  // ставим Y правым потомком X (или не так хз)
  if (x != nullptr) x->right = y;  // ставим Y правым отроком X
  y->p = x;                        // а родителем Y ставим X
}

template <typename T>
void s21::Tree<T>::insert_fixup(BaseNode *&y, BaseNode *&z) {
  if (z == nullptr) return;

  {
    while (z != this->tree_root_ && z->p != this->tree_nil_ &&
           z->p->color == RED &&
           z->p->p != this->tree_nil_) {  // пока родитель не станет черным
                                          // (то что з.п красный
      //       значит
      // он не корень и значит у него есть з.п.п)
      if (dad_is_left_son(z)) {  // для левого потомков деда

        left_descendants(y, z);
      } else {
        right_desdendants(y, z);
      }
    }
  }
}

template <typename T>
void s21::Tree<T>::HasTwoDescedants(BaseNode *x, BaseNode *y, BaseNode *z) {
  x = y->right;
  if (y->p == z)
    x->p = y;
  else {
    transplant(y, y->right);
    y->right = z->right;
    y->right->p = y;
  }
  transplant(z, y);
  y->left = z->left;
  y->left->p = y;
  y->color = z->color;
}

template <typename T>
std::pair<typename s21::Tree<T>::iterator, bool> s21::Tree<T>::find(T &obj) {
  BaseNode *x = this->tree_root_;
  BaseNode *y = this->tree_nil_;
  std::pair<typename s21::Tree<T>::iterator, bool> result =
      std::make_pair(iterator(y, this->tree_nil_), false);

  if constexpr (value_is_pair<T>) {
    while (x != this->tree_nil_ && result.second == false) {
      y = x;
      if (obj.first < x->item.first) {
        x = x->left;
      } else if (obj.first > x->item.first) {
        x = x->right;
      } else {
        result = std::make_pair(iterator(x, this->tree_nil_), true);
      }
    }
  } else {
    while (x != this->tree_nil_ && result.second == false) {
      y = x;
      if (obj < x->item) {
        x = x->left;
      } else if (obj > x->item) {
        x = x->right;
      } else {
        result = std::make_pair(iterator(x, this->tree_nil_), true);
      }
    }
  }
  if (result.second == false)
    result = std::make_pair(iterator(y, this->tree_nil_), false);
  return result;
}

template <typename T>
std::pair<typename s21::Tree<T>::iterator, bool> s21::Tree<T>::insert(
    const value_type &node) {
  BaseNode *y;
  size_type size = this->tree_size_;
  BaseNode *z = new BaseNode(node);

  std::pair<typename s21::Tree<T>::iterator, bool> result =
      std::make_pair(iterator(this->tree_nil_, this->tree_nil_), false);

  if (tree_size_ != 0) result = find(z->item);

  if (result.second == false) {
    y = result.first.current_;

    z->p = y;  // здесь на место листа ставим зэт , и
               // родителем зэта узел находящийся выше

    if (y == this->tree_nil_) {  // в цикл while (x != this->tree_nil_) не
                                 // заходил значит дерево пустое
      this->tree_root_ = z;      // дерево было пустым, делаем зэт корнем

    } else if ((z->item) < (y->item))  // устанавливаем зет на место потомка
      y->left = z;
    else
      y->right = z;
    z->left = this->tree_nil_;
    z->right = this->tree_nil_;
    z->color = RED;
    insert_fixup(y, z);
    this->tree_root_->color = BLACK;

    result.second = true;
    this->tree_size_++;
  }
  if (size == this->tree_size_) result.second = false;
  return result;
}

template <typename T>
void s21::Tree<T>::transplant(BaseNode *&u, BaseNode *&v) {
  if (u->p == this->tree_nil_)  // проверяем, если U является корнем,
  {
    this->tree_root_ = v;      // делаем V корнем
  } else if (u == u->p->left)  // если U левый потомок
  {
    u->p->left = v;  // ставим V вместо U
  } else {
    u->p->right = v;  // если U правый потомок ставим V вместо u.p.right
  }
  v->p = u->p;  // ставим не место предка V предка U
}

template <typename T>
void s21::Tree<T>::erase(iterator pos) {
  if (this->tree_size_ == 1) {
    this->tree_root_ = this->tree_nil_;
    this->tree_size_--;
    return;
  }
  BaseNode *z = pos.current_;
  BaseNode *x;
  BaseNode *y = z;
  bool y_original_color = y->color;
  if (z->left == this->tree_nil_ &&
      z->right != this->tree_nil_) {  // у зет нет левого дочернего узла
    x = z->right;                     //
    transplant(z, z->right);  // переносим на место зет правый дочерний узел
  } else if (z->right == this->tree_nil_ &&
             z->left != this->tree_nil_) {  // есть только левый потомок
    x = z->left;
    transplant(z, z->left);
  } else if (z->left != this->tree_nil_ &&
             z->right !=
                 this->tree_nil_) {  // когда есть 2 дочерних узла // вынести
    pos++;
    y = pos.current_;
    y_original_color = y->color;
    HasTwoDescedants(x, y, z);
  } else {
    if (z == z->p->right)
      z->p->right = this->tree_nil_;
    else
      z->p->left = this->tree_nil_;
  }
  this->tree_size_--;

  if (y_original_color == BLACK) delete_fixup(x);
  delete z;
}

template <typename T>
void s21::Tree<T>::swap(Tree &other) {
  Tree temp(other);
  other = std::move(*this);
  *this = std::move(temp);
}

template <typename T>
void s21::Tree<T>::merge(Tree &other) {
  std::pair<typename s21::Tree<T>::iterator, bool> result;
  iterator iter = other.begin();
  size_type size = other.size();
  for (size_type i = 0; i < size; i++) {
    result = this->insert(iter.current_->item);
    iterator temp = iter;
    iter++;
    if (result.second) other.erase(temp);
    temp = iter;
  }
}

template <typename T>
void s21::Tree<T>::son_is_left_descendants(BaseNode *x) {
  BaseNode *w = x->p->right;
  if (w->color == RED) {
    w->color = BLACK;
    x->p->color = RED;
    left_rotate(x->p);
    w = x->p->right;
  }
  if (w->left->color == BLACK && w->right->color == BLACK) {
    w->color = RED;
    x = x->p;
  } else {
    if (w->right->color == BLACK) {
      w->left->color = BLACK;
      w->color = RED;
      right_rotate(w);
      w = x->p->right;
    }
    w->color = x->p->color;
    x->p->color = BLACK;
    w->right->color = BLACK;
    left_rotate(x->p);
    x = this->tree_root_;
  }
}

template <typename T>
void s21::Tree<T>::son_is_right_descendants(BaseNode *x) {
  BaseNode *w = x->p->right;
  if (w->color == RED) {
    w->color = BLACK;
    x->p->color = RED;
    right_rotate(x->p);
    w = x->p->left;
  }
  if (w->right->color == BLACK && w->left->color == BLACK) {
    w->color = RED;
    x = x->p;
  } else {
    if (w->left->color == BLACK) {
      w->right->color = BLACK;
      w->color = RED;
      left_rotate(w);
      w = x->p->left;
    }
    w->color = x->p->color;
    x->p->color = BLACK;
    w->left->color = BLACK;
    right_rotate(x->p);
    x = this->tree_root_;
  }
}

template <typename T>
void s21::Tree<T>::delete_fixup(BaseNode *&x) {
  while (x != tree_root_ && x->color == BLACK) {
    if (x == x->p->left) {
      son_is_left_descendants(x);
      // BaseNode *w = x->p->right;
      // if (w->color == RED) {
      //   w->color = BLACK;
      //   x->p->color = RED;
      //   left_rotate(x->p);
      //   w = x->p->right;
      // }
      // if (w->left->color == BLACK && w->right->color == BLACK) {
      //   w->color = RED;
      //   x = x->p;
      // } else {
      //   if (w->right->color == BLACK) {
      //     w->left->color = BLACK;
      //     w->color = RED;
      //     right_rotate(w);
      //     w = x->p->right;
      //   }
      //   w->color = x->p->color;
      //   x->p->color = BLACK;
      //   w->right->color = BLACK;
      //   left_rotate(x->p);
      //   x = this->tree_root_;
      // }
    } else {
      son_is_right_descendants(x);
      // BaseNode *w = x->p->right;
      // if (w->color == RED) {
      //   w->color = BLACK;
      //   x->p->color = RED;
      //   right_rotate(x->p);
      //   w = x->p->left;
      // }
      // if (w->right->color == BLACK && w->left->color == BLACK) {
      //   w->color = RED;
      //   x = x->p;
      // } else {
      //   if (w->left->color == BLACK) {
      //     w->right->color = BLACK;
      //     w->color = RED;
      //     left_rotate(w);
      //     w = x->p->left;
      //   }
      //   w->color = x->p->color;
      //   x->p->color = BLACK;
      //   w->left->color = BLACK;
      //   right_rotate(x->p);
      //   x = this->tree_root_;
      // }
    }
  }
  x->color = BLACK;
}

template <typename T>
void s21::Tree<T>::print_tree(BaseNode *base_node, bool is_right, int depth) {
  if (base_node == nullptr || base_node == tree_nil_) return;
  print_tree(base_node->right, true, depth + 1);
  for (int i = 0; i < depth; i++) {
    std::cout << "    ";
  }
  if (depth > 0) {
    if (is_right) {
      std::cout << "┌── ";
    } else {
      std::cout << "└── ";
    }
  }
  if (base_node->color == RED) {
    std::cout << "\033[31m";
  } else {
    std::cout << "\033[37m";
  }
  std::cout << base_node->item.first << ":" << base_node->item.second;

  if (base_node == tree_root_) {
    std::cout << " (ROOT)";
  }
  std::cout << "\033[0m" << std::endl;
  print_tree(base_node->left, false, depth + 1);
}

template <typename T>
void s21::Tree<T>::print_start() {
  std::cout << "=== Tree Structure ===" << std::endl;
  print_tree(tree_root_, false, 0);
  std::cout << "======================" << std::endl;
}

template <typename T>
typename s21::Tree<T>::size_type s21::Tree<T>::size() {
  return this->tree_size_;
}

template <typename T>
typename s21::Tree<T>::BaseNode *s21::Tree<T>::TreeMinimum(BaseNode *node,
                                                           BaseNode *nil) {
  BaseNode *x = node;
  BaseNode *min = nil;
  while (x != nil) {
    min = x;
    x = x->left;
  }
  return min;
}

template <typename T>
typename s21::Tree<T>::BaseNode *s21::Tree<T>::TreeMaximum(BaseNode *node,
                                                           BaseNode *nil) {
  BaseNode *x = node;
  BaseNode *max = nil;
  while (x != nil) {
    max = x;
    x = x->right;
  }
  return max;
}

template <typename T>
typename s21::Tree<T>::iterator s21::Tree<T>::begin() {
  BaseNode *min;
  if (this->tree_size_ > 1)
    min = TreeMinimum(this->tree_root_, this->tree_nil_);
  else
    min = this->tree_root_;  // ???
  iterator minimum = iterator(min, this->tree_nil_);
  return minimum;
}

template <typename T>
typename s21::Tree<T>::iterator s21::Tree<T>::end() {
  BaseNode *max;
  if (this->tree_size_ > 1)
    max = TreeMaximum(this->tree_root_, this->tree_nil_);
  else
    max = this->tree_root_;
  iterator maximum = iterator(max, this->tree_nil_);
  return maximum;
}

// template <typename T>
// typename s21::Tree<T>::const_iterator s21::Tree<T>::const_begin() const {
//   BaseNode *min;
//   if (this->tree_size_ > 1)
//     min = TreeMinimum(this->tree_root_, this->tree_nil_);
//   else
//     min = this->tree_root_;  // ???
//   const_iterator minimum(min, this->tree_nil_);
//   return minimum;
// }

// template <typename T>
// typename s21::Tree<T>::const_iterator s21::Tree<T>::const_end() const {
//   BaseNode *max;
//   if (this->tree_size_ > 1)
//     max = TreeMaximum(this->tree_root_, this->tree_nil_);
//   else
//     max = this->tree_root_;
//   const const_iterator maximum(max, this->tree_nil_);
//   return maximum;
// }

template <typename T>
void s21::Tree<T>::clear() {
  clear_support(this->tree_root_);
  this->tree_root_ = this->tree_nil_;
  this->tree_size_ = 0;
}

template <typename T>
void s21::Tree<T>::clear_support(BaseNode *node) {
  if (node == this->tree_nil_) {
    return;
  }

  clear_support(node->left);
  clear_support(node->right);

  if (node != nullptr && node != this->tree_nil_) delete node;
}

template <typename T>
bool s21::Tree<T>::empty() {
  bool result = false;
  if (this->tree_size_ == 0) result = true;
  return result;
}

template <typename T>

typename s21::Tree<T>::size_type s21::Tree<T>::max_size() {
  size_type result = 256204778801521550;  // fix
  return result;
}

template <typename T>
void s21::Tree<T>::copy_tree(BaseNode *source_node, BaseNode *source_nil) {
  if (source_node == source_nil) return;

  this->insert(source_node->item);

  if (source_node->left != source_nil) {
    copy_tree(source_node->left, source_nil);
  }

  if (source_node->right != source_nil) {
    copy_tree(source_node->right, source_nil);
  }
}
}  // namespace s21

#endif  // TREE_TPP