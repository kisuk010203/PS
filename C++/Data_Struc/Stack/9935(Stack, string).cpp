#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string str, word;
    cin >> str >> word;
    int word_len = word.length();
    stack <char> st;
    for(char c: str){
        st.push(c);
        if(st.size() >= word_len){
            stack <char> temp;
            for(int i=word_len-1; i>=0; i--){
                char popped = st.top();
                if(popped != word[i]){
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
                temp.push(st.top());
                st.pop();
            }
        }
    }
    if(st.empty()) cout << "FRULA";
    else{
        int stack_size = st.size();
        char *arr = new char[stack_size];
        for(int i=0; i<stack_size; i++){
            arr[stack_size-1-i] = st.top();
            st.pop();
        }

        for(int i=0; i<stack_size; i++) cout << arr[i];
    }
}
