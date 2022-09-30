//
//  main.cpp
//  revegetate2
//
//  Created by Jerry Cheng on 5/17/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct cow{
    int a;
    char type;
};

bool possible = true;
int n, m, groups[100001], check[100001];
vector<cow> c[100001];

void floodfill (int current, int last, int fill, int type){
    if (groups[current] == 0){
        groups[current] = fill;
        if (type == 'S'){
            check[current] = check[last];
        }else if (type == 'D'){
            check[current] = check[last] * -1;
        }
    }else{
        if (type == 'S'){
            if (check[current] != check[last]){
                possible = false;
            }
        }else{
            if (check[current] == check[last]){
                possible = false;
            }
        }
        return;
    }
    
    for (int i = 0; i < c[current].size(); i++){
        floodfill(c[current][i].a, current, fill, c[current][i].type);
    }
}


int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        char type;
        fin >> type >> x >> y;
        cow z;
        z.type = type;
        z.a = y;
        c[x].push_back(z);
        z.a = x;
        c[y].push_back(z);
    }
    for (int i = 0; i < n; i++){
        groups[i] = 0;
    }
    
    int fillnum = 1;
    for (int i = 1; i <= n; i++){
        if (groups[i] == 0){
            check[i] = 1;
            floodfill(i, 0, fillnum, 'A');
            fillnum++;
        }
    }
    
    if (possible){
        fout << 1;
        for (int i = 0; i < fillnum - 1; i++){
            fout << 0;
        }
    }else{
        fout << 0;
    }
    fout << endl;
    return 0;
}
