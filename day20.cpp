#include <bits/stdc++.h>
using namespace std;
enum direction {UP, DOWN, LEFT, RIGHT};







string side (vector<string> &v, direction d){
    string s;
    switch(d){
        case UP:
            for (int i = 0; i < v.size(); i++){
                s += v[i][0];
            }
            break;
        case DOWN:
            for (int i = 0; i < v.size(); i++){
                s += v[i][v[0].size() - 1];
            }
            break;
        case LEFT:
            for (int i = 0; i < v[0].size(); i++){
                s += v[0][i];
            }
            break;
        case RIGHT:
            for (int i = 0; i < v[0].size(); i++){
                s += v[v.size() - 1][i];
            }
            break;
    }
    return s;
}

int main(){
    ifstream file;
    file.open("input.txt");
    string line;
    unordered_map<int, vector<string>> m;
    while(!file.eof()){
        getline (file, line);
        line = line.substr(line.find(' ') + 1);
        line.pop_back();
        int id = stoi(line);
        vector<string> v;
        //cout << line << endl;
        while (getline(file, line)){
            if (line == "") break;
            //cout << line << endl;
            v.push_back(line);
        }
        m[id] = v;
    }
    file.close();
    unordered_map<string, unordered_set<int>> m2;
    for (auto &[id, v] : m){
        string s = side(v, UP);
        m2[s].insert(id);
        reverse(s.begin(), s.end());
        m2[s].insert(id);

        s = side(v, LEFT);
        m2[s].insert(id);
        reverse(s.begin(), s.end());
        m2[s].insert(id);

        s = side(v, DOWN);
        m2[s].insert(id);
        reverse(s.begin(), s.end());
        m2[s].insert(id);

        s = side(v, RIGHT);
        m2[s].insert(id);
        reverse(s.begin(), s.end());
        m2[s].insert(id);
    }
    //print
    unordered_map<int,set<int>> m3;
    for (auto &[k, v] : m2){
        vector <int> v2;
        for (auto i : v){
            v2.push_back(i);
        }
        for (int i = 0; i < v2.size(); i++){
            for (int j = i + 1; j < v2.size(); j++){
                m3[v2[i]].insert(v2[j]);
                m3[v2[j]].insert(v2[i]);
            }
        }
    }
    long long ans = 1;
    for (auto &[k, v] : m3){
        
        if (v.size() == 2){
            ans *= k;
            cout << k << ": ";
            for (auto i : v){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    cout << "Part 1: " << ans << endl;
}