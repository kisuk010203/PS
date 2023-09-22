#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int used_alph[26];
    fill(used_alph, used_alph+26, -1);
    vector<string> words;
    bool flag = true;

    for(int i=0; i<M; i++){
        string temp; cin >> temp;
        words.push_back(temp);
        for (int j = 0; j < N; j++){
            int curr_char = temp[j] - 'A';
            if(used_alph[curr_char] != -1 && used_alph[curr_char] != j)
                flag = false;
            else if(used_alph[curr_char] == -1)
                used_alph[curr_char] = j;
        }
    }
    sort(words.begin(), words.end());
    for(int i=0; i<words.size()-1; i++){
        if(words[i] == words[i+1])
            flag = false;
    }
    int res = 1;
    for(int i=0; i<N; i++){
        int cnt = 0;
        for(auto item : used_alph)
            if(item == i) cnt++;
        res *= cnt;
    }
    if(res != M) flag = false;
    if(flag){ 
        cout << "YES" << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<26; j++){
                if(used_alph[j] == i)
                    cout << (char)(j+'A');
            } cout << '\n';
        }
    }
    else cout << "NO";

    return 0;
}
