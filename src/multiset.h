#ifndef MULTISET_H
#define MULTISET_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21
{

    template <typename Key>
    class multiset : public Tree<Key>
    {
    public:
        class SetIterator;

        // multiset Member type
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
            s21::multiset<Key>::Node *current_;
        };

        // multiset Member functions
        multiset() : Tree<Key>() {};
        multiset(std::initializer_list<value_type> const &items)
            : Tree<Key>(items) {}
        multiset(const multiset &m) : Tree<Key>(m) {};
        multiset(multiset &&m);
        multiset &operator=(multiset &other);
        multiset &operator=(multiset &&other);

        // multiset Element access
        // Key &at(const Key &key);s
        // Key &operator[](const Key &key);

        // Map Modifiers
        // std::pair<iterator, bool> insert(const value_type &value);
        // using Tree<Key>::insert;
        // std::pair<iterator, bool> insert(const Key &key, const Key &obj);
        // std::pair<iterator, bool> insert_or_assign(const Key &key, const Key &obj);

        // Map Lookup
        iterator find(const Key &key);
        bool contains(const Key &key);
    };
} // namespace s21

#include "multiset.tpp"

#endif // MULTISET_H