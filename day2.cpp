#include <bits/stdc++.h>
using namespace std;

struct Password{
    int min;
    int max;
    char c;
    string s;
    bool isValid(){
        return count(s.begin(), s.end(), c) >= min && count(s.begin(), s.end(), c) <= max;
    }
    bool isValid2(){
        return (s.size() >= max && s[min - 1] == c && s[max - 1] != c) || (s.size() >= min && s[min - 1] != c && s[max - 1] == c);
    }
};


int main(){
    fstream file;
    file.open("input.txt");
    vector<Password> v;
    string line;
    while (getline(file, line)){
        Password p;
        stringstream ss(line);
        string s;
        getline(ss, s, '-');
        p.min = stoi(s);
        getline(ss, s, ' ');
        p.max = stoi(s);
        getline(ss, s, ':');
        p.c = s[0];
        getline(ss, s);
        p.s = s.substr(1);
        v.push_back(p);
    }
    cout << "Part 1: " << count_if(v.begin(), v.end(), [](Password p){return p.isValid();}) << "\n";
    cout << "Part 2: " << count_if(v.begin(), v.end(), [](Password p){return p.isValid2();}) << "\n";
    file.close();
    return 0;
}