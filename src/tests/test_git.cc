#include <gtest/gtest.h>

#include <map>

#include "map.h"

TEST(TestMap, Size_map) {
  s21::map<std::string, int> myMap{{"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3},
                                   {"ключ04", 4}, {"ключ05", 5}, {"ключ06", 6},
                                   {"ключ07", 7}, {"ключ08", 8}, {"ключ09", 9},
                                   {"ключ10", 10}};

  // s21::map<std::string, int> myMap{
  //   std::pair<const std::string, int>("ключ01", 1)
  // };

  // myMap.print_start();
  // std::cout << "Size: " << myMap.size() << std::endl;
  s21::map<std::string, int>::iterator iter;

  iter = myMap.begin();  // срабатывает оператор перемещения а потом только
                         // копирования и меняетсяя нил
  iter++;
  iter++;
  iter++;
  iter++;
  iter++;
  iter++;
  iter++;
  iter++;
  iter++;  //
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter--;
  // iter++;
  // iter++;
  // iter++;
  myMap.erase(iter);

  // std::cout << (int)myMap.size() << std::endl;
  // s21::map<std::string, int>::Node A = new Node;
  EXPECT_EQ((int)myMap.size(), 9);
  std::cout << "После удаления" << std::endl;
  myMap.print_start();

  // iter++; // sega
  // myMap.erase(iter);  // sega
  // EXPECT_EQ((int)myMap.size(), 9);

  // myMap.print_start();
}

TEST(TestMapCopyMoveConstructor, Size_map) {
  s21::map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}};

  myMap.print_start();

  s21::map<std::string, int>
      myMap_1;  // object 0x1000000000000000: pointer being freed was not
  myMap_1 = myMap;
  // allocated

  EXPECT_EQ((int)myMap.size(), (int)myMap_1.size());

  myMap.print_start();
  myMap_1.print_start();

  s21::map<std::string, int> myMap_2(std::move(myMap_1));

  myMap_2.print_start();
  std::cout << "myMap_1: " << std::endl;
  myMap_1.print_start();
}

TEST(TestSwapAtConstructor, Size_map) {
  s21::map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // myMap.print_start();

  s21::map<std::string, int> myMap_1 = {
      {"ключ10", 1}, {"ключ09", 2}, {"ключ08", 3}, {"ключ07", 4},
      {"ключ06", 5}, {"ключ05", 6}, {"ключ04", 7}, {"ключ03", 8},
      {"ключ02", 9}, {"ключ01", 10}

  };

  myMap_1.insert("ключ06", 666);  // beck
  myMap.swap(myMap_1);

  // EXPECT_EQ((int)myMap.size(), myMap.at("ключ10"));

  std::cout << "TestSwapmyMap: " << std::endl;
  myMap.print_start();
  std::cout << "TestSwapmyMap_1: " << std::endl;
  myMap_1.print_start();

  myMap_1.insert_or_assign("ключ06", 666);  // вернуть
  std::cout << "Testinsert_or_assign: После вставки: " << std::endl;
  myMap.at("ключ10") = 111;
  myMap_1["ключ11"] = 1112;
  myMap_1.print_start();
  std::cout << myMap.at("ключ10") << std::endl;
  // myMap.at("ключ10");
}

TEST(TestEmptyMaxSizeClear, Size_map) {
  s21::map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // myMap.print_start();
  EXPECT_EQ((int)myMap.size(), 10);
  myMap.print_start();
  myMap.empty();

  std::cout << "myMap.empty(): " << myMap.empty() << std::endl;

  EXPECT_EQ(myMap.empty(), false);

  EXPECT_EQ(myMap.max_size(), 18446744073709551615ULL);

  myMap.clear();
  myMap.print_start();

  EXPECT_EQ((int)myMap.size(), 0);  // 10 почему то
  myMap.print_start();
}

TEST(TestPrintEmptyTree, Size_map) {
  s21::map<std::string, int> myMap;
  myMap.print_start();
}

TEST(TestMerge, Size_map) {
  s21::map<int, std::string> map1{{1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};
  s21::map<int, std::string> map2{
      {3, "Coconut"}, {4, "Date"}, {5, "Elderberry"}};

  // map1.insert({1, "Apple"});
  // map1.insert({2, "Banana"});
  // map1.insert({3, "Cherry"});

  // map2.insert({3, "Coconut"});
  // map2.insert({4, "Date"});
  // map2.insert({5, "Elderberry"});

  map1.merge(map2);
  map1.print_start();
  map2.print_start();  // beck
  EXPECT_EQ((int)map1.size(), 5);
}

// TEST(TestTest, Size_map) {
//   s21::map<int, std::string> map1{{2, "Apple"}, {1, "Banana"}};

//   // map1.insert({1, "Apple"});
//   // map1.insert({2, "Banana"});
//   // map1.insert({3, "Cherry"});

//   // map2.insert({3, "Coconut"});
//   // map2.insert({4, "Date"});
//   // map2.insert({5, "Elderberry"});

//   map1.print_start();
//   // map1.erase((map1.end())--);
//   map1.print_start();
//   EXPECT_EQ((int)map1.size(), 2);
// }

TEST(map_constructor, case1) {
  s21::map<int, int> s21_map_int;
  s21::map<double, double> s21_map_double;
  s21::map<std::string, std::string> s21_map_string;

  EXPECT_EQ(s21_map_int.size(), 0U);
  EXPECT_EQ(s21_map_double.size(), 0U);
  EXPECT_EQ(s21_map_string.size(), 0U);
}

TEST(map_constructor, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_constructor, case3) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_constructor, case4) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

// TEST(ma/

// конструктор копирования
TEST(map_constructor, case6) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(map_constructor, case7) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  s21::map<double, std::string> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(map_constructor, case8) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  s21::map<std::string, int> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

// конструктор перемещения
TEST(map_constructor, case9) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

TEST(map_constructor, case10) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  s21::map<double, std::string> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

TEST(map_constructor, case11) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  s21::map<std::string, int> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

// оператор =
TEST(map_constructor, case12) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

TEST(map_constructor, case13) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3};

  s21::map<double, std::string> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0);
  EXPECT_EQ(s21_map_res.size(), 3);
}

TEST(map_constructor, case14) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map_ref = {pair1, pair2, pair3};

  s21::map<std::string, int> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.size(), 0);
  EXPECT_EQ(s21_map_res.size(), 3);
}

// TEST(map_constructor, case15) {
//   std::pair<int, double> pair1{9, 1.4};
//   std::pair<int, double> pair2{23, 2.77};
//   std::pair<int, double> pair3{98, 3.9};

//   s21::map<int, double> s21_map_ref_int{pair1, pair2, pair3};
//   s21::map<int, double> s21_map_res_int{s21_map_ref_int};

//   std::pair<double, std::string> pair4{1.4, "hello"};
//   std::pair<double, std::string> pair5{2.77, "hi"};
//   std::pair<double, std::string> pair6{3.9, "hola"};

//   s21::map<double, std::string> s21_map_ref_double{pair4, pair5, pair6};
//   s21::map<double, std::string> s21_map_res_double{s21_map_ref_double};

//   std::pair<std::string, int> pair7{"hello", 1};
//   std::pair<std::string, int> pair8{"hi", 2};
//   std::pair<std::string, int> pair9{"hola", 3};

//   s21::map<std::string, int> s21_map_ref_string{pair7, pair8, pair9};
//   s21::map<std::string, int> s21_map_res_string{s21_map_ref_string};

//   auto it_res_int = s21_map_res_int.begin();
//   for (auto it_ref_int = s21_map_ref_int.begin();
//        *it_ref_int != *(s21_map_ref_int.end()); ++it_ref_int) {
//     EXPECT_EQ(it_res_int->first, it_ref_int->first);
//     it_res_int++;
//   }

//   auto it_res_double = s21_map_res_double.begin();
//   for (auto it_ref_double = s21_map_ref_double.begin();
//        *it_ref_double != *(s21_map_ref_double.end()); ++it_ref_double) {
//     EXPECT_EQ(it_res_double->first, it_ref_double->first);
//     it_res_double++;
//   }

//   auto it_res_string = s21_map_res_string.begin();
//   for (auto it_ref_string = s21_map_ref_string.begin();
//        *it_ref_string != *(s21_map_ref_string.end()); ++it_ref_string) {
//     EXPECT_EQ(it_res_string->first, it_ref_string->first);
//     it_res_string++;
//   }
// }

TEST(map_insert, case1) {  //
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};

  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);  //
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case2) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};
  std::pair<double, std::string> pair4{2.77, "hi"};
  std::pair<double, std::string> pair5{3.9, "hola"};

  s21::map<double, std::string, false> s21_map;

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hi", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello", 1};

  s21::map<std::string, int> s21_map;

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case4) {
  std::pair<int, double> pair1{9, 1.4};

  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair1);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  s21::map<double, std::string> s21_map = {pair1};

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};

  s21::map<std::string, int> s21_map = {pair1};

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.size(), 2U);
}

TEST(map_insert, case7) {
  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(23, 2.77);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(98, 3.9);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case8) {
  s21::map<double, std::string> s21_map;

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(1.4, "hello");
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(2.77, "hi");
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(3.9, "hola");
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(2.77, "hi");
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(3.9, "hola");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case9) {
  s21::map<std::string, int> s21_map;

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert("hello", 1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert("hola", 3);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert("hello", 1);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case10) {
  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case11) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  s21::map<double, std::string> s21_map = {pair1};

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(1.4, "hello");
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case12) {
  std::pair<std::string, int> pair1{"hello", 1};

  s21::map<std::string, int> s21_map = {pair1};

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.size(), 2U);
}

TEST(map_begin, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{7, 151.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{2, 3.9};

  s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.begin();

  EXPECT_EQ(min_value->first, 2);
}

TEST(map_begin, case2) {
  std::pair<double, std::string> pair1{11.4, "hello"};
  std::pair<double, std::string> pair2{2.770001, "hee"};
  std::pair<double, std::string> pair3{3.901, "hola"};
  std::pair<double, std::string> pair4{2.77, "hi"};
  std::pair<double, std::string> pair5{3.9, "hee-hee"};

  s21::map<double, std::string> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.begin();

  EXPECT_EQ(min_value->first, 2.77);
}

TEST(map_begin, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hi-hi", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello, there", 1};

  s21::map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.begin();

  EXPECT_EQ(min_value->first, "hello");
}

TEST(map_begin, case4) {
  s21::map<int, double> s21_map;
  // std::map<int, double> stl21_map;

  //   EXPECT_THROW(s21_map.begin(),
  //                std::out_of_range);  // зачем??
  // EXPECT_THROW(stl21_map.begin(),
  // std::out_of_range);  // зачем??
}

TEST(map_begin, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  s21::map<double, std::string> s21_map = {pair1, pair1};

  auto min_value = s21_map.begin();

  EXPECT_EQ(min_value->first, 1.4);
  EXPECT_EQ(min_value->second, "hello");
}

TEST(map_begin, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hello", 2};
  std::pair<std::string, int> pair3{"hello", 45};

  s21::map<std::string, int> s21_map = {pair1, pair2, pair3};

  auto min_value = s21_map.begin();

  EXPECT_EQ(min_value->first, "hello");
  EXPECT_EQ(min_value->second, 1);
}

// TEST(map_end, case1) {
//   std::pair<int, double> pair1{9, 1.4};
//   std::pair<int, double> pair2{15, 1.456};
//   std::pair<int, double> pair3{7, 151.4};
//   std::pair<int, double> pair4{23, 2.77};
//   std::pair<int, double> pair5{2, 3.9};

//   s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};

//   auto max_value = s21_map.end();

//   EXPECT_EQ(max_value->first, 23);
// }

// TEST(map_end, case2) {
//   std::pair<double, std::string> pair1{11.4, "hello"};
//   std::pair<double, std::string> pair2{2.770001, "hee"};
//   std::pair<double, std::string> pair3{3.901, "hola"};
//   std::pair<double, std::string> pair4{11.400000001, "hi"};
//   std::pair<double, std::string> pair5{3.9, "hee-hee"};

//   s21::map<double, std::string> s21_map = {pair1, pair2, pair3, pair4,
//   pair5};

//   auto max_value = s21_map.end();
//   max_value--;

//   EXPECT_EQ(max_value->first, 11.400000001);
// }

// TEST(map_end, case3) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};
//   std::pair<std::string, int> pair3{"hola-hola", 2};
//   std::pair<std::string, int> pair4{"hola", 3};
//   std::pair<std::string, int> pair5{"hello, there", 1};

//   s21::map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

//   auto max_value = s21_map.end();

//   EXPECT_EQ(max_value->first, "hola-hola");
// }

// TEST(map_end, case4) {
//   s21::map<int, double> s21_map;

//   EXPECT_THROW(s21_map.end(), std::out_of_range);  //???
// }

// TEST(map_end, case5) {
//   std::pair<double, std::string> pair1{1.4, "hello"};

//   s21::map<double, std::string> s21_map = {pair1, pair1};

//   auto max_value = s21_map.end();

//   EXPECT_EQ(max_value->first, 1.4);
//   EXPECT_EQ(max_value->second, "hello");
// }

// TEST(map_end, case6) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hello", 2};
//   std::pair<std::string, int> pair3{"hello", 45};

//   s21::map<std::string, int> s21_map = {pair1, pair2, pair3};

//   auto max_value = s21_map.end();

//   EXPECT_EQ(max_value->first, "hello");
//   EXPECT_EQ(max_value->second, 1);
// }

// TEST(map_balance, case1) {
//   std::pair<int, double> pair1{1, 1.4};
//   std::pair<int, double> pair2{15, 1.456};
//   std::pair<int, double> pair3{5, 151.4};

//   s21::map<int, double> s21_map = {pair1, pair2, pair3};

//   auto max_value = s21_map.end();

//   EXPECT_EQ(max_value->first, 15);
//   EXPECT_EQ(s21_map.size(), 3U);
// }

// TEST(map_balance, case2) {
//   std::pair<double, std::string> pair1{11.4, "hello"};
//   std::pair<double, std::string> pair2{2.770001, "hi"};
//   std::pair<double, std::string> pair3{3.901, "hola"};

//   s21::map<double, std::string> s21_map = {pair1, pair2, pair3};

//   auto min_value = s21_map.end();

//   EXPECT_EQ(min_value->first, 11.4);
//   EXPECT_EQ(s21_map.size(), 3U);
// }

// TEST(map_balance, case3) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};
//   std::pair<std::string, int> pair3{"hola-hola", 2};
//   std::pair<std::string, int> pair4{"hola", 3};
//   std::pair<std::string, int> pair5{"hello, there", 1};

//   s21::map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

//   auto min_value = s21_map.end();

//   EXPECT_EQ(min_value->first, "hola-hola");
//   EXPECT_EQ(s21_map.size(), 5U);
// }

// TEST(map_balance, case4) {
//   std::pair<int, int> pair1{10, 10};
//   std::pair<int, int> pair2{5, 5};
//   std::pair<int, int> pair3{20, 20};
//   std::pair<int, int> pair4{30, 30};
//   std::pair<int, int> pair5{1543, 1543};

//   s21::map<int, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

//   EXPECT_EQ(s21_map.end()->first, 1543);
//   EXPECT_EQ(s21_map.begin()->first, 5);
//   EXPECT_EQ(s21_map.size(), 5U);
// }

// TEST(map_balance, case5) {
//   std::pair<int, int> pair1{30, 30};
//   std::pair<int, int> pair2{5, 5};
//   std::pair<int, int> pair3{43, 43};
//   std::pair<int, int> pair4{1, 1};
//   std::pair<int, int> pair5{20, 20};
//   std::pair<int, int> pair6{40, 60};
//   std::pair<int, int> pair7{60, 60};
//   std::pair<int, int> pair8{35, 35};
//   std::pair<int, int> pair9{32, 32};

//   s21::map<int, int> s21_map = {pair1, pair2, pair3, pair4, pair5,
//                                 pair6, pair7, pair8, pair9};

//   EXPECT_EQ(s21_map.end()->first, 60);
//   EXPECT_EQ(s21_map.begin()->first, 1);
//   EXPECT_EQ(s21_map.size(), 9U);
// }

TEST(map_erase, case1) {
  std::pair<int, int> pair1{10, 10};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{15, 15};
  std::pair<int, int> pair4{4, 4};
  std::pair<int, int> pair5{18, 18};
  std::pair<int, int> pair6{13, 13};
  std::pair<int, int> pair7{16, 16};

  s21::map<int, int> s21_map = {pair1, pair2, pair3, pair4,
                                pair5, pair6, pair7};

  s21::map<int, int>::iterator it;
  it = s21_map.begin();
  it++;               // 5
  it++;               // 10
  it++;               // 13
  it++;               // 15
  s21_map.erase(it);  // 15-
  EXPECT_EQ(s21_map.begin()->first, 4);
  // EXPECT_EQ(s21_map.end()->first, 18);
  EXPECT_EQ(s21_map.size(), 6);

  it = s21_map.begin();  // 4
  s21_map.erase(it);     // 4-
  EXPECT_EQ(s21_map.begin()->first, 5);
  // EXPECT_EQ(s21_map.end()->first, 18);
  EXPECT_EQ(s21_map.size(), 5);

  it = s21_map.begin();  // 5
                         // try {
  it++;

  // Exception has occurred.
  // EXC_BAD_ACCESS (code=EXC_I386_GPFLT)
  s21_map.erase(it);  // 10 -

  // } catch (const std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }

  // try {
  /* code */
  EXPECT_EQ(s21_map.begin()->first, 5);
  // } catch (const std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }

  EXPECT_EQ(s21_map.size(), 4);

  EXPECT_EQ(s21_map.begin()->first, 5);
  // EXPECT_EQ(s21_map.end()->first, 16);
  EXPECT_EQ(s21_map.size(), 4);

  it = s21_map.begin();
  it++;
  s21_map.erase(it);

  it = s21_map.begin();
  it++;
  s21_map.erase(it);

  it = s21_map.begin();
  s21_map.erase(it);

  EXPECT_EQ(s21_map.size(), 1);
}

TEST(map_erase, case2) {
  std::pair<int, int> pair1{30, 30};
  std::pair<int, int> pair2{1543, 1543};

  s21::map<int, int> s21_map = {pair1, pair2};

  auto it = s21_map.begin();
  it++;
  s21_map.erase(it);
  it = s21_map.begin();
  s21_map.erase(it);

  EXPECT_EQ(s21_map.size(), 0U);
}

TEST(map_erase, case5) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  auto it = s21_map.begin();
  //   EXPECT_THROW(it--, std::out_of_range);
  s21_map.erase(it);     // {1.44, 3};
  it = s21_map.begin();  // {12.4457, 2}
  ++it;
  ++it;
  s21_map.print_start();
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.size(), 3U);
}

// TEST(MapComparison, IteratorDecrementAndErase) {
//   // Тестовые данные
//   std::pair<double, int> pair1{22.2, 1};
//   std::pair<double, int> pair2{44.48, 1};
//   std::pair<double, int> pair3{12.4457, 2};
//   std::pair<double, int> pair4{1.44, 3};

//   // Ваша реализация
//   s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4};

//   // Стандартная реализация
//   std::map<double, int> std_map = {pair1, pair2, pair3, pair4};

//   // Размеры должны совпадать перед операциями
//   EXPECT_EQ(s21_map.size(), std_map.size());
//   EXPECT_EQ(s21_map.size(), 4U);

//   // Тест 1: Декремент от begin() и erase
//   auto s21_it = s21_map.begin();
//   auto std_it = std_map.begin();

//   // Проверяем, что begin() совпадает
//   EXPECT_DOUBLE_EQ(s21_it->first, std_it->first);
//   EXPECT_EQ(s21_it->second, std_it->second);

//   // Декремент от begin() - неопределенное поведение, но проверим
//   // В std::map это может привести к UB, так что будем осторожны
//   try {
//     --s21_it;
//     // Если не выброшено исключение, проверяем поведение
//     s21_map.erase(s21_it);
//   } catch (const std::exception& e) {
//     // Ожидаемое поведение - исключение при декременте begin()
//     SUCCEED();
//   }

//   try {
//     --std_it;
//     std_map.erase(std_it);
//   } catch (const std::exception& e) {
//     SUCCEED();
//   }

//   // После операций размеры должны совпадать
//   EXPECT_EQ(s21_map.size(), std_map.size());
// }

TEST(map_erase, case6) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{6.84, 2};
  std::pair<double, int> pair5{1.44, 3};

  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.begin();
  ++it;
  ++it;
  ++it;
  s21_map.erase(it);
  it = s21_map.begin();
  it++;
  it++;
  it++;
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.size(), 4U);
}

TEST(map_erase, case7) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{12.4457, 2};
  std::pair<double, int> pair3{56.84, 2};
  std::pair<double, int> pair4{941.44, 3};
  std::pair<double, int> pair5{44.48, 1};

  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.begin();
  ++it;
  s21_map.erase(it);
  it = s21_map.begin();
  ++it;
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.size(), 4U);
}

TEST(map_erase, case8) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  auto it = s21_map.begin();
  ++it;
  s21_map.erase(it);
  it = s21_map.begin();
  ++it;
  EXPECT_EQ(it->first, 22.2);
  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_empty, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  EXPECT_EQ(s21_map.empty(), 0);
}

TEST(map_empty, case2) {
  s21::map<double, int> s21_map;

  EXPECT_EQ(s21_map.empty(), 1);
}

TEST(map_swap, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};
  std::pair<double, int> pair5{22.2, 15};

  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res = {pair3, pair4, pair5};

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.begin()->first, 1.44);

  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.begin()->first, 22.2);
}

TEST(map_swap, case2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res;

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 0U);

  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.begin()->first, 22.2);
}

TEST(map_swap, case3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};

  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res = {pair1, pair2, pair3};

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.begin()->first, 1.44);

  EXPECT_EQ(s21_map_res.size(), 0U);
}

TEST(map_swap, case4) {
  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res;

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 0U);
}

TEST(map_contains, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  s21::map<double, int> s21_map = {pair1, pair2};

  EXPECT_EQ(s21_map.contains(22.2), true);
  EXPECT_EQ(s21_map.contains(44.48), true);
}

TEST(map_contains, case2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res;

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_ref.contains(22.2), false);
  EXPECT_EQ(s21_map_ref.contains(44.48), false);

  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.contains(22.2), true);
  EXPECT_EQ(s21_map_res.contains(44.48), true);
}

TEST(map_contains, case3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};

  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res = {pair1, pair2, pair3};

  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.contains(12.4457), true);
  EXPECT_EQ(s21_map_ref.contains(1.44), true);
  EXPECT_EQ(s21_map_ref.contains(22.2), true);

  EXPECT_EQ(s21_map_res.size(), 0U);
  EXPECT_EQ(s21_map_res.contains(12.4457), false);
  EXPECT_EQ(s21_map_res.contains(1.44), false);
  EXPECT_EQ(s21_map_res.contains(22.2), false);
}

TEST(map_contains, case4) {
  s21::map<double, int> s21_map;

  EXPECT_EQ(s21_map.size(), 0U);
  EXPECT_EQ(s21_map.contains(12.4457), false);
}

TEST(map_at, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};

  s21::map<int, double> s21_map_int{pair1,  pair2,  pair3,
                                    pair11, pair22, pair33};
  EXPECT_EQ(s21_map_int.at(9), 1.4);
  EXPECT_EQ(s21_map_int.at(23), 2.77);
  EXPECT_EQ(s21_map_int.at(98), 3.9);
  EXPECT_EQ(s21_map_int.at(78), 3.9);
  EXPECT_EQ(s21_map_int.at(88), 3.9);
  EXPECT_EQ(s21_map_int.at(108), 3.9);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  s21::map<double, std::string> s21_map_double{pair4, pair5, pair6};
  EXPECT_EQ(s21_map_double.at(1.4), "hello");
  EXPECT_EQ(s21_map_double.at(2.77), "hi");
  EXPECT_EQ(s21_map_double.at(3.9), "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  s21::map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string.at("hello"), 1);
  EXPECT_EQ(s21_map_string.at("hi"), 2);
  EXPECT_EQ(s21_map_string.at("hola"), 3);
}

TEST(map_brackets, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};

  s21::map<int, double> s21_map_int{pair1,  pair2,  pair3,
                                    pair11, pair22, pair33};
  EXPECT_EQ(s21_map_int[9], 1.4);
  EXPECT_EQ(s21_map_int[23], 2.77);
  EXPECT_EQ(s21_map_int[98], 3.9);
  EXPECT_EQ(s21_map_int[78], 3.9);
  EXPECT_EQ(s21_map_int[88], 3.9);
  EXPECT_EQ(s21_map_int[108], 3.9);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  s21::map<double, std::string> s21_map_double{pair4, pair5, pair6};
  EXPECT_EQ(s21_map_double[1.4], "hello");
  EXPECT_EQ(s21_map_double[2.77], "hi");
  EXPECT_EQ(s21_map_double[3.9], "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  s21::map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string["hello"], 1);
  EXPECT_EQ(s21_map_string["hi"], 2);
  EXPECT_EQ(s21_map_string["hola"], 3);
}

TEST(map_brackets, case2) {
  std::pair<int, int> pair1{9, 14};
  std::pair<int, int> pair2{23, 277};
  std::pair<int, int> pair3{8, 39};

  s21::map<int, int> s21_map_int = {pair1, pair2, pair3};

  s21_map_int[78] = 78;
  s21_map_int[88] = 88;
  s21_map_int[108] = 108;

  s21_map_int.print_start();

  EXPECT_EQ(s21_map_int[9], 14);
  EXPECT_EQ(s21_map_int[23], 277);
  EXPECT_EQ(s21_map_int[8], 39);
  EXPECT_EQ(s21_map_int[78], 78);
  EXPECT_EQ(s21_map_int[88], 88);
  EXPECT_EQ(s21_map_int[108], 108);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  s21::map<double, std::string> s21_map_double{pair4, pair5};
  s21_map_double[3.9] = "hola";

  EXPECT_EQ(s21_map_double[1.4], "hello");
  EXPECT_EQ(s21_map_double[2.77], "hi");
  EXPECT_EQ(s21_map_double[3.9], "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  s21::map<std::string, int> s21_map_string{pair7};
  s21_map_string["hi"] = 2;
  s21_map_string["hola"] = 3;

  EXPECT_EQ(s21_map_string["hello"], 1);
  EXPECT_EQ(s21_map_string["hi"], 2);
  EXPECT_EQ(s21_map_string["hola"], 3);
}

TEST(map_merge, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 4.59};
  std::pair<int, double> pair22{88, 12.902};
  std::pair<int, double> pair33{108, 56.41};

  s21::map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  s21::map<int, double> s21_map_int_res{pair11, pair22, pair33};

  s21_map_int_res.merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.size(), 6U);
}

TEST(map_merge, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  s21::map<int, double> s21_map_int_res;

  s21_map_int_res.merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.size(), 3U);
}

TEST(map_merge, case3) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_int_ref;
  s21::map<int, double> s21_map_int_res{pair1, pair2, pair3};

  EXPECT_EQ(s21_map_int_res.size(), 3U);
}

TEST(map_merge, case4) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair4{1, 22.2};
  std::pair<int, double> pair5{8, 44.48};
  std::pair<int, double> pair6{32, 12.4457};

  s21::map<int, double> s21_map_int_ref = {pair1, pair2, pair3, pair4};
  s21::map<int, double> s21_map_int_res = {pair5, pair6};

  s21_map_int_res.merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.size(), 6U);
}

// TEST(map_emplace, case1) {
//   std::pair<int, double> pair1{9, 1.4};
//   std::pair<int, double> pair2{9, 1.4};
//   std::pair<int, double> pair3{9, 1.4};
//   std::pair<int, double> pair4{23, 2.77};
//   std::pair<int, double> pair5{8, 3.9};

//   s21::map<int, double> s21_map;

//   std::vector<std::pair<s21::map<int, double>::iterator, bool>> emplace1 =
//       s21_map.emplace(pair1, pair2, pair3, pair4, pair5);

//   EXPECT_EQ(emplace1[0].first->first, 9);
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.size(), 3U);
// }

// TEST(map_emplace, case2) {
//   std::pair<double, std::string> pair1{1.4, "hello"};
//   std::pair<double, std::string> pair2{2.77, "hi"};
//   std::pair<double, std::string> pair3{3.9, "hola"};
//   std::pair<double, std::string> pair4{2.77, "hi"};
//   std::pair<double, std::string> pair5{3.9, "hola"};

//   s21::map<double, std::string> s21_map;

//   std::vector<std::pair<s21::map<double, std::string>::iterator, bool>>
//       emplace1 = s21_map.emplace(pair1, pair2, pair3);

//   EXPECT_EQ(emplace1[0].first->first, 2.77);
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.size(), 3U);
// }

// TEST(map_emplace, case3) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};
//   std::pair<std::string, int> pair3{"hi", 2};
//   std::pair<std::string, int> pair4{"hola", 3};
//   std::pair<std::string, int> pair5{"hello", 1};

//   s21::map<std::string, int> s21_map;

//   std::vector<std::pair<s21::map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.emplace(pair1, pair2, pair3, pair4, pair5);

//   EXPECT_EQ(emplace1[0].first->first, "hi");
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.size(), 3U);
// }

// TEST(map_emplace, case4) {
//   std::pair<int, double> pair1{9, 1.4};

//   s21::map<int, double> s21_map;

//   std::vector<std::pair<s21::map<int, double>::iterator, bool>> emplace1 =
//       s21_map.emplace(pair1);

//   EXPECT_EQ(emplace1[0].first->first, 9);
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.size(), 1U);
// }

// TEST(map_emplace, case5) {
//   std::pair<double, std::string> pair1{1.4, "hello"};

//   s21::map<double, std::string> s21_map = {pair1};

//   std::vector<std::pair<s21::map<double, std::string>::iterator, bool>>
//       emplace1 = s21_map.emplace(pair1);

//   EXPECT_EQ(emplace1[0].second, false);
//   EXPECT_EQ(s21_map.size(), 1U);
// }

// TEST(map_emplace, case6) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};

//   s21::map<std::string, int> s21_map = {pair1};

//   std::vector<std::pair<s21::map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.emplace(pair2);

//   EXPECT_EQ(emplace1[0].first->first, "hi");
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.size(), 2U);
// }

TEST(MapTests, DefaultConstructor1) {
  s21::map<int, int> a;
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.empty());
}

TEST(MapTests, DefaultConstructor2) {
  s21::map<int, char> a;
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.empty());
}

TEST(MapTests, DefaultConstructor3) {
  s21::map<int, std::string> a;
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.empty());
}

TEST(MapTests, DefaultConstructor) {
  s21::map<int, double> a;
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.empty());
}

TEST(MapTests, InitializerListConstructor1) {
  s21::map<int, double> s21_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, InitializerListConstructor3) {
  s21::map<std::string, double> s21_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  std::map<std::string, double> std_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, CopyConstructor1) {
  s21::map<int, double> s21_other{
      {1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  s21::map<int, double> s21_map(s21_other);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, CopyConstructor2) {
  s21::map<std::string, double> s21_other{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  std::map<std::string, double> std_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  s21::map<std::string, double> s21_map(s21_other);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, MoveConstructor1) {
  s21::map<int, double> s21_other{
      {1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  s21::map<int, double> s21_map(std::move(s21_other));

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_other.size(), 0);

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, MoveConstructor2) {
  s21::map<std::string, double> s21_other{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  std::map<std::string, double> std_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  s21::map<std::string, double> s21_map(std::move(s21_other));

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_other.size(), 0);

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, OperatorCopy) {
  s21::map<int, double> s21_other{
      {1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  s21::map<int, double> s21_map;
  s21_map = s21_other;

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, OperatorMove) {
  s21::map<std::string, double> s21_other{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  std::map<std::string, double> std_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  s21::map<std::string, double> s21_map;
  s21_map = std::move(s21_other);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, at1) {
  s21::map<int, double> s21_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  EXPECT_EQ(s21_map.at(1), std_map.at(1));
  EXPECT_EQ(s21_map.at(5), std_map.at(5));
  EXPECT_EQ(s21_map.at(8), std_map.at(8));
  EXPECT_EQ(s21_map.at(10), std_map.at(10));

  EXPECT_THROW(s21_map.at(12), std::out_of_range);
}

TEST(MapTests, at2) {
  s21::map<std::string, double> s21_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  std::map<std::string, double> std_map{
      {"Lite", 12.5}, {"Spike", 3.33}, {"Fake", 1.2356}, {"Take", 22.22}};
  EXPECT_EQ(s21_map.at("Lite"), std_map.at("Lite"));
  EXPECT_EQ(s21_map.at("Spike"), std_map.at("Spike"));
  EXPECT_EQ(s21_map.at("Fake"), std_map.at("Fake"));
  EXPECT_EQ(s21_map.at("Take"), std_map.at("Take"));
}

TEST(MapTests, access_or_insert1) {
  s21::map<int, double> s21_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  EXPECT_EQ(s21_map[1], std_map[1]);
  EXPECT_EQ(s21_map[5], std_map[5]);
  EXPECT_EQ(s21_map[8], std_map[8]);
  EXPECT_EQ(s21_map[10], std_map[10]);
}

TEST(MapTests, access_or_insert2) {
  s21::map<int, double> s21_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};
  std::map<int, double> std_map{{1, 12.5}, {5, 3.33}, {8, 1.2356}, {10, 22.22}};

  s21_map[15] = 122.222;
  std_map[15] = 122.222;

  s21_map[28] = 1.241245;
  std_map[28] = 1.241245;

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_EQ(s21_it->first, std_it->first);
    EXPECT_EQ(s21_it->second, std_it->second);
  }
}

TEST(MapTests, empty) {
  s21::map<int, int> s21_map;
  EXPECT_TRUE(s21_map.empty());

  s21_map.insert({2, 2});
  EXPECT_FALSE(s21_map.empty());
}

TEST(MapTests, size) {
  s21::map<int, int> s21_map;
  EXPECT_EQ(s21_map.size(), 0);
  s21_map.insert({2, 2});
  EXPECT_EQ(s21_map.size(), 1);

  s21_map.insert({5, 5});
  EXPECT_EQ(s21_map.size(), 2);

  s21_map.insert({8, 8});
  EXPECT_EQ(s21_map.size(), 3);
}

TEST(MapTests, max_size) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;

  EXPECT_EQ(s21_map.max_size(), std_map.max_size());

  s21_map[1] = 125;
  std_map[1] = 125;
  EXPECT_EQ(s21_map.max_size(), std_map.max_size());
}

TEST(MapTests, clear) {
  s21::map<int, int> a{{5, 5}, {2, 2}, {4, 4}};
  EXPECT_EQ(a.size(), 3);
  a.clear();
  EXPECT_EQ(a.size(), 0);
  a.clear();
  EXPECT_EQ(a.size(), 0);
}

TEST(MapTests, insert1) {
  s21::map<int, int> a{{6, 6}, {2, 2}, {4, 4}};
  EXPECT_EQ(a.size(), 3);

  auto pair = a.insert({3, 3});
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ((pair.first)->first, 3);
  EXPECT_TRUE(pair.second);

  pair = a.insert({5, 5});
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ((pair.first)->first, 5);
  EXPECT_TRUE(pair.second);

  pair = a.insert({4, 3});
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ((pair.first)->first, 4);
  EXPECT_FALSE(pair.second);
}

TEST(MapTests, insert2) {
  s21::map<int, int> a{{6, 5}, {2, 2}, {4, 4}};
  EXPECT_EQ(a.size(), 3);
  // a.print_start();
  auto pair = a.insert(3, 3);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(pair.first->first, 3);
  EXPECT_TRUE(pair.second);
  // a.print_start();
  pair = a.insert(5, 5);
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(pair.first->first, 5);
  EXPECT_TRUE(pair.second);

  // a.print_start();
  pair = a.insert(4, 3);
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(pair.first->first, 4);
  EXPECT_EQ(pair.first->second, 4);  //
  EXPECT_FALSE(pair.second);
  // a.print_start();
}

TEST(MapTests, insert3) {
  s21::map<int, int> a;
  EXPECT_EQ(a.size(), 0);

  auto pair = a.insert(3, 3);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(pair.first->first, 3);
  EXPECT_TRUE(pair.second);
}

TEST(MapTests, insert_or_assign) {
  s21::map<int, int> a{{21, 21}, {172, 172}, {1, 1},     {17, 17}, {199, 199},
                       {42, 42}, {58, 58},   {322, 322}, {2, 2},   {88, 88}};

  EXPECT_EQ((*a.begin()).second, 1);

  auto pair = a.insert_or_assign(1, 25);
  EXPECT_EQ(pair.first->first, 1);
  EXPECT_EQ(pair.first->second, 25);
  EXPECT_FALSE(pair.second);

  pair = a.insert_or_assign(3, 3);
  EXPECT_EQ(pair.first->first, 3);
  EXPECT_EQ(pair.first->second, 3);
  EXPECT_TRUE(pair.second);
}

TEST(MapTests, erase1) {
  s21::map<int, int> a{{21, 21}, {172, 172}, {1, 1},     {17, 17}, {199, 199},
                       {42, 42}, {58, 58},   {322, 322}, {2, 2},   {88, 88}};
  std::cout << a.size() << std::endl;
  EXPECT_EQ(a.size(), 10);
  a.erase(a.begin());
  EXPECT_EQ(a.size(), 9);
  EXPECT_FALSE(a.contains(1));
  a.erase(--a.end());
  a.print_start();
  EXPECT_EQ(a.size(), 8);
  EXPECT_FALSE(a.contains(322));

  a.erase(++a.begin());
  EXPECT_EQ(a.size(), 7);
  EXPECT_FALSE(a.contains(17));
}

TEST(MapTests, erase2) {
  s21::map<int, int> a{{2, 2}, {1, 1}, {3, 3}};

  a.erase(++a.begin());
  EXPECT_EQ(a.size(), 2);
  EXPECT_FALSE(a.contains(2));

  a.erase(--a.end());
  EXPECT_EQ(a.size(), 1);
  EXPECT_FALSE(a.contains(3));

  a.erase(a.begin());
  EXPECT_EQ(a.size(), 0);
  EXPECT_FALSE(a.contains(1));

  a.erase(a.begin());
  a.erase(a.end());
}

TEST(MapTests, MapSwap) {
  s21::map<int, int> a{{2, 2}, {1, 1}, {3, 3}};
  s21::map<int, int> b{{5, 5}, {12, 12}};

  a.swap(b);
  EXPECT_EQ(a.size(), 2);
  EXPECT_EQ(b.size(), 3);
}

TEST(MapTests, MapMerge) {
  s21::map<int, int> a{{2, 2}, {1, 1}, {3, 3}};
  s21::map<int, int> b{{5, 5}, {12, 12}};
  a.merge(b);
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(b.size(), 0);

  s21::map<int, int> c;
  s21::map<int, int> d{{5, 5}, {12, 12}};
  c.merge(d);
  EXPECT_EQ(c.size(), 2);
  EXPECT_EQ(d.size(), 0);

  s21::map<int, int> e;
  s21::map<int, int> f;
  e.merge(f);
  EXPECT_EQ(e.size(), 0);
  EXPECT_EQ(f.size(), 0);

  s21::map<int, int> g{{2, 2}, {1, 1}, {3, 3}};
  s21::map<int, int> h{{3, 3}, {12, 12}};
  g.merge(h);
  EXPECT_EQ(g.size(), 4);
  EXPECT_EQ(h.size(), 1);
}

TEST(MapTests, MapContains) {
  s21::map<int, int> a{{2, 2}, {1, 1}, {3, 3}};

  EXPECT_TRUE(a.contains(2));
  EXPECT_TRUE(a.contains(1));
  EXPECT_TRUE(a.contains(3));
  EXPECT_FALSE(a.contains(4));
}

TEST(MapTests, MapInsertMany) {
  s21::map<int, int> a;
  s21::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};

  a.insert_many();
  EXPECT_TRUE(a.empty());

  a.insert_many(std::pair<int, int>(1, 1));
  EXPECT_EQ(a.size(), 1);

  auto res = a.insert_many(std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
                           std::pair<int, int>(4, 4));
  EXPECT_EQ(a.size(), 4);

  for (auto i : res) {
    EXPECT_TRUE(i.second);
  }

  res = a.insert_many(std::pair<int, int>(5, 5), std::pair<int, int>(6, 6),
                      std::pair<int, int>(7, 7), std::pair<int, int>(8, 8),
                      std::pair<int, int>(9, 9));

  EXPECT_EQ(a.size(), 9);
  for (auto i : res) {
    EXPECT_TRUE(i.second);
  }

  auto it_a = a.begin(), it_b = b.begin();

  for (; it_a != a.end(); ++it_a, ++it_b) {
    EXPECT_EQ(*it_a, *it_b);
  }
}

// int main(int argc, char** argv) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }