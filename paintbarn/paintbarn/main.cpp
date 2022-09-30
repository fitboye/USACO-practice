//
//  main.cpp
//  paintbarn
//
//  Created by Jerry Cheng on 2/24/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    int n, k;
    fin >> n >> k;
    int x1, y1, x2, y2, all[1001][1001];
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 1001; j++){
            all[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++){
        fin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++){
            all[x1][j]++;
            all[x2][j]--;
        }
    }
    
    int current = 0, total = 0;
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 1001; j++){
            current = current + all[j][i];
            if (current == k){
                total++;
            }
            
        }
    }
    fout << total << endl;
    return 0;
}
