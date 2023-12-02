#include <bits/stdc++.h>
using namespace std;
int main(){
    fstream file;
    file.open("input.txt");
    string line;
    getline(file, line);
    int time = stoi(line);
    vector<int> busses;
    vector<int> delays;
    
    getline(file, line);
    stringstream ss(line);
    int d = 0;
    while(getline(ss, line, ',')){
        if(line != "x"){
            busses.push_back(stoi(line));
            delays.push_back(d);
        }
        d++;
    }
    file.close();
    int mini = (time / busses[0] + 1) * busses[0] - time;
    int index = 0;
    for(int i = 1; i < busses.size(); i++){
        int t = (time / busses[i] + 1) * busses[i] - time;
        if(t < mini){
            mini = t;
            index = i;
        }
    }
    cout << "Part 1: " << mini * busses[index] << endl;
    long long stepsize = busses[0];
    long long timestamp = 0;
    for (int i = 1; i < busses.size(); i++){
        while((timestamp + delays[i]) % busses[i] != 0){
            timestamp += stepsize;
        }
        stepsize *= busses[i];
    }
    cout << "Part 2: " << timestamp << endl;
    return 0;
}