#include <iostream>
#include <map>

int main() {
  std::map<int, std::string> myMap = {
      {1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};

  // Using a traditional iterator
  for (std::map<int, std::string>::iterator it = myMap.begin();
       it != myMap.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
  return 0;
}