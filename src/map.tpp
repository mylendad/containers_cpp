#ifndef MAP_TPP
#define MAP_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>

#include "map.h"

namespace s21 {

// template <typename K, typename T>
// void s21::Map<const K, T>::node_insert(Node &arr, const value_type &item) {
//   arr.item = item;
// }

// template <typename K, typename T>
// void s21::Map<const K, T>::node_insert(Node &arr, const value_type &item) {
//   arr = Node(item);
// }
// template <typename K, typename T>
// bool s21::Map<const K, T>::is_zero(size_type value) {
//   return (bool)fabs(value) < 1e-7;
// }

// template <typename K, typename T>
// typename s21::Map<const K, T>::size_type s21::Map<const K, T>::size() {
//   return this->size_;
// }

// template <typename K, typename T>
// bool s21::Map<const K, T>::empty() {
//   bool res = true;
//   if (!is_zero(this->size_)) res = false;
//   return res;
// }

// using

// template <typename K, typename T>
// s21::Map<const K, T>::Map(std::initializer_list<value_type> const &items) {
//   // Node arr[items.size()];

//   Node *x;
//   Node *y;

//   y = this->tree_nil_;
//   x = this->tree_root_;

//   // Node *current_;
//   // size_t i = 1;
//   for (auto &item : items) {
//     Node *noda = new Node(item);  // for (size_t i = 1; x != tree_nil_; i++)
//     { this->size_++; while (x != tree_nil_) {
//       // node_insert(*noda, item);
//       y = x;
//       if ((noda->item.first) < (x->item.first))
//         x = x->left;
//       else
//         x = x->right;
//     }
//     noda->p = y;
//     if (y == tree_nil_)
//       tree_root_ = noda;
//     else if ((noda->item.first) < (y->item.first))
//       y->left = noda;
//     else
//       y->right = noda;
//     noda->left = tree_nil_;
//     noda->right = tree_nil_;
//     noda->color = RED;
//     // arr[i - 1].right = noda;
//     //   else arr[i - 1].left = noda;
//   }
// }  // initializer list constructor, creates the Map initizialized using
//    // std::initializer_list
// }

// template <typename K, typename T>
// s21::Map<const K, T>::Map(const Map &m) {}  // copy constructor
// template <typename K, typename T>
// s21::Map<const K, T>::Map(Map &&m) {}  // moTe constructor
// template <typename K, typename T>
// s21::Map<const K, T>::~Map()  // destructor
// // operator=(Map &&m)
// {}  // assignment operator oTerload for moTing object
// };  // namespace s21
// int main() {
//   s21::Map<std::string, int> myMap = {{"ключ1", 1}, {"ключ2", 2}, {"ключ3",
//   3}};

// template <typename T>
// s21::Tree<T>::BaseNode s21::Tree<T>::create_node(const value_type item) {
//   return new BaseNode(item);
// }

// template <typename K, typename T>
// typename s21::Map<const K, T>::Node s21::Map<const K, T>::create_node(
//     const value_type &item) {
//   // typename s21::Map<const K, T>::size_type s21::Map<const K, T>::size() {
//   return new Node(item);
// }
//   //   std::cout << "bread\t" << myMap["ключ1"] << std::endl;
//   //   std::cout << "milk\t" << myMap["ключ2"] << std::endl;
//   //   std::cout << "apple\t" << myMap["ключ3"] << std::endl;

//   // s21::Map<std::string, unsigned> products_2;
//   // products_2["bread"] = 30;
//   // products_2["milk"] = 80;
//   // products_2["apple"] = 60;

//   // std::cout << "bread\t" << products_2["bread"] << std::endl;
//   // std::cout << "milk\t" << products_2["milk"] << std::endl;
//   // std::cout << "apple\t" << products_2["apple"] << std::endl;
// }
}  // namespace s21

#endif  // MAP_TPP