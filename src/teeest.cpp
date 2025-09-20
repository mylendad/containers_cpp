#include <iostream>
#include <map>

int main() {
  std::map<double, std::string> myMap = {
      {1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};

  std::map<std::string, int> myMap_1 = {
      {"ключ01", 1}, {"ключ02", 2}, {"ключ03", 3}, {"ключ04", 4},
      {"ключ05", 5}, {"ключ06", 6}, {"ключ07", 7}, {"ключ08", 8},
      {"ключ09", 9}, {"ключ10", 10}};

  // Using a traditional iterator
  myMap.at(1) = "efwgwgw";
  for (std::map<double, std::string>::iterator it = myMap.begin();
       it != myMap.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

    std::cout << myMap.max_size() << std::endl;
    std::cout << myMap_1.max_size() << std::endl;
  }
  return 0;
}