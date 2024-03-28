#include <iostream>
#include <list>
int main() {
    std::list<int> ls;
    ls.push_back(10);
    ls.push_back(20);
    ls.push_back(30);
    ls.push_back(40);

    for (std::list<int>::iterator itr = ls.begin(); itr != ls.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}
