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

#include <iostream>
#include <map>
#include <string>

int main() {
  // Создаем два словаря
  std::map<int, std::string> map1;
  std::map<int, std::string> map2;

  // Заполняем первый словарь
  map1.insert({1, "Apple"});
  map1.insert({2, "Banana"});
  map1.insert({3, "Cherry"});

  // Заполняем второй словарь
  // Обратите внимание на ключи 3 и 4
  map2.insert({3, "Coconut"});  // Ключ 3 конфликтует с map1
  map2.insert({4, "Date"});
  map2.insert({5, "Elderberry"});

  std::cout << "Before merge:" << std::endl;
  std::cout << "Map1: ";
  for (const auto& [key, value] : map1) {
    std::cout << "{" << key << ": " << value << "} ";
  }
  std::cout << std::endl;

  std::cout << "Map2: ";
  for (const auto& [key, value] : map2) {
    std::cout << "{" << key << ": " << value << "} ";
  }
  std::cout << std::endl << std::endl;

  // ВЫПОЛНЯЕМ СЛИЯНИЕ: перемещаем элементы из map2 в map1
  map1.merge(map2);

  std::cout << "After merge:" << std::endl;
  std::cout << "Map1: ";
  for (const auto& [key, value] : map1) {
    std::cout << "{" << key << ": " << value << "} ";
  }
  std::cout << std::endl;

  std::cout << "Map2: ";
  for (const auto& [key, value] : map2) {
    std::cout << "{" << key << ": " << value << "} ";
  }
  std::cout << std::endl;

  return 0;
}