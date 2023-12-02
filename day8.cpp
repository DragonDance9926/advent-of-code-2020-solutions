#include <bits/stdc++.h>
using namespace std;

pair<bool,int> is_loop(vector<string> &v){
    int acc = 0;
    int i = 0;
    set<int> s;
    while(i < v.size() && s.find(i) == s.end()){
        s.insert(i);
        string s1 = v[i];
        string cmd = s1.substr(0, 3);
        string num = s1.substr(4);
        int off = stoi(num);
        if(cmd == "acc"){
            acc += off;
            i++;
        }
        else if(cmd == "jmp"){
            i += off;
        }
        else{
            i++;
        }
    }
    return {i == v.size(), acc};
}


int main(){
    fstream file;
    file.open("input.txt");
    vector<string> v;
    string line;
    while(getline(file, line)){
        v.push_back(line);
    }
    file.close();
    cout << "Part 1: " << is_loop(v).second << endl;
    vector<int> jmps;
    for(int i = 0; i < v.size(); i++){
        if(v[i].substr(0, 3) == "jmp" || v[i].substr(0, 3) == "nop"){
            jmps.push_back(i);
        }
    }
    for (auto &ind: jmps){
        v[ind] = v[ind].substr(0, 3) == "jmp" ? "nop " + v[ind].substr(4) : "jmp " + v[ind].substr(4);
        pair<bool, int> p = is_loop(v);
        if(p.first){
            cout << "Part 2: " << p.second << endl;
            break;
        }
        v[ind] = v[ind].substr(0, 3) == "jmp" ? "nop " + v[ind].substr(4) : "jmp " + v[ind].substr(4);
    }
    return 0;
} 