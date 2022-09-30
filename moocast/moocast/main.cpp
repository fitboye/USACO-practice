//
//  main.cpp
//  moocast
//
//  Created by Jerry Cheng on 1/12/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int n, tot;
bool a[200][200];

void search(int b, bool used[]){
    for (int i = 0; i < n; i++){
        if (a[b][i]){
            if (!used[i]){
                used[i] = true;
                tot++;
                search(i, used);
            }
        }
    }
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    int x[200], y[200], p[200];
    for (int i = 0; i < n; i++){
        fin >> x[i] >> y[i] >> p[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int d = pow((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), 0.5);
            if (d < p[i]){
                a[i][j] = true;
            }
        }
    }
    
    bool used[200];
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            used[j] = false;
        }
        tot = 0;
        search(i, used);
        if (tot > ans){
            ans = tot;
        }
    }
    fout << ans << endl;
    return 0;
}
