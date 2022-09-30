//
//  main.cpp
//  backforth
//
//  Created by Jerry Cheng on 12/15/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    int all[250000], a[10], b[11], len = 0, c[10], d[11];;
    for (int i = 0; i < 10; i++){
        fin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < 10; i++){
        fin >> b[i];
        d[i] = b[i];
    }

    int e[4][12100];
    int x = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 11; j++){
            for (int k = 0; k < 10; k++){
                for (int l = 0; l < 11; l++){
                    e[0][x] = i;
                    e[1][x] = j;
                    e[2][x] = k;
                    e[3][x] = l;
                    x++;
                }
            }
        }
    }
    
    int milk;
    for (int i = 0; i < x; i++){
        milk = 1000;
        for (int j = 0; j < 10; j++){
            a[j] = c[j];
        }
        for (int j = 0; j < 10; j++){
            b[j] = d[j];
        }
        milk = milk - a[e[0][i]];
        b[10] = a[e[0][i]];
        milk = milk + b[e[1][i]];
        a[e[0][i]] = b[e[1][i]];
        milk = milk - a[e[2][i]];
        b[e[1][i]] = a[e[2][i]];
        milk = milk + b[e[3][i]];
        bool y = true;
        for (int j = 0; j < len; j++){
            if (milk == all[j]){
                y = false;
                break;
            }
        }
        if (y){
            all[len] = milk;
            len++;
        }
    }
    
    fout << len << endl;
    return 0;
}
