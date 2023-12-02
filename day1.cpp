#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream file;
    file.open("input.txt");
    vector<int> v;
    int x;
    while (file >> x){
        v.push_back(x);
    }
    int ans = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        int target = 2020 - v[i];
        int res = binary_search(v.begin(), v.end(), target);
        if (res){
            ans *= target * v[i];
            break;
        }
    }
    cout << "Part 1: " << ans << "\n";
    ans = 1;
    for (int i = 0; i < v.size(); i++){
        int left = i + 1;
        int right = v.size() - 1;
        while (left < right){
            int sum = v[i] + v[left] + v[right];
            if (sum == 2020){
                ans *= v[i] * v[left] * v[right];
            }
            if (sum > 2020){
                right--;
            }
            else{
                left++;
            }
        }
    }
    cout << "Part 2: " << ans << "\n";
    file.close();
    return 0;

}