#include <bits/stdc++.h>
using namespace std;
#define MAX 101
int use_seq[MAX];
int is_used[MAX];
int vacancies;
void init(int holes, int usage) {
    for (int i = 0; i < MAX; i++) {
        is_used[i] = 0;
    }
    for (int i = 0; i < usage; i++) {
        cin >> use_seq[i];
    }
    vacancies = holes;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int holes, usage;
    cin >> holes >> usage;

    init(holes, usage);
    int eviction = 0;
    for (int i = 0; i < usage; i++) {
        int curr = use_seq[i];
        if (is_used[curr])
            continue;
        if (vacancies > 0) {
            is_used[curr] = 1;
            vacancies--;
            continue;
        }
        // need eviction, vacancies = 0
        int first_used_task[MAX];
        for (int i = 0; i < MAX; i++) {
            first_used_task[i] = INT_MAX;
        }
        for (int j = i + 1; j < usage; j++) {
            first_used_task[use_seq[j]] = min(first_used_task[use_seq[j]], j);
        }
        int evicted_task, evicted_max = -1;
        for(int i=0; i<MAX; i++){
            if(!is_used[i]) continue;
            if(evicted_max < first_used_task[i]){
                evicted_task = i;
                evicted_max = first_used_task[i];
            }
        }
        // eviction happens
        is_used[evicted_task] = 0;
        is_used[curr] = 1;
        eviction++;
    }
    cout << eviction << "\n";
}
