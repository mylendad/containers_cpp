#ifndef MULTISET_H
#define MULTISET_H

#include <string.h>

#include <initializer_list>
#include <iostream>

#include "tree.h"

namespace s21
{

    template <typename Key, int AllowDuplicate = Multiset>
    class multiset : public tree<Key, AllowDuplicate>
    {
    public:
        //   class SetIterator;

        // multiset Member type
        using iterator = typename tree<Key, AllowDuplicate>::TreeIterator;
        using typename tree<Key, AllowDuplicate>::size_type;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const reference;
        using mapped_type = Key;
        using const_iterator = const iterator;

        struct Node : public tree<Key, AllowDuplicate>::BaseNode
        {
            Node() : tree<Key, AllowDuplicate>::BaseNode() {}

            explicit Node(const value_type &val)
                : tree<Key, AllowDuplicate>::BaseNode() {}
        };

        //  public:
        //   class SetIterator : public tree<Key, AllowDuplicate>::TreeIterator {
        //    public:
        //     SetIterator() : tree<Key, AllowDuplicate>::TreeIterator() {}
        //     SetIterator(Node* node, Node*& nil)
        //         : tree<Key, AllowDuplicate>::TreeIterator(node) {}

        //    private:
        //     s21::multiset<Key, AllowDuplicate>::Node* current_;
        //   };

        // multiset Member functions
        multiset() : tree<Key, AllowDuplicate>() {};
        multiset(std::initializer_list<value_type> const &items)
            : tree<Key, AllowDuplicate>(items) {}
        multiset(const multiset &m) : tree<Key, AllowDuplicate>(m) {};
        multiset(multiset &&m);
        multiset &operator=(multiset &other);
        multiset &operator=(multiset &&other);

        // multiset Element access
        // Key &at(const Key &key);s
        // Key &operator[](const Key &key);

        // Map Modifiers
        // std::pair<iterator, bool> insert(const value_type &value);
        // using tree<Key, AllowDuplicate>::insert;
        // std::pair<iterator, bool> insert(const Key &key, const Key &obj);
        // std::pair<iterator, bool> insert_or_assign(const Key &key, const Key &obj);

        // Map Lookup
        iterator find(const Key &key);
        bool contains(const Key &key);
        size_type count(const Key &key)
        {
            size_type cnt = 0;
            iterator itr = this->begin();
            for (size_type i = 0; i < this->size(); i++)
            {
                if (itr.get_node()->item == key)
                {
                    cnt++;
                    // std::cout << "item:" << itr.get_node()->item << "key:" << key << std::endl;
                }
                ++itr;
            }
            return cnt;
        }

        iterator upper_bound(const Key &key)
        {
            return ++(this->find(key)); // back ++?
        }

        iterator lower_bound(const Key &key)
        {
            iterator result = this->upper_bound(key);
            size_type count = this->count(key);
            return result -= count;
        }

        std::pair<iterator, iterator> equal_range(const Key &key)
        {
            iterator first = this->lower_bound(key);
            iterator second = this->upper_bound(key);
            return std::pair<iterator, iterator>(first, second);
        }
    };
} // namespace s21

#include "multiset.tpp"

#endif // MULTISET_H