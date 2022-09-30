//
//  main.cpp
//  countcross
//
//  Created by Jerry Cheng on 1/3/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct road{
    int r, c, r1, c1;
};

int all[100][100];
bool hroad[101][100], vroad[100][101];

void search(int row, int column, int fill){
    all[row][column] = fill;
    if ((!vroad[row][column + 1]) && (all[row][column + 1] == 0)){
        //all[row][column] = fill;
        search(row, column + 1, fill);
    }
    if ((!vroad[row][column]) && (all[row][column - 1] == 0)){
        //all[row][column] = fill;
        search(row, column - 1, fill);
    }
    if ((!hroad[row + 1][column]) && (all[row + 1][column] == 0)){
        //all[row][column] = fill;
        search(row + 1, column, fill);
    }
    if ((!hroad[row][column]) && (all[row - 1][column] == 0)){
        //all[row][column] = fill;
        search(row - 1, column, fill);
    }
}

int main() {
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");
    int n, k, r;
    fin >> n >> k >> r;
    road a[100000];
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 99; j++){
            hroad[i][j] = false;
            vroad[j][i] = false;
        }
    }
    for (int i = 0; i < n; i++){
        hroad[n][i] = true;
        hroad[0][i] = true;
        vroad[i][n] = true;
        vroad[i][0] = true;
    }
    for (int i = 0; i < r; i++){
        fin >> a[i].r >> a[i].c >> a[i].r1 >> a[i].c1;
        if (a[i].r == a[i].r1){
            if (a[i].c < a[i].c1){
                vroad[a[i].r - 1][a[i].c] = true;
            }else{
                vroad[a[i].r - 1][a[i].c1] = true;
            }
        }else{
            if (a[i].r < a[i].r1){
                hroad[a[i].r][a[i].c - 1] = true;
            }else{
                hroad[a[i].r1][a[i].c - 1] = true;
            }
        }
    }
    
    
    
    int b[100], c[100];
    for (int i = 0; i < k; i++){
        fin >> b[i] >> c[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            all[i][j] = 0;
        }
    }
    int num = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (all[i][j] == 0){
                search(i, j, num);
                num++;
            }
        }
    }

    int cows[10000];
    for (int i = 0; i < k; i++){
        cows[i] = 0;
    }
    for (int i = 0; i < k; i++){
        cows[all[b[i] - 1][c[i] - 1] - 1]++;
    }
    int ans = 0;
    for (int i = 0; i < 10000; i++){
        if (i == num - 1){
            break;
        }
        ans = ans + (k - cows[i]) * cows[i];
    }
    fout << ans / 2 << endl;
    return 0;
}
