#ifndef SET_H
#define SET_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21
{

    template <typename Key>
    class set : public Tree<Key>
    {
    public:
        class SetIterator;

        // set Member type
        using iterator = typename Tree<Key>::TreeIterator;
        using typename Tree<Key>::size_type;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const reference;
        using mapped_type = Key;
        using const_iterator = const iterator;

        struct Node : public Tree<Key>::BaseNode
        {
            Node() : Tree<Key>::BaseNode() {}

            explicit Node(const value_type &val)
                : Tree<Key>::BaseNode() {}
        };

    public:
        class SetIterator : public Tree<Key>::TreeIterator
        {
        public:
            SetIterator() : Tree<Key>::TreeIterator() {}
            SetIterator(Node *node, Node *&nil)
                : Tree<Key>::TreeIterator(node) {}

        private:
            s21::set<Key>::Node *current_;
        };

        // set Member functions
        set() : Tree<Key>() {};
        set(std::initializer_list<value_type> const &items)
            : Tree<Key>(items) {}
        set(const set &m) : Tree<Key>(m) {};
        set(set &&m);
        set &operator=(set &other);
        set &operator=(set &&other);

        // set Element access
        // Key &at(const Key &key);s
        // Key &operator[](const Key &key);

        // Map Modifiers
        // std::pair<iterator, bool> insert(const value_type &value);
        // using Tree<Key>::insert;
        // std::pair<iterator, bool> insert(const Key &key, const Key &obj);
        // std::pair<iterator, bool> insert_or_assign(const Key &key, const Key &obj);

        // Map Lookup
        bool contains(const Key &key);
    };
} // namespace s21

#include "set.tpp"

#endif // SET_H