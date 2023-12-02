#include <bits/stdc++.h>
using namespace std;
const char dir[] = {'N', 'E', 'S', 'W'};
int main(){
    fstream file;
    vector<string> v;
    file.open("input.txt");
    string line;
    while(getline(file, line)){
        v.push_back(line);
    }
    file.close();
    int x = 0, y = 0;
    int dir = 1;
    for(auto &s : v){
        char c = s[0];
        int n = stoi(s.substr(1));
        switch(c){
            case 'N':
                y += n;
                break;
            case 'S':
                y -= n;
                break;
            case 'E':
                x += n;
                break;
            case 'W':
                x -= n;
                break;
            case 'L':
                switch (n){
                    case 90:
                        dir = (dir + 3) % 4;
                        break;
                    case 180:
                        dir = (dir + 2) % 4;
                        break;
                    case 270:
                        dir = (dir + 1) % 4;
                        break;
                }
                break;
            case 'R':
                switch (n){
                    case 90:
                        dir = (dir + 1) % 4;
                        break;
                    case 180:
                        dir = (dir + 2) % 4;
                        break;
                    case 270:
                        dir = (dir + 3) % 4;
                        break;
                }
                break;
            case 'F':
                switch (dir){
                    case 0:
                        y += n;
                        break;
                    case 1:
                        x += n;
                        break;
                    case 2:
                        y -= n;
                        break;
                    case 3:
                        x -= n;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    cout << "Part 1: " << abs(x) + abs(y) << endl;
    x = 0, y = 0;
    int wx = 10, wy = 1;
    int nx = 0, ny = 0;
    dir = 1;
    for(auto &s : v){
        char c = s[0];
        int n = stoi(s.substr(1));
        switch(c){
            case 'N':
                wy += n;
                break;
            case 'S':
                wy -= n;
                break;
            case 'E':
                wx += n;
                break;
            case 'W':
                wx -= n;
                break;
            case 'L':
                switch (n){
                    case 90:
                        nx = -wy;
                        ny = wx;
                        wx = nx;
                        wy = ny;
                        break;
                    case 180:
                        wx = -wx;
                        wy = -wy;
                        break;
                    case 270:
                        nx = wy;
                        ny = -wx;
                        wx = nx;
                        wy = ny;
                        break;
                }
                break;
            case 'R':
                switch (n){
                    case 90:
                        nx = wy;
                        ny = -wx;
                        wx = nx;
                        wy = ny;
                        break;
                    case 180:
                        wx = -wx;
                        wy = -wy;
                        break;
                    case 270:
                        nx = -wy;
                        ny = wx;
                        wx = nx;
                        wy = ny;
                        break;
                }
                break;
            case 'F':
                x += n * wx;
                y += n * wy;
            default:
                break;
        }
    }
    cout << "Part 2: " << abs(x) + abs(y) << endl;
    return 0;
}