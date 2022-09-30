//
//  main.cpp
//  buckets
//
//  Created by Jerry Cheng on 4/1/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    char a[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            fin >> a[i][j];
        }
    }
    
    int bi = 0, bj = 0, li = 0, lj = 0, ri = 0, rj = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (a[i][j] == 'B'){
                bi = i;
                bj = j;
            }else if (a[i][j] == 'L'){
                li = i;
                lj = j;
            }else if (a[i][j] == 'R'){
                ri = i;
                rj = j;
            }
        }
    }
    
    int cows = 0;
    if (bi < li){
        if (bj < lj){
            cows = li - bi + lj - bj;
        }else{
            cows = li - bi + bj - lj;
        }
    }else{
        if (bj < lj){
            cows = bi - li + lj - bj;
        }else{
            cows = bi - li + bj - lj;
        }
    }
    
    if ((bi == ri) && (ri == li)){
        if ((bj < rj) && (rj < lj)){
            cows = cows + 2;
        }else if ((lj < rj) && (rj < bj)){
            cows = cows + 2;
        }
    }else if ((bj == rj) && (rj == lj)){
        if ((bi < ri) && (ri < li)){
            cows = cows + 2;
        }else if ((li < ri) && (ri < bi)){
            cows = cows + 2;
        }
    }
    fout << cows - 1 << endl;
    return 0;
}

