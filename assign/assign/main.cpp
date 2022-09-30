//
//  main.cpp
//  assign
//
//  Created by Jerry Cheng on 8/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> same[16];
vector<int> diff[16];
int current[16], ans, n;

void all(int loc){
    for (int i = 1; i <= 3; i++){
        bool x = true;
        for (int j = 0; j < same[loc].size(); j++){
            if (current[same[loc][j]] != i && current[same[loc][j]] != 0){
                x = false;
                break;
            }
        }
        for (int j = 0; j < diff[loc].size(); j++){
            if (current[diff[loc][j]] == i){
                x = false;
                break;
            }
        }
        if(x){
            if(loc < n){
                current[loc] = i;
                all(loc + 1);
                current[loc] = 0;
            }else{
                ans++;
            }
        }
    }
}

int main() {
    ifstream fin("assign.in");
    ofstream fout("assign.out");
    int k;
    fin >> n >> k;
    for (int i = 0; i < k; i++){
        char a;
        int b, c;
        fin >> a >> b >> c;
        if (a == 'S'){
            same[b].push_back(c);
            same[c].push_back(b);
        }else{
            diff[b].push_back(c);
            diff[c].push_back(b);
        }
    }
    for (int i = 0; i <= n; i++){
        current[i] = 0;
    }
    all(1);
    fout << ans << endl;
    return 0;
}
