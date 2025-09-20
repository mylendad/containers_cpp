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
  iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  // iter++;
  iter++;
  iter--;
  // iter++;
  // iter++;
  // iter++;
  myMap.erase(iter);

  // std::cout << (int)myMap.size() << std::endl;
  // s21::Map<std::string, int>::Node A = new Node;
  EXPECT_EQ((int)myMap.size(), 9);
  std::cout << "После удаления" << std::endl;
  myMap.print_start();

  // iter++; // sega
  // myMap.erase(iter);  // sega
  // EXPECT_EQ((int)myMap.size(), 9);

  // myMap.print_start();
}

TEST(TestMapCopyMoveConstructor, Size_map) {
  s21::Map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // myMap.print_start();

  s21::Map<std::string, int> myMap_1 = myMap;

  EXPECT_EQ((int)myMap.size(), (int)myMap_1.size());

  myMap.print_start();
  myMap_1.print_start();

  s21::Map<std::string, int> myMap_2(std::move(myMap_1));

  myMap_2.print_start();
  std::cout << "myMap_1: " << std::endl;
  myMap_1.print_start();
}

TEST(TestSwapAtConstructor, Size_map) {
  s21::Map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // myMap.print_start();

  s21::Map<std::string, int> myMap_1 = {
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
  s21::Map<std::string, int> myMap = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // myMap.print_start();
  EXPECT_EQ((int)myMap.size(), 10);
  myMap.print_start();
  myMap.empty();

  std::cout << "myMap.empty(): " << myMap.empty() << std::endl;

  EXPECT_EQ(myMap.empty(), false);

  EXPECT_EQ(myMap.max_size(), 256204778801521550);

  myMap.clear();
  myMap.print_start();

  EXPECT_EQ((int)myMap.size(), 0);
  myMap.print_start();
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// #include <gtest/gtest.h>

// #include <memory>
// #include <vector>

// #include "map.h"

// // Вспомогательный класс для отслеживания вызовов деструкторов
// class DestructorTracker {
//  public:
//   static int destructor_count;
//   int id;

//   DestructorTracker(int i = 0) : id(i) {}
//   ~DestructorTracker() { destructor_count++; }

//   bool operator<(const DestructorTracker& other) const { return id <
//   other.id; } bool operator==(const DestructorTracker& other) const {
//     return id == other.id;
//   }
// };

// int DestructorTracker::destructor_count = 0;

// TEST(MapDestructorTest, BasicDestruction) {
//   DestructorTracker::destructor_count = 0;

//   {
//     s21::Map<int, std::string> m;
//     m.insert({1, "one"});
//     m.insert({2, "two"});
//     m.insert({3, "three"});
//     // Деструктор вызовется при выходе из scope
//   }

//   // Проверяем, что память освобождена (косвенно через отсутствие утечек)
//   // В реальности нужно использовать инструменты типа valgrind
//   SUCCEED();  // Если дошли сюда без crash - вероятно все ок
// }

// TEST(MapDestructorTest, DestructorWithComplexObjects) {
//   DestructorTracker::destructor_count = 0;
//   const int num_elements = 5;

//   {
//     s21::Map<int, DestructorTracker> m;
//     for (int i = 0; i < num_elements; ++i) {
//       m.insert({i, DestructorTracker(i)});
//     }
//     // Деструкторы элементов должны вызваться здесь
//   }

//   // Каждый DestructorTracker + возможно внутренние структуры
//   EXPECT_GE(DestructorTracker::destructor_count, num_elements);
// }

// TEST(MapDestructorTest, EmptyMapDestruction) {
//   {
//     s21::Map<int, std::string> empty_map;
//     // Не должно быть никаких проблем с уничтожением пустой Map
//   }
//   SUCCEED();
// }

// TEST(MapDestructorTest, LargeMapDestruction) {
//   const size_t large_size = 1000;

//   {
//     s21::Map<int, int> large_map;
//     for (size_t i = 0; i < large_size; ++i) {
//       large_map.insert({i, i * 2});
//     }

//     EXPECT_EQ(large_map.size(), large_size);
//     // Деструктор должен корректно обработать большое количество элементов
//   }
//   SUCCEED();
// }

// TEST(MapDestructorTest, DestructionAfterMove) {
//   DestructorTracker::destructor_count = 0;

//   {
//     s21::Map<int, DestructorTracker> source_map;
//     source_map.insert({1, DestructorTracker(1)});
//     source_map.insert({2, DestructorTracker(2)});

//     s21::Map<int, DestructorTracker> moved_map = std::move(source_map);

//     // source_map теперь должен быть в valid empty state
//     EXPECT_TRUE(source_map.empty());

//     // moved_map будет уничтожен первым, затем source_map
//   }

//   // Должны быть вызваны деструкторы для всех элементов
//   EXPECT_GE(DestructorTracker::destructor_count, 2);
// }

// TEST(MapDestructorTest, DestructionAfterCopy) {
//   DestructorTracker::destructor_count = 0;

//   {
//     s21::Map<int, DestructorTracker> original;
//     original.insert({1, DestructorTracker(1)});
//     original.insert({2, DestructorTracker(2)});

//     s21::Map<int, DestructorTracker> copy = original;

//     // Оба содержат копии элементов
//     EXPECT_EQ(original.size(), 2);
//     EXPECT_EQ(copy.size(), 2);

//     // Деструкторы должны вызваться для всех 4 элементов
//   }

//   EXPECT_GE(DestructorTracker::destructor_count, 4);
// }

// TEST(MapDestructorTest, NestedMapDestruction) {
//   {
//     s21::Map<int, s21::Map<int, std::string>> nested_map;

//     s21::Map<int, std::string> inner_map;
//     inner_map.insert({1, "inner"});
//     inner_map.insert({2, "values"});

//     nested_map.insert({1, inner_map});
//     nested_map.insert({2, inner_map});

//     // Деструктор должен рекурсивно уничтожить все вложенные Map
//   }
//   SUCCEED();
// }

// TEST(MapDestructorTest, StringValuesDestruction) {
//   // Тест с std::string которые имеют свои деструкторы
//   {
//     s21::Map<int, std::string> string_map;
//     string_map.insert(
//         {1, "very long string that should be properly deallocated"});
//     string_map.insert({2, "another long string for testing destruction"});
//     string_map.insert({3, std::string(1000, 'x')});  // Очень длинная строка

//     // Деструктор должен корректно освободить память строк
//   }
//   SUCCEED();
// }

// TEST(MapDestructorTest, PointerValuesDestruction) {
//   // Тест с указателями (деструктор не должен удалять сырые указатели!)
//   {
//     int* value1 = new int(42);
//     int* value2 = new int(84);

//     {
//       s21::Map<int, int*> pointer_map;
//       pointer_map.insert({1, value1});
//       pointer_map.insert({2, value2});

//       // Деструктор Map не должен удалять сырые указатели!
//     }

//     // Проверяем, что указатели все еще валидны
//     EXPECT_EQ(*value1, 42);
//     EXPECT_EQ(*value2, 84);

//     delete value1;
//     delete value2;
//   }
// }

// TEST(MapDestructorTest, RepeatedDestruction) {
//   // Многократное создание и уничтожение
//   for (int i = 0; i < 10; ++i) {
//     s21::Map<int, int> temp_map;
//     for (int j = 0; j < 10; ++j) {
//       temp_map.insert({j, j * i});
//     }
//     // Деструктор вызывается на каждой итерации
//   }
//   SUCCEED();
// }

// // TEST(MapDestructorTest, DestructionWithCustomComparator) {
// //   // Тест с пользовательским компаратором
// //   struct CustomCompare {
// //     bool operator()(const std::string& a, const std::string& b) const {
// //       return a.length() < b.length();
// //     }
// //   };

// //   {
// //     s21::Map<std::string, int, CustomCompare> custom_map;
// //     custom_map.insert({"short", 1});
// //     custom_map.insert({"very long string", 2});
// //     custom_map.insert({"medium", 3});

// //     // Деструктор должен работать с кастомным компаратором
// //   }
// //   SUCCEED();
// // }

// // Тест для проверки утечек памяти (лучше запускать с valgrind)
// TEST(MapDestructorTest, NoMemoryLeaks) {
//   const int iterations = 100;
//   const int elements_per_iteration = 50;

//   for (int i = 0; i < iterations; ++i) {
//     s21::Map<int, std::string> test_map;
//     for (int j = 0; j < elements_per_iteration; ++j) {
//       test_map.insert({j, "test string number " + std::to_string(j)});
//     }

//     // Если есть утечки памяти, они проявятся после многих итераций
//     if (i % 10 == 0) {
//       // Периодическая проверка размера
//       EXPECT_EQ(test_map.size(), elements_per_iteration);
//     }
//   }
//   // Если тест не упал и не было segmentation fault - вероятно утечек нет
//   SUCCEED();
// }

// int main(int argc, char** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }