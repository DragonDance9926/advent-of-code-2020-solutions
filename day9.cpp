#include <bits/stdc++.h>
using namespace std;
bool find_pair(vector<long long>::iterator begin, vector<long long>::iterator end, long long num){
    unordered_set<long long> s;
    for (auto it = begin; it != end; it++){
        if (s.find(num - *it) != s.end())
            return true;
        s.insert(*it);
    }   
    return false;
}

long long weakness(vector<long long>::iterator begin, vector<long long>::iterator end, long long num){
    for (auto it = begin; it != end; it++){
        long long sum = 0;
        for (auto it2 = it; it2 != end; it2++){
            sum += *it2;
            if (sum == num){
                long long min = *it2, max = *it2;
                for (auto it3 = it; it3 != it2; it3++){
                    min = min > *it3 ? *it3 : min;
                    max = max < *it3 ? *it3 : max;
                }
                //cout << min << " " << max << endl;
                return min + max;
            }
        }
    }
    return -1;
}


int main(){
    fstream file;
    file.open("input.txt");
    vector<long long> v;
    int num;
    while(file >> num)
        v.push_back(num);
    file.close();
    const int prem = 25;
    for (int i = prem; i < v.size(); i++){
        if (!find_pair(v.begin() + i - prem, v.begin() + i, v[i])){
            cout << "Part 1: " << v[i] << endl;
            cout << "Part 2: " << weakness(v.begin(), v.begin() + i, v[i]) << endl;
            break;
        }
    }
    return 0;
}