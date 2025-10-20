#include <gtest/gtest.h>
#include <set>

// #include "all_tests.h"
#include "multiset.h"

TEST(MultisetTests, MultisetDefaultConstructor1)
{
    s21::multiset<int> a;
    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetDefaultConstructor2)
{
    s21::multiset<std::string> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetInitializerListConstructor1)
{
    s21::multiset<int> s21_ms{1, 2, 5, 12, 1824, 44, 28};
    std::multiset<int> std_ms{1, 2, 5, 12, 1824, 44, 28};

    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, MultisetInitializerListConstructor2)
{
    s21::multiset<std::string> s21_ms{
        "Shall", "I", "compare", "thee", "to", "a", "summer\'s", "day", "day"};
    std::multiset<std::string> std_ms{
        "Shall", "I", "compare", "thee", "to", "a", "summer\'s", "day", "day"};

    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, MultisetInitializerListConstructor3)
{
    s21::multiset<int> s({});
    EXPECT_TRUE(s.empty());
}

TEST(MultisetTests, MultisetInitializerListConstructor4)
{
    s21::multiset<int> s21_ms({1, 1, 5, 5, 7, 3, 7, 4, 3, 2});
    std::multiset<int> std_ms({1, 1, 5, 5, 7, 3, 7, 4, 3, 2});
    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, SetCopyConstructor)
{
    s21::multiset<double> other{55.52, 1.214, 214.55, 2.4124, 17.8235,
                                99.440, 120.0001, 44.44, 10101.1224, 111.112};

    std::multiset<double> std_ms{55.52, 1.214, 214.55, 2.4124, 17.8235,
                                 99.440, 120.0001, 44.44, 10101.1224, 111.112};

    s21::multiset<double> s21_ms(other);
    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, SetMoveConstructor1)
{
    s21::multiset<char> other{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};
    std::multiset<char> std_ms{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};

    s21::multiset<char> s21_ms(std::move(other));
    EXPECT_EQ(s21_ms.size(), std_ms.size());
    EXPECT_TRUE(other.empty());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();
    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, SetMoveConstructor2)
{
    s21::multiset<int> s1;
    s21::multiset<int> s2(std::move(s1));
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(MultisetTests, SetCopyOperator)
{
    s21::multiset<double> other{55.52, 1.214, 214.55, 2.4124, 17.8235,
                                99.440, 120.0001, 44.44, 10101.1224, 111.112};

    std::multiset<double> std_ms{55.52, 1.214, 214.55, 2.4124, 17.8235,
                                 99.440, 120.0001, 44.44, 10101.1224, 111.112};

    s21::multiset<double> s21_ms = other;
    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, SetCopyOperator2)
{
    s21::multiset<int> s1({1, 2, 3});
    s21::multiset<int> s2({4, 5});
    s2 = s1;
    EXPECT_EQ(s2.size(), 3);
    EXPECT_EQ(s1.size(), 3);
}

TEST(MultisetTests, SetCopyOperator3)
{
    s21::multiset<int> s1;
    s21::multiset<int> s2;
    s2 = s1;
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(MultisetTests, SetMoveOperator1)
{
    s21::multiset<char> other{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};
    std::multiset<char> std_ms{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};

    s21::multiset<char> s21_ms = std::move(other);
    EXPECT_EQ(s21_ms.size(), std_ms.size());
    EXPECT_TRUE(other.empty());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, SetMoveOperator2)
{
    s21::multiset<int> s1({1, 2, 3});
    s21::multiset<int> s2({4, 5});
    s2 = std::move(s1);
    EXPECT_EQ(s2.size(), 3);
    EXPECT_TRUE(s1.empty());
}

TEST(MultisetTests, SetMoveOperator3)
{
    s21::multiset<int> s1;
    s21::multiset<int> s2;
    s2 = std::move(s1);
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(MultisetTests, MultisetIterators1)
{
    s21::multiset<int> s21_ms{1, 124, -145, 251, 0, 888,
                              1, 124, -145, 251, 0, 888};
    std::multiset<int> std_ms{1, 124, -145, 251, 0, 888,
                              1, 124, -145, 251, 0, 888};

    EXPECT_EQ(s21_ms.size(), std_ms.size());

    auto s21_it = s21_ms.begin();
    auto std_it = std_ms.begin();

    for (; s21_it != s21_ms.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }

    --s21_it;
    --std_it;

    for (; s21_it != s21_ms.begin(); --s21_it, --std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(MultisetTests, MultisetIterators2)
{
    s21::multiset<int> a;
    EXPECT_EQ(a.begin(), a.end());
}

TEST(MultisetTests, MultisetEmpty)
{
    s21::multiset<char> a;
    EXPECT_TRUE(a.empty());

    a.insert('b');
    EXPECT_FALSE(a.empty());

    a.erase(a.begin());
    EXPECT_TRUE(a.empty());

    a.insert('b');
    EXPECT_FALSE(a.empty());

    a.insert('c');
    EXPECT_FALSE(a.empty());
    a.insert('a');
    EXPECT_FALSE(a.empty());
    a.clear();

    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetSize)
{
    s21::multiset<int> a;
    EXPECT_EQ(a.size(), 0);

    a.insert(1);
    EXPECT_EQ(a.size(), 1);

    a.insert(1);
    EXPECT_EQ(a.size(), 2);

    a.insert(2);
    EXPECT_EQ(a.size(), 3);

    a.insert(5);
    EXPECT_EQ(a.size(), 4);

    a.insert(4);
    EXPECT_EQ(a.size(), 5);

    a.insert(3);
    EXPECT_EQ(a.size(), 6);

    a.insert(8);
    EXPECT_EQ(a.size(), 7);

    a.insert(9);
    EXPECT_EQ(a.size(), 8);

    a.insert(10);
    EXPECT_EQ(a.size(), 9);

    a.insert(2);
    EXPECT_EQ(a.size(), 10);
}

TEST(MultisetTests, MultisetMaxSize)
{
    s21::multiset<int> a;
    std::multiset<int> b;

    EXPECT_EQ(a.max_size(), b.max_size());

    a.insert(2);
    b.insert(2);
    EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(MultisetTests, MultisetClear1)
{
    s21::multiset<int> a{125, 12, 124, 11, 1, 17, 18,
                         101, 1010, 1023, 2025, 1998, 1995, 1941,
                         1945, 1812, 1861, 988, 1991, 1914, 1918,
                         1939, 125, 125, 125, 125, 125, 125};

    EXPECT_EQ(a.size(), 28);
    a.clear();
    EXPECT_TRUE(a.empty());
    a.insert(5);
    EXPECT_EQ(a.size(), 1);
    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetClear2)
{
    s21::multiset<int> a;

    a.clear();
    EXPECT_TRUE(a.empty());
    a.insert(5);
    EXPECT_EQ(a.size(), 1);
    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetInsert1)
{
    s21::multiset<int> a;
    std::multiset<int> b;
    a.insert(0);
    b.insert(0);
    EXPECT_EQ(a.size(), b.size());
    for (int i = 1, j = 999; i < 1000; ++i, --j)
    {
        a.insert(i);
        a.insert(j);
        b.insert(i);
        b.insert(j);
    }

    EXPECT_EQ(a.size(), b.size());

    auto s21_it = a.begin();
    auto std_it = b.begin();
    for (; s21_it != a.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }

    EXPECT_EQ(a.insert(19191), 19191);
}

TEST(MultisetTests, MultisetErase1)
{
    s21::multiset<int> a;
    std::multiset<int> b;
    a.insert(0);
    b.insert(0);
    EXPECT_EQ(a.size(), b.size());
    for (int i = 1, j = 999; i < 1000; ++i, --j)
    {
        a.insert(i);
        a.insert(j);
        b.insert(i);
        b.insert(j);
    }

    EXPECT_EQ(a.size(), b.size());

    auto s21_it = a.begin();
    auto std_it = b.begin();
    while (s21_it != a.end())
    {
        EXPECT_EQ(*s21_it, *std_it);
        a.erase(s21_it);
        b.erase(std_it);
        EXPECT_EQ(a.size(), b.size());
        s21_it = a.begin();
        std_it = b.begin();
    }

    EXPECT_TRUE(a.empty());
}

TEST(MultisetTests, MultisetErase2)
{
    s21::multiset<int> a;
    std::multiset<int> b;
    for (int i = 1; i < 100000; ++i)
    {
        a.insert(i);
        b.insert(i);
    }

    for (int i = 1; i < 100000; ++i)
    {
        a.insert(i);
        b.insert(i);
    }

    EXPECT_EQ(a.size(), b.size());

    while (!a.empty())
    {
        auto s21_it = --a.end();
        auto std_it = --b.end();
        EXPECT_EQ(*s21_it, *std_it);

        a.erase(s21_it);
        b.erase(std_it);
        EXPECT_EQ(a.size(), b.size());
    }

    EXPECT_EQ(a.begin(), a.end());
    a.erase(a.begin());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.begin(), a.end());
}

TEST(MultisetTests, MultisetSwap1)
{
    s21::multiset<int> ms1;
    s21::multiset<int> ms2({1, 2, 3});
    ms1.swap(ms2);
    EXPECT_TRUE(ms2.empty());
    EXPECT_EQ(ms1.size(), 3);
}

TEST(MultisetTests, MultisetSwap2)
{
    s21::multiset<int> ms1({1, 2, 3});
    s21::multiset<int> ms2;
    ms1.swap(ms2);
    EXPECT_TRUE(ms1.empty());
    EXPECT_EQ(ms2.size(), 3);
}

TEST(MultisetTests, MultisetSwap3)
{
    s21::multiset<int> ms1({1, 2, 3});
    s21::multiset<int> ms2({6, 8, 2, 5});
    ms1.swap(ms2);
    EXPECT_EQ(ms1.size(), 4);
    EXPECT_EQ(ms2.size(), 3);

    auto it1 = ms1.begin();
    EXPECT_EQ(*(it1++), 2);
    EXPECT_EQ(*(it1++), 5);
    EXPECT_EQ(*(it1++), 6);
    EXPECT_EQ(*(it1++), 8);

    auto it2 = ms2.begin();
    EXPECT_EQ(*(it2++), 1);
    EXPECT_EQ(*(it2++), 2);
    EXPECT_EQ(*(it2++), 3);
}

TEST(MultisetTests, MultisetMerge1)
{
    s21::multiset<int> a{5, 5, 5};
    s21::multiset<int> b{5, 5, 5};
    a.merge(b);
    EXPECT_EQ(a.size(), 6);
    EXPECT_TRUE(b.empty());
}

TEST(MultisetTests, MultisetMerge2)
{
    s21::multiset<int> a;
    s21::multiset<int> b{5, 5, 5};
    a.merge(b);
    EXPECT_EQ(a.size(), 3);
    EXPECT_TRUE(b.empty());
}

TEST(MultisetTests, MultisetMerge3)
{
    s21::multiset<int> a{5, 5, 5};
    s21::multiset<int> b;
    a.merge(b);
    EXPECT_EQ(a.size(), 3);
    EXPECT_TRUE(b.empty());
}

TEST(MultisetTests, MultisetMerge4)
{
    s21::multiset<int> a;
    s21::multiset<int> b;
    a.merge(b);
    EXPECT_TRUE(a.empty());
    EXPECT_TRUE(b.empty());
}

// TEST(MultisetTests, MultisetCount1)
// {
//     s21::multiset<int> a{5, 5, 5, 3, 12, 5, 5, 55, 3, 5};
//     EXPECT_EQ(a.count(5), 6);
//     EXPECT_EQ(a.count(3), 2);
//     EXPECT_EQ(a.count(12), 1);
//     EXPECT_EQ(a.count(55), 1);
//     EXPECT_EQ(a.count(122), 0);
// }

// TEST(MultisetTests, MultisetCount2)
// {
//     s21::multiset<int> a;
//     EXPECT_EQ(a.count(5), 0);
//     EXPECT_EQ(a.count(3), 0);
// }

TEST(MultisetTests, MultisetFind1)
{
    s21::multiset<char> a{'a', 'z', 'b', 'y', 'c', 'x', 'd', 'w', 'e', 'v',
                          'a', 'z', 'b', 'c', 'x', 'd', 'w', 'e', 'v'};

    auto it = a.find('a');
    EXPECT_EQ(*it, 'a');
    EXPECT_EQ(*(++it), 'a');

    it = a.find('x');
    EXPECT_EQ(*it, 'x');
    EXPECT_EQ(*(++it), 'x');

    it = a.find('y');
    EXPECT_EQ(*it, 'y');
    EXPECT_EQ(*(++it), 'z');

    it = a.find('h');
    EXPECT_EQ(it, a.end());
}

TEST(MultisetTests, MultisetFind2)
{
    s21::multiset<char> a;

    auto it = a.find('h');
    EXPECT_EQ(it, a.end());
}

TEST(MultisetTests, MultisetContains1)
{
    s21::multiset<char> a{'a', 'z', 'b', 'y', 'c', 'x', 'd', 'w', 'e', 'v',
                          'a', 'z', 'b', 'c', 'x', 'd', 'w', 'e', 'v'};

    EXPECT_TRUE(a.contains('a'));
    EXPECT_TRUE(a.contains('b'));
    EXPECT_TRUE(a.contains('z'));
    EXPECT_TRUE(a.contains('d'));
    EXPECT_FALSE(a.contains('h'));
}

TEST(MultisetTests, MultisetContains2)
{
    s21::multiset<char> a;

    EXPECT_FALSE(a.contains('a'));
    EXPECT_FALSE(a.contains('b'));
    EXPECT_FALSE(a.contains('z'));
    EXPECT_FALSE(a.contains('d'));
    EXPECT_FALSE(a.contains('h'));
}

// TEST(MultisetTests, MultisetEqualRange1)
// {
//     s21::multiset<char> a{'a', 'z', 'b', 'y', 'c', 'x', 'd', 'w', 'e', 'v',
//                           'a', 'z', 'b', 'c', 'x', 'd', 'w', 'e', 'v'};

//     auto it = a.equal_range('a');
//     EXPECT_EQ(it.first, a.find('a'));
//     EXPECT_EQ(it.second, ++(++a.find('a')));

//     it = a.equal_range('z');
//     EXPECT_EQ(it.first, a.find('z'));
//     EXPECT_EQ(it.second, a.end());

//     it = a.equal_range('y');
//     EXPECT_EQ(it.first, a.find('y'));
//     EXPECT_EQ(it.second, a.find('z'));

//     it = a.equal_range('h');
//     EXPECT_EQ(it.first, a.end());
//     EXPECT_EQ(it.second, a.end());
// }

// TEST(MultisetTests, MultisetEqualRange2)
// {
//     s21::multiset<char> a;

//     auto it = a.equal_range('h');
//     EXPECT_EQ(it.first, a.end());
//     EXPECT_EQ(it.second, a.end());
// }

// TEST(MultisetTests, MultisetLowerBound1)
// {
//     s21::multiset<int> a{5, 12, 5, 124, 22, 11, 5, 252, 1, 5, 25, 4, 2, 3};

//     auto it = a.lower_bound(5);
//     EXPECT_EQ(*it, 5);
//     EXPECT_EQ(*(++it), 5);
//     EXPECT_EQ(*(++it), 5);
//     EXPECT_EQ(*(++it), 5);
//     EXPECT_EQ(*(++it), 11);

//     it = a.lower_bound(6);
//     EXPECT_EQ(*it, 11);

//     it = a.lower_bound(252);
//     EXPECT_EQ(it, --a.end());

//     it = a.lower_bound(253);
//     EXPECT_EQ(it, a.end());
// }

// TEST(MultisetTests, MultisetLowerBound2)
// {
//     s21::multiset<int> a;

//     auto it = a.lower_bound(5);
//     EXPECT_EQ(it, a.end());
// }

// TEST(MultisetTests, MultisetUpperBound1)
// {
//     s21::multiset<int> a{5, 12, 5, 124, 22, 11, 5, 252, 1, 5, 25, 4, 2, 3};

//     auto it = a.upper_bound(5);
//     EXPECT_EQ(*it, 11);
//     EXPECT_EQ(*(--it), 5);

//     it = a.upper_bound(6);
//     EXPECT_EQ(*it, 11);

//     it = a.upper_bound(252);
//     EXPECT_EQ(it, a.end());
// }

// TEST(MultisetTests, MultisetUpperBound2)
// {
//     s21::multiset<int> a;

//     auto it = a.upper_bound(5);
//     EXPECT_EQ(it, a.end());
// }

// TEST(MultisetTests, MultisetInsertMany1)
// {
//     s21::multiset<int> a;
//     a.insert_many(5, 2, 3, 12, 22, 44, 2321, 23, 2, 3);
//     EXPECT_EQ(a.size(), 10);

//     auto it = a.begin();
//     EXPECT_EQ(*it, 2);
//     EXPECT_EQ(*(++it), 2);
//     EXPECT_EQ(*(++it), 3);
//     EXPECT_EQ(*(++it), 3);
//     EXPECT_EQ(*(++it), 5);
//     EXPECT_EQ(*(++it), 12);
//     EXPECT_EQ(*(++it), 22);
//     EXPECT_EQ(*(++it), 23);
//     EXPECT_EQ(*(++it), 44);
//     EXPECT_EQ(*(++it), 2321);
// }

// TEST(MultisetTests, MultisetInsertMany2)
// {
//     s21::multiset<int> a{2, 4};
//     std::multiset<int> b{2, 3, 4};
//     a.insert_many();
//     EXPECT_EQ(a.size(), 2);

//     a.insert_many(3);
//     auto s21_it = a.begin();
//     auto std_it = b.begin();
//     EXPECT_EQ(a.size(), b.size());
//     for (; s21_it != a.end(); ++s21_it, ++std_it)
//     {
//         EXPECT_EQ(*s21_it, *std_it);
//     }
// }

// TEST(MultisetTests, MultisetInsertMany3)
// {
//     s21::multiset<int> a{2, 6};
//     std::multiset<int> b{2, 3, 4, 5, 6};
//     a.insert_many(3, 4, 5);
//     auto s21_it = a.begin();
//     auto std_it = b.begin();
//     EXPECT_EQ(a.size(), b.size());
//     for (; s21_it != a.end(); ++s21_it, ++std_it)
//     {
//         EXPECT_EQ(*s21_it, *std_it);
//     }
// }