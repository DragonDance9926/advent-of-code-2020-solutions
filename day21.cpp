#include <bits/stdc++.h>
#include <regex>
using namespace std;
//regex: ([\w ]*)\(contains ([\w, ]*)\)

int main(){
    ifstream file("input.txt");
    string line;
    regex re("([\\w ]*)\\(contains ([\\w, ]*)\\)");
    smatch match;
    unordered_map<string, unordered_set<string>> allergenMap;
    unordered_map<string, int> ingredientCount;
    cout <<"Getting input" << endl;
    while(getline(file, line)){
        regex_match(line, match, re);
        string ingredients = match[1];
        string allergens = match[2];
        unordered_set<string> ingredientSet;
        stringstream ss(ingredients);
        string ingredient;
        while(ss >> ingredient){
            ingredientSet.insert(ingredient);
            ingredientCount[ingredient]++;
        }
        stringstream ss2(allergens);
        string allergen;
        unordered_set<string> allergenSet;
        while(ss2 >> allergen){
            if (allergen[allergen.size()-1] == ','){
                allergen = allergen.substr(0, allergen.size()-1);
            }
            allergenSet.insert(allergen);
        }
        for (auto &a : allergenSet){
            if(allergenMap.find(a) == allergenMap.end()){
                allergenMap[a] = ingredientSet;
            }else{
                unordered_set<string> tmp;
                for (auto &i : ingredientSet){
                    if(allergenMap[a].find(i) != allergenMap[a].end()){
                        tmp.insert(i);
                    }
                }
                
                allergenMap[a] = tmp;
            }
        }
    }
    for (auto &a : allergenMap){
        cout << a.first << ": ";
        for (auto &i : a.second){
            cout << i << " ";
        }
        cout << endl;
    }
    int count = 0;
    unordered_set<string> foundAllargens;
    for (auto &[k, v] : allergenMap){
        for (auto &i : v){
            foundAllargens.insert(i);
        }
    }
    for (auto &[k, v] : ingredientCount){
        
        if (foundAllargens.find(k) == foundAllargens.end()){
            //cout << k << " " << v << endl;
            count += v;
        }
    }
    cout << "Part 1: " << count << endl;
    map<string, string> allergenToIngredient;
    while(allergenMap.size() > 0){
        for (auto &[k, v] : allergenMap){
            if (v.size() == 1){
                string ingredient = *v.begin();
                allergenToIngredient[k] = ingredient;
                for (auto &[k2, v2] : allergenMap){
                    v2.erase(ingredient);
                }
                allergenMap.erase(k);
                break;
            }
        }
    }
    string result;
    for (auto &[k, v] : allergenToIngredient){
        result += v + ",";
    }
    result.pop_back();
    cout << "Part 2: " << result << endl;
    


    return 0;
}