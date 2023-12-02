#include <bits/stdc++.h>
using namespace std;


long long lastNumberSpoken(vector<int>& seq, unordered_map<long long, pair<long long, long long>>& last, long long turn) {
    long long c = 0;
    for (auto& n : seq) {
        last[n] = make_pair(c++, -1);
    }
    long long last_n = seq.back();
    for (long long i = c; i < turn; i++) {
        long long says;
        if (last.find(last_n) == last.end() || last[last_n].second == -1) {
            says = 0;
        }
        else {
            says = last[last_n].first - last[last_n].second;
            if (says < 0){
                cout << says << " " << last[last_n].first << " " << last[last_n].second << endl;
            }
        }
        last_n = says;
        if (last.find(last_n) == last.end()) {
            last[last_n] = make_pair(i, -1);
        }
        else {
            last[last_n].second = last[last_n].first;
            last[last_n].first = i;
        }
    }
    return last_n;
}


int main(){
    vector<int> seq = {2,1,10,11,0,6};
    unordered_map<long long, pair<long long, long long>> last;
    cout << "Part 1: " << lastNumberSpoken(seq, last, 2020) << endl;
    last.clear();
    cout << "Part 2: " << lastNumberSpoken(seq, last, 30000000) << endl;
}