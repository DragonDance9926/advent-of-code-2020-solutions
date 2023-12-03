#include <bits/stdc++.h>
#include <regex>
using namespace std;

//Regex: ([\w| ]*): (\d)+-(\d+) or (\d+)-(\d+)
string reg = "([\\w| ]*): (\\d+)-(\\d+) or (\\d+)-(\\d+)";


bool check_val(int val, unordered_map<string,pair<pair<int,int>,pair<int,int>>> &m){

    for (auto &[k,v] : m){
        auto [min1, max1] = v.first;
        auto [min2, max2] = v.second;
        bool f1 = val >= min1 && val <= max1;
        bool f2 = val >= min2 && val <= max2;
        if (f1 || f2){
            return true;
        }
    }
    return false;
}


int main(){
    string line;
    ifstream file;
    unordered_map<string,pair<pair<int,int>,pair<int,int>>> m;
    file.open("input.txt");
    while (getline(file, line)){
        if (line == ""){
            break;
        }
        smatch matches;
        regex re(reg);
        if (regex_search(line, matches, re)){
            //cout << matches[1] << " " << matches[2] << " " << matches[3] << " " << matches[4] << " " << matches[5] << endl;
            m[matches[1]] = {{stoi(matches[2]), stoi(matches[3])}, {stoi(matches[4]), stoi(matches[5])}};
        }

    }
    getline(file,line);
    getline(file,line);
    vector<int> myticket;
    stringstream ss(line);
    while(getline(ss, line, ',')){
        myticket.push_back(stoi(line));
        //cout << line << " ";
    }
    //cout << endl;
    getline(file,line);
    getline(file,line);
    vector<vector<int>> tickets;
    while(getline(file, line)){
        stringstream ss(line);
        vector<int> ticket;
        while(getline(ss, line, ',')){
            //cout << line << " ";
            ticket.push_back(stoi(line));
        }
        //cout << endl;
        tickets.push_back(ticket);
    }
    file.close();
    //cout << tickets.size() << endl;
    int sum = 0;
    vector<vector<int>> valid;
    for(int i = 0; i < tickets.size(); i++){
        vector<int> ticket = tickets[i];
        bool valid_ticket = true;
        for(int j = 0; valid_ticket && j < ticket.size(); j++){
            //cout << ticket[j] << " ";
            if (!check_val(ticket[j], m)){
                sum += ticket[j];
                valid_ticket = false;
            }
        }
        //cout << endl;
        if (valid_ticket){
            valid.push_back(ticket);
        }
    }
    cout << "Part 1: " << sum << endl;
    valid.push_back(myticket);
    //cout << valid.size() << endl;
    unordered_map<string,vector<int>> m2;
    for(auto &[t_class, ranges]:m){
        auto [min1, max1] = ranges.first;
        auto [min2, max2] = ranges.second;
        for (int i = 0; i < valid[0].size(); i++){
            bool flag = true;
            for(int j = 0; j < valid.size() && flag; j++){
                flag = valid[j][i] >= min1 && valid[j][i] <= max1 || valid[j][i] >= min2 && valid[j][i] <= max2;
            }
            if (flag){
                m2[t_class].push_back(i);
            }
        }
    }
    vector<pair<vector<int>,string>> candidates;
    long long prod = 1;
    for (auto &[k,v] : m){
        auto [min1, max1] = v.first;
        auto [min2, max2] = v.second;
        vector<int> tmp;
        for(int i = 0; i < valid[0].size(); i++){
            bool flag2 = true;
            for (int j = 0;flag2 && j < valid.size(); j++){
                flag2 = valid[j][i] >= min1 && valid[j][i] <= max1 || valid[j][i] >= min2 && valid[j][i] <= max2;
            }
            if (flag2){
                tmp.push_back(i);
            }
        }
        candidates.push_back({tmp, k});
    }
    sort (candidates.begin(), candidates.end(), [](pair<vector<int>,string> &a, pair<vector<int>,string> &b){
        return a.first.size() < b.first.size();
        
    });
    unordered_map<string,int> field_index;
    vector<bool> taken(candidates.size(), false);
    for (auto &pair: candidates){
        for (int i = 0; i < pair.first.size(); i++){
            if (!taken[pair.first[i]]){
                field_index[pair.second] = pair.first[i];
                taken[pair.first[i]] = true;
                //cout << pair.second << " " << pair.first[i] << endl;
                break;
            }
        }
    }
    for (auto &[k,v] : field_index){
        if (k.substr(0,9) == "departure"){
            cout << k << " " << myticket[v] << endl;
            prod *= myticket[v];
        }
    }


    cout << "Part 2: " << prod << endl;

    return 0;
}