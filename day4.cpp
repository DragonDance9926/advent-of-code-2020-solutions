#include <bits/stdc++.h>
#include <regex>
using namespace std;



const string byr_r = "^(19[2-9][0-9]|200[0-2])$";
const string iyr_r = "^(201[0-9]|2020)$";
const string eyr_r = "^(202[0-9]|2030)$";
const string hgt_r = "^(1([5-8][0-9]|9[0-3])cm|(59|6[0-9]|7[0-6])in)$";
const string hcl_r = "^#[0-9a-f]{6}$";
const string ecl_r = "^(amb|blu|brn|gry|grn|hzl|oth)$";
const string pid_r = "^[0-9]{9}$";
unordered_map<string, string> rules = {
    {"byr", byr_r},
    {"iyr", iyr_r},
    {"eyr", eyr_r},
    {"hgt", hgt_r},
    {"hcl", hcl_r},
    {"ecl", ecl_r},
    {"pid", pid_r}
};


struct info{
    unordered_map<string, string> passport;
    info(){
        passport = {
            {"byr", ""},
            {"iyr", ""},
            {"eyr", ""},
            {"hgt", ""},
            {"hcl", ""},
            {"ecl", ""},
            {"pid", ""},
            {"cid", ""}
        };
    }
    bool isValid(){
        bool valid = true;
        for (auto x : passport) {
            if (x.second == "" && x.first != "cid") {
                valid = false;
            }
        }
        return valid;
    };
    bool isValid2(){
        bool valid = true;
        for (auto x : passport) {
            if (x.first == "cid") {
                continue;
            }
            if (x.second == "") {
                return false;
            } else if (!regex_match(x.second, regex(rules[x.first]))) {
                return false;
            }
        }
        return valid;
    }
    string print() {
        string s = "";
        for (auto x : passport) {
            s += x.first + ": " + x.second + "\n";
        }
        return s;
    }
};



int main(){
    fstream file;
    file.open("input.txt");
    vector<info> v;
    string line;
    info current;
    while (file.eof() == false){
        getline(file, line);
        if (line == ""){
            v.push_back(current);
            current = info();
        } else {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                string key = word.substr(0, 3);
                string value = word.substr(4);
                current.passport[key] = value;
            }
        }
    }
    
    file.close();
    cout << "Part 1: " << count_if(v.begin(), v.end(), [](info x){return x.isValid();}) << "\n";
    cout << "Part 2: " << count_if(v.begin(), v.end(), [](info x){return x.isValid2();}) << "\n";
    return 0;
}