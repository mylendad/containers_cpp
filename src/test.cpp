// #include <iostream>
// #include <map>

// int main() {
//   std::map<double, std::string> myMap = {
//       {1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};

//   std::map<std::string, int> myMap_1 = {
//       {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
//       {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
//       {"ключ09", 9}, {"ключ10", 10}};

//   // Using a traditional iterator
//   myMap.at(1) = "efwgwgw";
//   for (std::map<double, std::string>::iterator it = myMap.begin();
//        it != myMap.end(); ++it) {
//     std::cout << "Key: " << it->first << ", Value: " << it->second <<
//     std::endl;

//     // std::cout << myMap.contains("ключ09") << std::endl;
//     std::cout << myMap_1.max_size() << std::endl;
//   }
//   return 0;
// }

// #include <iostream>
// #include <map>
// #include <string>

// int main() {
//   // Создаем два словаря
//   std::map<int, std::string> map1;
//   std::map<int, std::string> map2;

//   // Заполняем первый словарь
//   map1.insert({1, "Apple"});
//   map1.insert({2, "Banana"});
//   map1.insert({3, "Cherry"});

//   // Заполняем второй словарь
//   // Обратите внимание на ключи 3 и 4
//   map2.insert({3, "Coconut"});  // Ключ 3 конфликтует с map1
//   map2.insert({4, "Date"});
//   map2.insert({5, "Elderberry"});

//   std::cout << "Before merge:" << std::endl;
//   std::cout << "Map1: ";
//   for (const auto& [key, value] : map1) {
//     std::cout << "{" << key << ": " << value << "} ";
//   }
//   std::cout << std::endl;

//   std::cout << "Map2: ";
//   for (const auto& [key, value] : map2) {
//     std::cout << "{" << key << ": " << value << "} ";
//   }
//   std::cout << std::endl << std::endl;

//   // ВЫПОЛНЯЕМ СЛИЯНИЕ: перемещаем элементы из map2 в map1
//   map1.merge(map2);

//   std::cout << "After merge:" << std::endl;
//   std::cout << "Map1: ";
//   for (const auto& [key, value] : map1) {
//     std::cout << "{" << key << ": " << value << "} ";
//   }
//   std::cout << std::endl;

//   std::cout << "Map2: ";
//   for (const auto& [key, value] : map2) {
//     std::cout << "{" << key << ": " << value << "} ";
//   }
//   std::cout << std::endl;

//   return 0;
// }

#include <gtest/gtest.h>

#include <set>

#include "set.h"

TEST(set_constructor, case1)
{
    s21::set<int> s21_set_int;
    s21::set<double> s21_set_double;
    s21::set<std::string> s21_set_string;

    EXPECT_EQ(s21_set_int.size(), 0U);
    EXPECT_EQ(s21_set_double.size(), 0U);
    EXPECT_EQ(s21_set_string.size(), 0U);
}

TEST(set_constructor, case2)
{
    s21::set<int> s21_set_int{1, 2, 3, 4, 5};
    s21::set<double> s21_set_double{1.30359, 2847.4925, 923.39281};
    s21::set<std::string> s21_set_string{"Hello", ",", "world", "!"};

    EXPECT_EQ(s21_set_int.size(), 5U);
    EXPECT_EQ(s21_set_double.size(), 3U);
    EXPECT_EQ(s21_set_string.size(), 4U);
}

TEST(set_constructor, case3)
{
    s21::set<int> s21_set_ref_int{1, 2, 3, 4, 5};
    s21::set<int> s21_set_res_int{s21_set_ref_int};

    s21::set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
    s21::set<double> s21_set_res_double{s21_set_ref_double};

    s21::set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
    s21::set<std::string> s21_set_res_string{s21_set_ref_string};

    EXPECT_EQ(s21_set_ref_int.size(), s21_set_res_int.size());
    EXPECT_EQ(s21_set_ref_double.size(), s21_set_res_double.size());
    EXPECT_EQ(s21_set_ref_string.size(), s21_set_res_string.size());
}

TEST(set_constructor, case4)
{
    s21::set<int> s21_set_ref_int{1, 2, 3, 4, 5};
    s21::set<int> s21_set_res_int = std::move(s21_set_ref_int);

    s21::set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
    s21::set<double> s21_set_res_double = std::move(s21_set_ref_double);

    s21::set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
    s21::set<std::string> s21_set_res_string = std::move(s21_set_ref_string);

    EXPECT_EQ(s21_set_ref_int.size(), 0U);
    EXPECT_EQ(s21_set_res_int.size(), 5U);

    EXPECT_EQ(s21_set_ref_double.size(), 0U);
    EXPECT_EQ(s21_set_res_double.size(), 3U);

    EXPECT_EQ(s21_set_ref_string.size(), 0U);
    EXPECT_EQ(s21_set_res_string.size(), 4U);
}

TEST(set_constructor, case5)
{
    s21::set<int> s21_set_ref_int{1, 2, 3, 4, 5};
    s21::set<int> s21_set_res_int;
    s21_set_res_int = std::move(s21_set_ref_int);

    s21::set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
    s21::set<double> s21_set_res_double;
    s21_set_res_double = std::move(s21_set_ref_double);

    s21::set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
    s21::set<std::string> s21_set_res_string;
    s21_set_res_string = std::move(s21_set_ref_string);

    EXPECT_EQ(s21_set_ref_int.size(), 0U);
    EXPECT_EQ(s21_set_res_int.size(), 5U);

    EXPECT_EQ(s21_set_ref_double.size(), 0U);
    EXPECT_EQ(s21_set_res_double.size(), 3U);

    EXPECT_EQ(s21_set_ref_string.size(), 0U);
    EXPECT_EQ(s21_set_res_string.size(), 4U);
}

TEST(set_constructor, case7)
{
    s21::set<int> s21_set_ref_int{1, 2, 3, 4};
    s21::set<int> s21_set_res_int{s21_set_ref_int};

    s21::set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281, 1.23};
    s21::set<double> s21_set_res_double{s21_set_ref_double};

    s21::set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
    s21::set<std::string> s21_set_res_string{s21_set_ref_string};

    auto it_res_int = s21_set_res_int.begin();
    for (auto it_ref_int = s21_set_ref_int.begin();
         it_ref_int != s21_set_ref_int.end(); ++it_ref_int)
    {
        EXPECT_EQ(*it_res_int, *it_ref_int);
        it_res_int++;
    }

    auto it_res_double = s21_set_res_double.begin();
    for (auto it_ref_double = s21_set_ref_double.begin();
         it_ref_double != s21_set_ref_double.end(); ++it_ref_double)
    {
        EXPECT_EQ(*it_res_double, *it_ref_double);
        it_res_double++;
    }

    auto it_res_string = s21_set_res_string.begin();
    for (auto it_ref_string = s21_set_ref_string.begin();
         it_ref_string != s21_set_ref_string.end(); ++it_ref_string)
    {
        EXPECT_EQ(*it_res_string, *it_ref_string);
        it_res_string++;
    }
}

TEST(set_insert, case1)
{
    s21::set<int> s21_set;

    std::pair<s21::set<int>::iterator, bool> insert1 = s21_set.insert(9);
    EXPECT_EQ(*insert1.first, 9);
    EXPECT_EQ(insert1.second, true);

    std::pair<s21::set<int>::iterator, bool> insert2 = s21_set.insert(9);
    std::pair<s21::set<int>::iterator, bool> insert3 = s21_set.insert(9);
    EXPECT_EQ(insert2.second, 0);
    EXPECT_EQ(insert3.second, false);

    std::pair<s21::set<int>::iterator, bool> insert4 = s21_set.insert(23);
    EXPECT_EQ(*insert4.first, 23);
    EXPECT_EQ(insert4.second, true);

    std::pair<s21::set<int>::iterator, bool> insert5 = s21_set.insert(98);
    EXPECT_EQ(*insert5.first, 98);
    EXPECT_EQ(insert5.second, true);

    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_insert, case2)
{
    s21::set<double> s21_set;

    std::pair<s21::set<double>::iterator, bool> insert1 = s21_set.insert(1.4);
    EXPECT_EQ(*insert1.first, 1.4);
    EXPECT_EQ(insert1.second, true);

    std::pair<s21::set<double>::iterator, bool> insert2 = s21_set.insert(2.77);
    EXPECT_EQ(*insert2.first, 2.77);
    EXPECT_EQ(insert2.second, true);

    std::pair<s21::set<double>::iterator, bool> insert3 = s21_set.insert(3.9);
    EXPECT_EQ(*insert3.first, 3.9);
    EXPECT_EQ(insert3.second, true);

    std::pair<s21::set<double>::iterator, bool> insert4 = s21_set.insert(2.77);
    std::pair<s21::set<double>::iterator, bool> insert5 = s21_set.insert(3.9);
    EXPECT_EQ(insert4.second, false);
    EXPECT_EQ(insert5.second, false);

    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_insert, case3)
{
    s21::set<std::string> s21_set;

    std::pair<s21::set<std::string>::iterator, bool> insert1 =
        s21_set.insert("hello");
    EXPECT_EQ(*insert1.first, "hello");
    EXPECT_EQ(insert1.second, true);

    std::pair<s21::set<std::string>::iterator, bool> insert2 =
        s21_set.insert("hi");
    EXPECT_EQ(*insert2.first, "hi");
    EXPECT_EQ(insert2.second, true);

    std::pair<s21::set<std::string>::iterator, bool> insert3 =
        s21_set.insert("hi");
    EXPECT_EQ(insert3.second, false);

    std::pair<s21::set<std::string>::iterator, bool> insert4 =
        s21_set.insert("hola");
    EXPECT_EQ(*insert4.first, "hola");
    EXPECT_EQ(insert4.second, true);

    std::pair<s21::set<std::string>::iterator, bool> insert5 =
        s21_set.insert("hello");
    EXPECT_EQ(insert5.second, false);

    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_insert, case4)
{
    s21::set<int> s21_set;

    std::pair<s21::set<int>::iterator, bool> insert1 = s21_set.insert(9);
    EXPECT_EQ(*insert1.first, 9);
    EXPECT_EQ(insert1.second, true);

    std::pair<s21::set<int>::iterator, bool> insert2 = s21_set.insert(9);
    std::pair<s21::set<int>::iterator, bool> insert3 = s21_set.insert(9);
    EXPECT_EQ(insert2.second, false);
    EXPECT_EQ(insert3.second, false);

    EXPECT_EQ(s21_set.size(), 1U);
}

TEST(set_insert, case5)
{
    s21::set<double> s21_set = {21};

    std::pair<s21::set<double>::iterator, bool> insert1 = s21_set.insert(1.4);
    EXPECT_EQ(insert1.second, true);

    EXPECT_EQ(s21_set.size(), 2U);
}

TEST(set_insert, case6)
{
    s21::set<std::string> s21_set = {"hello"};

    std::pair<s21::set<std::string>::iterator, bool> insert1 =
        s21_set.insert("hi");
    EXPECT_EQ(*insert1.first, "hi");
    EXPECT_EQ(insert1.second, true);

    EXPECT_EQ(s21_set.size(), 2U);
}

TEST(set_begin, case1)
{
    s21::set<int> s21_set = {9, 15, 7, 23, 2};

    EXPECT_EQ(*s21_set.begin(), 2);
}

TEST(set_begin, case2)
{
    s21::set<double> s21_set = {11.4, 2.770001, 3.901, 2.77, 3.9};

    EXPECT_EQ(*s21_set.begin(), 2.77);
}

TEST(set_begin, case3)
{
    s21::set<std::string> s21_set = {"hello", "hi", "hi-hi", "hola",
                                     "hello, there"};

    EXPECT_EQ(*s21_set.begin(), "hello");
}

TEST(set_begin, case4)
{
    s21::set<int> s21_set;

    EXPECT_THROW(s21_set.begin(), std::out_of_range);
}

TEST(set_begin, case5)
{
    s21::set<double> s21_set = {1.4, 1.4};

    EXPECT_EQ(*s21_set.begin(), 1.4);
}

TEST(set_begin, case6)
{
    s21::set<std::string> s21_set = {"hello", "hello", "hello"};

    EXPECT_EQ(*s21_set.begin(), "hello");
}

// TEST(set_end, case1)
// {
//     s21::set<int> s21_set = {9, 15, 7, 23, 2};
//     s21::set<int>::iterator end = s21_set.end();
//     end--;
//     EXPECT_EQ(*(end), 23);
// }

// TEST(set_end, case2)
// {
//     s21::set<double> s21_set = {11.4, 2.770001, 3.901, 11.400000001, 3.9};

//     EXPECT_EQ(*s21_set.end(), 11.400000001);
// }

// TEST(set_end, case3)
// {
//     s21::set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
//                                      "hello, there"};

//     EXPECT_EQ(*s21_set.end(), "hola-hola");
// }

// TEST(set_end, case4)
// {
//     s21::set<int> s21_set;

//     EXPECT_THROW(s21_set.end(), std::out_of_range);
// }

// TEST(set_end, case5)
// {
//     s21::set<double> s21_set = {1.4, 1.4};

//     EXPECT_EQ(*s21_set.end(), 1.4);
// }

// TEST(set_end, case6)
// {
//     s21::set<std::string> s21_set = {"hello", "hello", "hello"};

//     EXPECT_EQ(*s21_set.end(), "hello");
// }

TEST(set_balance, case1)
{
    s21::set<int> s21_set = {1, 15, 5};

    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_balance, case2)
{
    s21::set<double> s21_set = {11.4, 2.770001, 3.901};

    // EXPECT_EQ(*s21_set.end(), 11.4);
    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_balance, case3)
{
    s21::set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                     "hello, there"};

    // EXPECT_EQ(*s21_set.end(), "hola-hola");
    EXPECT_EQ(s21_set.size(), 5U);
}

TEST(set_balance, case4)
{
    s21::set<int> s21_set = {10, 5, 20, 30, 1543};

    // EXPECT_EQ(*s21_set.end(), 1543);
    EXPECT_EQ(*s21_set.begin(), 5);
    EXPECT_EQ(s21_set.size(), 5U);
}

TEST(set_balance, case5)
{
    s21::set<int> s21_set = {30, 5, 43, 1, 20, 40, 60, 35, 32};

    // EXPECT_EQ(*s21_set.end(), 60);
    EXPECT_EQ(*s21_set.begin(), 1);
    EXPECT_EQ(s21_set.size(), 9U);
}

TEST(set_erase, case1)
{
    s21::set<int> s21_set = {10, 5, 15, 4, 18, 13, 16};

    auto it = s21_set.begin();
    it++;
    it++;
    it++;
    it++;
    s21_set.erase(it);
    EXPECT_EQ(*s21_set.begin(), 4);
    // EXPECT_EQ(*s21_set.end(), 18);/
    EXPECT_EQ(s21_set.size(), 6U);

    it = s21_set.begin();
    s21_set.erase(it);
    EXPECT_EQ(*s21_set.begin(), 5);
    // EXPECT_EQ(*s21_set.end(), 18);/
    EXPECT_EQ(s21_set.size(), 5U);

    it = s21_set.begin();
    it++;
    s21_set.erase(it);
    EXPECT_EQ(*s21_set.begin(), 5);
    // EXPECT_EQ(*s21_set.end(), 18);
    EXPECT_EQ(s21_set.size(), 4U);

    it = s21_set.end();
    it--;
    // std::cout << it->item << std::endl;
    s21_set.erase(it);
    // EXPECT_EQ(*s21_set.begin(), 5);
    // EXPECT_EQ(*s21_set.end(), 16);
    EXPECT_EQ(s21_set.size(), 3U);

    it = s21_set.begin();
    it++;
    s21_set.erase(it);

    it = s21_set.begin();
    it++;
    s21_set.erase(it);

    it = s21_set.begin();
    s21_set.erase(it);

    EXPECT_EQ(s21_set.size(), 0U);
}

TEST(set_erase, case2)
{
    s21::set<int> s21_set = {30, 1543};

    auto it = s21_set.begin();
    it++;
    s21_set.erase(it);
    it = s21_set.begin();
    s21_set.erase(it);

    EXPECT_EQ(s21_set.size(), 0U);
}

// TEST(set_erase, case3)
// {
//     s21::set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
//                                      "hello, there"};

//     auto it = s21_set.end();
//     s21_set.erase(it);
//     EXPECT_EQ(*s21_set.end(), "hola");
//     EXPECT_EQ(s21_set.size(), 4U);

//     it = s21_set.end();
//     s21_set.erase(it);
//     EXPECT_EQ(*s21_set.end(), "hi");
//     EXPECT_EQ(s21_set.size(), 3U);

//     s21_set.insert("hola-hola");
//     s21_set.insert("hola");
//     it = s21_set.end();
//     s21_set.erase(it);
//     EXPECT_EQ(*s21_set.end(), "hola");
//     EXPECT_EQ(s21_set.size(), 4U);
// }

// TEST(set_erase, case4)
// {
//     s21::set<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

//     auto it = s21_set.end();
//     it--;
//     s21_set.erase(it);
//     it = s21_set.end();
//     EXPECT_EQ(*it, 941.44);
//     EXPECT_EQ(s21_set.size(), 4U);

//     it = s21_set.begin();
//     ++it;
//     ++it;
//     ++it;
//     s21_set.erase(it);
//     it = s21_set.begin();
//     ++it;
//     ++it;
//     ++it;
//     EXPECT_EQ(*s21_set.end(), 44.48);
//     EXPECT_EQ(s21_set.size(), 3U);
// }

TEST(set_erase, case5)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

    auto it = s21_set.begin();
    it--;
    s21_set.erase(it);
    it = s21_set.begin();
    ++it;
    ++it;
    // EXPECT_EQ(*it, 44.48);
    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_erase, case6)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 6.84, 1.44};

    auto it = s21_set.begin();
    ++it;
    ++it;
    ++it;
    s21_set.erase(it);
    it = s21_set.begin();
    it--;
    it--;
    it--;
    // EXPECT_EQ(*it, 44.48);
    EXPECT_EQ(s21_set.size(), 4U);
}

TEST(set_erase, case7)
{
    s21::set<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

    auto it = s21_set.begin();
    ++it;
    s21_set.erase(it);
    it = s21_set.begin();
    ++it;
    EXPECT_EQ(*it, 44.48);
    EXPECT_EQ(s21_set.size(), 4U);
}

TEST(set_erase, case8)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

    auto it = s21_set.begin();
    ++it;
    s21_set.erase(it);
    it = s21_set.begin();
    ++it;
    EXPECT_EQ(*it, 22.2);
    EXPECT_EQ(s21_set.size(), 3U);
}

TEST(set_erase, case9)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 32.45,
                                65.12, 66.32, 40.54, 6.4};

    auto it = s21_set.end();
    it--;
    it--;
    it--;
    it--;
    s21_set.erase(it);
    it = s21_set.begin();
    ++it;
    ++it;
    ++it;
    EXPECT_EQ(*it, 40.54);
    EXPECT_EQ(s21_set.size(), 7U);
}

TEST(set_erase, case10)
{
    s21::set<double> s21_set = {22.2};

    auto it = s21_set.end();
    it--;
    it--;
    ++it;
    s21_set.erase(it);
    EXPECT_EQ(s21_set.size(), 0U);
}

TEST(set_empty, case1)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

    EXPECT_EQ(s21_set.empty(), 0);
}

TEST(set_empty, case2)
{
    s21::set<double> s21_set;

    EXPECT_EQ(s21_set.empty(), 1);
}

TEST(set_MaxSize, case1)
{
    s21::set<double> s21_set;
    std::set<double> std_set;

    EXPECT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(set_MaxSize, case2)
{
    s21::set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

    std::set<double> std_set = {22.2, 44.48, 12.4457, 1.44};

    EXPECT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(set_swap, case1)
{
    s21::set<double> s21_set_ref = {22.2, 44.48};
    s21::set<double> s21_set_res = {12.4457, 1.44, 22.2};

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 3U);
    EXPECT_EQ(*s21_set_ref.begin(), 1.44);

    EXPECT_EQ(s21_set_res.size(), 2U);
    EXPECT_EQ(*s21_set_res.begin(), 22.2);
}

TEST(set_swap, case2)
{
    s21::set<double> s21_set_ref = {22.2, 44.48};
    s21::set<double> s21_set_res;

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 0U);

    EXPECT_EQ(s21_set_res.size(), 2U);
    EXPECT_EQ(*s21_set_res.begin(), 22.2);
}

TEST(set_swap, case3)
{
    s21::set<double> s21_set_ref;
    s21::set<double> s21_set_res = {12.4457, 1.44, 22.2};

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 3U);
    EXPECT_EQ(*s21_set_ref.begin(), 1.44);

    EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(set_swap, case4)
{
    s21::set<double> s21_set_ref;
    s21::set<double> s21_set_res;

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 0U);
    EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(set_contains, case1)
{
    s21::set<double> s21_set = {22.2, 44.48};

    EXPECT_EQ(s21_set.contains(22.2), true);
    EXPECT_EQ(s21_set.contains(44.48), true);
}

TEST(set_contains, case2)
{
    s21::set<double> s21_set_ref = {22.2, 44.48};
    s21::set<double> s21_set_res;

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 0U);
    EXPECT_EQ(s21_set_ref.contains(22.2), false);
    EXPECT_EQ(s21_set_ref.contains(44.48), false);

    EXPECT_EQ(s21_set_res.size(), 2U);
    EXPECT_EQ(s21_set_res.contains(22.2), true);
    EXPECT_EQ(s21_set_res.contains(44.48), true);
}

TEST(set_contains, case3)
{
    s21::set<double> s21_set_ref;
    s21::set<double> s21_set_res = {12.4457, 1.44, 22.2};

    s21_set_ref.swap(s21_set_res);

    EXPECT_EQ(s21_set_ref.size(), 3U);
    EXPECT_EQ(s21_set_ref.contains(12.4457), true);
    EXPECT_EQ(s21_set_ref.contains(1.44), true);
    EXPECT_EQ(s21_set_ref.contains(22.2), true);

    EXPECT_EQ(s21_set_res.size(), 0U);
    EXPECT_EQ(s21_set_res.contains(12.4457), false);
    EXPECT_EQ(s21_set_res.contains(1.44), false);
    EXPECT_EQ(s21_set_res.contains(22.2), false);
}

TEST(set_contains, case4)
{
    s21::set<double> s21_set;

    EXPECT_EQ(s21_set.size(), 0U);
    EXPECT_EQ(s21_set.contains(12.4457), false);
}

// TEST(set_find, case1)
// {
//     s21::set<double> s21_set;

//     EXPECT_THROW(s21_set.find(23.4), std::out_of_range);
// }

// TEST(set_find, case2)
// {
//     s21::set<double> s21_set = {12.4457, 1.44, 22.2};

//     auto it = s21_set.begin();
//     ++it;
//     EXPECT_EQ(*s21_set.find(12.4457), *it);

//     it--;
//     EXPECT_EQ(*s21_set.find(1.44), *it);

//     it++;
//     it++;
//     EXPECT_EQ(*s21_set.find(22.2), *it);
// }

// TEST(set_emplace, case1)
// {
//     s21::set<int> s21_set;

//     std::vector<std::pair<s21::set<int>::iterator, bool>> emplace1 =
//         s21_set.emplace(9, 9, 9, 23, 98);

//     EXPECT_EQ(*emplace1[0].first, 23);
//     EXPECT_EQ(emplace1[0].second, true);
//     EXPECT_EQ(s21_set.size(), 3U);
// }

// TEST(set_emplace, case2)
// {
//     s21::set<double> s21_set;

//     std::vector<std::pair<s21::set<double>::iterator, bool>> emplace1 =
//         s21_set.emplace(1.4, 2.77, 3.9, 2.77, 3.9);

//     EXPECT_EQ(*emplace1[0].first, 2.77);
//     EXPECT_EQ(emplace1[0].second, true);
//     EXPECT_EQ(s21_set.size(), 3U);
// }

// TEST(set_emplace, case3)
// {
//     s21::set<std::string> s21_set;

//     std::vector<std::pair<s21::set<std::string>::iterator, bool>> emplace1 =
//         s21_set.emplace("hello", "hi", "hi", "hola", "hello");

//     EXPECT_EQ(*emplace1[0].first, "hi");
//     EXPECT_EQ(emplace1[0].second, true);
//     EXPECT_EQ(s21_set.size(), 3U);
// }

// TEST(set_emplace, case4)
// {
//     s21::set<int> s21_set;

//     std::vector<std::pair<s21::set<int>::iterator, bool>> emplace1 =
//         s21_set.emplace(9);

//     EXPECT_EQ(*emplace1[0].first, 9);
//     EXPECT_EQ(emplace1[0].second, true);
//     EXPECT_EQ(s21_set.size(), 1U);
// }

// TEST(set_emplace, case5)
// {
//     s21::set<double> s21_set = {1.4};

//     std::vector<std::pair<s21::set<double>::iterator, bool>> emplace1 =
//         s21_set.emplace(1.4);

//     EXPECT_EQ(emplace1[0].second, false);
//     EXPECT_EQ(s21_set.size(), 1U);
// }

// TEST(set_emplace, case6)
// {
//     s21::set<std::string> s21_set = {"hello"};

//     std::vector<std::pair<s21::set<std::string>::iterator, bool>> emplace1 =
//         s21_set.emplace("hi");

//     EXPECT_EQ(*emplace1[0].first, "hi");
//     EXPECT_EQ(emplace1[0].second, true);
//     EXPECT_EQ(s21_set.size(), 2U);
// }

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

TEST(SetTests, SetDefaultConstructor1)
{
    s21::set<int> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_TRUE(a.empty());
}

TEST(SetTests, SetDefaultConstructor2)
{
    s21::set<std::string> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_TRUE(a.empty());
}

TEST(SetTests, SetInitializerListConstructor1)
{
    s21::set<int> s21_set{1, 2, 5, 12, 1824, 44, 28};
    std::set<int> std_set{1, 2, 5, 12, 1824, 44, 28};

    EXPECT_EQ(s21_set.size(), std_set.size());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();

    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetInitializerListConstructor2)
{
    s21::set<std::string> s21_set{"Shall", "I", "compare", "thee", "to",
                                  "a", "summer\'s", "day", "day"};
    std::set<std::string> std_set{"Shall", "I", "compare", "thee", "to",
                                  "a", "summer\'s", "day", "day"};

    EXPECT_EQ(s21_set.size(), std_set.size());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();

    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetInitializerListConstructor3)
{
    s21::set<int> s({});
    EXPECT_TRUE(s.empty());
}

TEST(SetTests, SetInitializerListConstructor4)
{
    s21::set<int> s({1, 1, 1});
    EXPECT_EQ(s.size(), 1);
}

TEST(SetTests, SetCopyConstructor)
{
    s21::set<double> other{55.52, 1.214, 214.55, 2.4124, 17.8235,
                           99.440, 120.0001, 44.44, 10101.1224, 111.112};

    std::set<double> std_set{55.52, 1.214, 214.55, 2.4124, 17.8235,
                             99.440, 120.0001, 44.44, 10101.1224, 111.112};

    s21::set<double> s21_set(other);
    EXPECT_EQ(s21_set.size(), std_set.size());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();

    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetMoveConstructor1)
{
    s21::set<char> other{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};
    std::set<char> std_set{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};

    s21::set<char> s21_set(std::move(other));
    EXPECT_EQ(s21_set.size(), std_set.size());
    EXPECT_TRUE(other.empty());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();
    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetMoveConstructor2)
{
    s21::set<int> s1;
    s21::set<int> s2(std::move(s1));
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(SetTests, SetCopyOperator)
{
    s21::set<double> other{55.52, 1.214, 214.55, 2.4124, 17.8235,
                           99.440, 120.0001, 44.44, 10101.1224, 111.112};

    std::set<double> std_set{55.52, 1.214, 214.55, 2.4124, 17.8235,
                             99.440, 120.0001, 44.44, 10101.1224, 111.112};

    s21::set<double> s21_set;
    s21_set = other;
    EXPECT_EQ(s21_set.size(), std_set.size());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();

    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetCopyOperator2)
{
    s21::set<int> s1({1, 2, 3});
    s21::set<int> s2({4, 5});
    s2 = s1;
    EXPECT_EQ(s2.size(), 3);
    EXPECT_EQ(s1.size(), 3);
}

TEST(SetTests, SetCopyOperator3)
{
    s21::set<int> s1;
    s21::set<int> s2;
    s2 = s1;
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(SetTests, SetMoveOperator1)
{
    s21::set<char> other{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};
    std::set<char> std_set{'g', 'h', 'k', 'p', 'f', 's', 'c', 'o', 'z', 'a'};

    s21::set<char> s21_set;
    s21_set = std::move(other);
    EXPECT_EQ(s21_set.size(), std_set.size());
    EXPECT_TRUE(other.empty());

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();

    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetMoveOperator2)
{
    s21::set<int> s1({1, 2, 3});
    s21::set<int> s2({4, 5});
    s2 = std::move(s1);
    EXPECT_EQ(s2.size(), 3);
    EXPECT_TRUE(s1.empty());
}

TEST(SetTests, SetMoveOperator3)
{
    s21::set<int> s1;
    s21::set<int> s2;
    s2 = std::move(s1);
    EXPECT_TRUE(s2.empty());
    EXPECT_TRUE(s1.empty());
}

TEST(SetTests, SetIterators1)
{
    s21::set<int> s21_set{1, 124, -145, 251, 0, 888};
    std::set<int> std_set{1, 124, -145, 251, 0, 888};

    auto s21_it = s21_set.begin();
    auto std_it = std_set.begin();
    for (; s21_it != s21_set.end(); ++s21_it, ++std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }

    --s21_it;
    --std_it;

    for (; s21_it != s21_set.begin(); --s21_it, --std_it)
    {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(SetTests, SetIterators2)
{
    s21::set<int> a;
    EXPECT_EQ(a.begin().get_node(), a.end().get_node());
}

TEST(SetTests, SetEmpty)
{
    s21::set<char> a;
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

TEST(SetTests, SetSize)
{
    s21::set<int> a;
    EXPECT_EQ(a.size(), 0);

    a.insert(1);
    EXPECT_EQ(a.size(), 1);

    a.insert(1);
    EXPECT_EQ(a.size(), 1);

    a.insert(2);
    EXPECT_EQ(a.size(), 2);

    a.insert(5);
    EXPECT_EQ(a.size(), 3);

    a.insert(4);
    EXPECT_EQ(a.size(), 4);

    a.insert(3);
    EXPECT_EQ(a.size(), 5);

    a.insert(8);
    EXPECT_EQ(a.size(), 6);

    a.insert(9);
    EXPECT_EQ(a.size(), 7);

    a.insert(10);
    EXPECT_EQ(a.size(), 8);

    a.insert(2);
    EXPECT_EQ(a.size(), 8);
}

TEST(SetTests, SetMaxSize)
{
    s21::set<int> a;
    std::set<int> b;

    EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(SetTests, SetClear1)
{
    s21::set<int> a{125, 12, 124, 11, 1, 17, 18, 101,
                    1010, 1023, 2025, 1998, 1995, 1941, 1945, 1812,
                    1861, 988, 1991, 1914, 1918, 1939};

    EXPECT_EQ(a.size(), 22);
    a.clear();
    EXPECT_TRUE(a.empty());
    a.insert(5);
    EXPECT_EQ(a.size(), 1);
    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(SetTests, SetClear2)
{
    s21::set<int> a;

    a.clear();
    EXPECT_TRUE(a.empty());
    a.insert(5);
    EXPECT_EQ(a.size(), 1);
    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(SetTests, SetInsert1)
{
    s21::set<int> a;
    a.insert(0);
    EXPECT_EQ(a.size(), 1);
    for (int i = 1; i < 1000; ++i)
    {
        a.insert(i);
    }
    EXPECT_EQ(a.size(), 1000);
    int counter = 0;
    for (int i : a)
    {
        EXPECT_EQ(i, counter);
        ++counter;
    }

    for (int i = 0; i < 1000; ++i)
    {
        a.insert(i);
    }
    EXPECT_EQ(a.size(), 1000);
}

TEST(SetTests, SetErase1)
{
    s21::set<int> a;
    for (int i = 0; i < 1000; ++i)
    {
        a.insert(i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        EXPECT_EQ(*a.begin(), i);
        a.erase(a.begin());
    }
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.begin(), a.end());
    a.erase(a.begin());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.begin(), a.end());
}

TEST(SetTests, SetErase2)
{
    s21::set<int> a;
    for (int i = 0; i < 1000; ++i)
    {
        a.insert(i);
    }

    for (int i = 999; i >= 0; --i)
    {
        auto it = --a.end();
        EXPECT_EQ(*it, i);
        a.erase(it);
    }

    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.begin(), a.end());
    a.erase(a.begin());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.begin(), a.end());
}

TEST(SetTests, SetSwap)
{
    s21::set<int> s1;
    s21::set<int> s2({1, 2, 3});
    s1.swap(s2);
    EXPECT_TRUE(s2.empty());
    EXPECT_EQ(s1.size(), 3);
}

TEST(SetTests, SetMerge1)
{
    s21::set<int> s1({1, 3, 5});
    s21::set<int> s2({2, 4, 6});
    s1.merge(s2);
    EXPECT_EQ(s1.size(), 6);
    EXPECT_TRUE(s2.empty());
}

TEST(SetTests, SetMerge2)
{
    s21::set<int> s1({1, 2, 3});
    s21::set<int> s2({2, 3, 4});
    s1.merge(s2);
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(s2.size(), 2);
}

TEST(SetTests, SetFind1)
{
    s21::set<int> a{1, 2, 3, 4};

    // Проверка find(2)
    // auto it2 = a.find(2);
    auto end_it = a.end();
    // EXPECT_NE(it2, end_it);

    // Проверка find(1) - должен быть begin
    auto it1 = a.find(1);
    auto begin_it = a.begin();
    EXPECT_EQ(it1, begin_it);

    // Проверка find(4) - должен быть последним элементом
    auto it4 = a.find(4);
    auto last_it = a.end();
    --last_it; // получаем последний элемент
    EXPECT_EQ(it4, last_it);

    // Проверка find(5) - не должен найтись
    auto it5 = a.find(5);
    end_it = a.end(); // обновляем end iterator
    EXPECT_EQ(it5, end_it);
}

TEST(SetTests, SetFind2)
{
    s21::set<int> a;

    // Поиск в пустом множестве
    auto not_found = a.find(2);
    auto end_it = a.end();
    EXPECT_EQ(not_found, end_it);

    // Поиск после вставки
    a.insert(2);
    auto found = a.find(2);
    end_it = a.end(); // обновляем end iterator
    EXPECT_NE(found, end_it);
}

TEST(SetTests, SetFind3)
{
    s21::set<int> a;
    for (int i = 0; i < 1000; ++i)
    {
        a.insert(i);
    }

    auto it = a.begin();
    for (int i = 0; i < 1000; ++i)
    {
        EXPECT_EQ(a.find(i), it);
        ++it;
    }
}

TEST(SetTests, SetContains1)
{
    s21::set<int> a;
    for (int i = 0; i < 1000; ++i)
    {
        a.insert(i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        EXPECT_TRUE(a.contains(i));
    }

    EXPECT_FALSE(a.contains(1000));
}

// TEST(SetTests, SetInsertMany)
// {
//     s21::set<int> a;
//     std::set<int> b{1, 2, 3, 4, 5};
//     a.insert_many();
//     EXPECT_EQ(a.size(), 0);

//     a.insert_many(1);
//     EXPECT_EQ(a.size(), 1);

//     a.insert_many(5);
//     EXPECT_EQ(a.size(), 2);

//     a.insert_many(2, 3, 4);
//     EXPECT_EQ(a.size(), 5);

//     auto s21_it = a.begin();
//     auto std_it = b.begin();
//     for (; s21_it != a.end(); s21_it++, std_it++)
//     {
//         EXPECT_EQ(*s21_it, *std_it);
//     }

//     std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     a.insert_many(6, 7, 8, 9, 10);
//     EXPECT_EQ(a.size(), 10);

//     s21_it = a.begin();
//     std_it = c.begin();
//     for (; s21_it != a.end(); s21_it++, std_it++)
//     {
//         EXPECT_EQ(*s21_it, *std_it);
//     }
// }