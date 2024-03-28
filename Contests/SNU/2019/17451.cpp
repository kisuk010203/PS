#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
    int n;
    vector<int> speed;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        speed.push_back(temp);
    }
    long long start_speed = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (start_speed % speed[i] == 0)
            continue;
        start_speed += (speed[i] - start_speed % speed[i]);
    }

    cout << start_speed << endl;

    return 0;
}
