#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s){
    for(typename std::set<T>::iterator itr = s.begin(); itr!= s.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
}
int main(){
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "print set" << std::endl;
    print_set(s);

    std::cout << "is 20 in s?" << std::endl;
    auto itr = s.find(20);
    if(itr != s.end()){
        std::cout << "YES" << std::endl;
    }
    else
        std::cout << "NO" << std::endl;
}
