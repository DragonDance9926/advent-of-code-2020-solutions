#include <bits/stdc++.h>
using namespace std;


int main(){
    set<tuple<int,int,int>> cubes;
    set<tuple<int,int,int,int>> dim4d;
    vector<string> mp;
    string line;
    ifstream file;
    file.open("input.txt");
    while (getline(file, line)){
        mp.push_back(line);
    }
    file.close();
    for (int i = 0; i < mp.size(); i++){
        for (int j = 0; j < mp[i].size(); j++){
            if (mp[i][j] == '#'){
                cubes.insert({i,j,0});
                dim4d.insert({i,j,0,0});
            }
        }
    }
    int cycles = 6;
    for (int i = 0; i < cycles; i++){
        set<tuple<int,int,int>> newcubes;
        //cout << "Cycle: " << i << " " << cubes.size() << endl;
        int x_min = INT_MAX,y_min = INT_MAX,z_min = INT_MAX;
        int x_max = INT_MIN,y_max = INT_MIN,z_max = INT_MIN;
        for (auto cube : cubes){
            int x = get<0>(cube);
            int y = get<1>(cube);
            int z = get<2>(cube);
            x_min = min(x,x_min);
            x_max = max(x,x_max);
            y_min = min(y,y_min);
            y_max = max(y,y_max);
            z_min = min(z,z_min);
            z_max = max(z,z_max);
        }
        for (int i = x_min - 1; i <= x_max + 1; i++){
            for (int j = y_min - 1; j <= y_max + 1; j++){
                for (int k = z_min - 1; k <= z_max + 1; k++){
                    //cout << i << " " << j << " " << k << endl;
                    int active_count = 0;
                    for (int x = -1; x <= 1; x++){
                        for (int y = -1; y <= 1; y++){
                            for (int z = -1; z <= 1; z++){
                                if (x == 0 && y == 0 && z == 0){
                                    continue;
                                }
                                if (cubes.find({i+x,j+y,k+z}) != cubes.end()){
                                    active_count++;
                                }
                            }
                        }
                    }
                    if (cubes.find({i,j,k}) != cubes.end()){
                        if (active_count == 2 || active_count == 3){
                            newcubes.insert({i,j,k});
                        }
                    } 
                    else{
                        if (active_count == 3){
                            newcubes.insert({i,j,k});
                        }
                    }
                }
            }
        }
        cubes.clear();
        for (auto cube : newcubes){
            cubes.insert(cube);
        }
    }
    cout << "Part 1: " << cubes.size() << endl;
    //Forget the cube
    for (int i = 0; i < cycles; i++){
        set<tuple<int,int,int,int>> newdim4d;
        int x_min = INT_MAX,y_min = INT_MAX,z_min = INT_MAX,w_min = INT_MAX;
        int x_max = INT_MIN,y_max = INT_MIN,z_max = INT_MIN,w_max = INT_MIN;
        for (auto cube : dim4d){
            int x = get<0>(cube);
            int y = get<1>(cube);
            int z = get<2>(cube);
            int w = get<3>(cube);
            x_min = min(x,x_min);
            x_max = max(x,x_max);
            y_min = min(y,y_min);
            y_max = max(y,y_max);
            z_min = min(z,z_min);
            z_max = max(z,z_max);
            w_min = min(w,w_min);
            w_max = max(w,w_max);
        }
        for (int i = x_min - 1; i <= x_max + 1; i++){
            for (int j = y_min - 1; j <= y_max + 1; j++){
                for (int k = z_min - 1; k <= z_max + 1; k++){
                    for (int l = w_min - 1; l <= w_max + 1; l++){
                        int active_count = 0;
                        for (int x = -1; x <= 1; x++){
                            for (int y = -1; y <= 1; y++){
                                for (int z = -1; z <= 1; z++){
                                    for (int w = -1; w <= 1; w++){
                                        if (x == 0 && y == 0 && z == 0 && w == 0){
                                            continue;
                                        }
                                        if (dim4d.find({i+x,j+y,k+z,l+w}) != dim4d.end()){
                                            active_count++;
                                        }
                                    }
                                }
                            }
                        }
                        if (dim4d.find({i,j,k,l}) != dim4d.end()){
                            if (active_count == 2 || active_count == 3){
                                newdim4d.insert({i,j,k,l});
                            }
                        }
                        else{
                            if (active_count == 3){
                                newdim4d.insert({i,j,k,l});
                            }
                        }
                    }
                }
            }
        }
        dim4d.clear();
        for (auto cube : newdim4d){
            dim4d.insert(cube);
        }
    }
    cout << "Part 2: " << dim4d.size() << endl;
    return 0;
}