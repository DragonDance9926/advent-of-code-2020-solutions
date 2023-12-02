#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<string> v;
    while (getline(file, line)){
        v.push_back(line);
    }
    file.close();
    int ans = 0;
    vector<int> v2;
    for(auto &s:v){
        int l_row = 0;
        int l_col = 0;
        int r_row = 127;
        int r_col = 7;
        for (auto &ch:s){
            if (ch == 'F'){
                r_row = (r_row + l_row) / 2;
            } else if (ch == 'B'){
                l_row = (l_row + r_row) / 2 + 1;
            } else if (ch == 'L'){
                r_col = (r_col + l_col) / 2;
            } else if (ch == 'R'){
                l_col = (l_col + r_col) / 2 + 1;
            }
        }
        ans = max(ans, l_row * 8 + l_col);
        if (l_row != 1 && l_row != 127){
            v2.push_back(l_row * 8 + l_col);
        }
    }
    cout << "Part 1: " << ans << "\n";
    sort(v2.begin(), v2.end());
    int ans2 = 0;
    for (int i = 1; i < v2.size(); i++){
        if (v2[i] - v2[i - 1] == 2 && !binary_search(v2.begin(), v2.end(), v2[i] - 1)){
            ans2 = v2[i] - 1;
            break;
            //cout << "Part 2: " << ans2 << "\n";
        }
    }
    cout << "Part 2: " << ans2 << "\n";
    file.close();
    return 0;
}