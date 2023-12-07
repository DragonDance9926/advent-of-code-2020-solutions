#include <bits/stdc++.h>
#include <regex>
using namespace std;


string c_regex(vector<vector<vector<int>>> &rules, string &ends, int i){
    if (ends[i] != ' '){
        return ends[i] == 'a' ? "a" : "b";
    }
    string res = "(?:";
    for (auto &rule: rules[i]){
        string temp = "";
        for (auto &sub: rule){
            temp += c_regex(rules, ends, sub);
        }
        res += temp + "|";
    }
    if (res.back() == '|'){
        res.pop_back();
    }
    res += ")";
    return res;
}



int main(){
    vector<string> v;
    vector<string> v2;
    string line;
    ifstream file;
    file.open("input.txt");
    while(getline(file, line)){
        if (line == "") break;
        v.push_back(line);
    }
    while(getline(file, line)){
        v2.push_back(line);
        //cout << line << endl;
    }
    file.close();
    vector<vector<vector<int>>> rules(v.size());
    string ends(v.size(), ' ');
    for (auto &rule: v){
        int id = stoi(rule.substr(0, rule.find(':')));
        rule = rule.substr(rule.find(':')+2);
        if (rule[0] == '"'){
            ends[id] = rule[1];
            continue;
        }
        stringstream ss(rule);
        while (getline(ss, rule, '|')){
            vector<int> sub;
            stringstream ss2(rule);
            int i;
            while (ss2 >> i){
                sub.push_back(i);
                //cout << i << " ";
            }
            rules[id].push_back(sub);
        }
    }
    regex re(c_regex(rules, ends, 0));
    smatch matches;
    int count = 0;
    for (auto &s: v2){
        //Check if full match
        if (regex_match(s, matches, re)){
            count++;
        }
    }
    cout << "Part 1: " << count << endl;
    return 0;
}