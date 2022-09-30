//
//  main.cpp
//  perimeter2
//
//  Created by Jerry Cheng on 12/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, a[1002][1002], area, p;

void floodfill (int x, int y){
    if (a[x][y] != 1){
        return;
    }
    
    area++;
    a[x][y] = 2;
    if (a[x + 1][y] == 0 || a[x + 1][y] == -1){
        p++;
    }
    if (a[x - 1][y] == 0 || a[x - 1][y] == -1){
        p++;
    }
    if (a[x][y + 1] == 0 || a[x][y + 1] == -1){
        p++;
    }
    if (a[x][y - 1] == 0 || a[x][y - 1] == -1){
        p++;
    }
    
    floodfill(x + 1, y);
    floodfill(x - 1, y);
    floodfill(x, y + 1);
    floodfill(x, y - 1);
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    fin >> n;
    for (int i = 0; i < n; i++){
        a[0][i] = -1;
        a[n + 1][i] = -1;
        a[i][0] = -1;
        a[i][n + 1] = -1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char x;
            fin >> x;
            if (x == '.'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }
    
    int maxarea = 0, maxp = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                area = 0;
                p = 0;
                floodfill(i, j);
                if (area > maxarea){
                    maxarea = area;
                    maxp = p;
                }else if (area == maxarea && p < maxp){
                    maxp = p;
                }
            }
        }
    }
    fout << maxarea << ' ' << maxp << endl;
    return 0;
}
