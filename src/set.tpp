#ifndef SET_TPP
#define SET_TPP

#include <math.h>
#include <string.h>

#include <initializer_list>
#include <iostream>
#include "set.h"

namespace s21
{

    template <typename Key>
    s21::set<Key>::set(set &&m)
    {
        *this = std::move(m);
    }

    template <typename Key>
    s21::set<Key> &s21::set<Key>::operator=(set &other)
    {
        Tree<Key>::operator=(other);
        return *this;
    }
    template <typename Key>
    s21::set<Key> &s21::set<Key>::operator=(set &&other)
    {
        Tree<Key>::operator=(std::move(other));
        return *this;
    }

    // template <typename Key>
    // std::pair<typename s21::set<Key>::iterator, bool> s21::set<Key>::insert(const value_type &value)
    // {
    //     return this->insert(value);
    // }

    // template <typename Key>
    // std::pair<typename s21::set<Key>::iterator, bool>
    // s21::set<Key>::insert_or_assign(const Key &key, const Key &obj)
    // {
    //     std::pair<typename s21rator, bool> result =
    //         insert(value_type(key, obj));
    //     if (result.second == false)
    //     {
    //         result.first->second = obj;
    //     }
    //     return result;
    // }

    // template <typename Key>
    // Key &s21::set<Key>::at(const Key &key)
    // {
    //     std::<Key>temp = {key, Key()};
    //     std::pair<iterator, bool> result = this->find(temp);
    //     if (result.second == false)
    //         throw std::out_of_range("Key not exist.");
    //     return result.first->second;
    // }

    // template <typename Key>
    // Key &s21::set<Key>::operator[](const Key &key)
    // {
    //     Key temp = {key, Key()};
    //     std::pair<iterator, bool> result =
    //         this->find(temp); // если не находит, в результат пишется отец!!! а temp
    //                           // что там во втором аргументе?
    //     if (result.second == false)
    //     {
    //         result.first = this->end();
    //         result = this->insert(temp);
    //     }
    //     return result.first->second; // кудаs
    // }

    // template <typename Key>
    // Key& s21::set<Key>::operator[](const Key& key) {
    //   std::pair<iterator, bool> result = this->insert({key, Key()});
    //   return result.first->second;
    // }

    template <typename Key>
    bool s21::set<Key>::contains(const Key &key)
    {
        Key temp = {key};
        std::pair<iterator, bool> result = this->find(temp);
        return result.second;
    }
} // namespace s21

#endif // SET_TPP::set<Key>::ite