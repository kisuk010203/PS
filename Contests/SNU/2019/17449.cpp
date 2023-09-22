#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int mid_rank;
    cin >> mid_rank;
    int n;
    cin >> n;
    vector<int> ranks;
    int low_rank = mid_rank, high_rank = mid_rank;
    int ties = 1;

    for (int i = 0; i < n; i++) {
        int rank;
        cin >> rank;
        ranks.push_back(rank);
        low_rank = low_rank + int(low_rank >= rank);
        if (rank < high_rank)
            high_rank++;
        else if (rank == high_rank)
            ties++;
        else { // rank > high_rank
            if (rank < high_rank + ties) {
                ties = high_rank + ties - rank + 1;
                high_rank = rank;
            }
        }
    }
    cout << high_rank << " " << low_rank << "\n";
    return 0;
}
