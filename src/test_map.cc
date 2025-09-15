#include <gtest/gtest.h>

#include <list>

#include "map.h"

TEST(TestMap, Size_map) {
  s21::Map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  myMap.print_start();
  // std::cout << "Size: " << myMap.size() << std::endl;
  s21::Map<std::string, int>::iterator iter;

  iter = myMap.begin();
  iter++;
  // iter++;
  // iter++;
  // iter++;
  myMap.erase(iter);

  // std::cout << (int)myMap.size() << std::endl;
  // s21::Map<std::string, int>::Node A = new Node;
  EXPECT_EQ((int)myMap.size(), 9);

  myMap.print_start();

  // iter++; // sega
  // myMap.erase(iter);  // sega
  // EXPECT_EQ((int)myMap.size(), 9);

  // myMap.print_start();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
