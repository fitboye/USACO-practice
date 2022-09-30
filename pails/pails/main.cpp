//
//  main.cpp
//  pails
//
//  Created by Jerry Cheng on 10/31/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int x, y, k, m, ans = 99999;
bool q[101][101][101];

void search(int x1, int y1, int d){
    int difference = m - x1 - y1;
    if (difference < 0){
        difference = difference * -1;
    }
    if (difference < ans){
        ans = difference;
    }
    if (d == k){
        return;
    }
    
    if (q[x1][y1][d] == true){
        return;
    }
    q[x1][y1][d] = true;
    
    search(x, y1, d + 1);
    search(x1, y, d + 1);
    
    search(0, y1, d + 1);
    search(x1, 0, d + 1);
    
    
    if (y > x1 + y1){
        search(0, y1 + x1, d + 1);
    }else{
        search(x1 - (y - y1), y, d + 1);
    }
    
    if (x > x1 + y1){
        search(x1 + y1, 0, d + 1);
    }else{
        search(x, y1 - (x - x1), d + 1);
    }
}

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> x >> y >> k >> m;
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            for (int l = 0; l < 101; l++){
                q[i][j][l] = false;
            }
        }
    }
    search(0, 0, 0);
    fout << ans << endl;
    return 0;
}
