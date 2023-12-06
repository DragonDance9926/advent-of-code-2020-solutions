#include <bits/stdc++.h>
using namespace std;




int part_1_precedence(char &ch){
    if (ch == '('){
        return 1;
    }
    return 2;
}

int part_2_precedence(char &ch){
    if (ch == '('){
        return 0;
    }
    if (ch == '+' || ch == '-'){
        return 2;
    }
    return 1;
}

long long postfix_calc(string &postfix) {
    string integer = "";
    stack<long long> st;
    stringstream ss(postfix);
    long long a, b;
    while (getline(ss, integer, ' ')) {
        if (integer == "+") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b + a);
        } else if (integer == "-") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b - a);
        } else if (integer == "*") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b * a);
        } else if (integer == "/") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b / a);
        } else {
            //cout << integer << endl;
            st.push(stoll(integer));
        }
    }
    return st.top();
}



int main(){
    vector<string> v;
    string line;
    ifstream file;
    file.open("input.txt");
    while (getline(file, line)){
        v.push_back(line);
    }
    
    file.close();
    long long sum = 0;
    for(auto &s: v){
        string postfix = "";
        string integer = "";
        stack<char> st;
        for(auto &ch: s){
            if (ch >= '0' && ch <= '9'){
                integer += ch;
            } else{
                if (!integer.empty()){
                    postfix += integer + " ";
                    integer = "";
                }
                if (ch == ' '){
                    continue;
                }
                else if (ch == '('){
                    st.push(ch);
                }
                else if (ch == ')'){
                    while (!st.empty() && st.top() != '('){
                        postfix += st.top();
                        postfix += " ";
                        st.pop();
                    }
                    st.pop();
                }
                else {
                    while (!st.empty() && part_1_precedence(ch) <= part_1_precedence(st.top())){
                        postfix += st.top();
                        postfix += " ";
                        st.pop();
                    }
                    st.push(ch);
                }
            }
            //cout << postfix << endl;
            
        }
        if (!integer.empty()){
            postfix += integer + " ";
        }
        while (!st.empty()){
            postfix += st.top();
            postfix += " ";
            st.pop();
        }
        //cout << postfix << endl;
        sum += postfix_calc(postfix);
    }
    cout << "Part 1: " << sum << endl;
    sum = 0;
    for(auto &s: v){
        string postfix = "";
        string integer = "";
        stack<char> st;
        for(auto &ch: s){
            if (ch >= '0' && ch <= '9'){
                integer += ch;
            } else{
                if (!integer.empty()){
                    postfix += integer + " ";
                    integer = "";
                }
                if (ch == ' '){
                    continue;
                }
                else if (ch == '('){
                    st.push(ch);
                }
                else if (ch == ')'){
                    while (!st.empty() && st.top() != '('){
                        postfix += st.top();
                        postfix += " ";
                        st.pop();
                    }
                    st.pop();
                }
                else {
                    while (!st.empty() && part_2_precedence(ch) <= part_2_precedence(st.top())){
                        postfix += st.top();
                        postfix += " ";
                        st.pop();
                    }
                    st.push(ch);
                }
            }
            //cout << postfix << endl;
            
        }
        if (!integer.empty()){
            postfix += integer + " ";
        }
        while (!st.empty()){
            postfix += st.top();
            postfix += " ";
            st.pop();
        }
        
        //cout << postfix << endl;
        sum += postfix_calc(postfix);
    }
    cout << "Part 2: " << sum << endl;

    return 0;
}