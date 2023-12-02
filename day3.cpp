#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream file;
    file.open("input.txt");
    vector<string> map;
    string line;
    while (getline(file, line)){
        map.push_back(line);
    }
    int x = 0, y = 0, trees = 0;
    while (y < map.size()){
        if (map[y][x] == '#'){
            trees++;
        }
        x = (x + 3) % map[0].size();
        y++;
    }
    cout << "Part 1: " << trees << "\n";
    vector<pair<int, int>> slopes = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
    int ans = 1;
    for (auto &[dx,dy]: slopes){
        int x = 0, y = 0, trees = 0;
        while (y < map.size()){
            if (map[y][x] == '#'){
                trees++;
            }
            x = (x + dx) % map[0].size();
            y += dy;
        }
        ans *= trees;
    }
    cout << "Part 2: " << ans << "\n";
    file.close();
    return 0;
}