#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Custom string comparison function
bool customCompare(const std::string &str1, const std::string &str2) {
    // Customize the comparison logic as needed
    return str1.length() < str2.length();
}

int main() {
    // Vector of strings
    // std::vector<std::string> stringVector = {"applaaaaaaaaaaaaaaae", "banana", "orange",
    //                                          "grape"};

    // // Sorting the vector using the customCompare function
    // std::sort(stringVector.begin(), stringVector.end(), customCompare);

    // // Printing the sorted vector
    // std::cout << "Sorted Vector: ";
    // for (const auto &str : stringVector) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;

    string a = "a";
    cout << a.substr(1) << "\n";
    cout << (a.substr(1) == "" )<< "\n";
    cout << (a.substr(1) == "\0") << "\n";
    return 0;
}
