#include <bits/stdc++.h>
using namespace std;


string val_36binary(long long val){
    string res = "";
    for (int i = 0; i < 36; i++){
        if (val & (1LL << i)){
            res += '1';
        }
        else{
            res += '0';
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

long long binary_36val(string val){
    long long res = 0;
    for (int i = 0; i < val.size(); i++){
        if (val[i] == '1'){
            res |= (1LL << i);
        }
    }
    return res;
}




long long masked_val(string mask, long long val){
    reverse(mask.begin(), mask.end());
    long long res = val;
    for (int i = 0; i < mask.size(); i++){
        if (mask[i] == '1'){
            res |= (1LL << i);
        }
        if (mask[i] == '0'){
            res &= ~(1LL << i);
        }
    }
    return res;
}
string masked_val(string mask, string val){
    string res = "";
    for (int i = 0; i < mask.size(); i++){
        if (mask[i] == '0'){
            res += val[i];
        }
        else{
            res += mask[i];
        }
    }
    return res;
}

void sum_val(string &val,vector<string> &res,int index){
    if (index == val.size()){
        //cout << val << endl;
        res.push_back(val);
        return;
    }
    if (val[index] == 'X'){
        val[index] = '0';
        sum_val(val,res,index+1);
        val[index] = '1';
        sum_val(val,res,index+1);
        val[index] = 'X';
    }
    else if (val[index] == '1'){
        sum_val(val,res,index+1);
    }
    else if (val[index] == '0'){
        sum_val(val,res,index+1);
    }
}



int main(){
    fstream file;
    file.open("input.txt");
    vector<string> bitmask;
    vector<vector<pair<long long, long long>>> mem;
    vector<pair<long long,long long>> temp;
    string line;
    while(getline(file, line)){
        if(line[1] == 'a'){
            if (temp.size() > 0){
                mem.push_back(temp);
                temp.clear();
            }
            bitmask.push_back(line.substr(7));
            //cout << line.substr(7) << endl;
        }
        else{
            long long mem_addr = stoll(line.substr(4, line.find(']')-4));
            long long val = stoll(line.substr(line.find('=')+2));
            temp.push_back({mem_addr, val});
        }
    }
    mem.push_back(temp);
    file.close();
    unordered_map<long long, long long> memory;
    for (int i = 0; i < mem.size(); i++){
        for (int j = 0; j < mem[i].size(); j++){
            memory[mem[i][j].first] = masked_val(bitmask[i], mem[i][j].second);
        }
    }
    //Give the sum of all values in memory
    long long sum = 0;
    for (auto it = memory.begin(); it != memory.end(); it++){
        sum += it->second;
    }
    cout << "Part 1: " << sum << endl;
    memory.clear();
    for (int i = 0; i < mem.size(); i++){
        for (int j = 0; j < mem[i].size(); j++){
            string res = masked_val(bitmask[i], val_36binary(mem[i][j].first));
            vector<string> result = {};
            sum_val(res, result, 0);
            for (int k = 0; k < result.size(); k++){
                memory[binary_36val(result[k])] = mem[i][j].second;
            }
        }
    }
    //Give the sum of all values in memory
    sum = 0;
    for (auto it = memory.begin(); it != memory.end(); it++){
        sum += it->second;  
    }
    cout << "Part 2: " << sum << endl;
    return 0;
}