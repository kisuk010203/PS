#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    double subjects;
    cin >> subjects;
    double max_score = 0;
    double sum_of_scores = 0;
    for (int i = 0; i < subjects; i++) {
        double temp;
        cin >> temp;
        max_score = max(max_score, temp);
        sum_of_scores += temp;
    }
    double new_sum_of_scores = sum_of_scores * 100 / max_score;
    cout << new_sum_of_scores / subjects << endl;
    return 0;
}
