#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    std::cout << itr->first << " " << itr->second << std::endl;
  }
}

int main() {
  std::map<std::string, double> pitcher_list;

  pitcher_list.insert(std::pair<std::string, double>("Park", 2.23));
  pitcher_list.insert(std::pair<std::string, double>("Hack ", 2.93));

  pitcher_list.insert(std::pair<std::string, double>("Peer ", 2.95));


  pitcher_list.insert(std::make_pair("Cha", 3.04));
  pitcher_list.insert(std::make_pair("Jang ", 3.05));
  pitcher_list.insert(std::make_pair("Hector ", 3.09));

  // 혹은 insert 를 안쓰더라도 [] 로 바로
  // 원소를 추가할 수 있습니다.
  pitcher_list["Nip"] = 3.56;
  pitcher_list["PJH"] = 3.76;
  pitcher_list["Kel"] = 3.90;

  print_map(pitcher_list);

  std::cout << "Park 방어율은? :: " << pitcher_list["Park"] << std::endl;
}
