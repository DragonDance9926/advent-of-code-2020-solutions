#include <bits/stdc++.h>
using namespace std;

int recursive_game(deque<int>& dq1, deque<int>& dq2){
    set<pair<deque<int>, deque<int>>> seen;
    while (!dq1.empty() && !dq2.empty()){
        if (seen.count({dq1, dq2})){
            return 1;
        }
        seen.insert({dq1, dq2});
        int v1 = dq1.front();
        int v2 = dq2.front();
        dq1.pop_front();
        dq2.pop_front();
        int winner;
        if (v1 <= dq1.size() && v2 <= dq2.size()){
            deque<int> dq1_copy(dq1.begin(), dq1.begin() + v1);
            deque<int> dq2_copy(dq2.begin(), dq2.begin() + v2);
            winner = recursive_game(dq1_copy, dq2_copy);
        } else {
            winner = v1 > v2 ? 1 : 2;
        }
        if (winner == 1){
            dq1.push_back(v1);
            dq1.push_back(v2);
        } else {
            dq2.push_back(v2);
            dq2.push_back(v1);
        }
    }
    return dq1.empty() ? 2 : 1;
}


int main(){
    vector<int> v1 = {9, 2, 6, 3, 1};
    v1 = {50,19,40,22,7,4,3,16,34,45,46,39,44,32,20,29,15,35,41,2,21,28,6,26,48};
    vector<int> v2 = {5, 8, 4, 7, 10};
    v2 = {14,9,37,47,38,27,30,24,36,31,43,42,11,17,18,10,12,5,33,25,8,23,1,13,49};
    deque<int> dq1(v1.begin(), v1.end());
    deque<int> dq2(v2.begin(), v2.end());
    while (!dq1.empty() && !dq2.empty()){
        int v1 = dq1.front();
        int v2 = dq2.front();
        //cout << v1 << " " << v2 << endl;
        dq1.pop_front();
        dq2.pop_front();
        if (v1 > v2){
            dq1.push_back(v1);
            dq1.push_back(v2);
        } else {
            dq2.push_back(v2);
            dq2.push_back(v1);
        }
    }
    deque<int> dq = dq1.empty() ? dq2 : dq1;
    auto it = dq.rbegin();
    int sum = 0;
    for (int i = 1; it != dq.rend(); ++it, ++i){
        sum += i * (*it);
    }
    cout << "Part 1: " << sum << endl;
    dq1 = deque<int>(v1.begin(), v1.end());
    dq2 = deque<int>(v2.begin(), v2.end());
    int winner = recursive_game(dq1, dq2);
    dq = winner == 1 ? dq1 : dq2;
    it = dq.rbegin();
    sum = 0;
    for (int i = 1; it != dq.rend(); ++it, ++i){
        sum += i * (*it);
    }
    cout << "Part 2: " << sum << endl;
}