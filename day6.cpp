#include <bits/stdc++.h>
using namespace std;
int main(){
    fstream file;
    file.open("input.txt");
    int ans = 0;
    bitset<26> arr;
    string line;
    while(file.eof() == false){
        getline(file, line);
        if (line == ""){
            ans += arr.count();
            arr.reset();
        } else {
            for (auto ch : line){
                arr.set(ch - 'a');
            }
        }
    }
    cout << "Part 1: " << ans << "\n";
    //Turn back to start at file beginning
    file.close();
    file.open("input.txt");
    ans = 0;
    //Set all bits to 1
    arr.set();
    while(file.eof() == false){
        getline(file, line);
        if (line == ""){
            ans += arr.count();
            arr.set();
        } else {
            bitset<26> arr2;
            arr2.reset();
            for (auto ch : line){
                arr2.set(ch - 'a');
            }
            arr &= arr2;
        }
        
    }
    cout << "Part 2: " << ans << "\n";
    file.close();
    return 0;
}