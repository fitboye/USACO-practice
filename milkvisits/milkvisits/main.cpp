//
//  main.cpp
//  milkvisits
//
//  Created by Jerry Cheng on 1/9/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string breeds;
vector<int> roads[100001];
int section[100001];
void search (int current, int last, int num, char lastbreed){
    if (breeds[current - 1] != lastbreed){
        return;
    }
    section[current] = num;
    
    for (int i = 0; i < roads[current].size(); i++){
        if (roads[current][i] != last){
            search(roads[current][i], current, num, lastbreed);
        }
    }
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    int n, m;
    fin >> n >> m >> breeds;
    
    for (int i = 0; i < n - 1; i++){
        int x, y;
        fin >> x >> y;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    
    int num = 1;
    for (int i = 0; i <= n; i++){
        section[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        if (section[i] == 0){
            search(i, -1, num, breeds[i - 1]);
            num++;
        }
    }
    
    string ans = "";
    for (int i = 0; i < m; i++){
        int x, y;
        char z;
        fin >> x >> y >> z;
        //cout << section[x] << ' ' << section[y] << endl;
        if (section[x] != section[y] || breeds[x - 1] == z){
            ans += '1';
        }else{
            ans += '0';
        }
    }
    fout << ans << endl;
    return 0;
}
