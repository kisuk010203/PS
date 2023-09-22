#include <iostream>
#include <vector>
int main(){
    std::vector <int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    // for(std::vector<int>::size_type i = 0 ; i<vec.size(); i++)
    //     std::cout << i <<"th element of vec : "<<vec[i] << std::endl;
    
    //iterator
    // for(std::vector<int>::iterator itr = vec.begin(); itr!= vec.end(); ++itr)
    //     std::cout << *itr << std::endl;
    // std::vector<int>::iterator itr = vec.begin()+2;
    // std::cout << "3rd element: "<< *itr << std::endl;

    //range-based for loop
    for(int elem : vec) std::cout << "element : " << elem << std::endl;
}