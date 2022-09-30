//
//  main.cpp
//  fenceplan
//
//  Created by Jerry Cheng on 1/12/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> c[100000];
int a[2][100000], top = 100000000, bottom = 0, l = 1000000000, r = 0;

void search(int b, int cows[], int fill){
    //cout << b << endl;
    if (a[0][b] < l){
        l = a[0][b];
    }
    if (a[0][b] > r){
        r = a[0][b];
    }
    if (a[1][b] < top){
        top = a[1][b];
    }
    if (a[1][b] > bottom){
        bottom = a[1][b];
    }
    cows[b] = fill;
    
    for (int i = 0; i < c[b].size(); i++){
        if (cows[c[b][i]] == 0){
            search(c[b][i], cows, fill);
        }
    }
}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    int n, m;
    fin >> n >> m;
    int b[2][100000];
    for (int i = 0; i < n; i++){
        fin >> a[0][i] >> a[1][i];
    }
    for (int i = 0; i < m; i++){
        fin >> b[0][i] >> b[1][i];
        //cout << b[0][i] - 1 << ' ' << b[1][i] - 1 << endl;
        c[b[0][i] - 1].push_back(b[1][i] - 1);
        c[b[1][i] - 1].push_back(b[0][i] - 1);
    }
    int cows[100000], fill = 1;
    for (int i = 0; i < n; i++){
        cows[i] = 0;
    }
    int p, ans = 1000000000;
    for (int i = 0; i < n; i++){
        top = 100000000;
        bottom = 0;
        l = 1000000000;
        r = 0;
        if(cows[i] == 0){
            search(i, cows, fill);
            fill++;
            //cout << bottom << ' ' << top << ' ' << r << ' ' << l << endl;
            p = (bottom - top) * 2 + (r - l) * 2;
            if (p < ans){
                ans = p;
            }
        }
    }
    fout << ans << endl;
    return 0;
}
