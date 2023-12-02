#include <bits/stdc++.h>
using namespace std;



long long count_ways(int n, unordered_set<int> &s, unordered_map<int, long long> &ways){
    if (n == 0){
        return 1;
    }
    if (s.find(n) == s.end()){
        return 0;
    }
    if (ways.find(n) != ways.end()){
        return ways[n];
    }
    long long ans = 0;
    for (int i = 1; i <= 3; i++){
        ans += count_ways(n - i, s, ways);
    }
    ways[n] = ans;
    return ans;
}




int main(){
    fstream file;
    vector<int> v;
    file.open("input.txt");
    int n = 0;
    while(file >> n){
        v.push_back(n);
    }
    file.close();
    //sort desc
    sort (v.begin(), v.end(), greater<int>());
    unordered_map<int, int> diff;
    diff[v.back()] = 1;
    diff[3] = 1;
    for(int i = 0; i < v.size() - 1; i++){
        diff[v[i] - v[i+1]]++;
    }
    cout << "Part 1: " << diff[1] * diff[3] << "\n";
    unordered_map<int, long long> ways;
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++){
        s.insert(v[i]);
    }
    s.insert(v.front() + 3);
    count_ways(v.front() + 3, s, ways);
    cout << "Part 2: " <<  ways[v.front()] << "\n";
}