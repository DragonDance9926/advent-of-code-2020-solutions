#include <bits/stdc++.h>
#include <regex>
using namespace std;

//regex1 : (.*) bags contain (.*).$
string regex1 = R"((.*) bags contain (.*).$)";
//regex2 : (\d+) ([a-zA-Z ]*)bag[s]?
string regex2 = R"((\d+) ([a-zA-Z ]*)bag[s]?)";

bool is_contain_shiny_gold(string main_bag, unordered_map<string, unordered_map<string, int>> &m){
    if (main_bag == "shiny gold"){
        return true;
    }
    for (auto x : m[main_bag]){
        if (is_contain_shiny_gold(x.first, m)){
            return true;
        }
    }
    return false;
}

int count_bags(string main_bag, unordered_map<string, unordered_map<string, int>> &m){
    if (m[main_bag].empty()){
        return 0;
    }
    int ans = 0;
    for (auto x : m[main_bag]){
        ans += x.second * (1 + count_bags(x.first, m));
    }
    return ans;
}



int main(){
    unordered_map<string, unordered_map<string, int>> m;
    fstream file;
    file.open("input.txt");
    string line;
    regex r1(regex1);
    regex r2(regex2);
    while (getline(file, line)){
        smatch m1;
        if (regex_search(line, m1, r1)){
            smatch m2;
            string main_bag = m1[1].str();
            string sub_bag = m1[2].str();
            if (sub_bag == "no other bags"){
                m[main_bag] = {};
                continue;
            }
            stringstream ss(sub_bag);
            unordered_map<string, int> sub;
            while (getline(ss, sub_bag, ',')){
                smatch m3;
                if (regex_search(sub_bag, m3, r2)){
                    string num = m3[1].str();
                    string color = m3[2].str();
                    int lead = 0;
                    while (color[lead] == ' '){
                        lead++;
                    }
                    color = color.substr(lead);
                    int trail = color.size() - 1;
                    while (color[trail] == ' '){
                        trail--;
                    }
                    color = color.substr(0, trail + 1);

                    
                    sub[color] = stoi(num);
                }
            }
            m[main_bag] = sub;
        }
    }
    
    file.close();
    int ans = 0;
    for (auto x : m){
        if (is_contain_shiny_gold(x.first, m)){
            ans++;
        }
    }
    cout << "Part 1: " << --ans << "\n";
    cout << "Part 2: " << count_bags("shiny gold", m) << "\n";
    return 0;
}