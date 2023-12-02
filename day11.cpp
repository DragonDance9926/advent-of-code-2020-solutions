#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream file;
    vector<string> v;
    file.open("input.txt");
    string line;
    while(getline(file, line)){
        v.push_back(line);
    }
    file.close();
    vector<pair<int, int>> adj = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<string> v2 = v;
    int ans = 0;
    while (true){
        vector<pair<int,int>> changed;
        for (int i = 0; i < v2.size(); i++){
            for (int j = 0; j < v2[i].size(); j++){
                if (v2[i][j] == '.'){
                    continue;
                }
                int occupied = 0;
                for (auto x : adj){
                    int ni = i + x.first;
                    int nj = j + x.second;
                    if (ni < 0 || nj < 0 || ni >= v2.size() || nj >= v2[i].size()){
                        continue;
                    }
                    if (v2[ni][nj] == '#'){
                        occupied++;
                    }
                }
                if (v2[i][j] == 'L' && occupied == 0){
                    changed.push_back({i, j});
                }
                if (v2[i][j] == '#' && occupied >= 4){
                    changed.push_back({i, j});
                }
            }
        }
        if (changed.size() == 0){
            break;
        }
        for (auto x : changed){
            v2[x.first][x.second] = (v2[x.first][x.second] == 'L' ? '#' : 'L');
        }
        ans++;
    }
    int count = 0;
    for (int i = 0; i < v2.size(); i++){
        for (int j = 0; j < v2[i].size(); j++){
            if (v2[i][j] == '#'){
                count++;
            }
        }
    }
    cout << "Part 1: " << count << endl;
    ans = 0;
    v2 = v;
    while (true){
        vector<pair<int,int>> changed;
        for (int i = 0; i < v2.size(); i++){
            for (int j = 0; j < v2[i].size(); j++){
                if (v2[i][j] == '.'){
                    continue;
                }
                int occupied = 0;
                for (auto x : adj){
                    int ni = i + x.first;
                    int nj = j + x.second;
                    while (ni >= 0 && nj >= 0 && ni < v2.size() && nj < v2[i].size()){
                        if (v2[ni][nj] == '#'){
                            occupied++;
                            break;
                        }
                        if (v2[ni][nj] == 'L'){
                            break;
                        }
                        ni += x.first;
                        nj += x.second;
                    }
                }
                if (v2[i][j] == 'L' && occupied == 0){
                    changed.push_back({i, j});
                }
                if (v2[i][j] == '#' && occupied >= 5){
                    changed.push_back({i, j});
                }
            }
        }
        if (changed.size() == 0){
            break;
        }
        for (auto x : changed){
            v2[x.first][x.second] = (v2[x.first][x.second] == 'L' ? '#' : 'L');
        }
        ans++;
    }
    count = 0;
    for (int i = 0; i < v2.size(); i++){
        for (int j = 0; j < v2[i].size(); j++){
            if (v2[i][j] == '#'){
                count++;
            }
        }
    }
    cout << "Part 2: " << count << endl;
    return 0;
}