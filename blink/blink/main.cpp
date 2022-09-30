//
//  main.cpp
//  blink
//
//  Created by Jerry Cheng on 3/7/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("blink.in");
    ofstream fout("blink.out");
    int n;
    long long b;
    fin >> n >> b;
    int all[20][70000];
    for (int i = 0; i < n; i++){
        fin >> all[i][0];
    }
    
    int c[70000];
    for (int i = 0; i < 70000; i++){
        c[i] = -1;
    }
    int multiples[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
    int start, end;
    for (int i = 1; i < 70000; i++){
        for (int j = 0; j < n; j++){
            all[j][i] = all[j][i - 1];
            //cout << all[j][i] << ' ';
        }
        //cout << endl;
        if (all[n - 1][i - 1] == 1){
            all[0][i] = (all[0][i] + 1) % 2;
        }
        //cout << all[0][i] << ' ';
        for (int j = 1; j < n; j++){
            if (all[j - 1][i - 1] == 1){
                all[j][i] = (all[j][i] + 1) % 2;
            }
            //cout << all[j][i] << ' ';
        }
        //cout << endl;
        
        int x = 0;
        for (int j = 0; j < n; j++){
            x = x + all[j][i] * multiples[j];
        }
        if (c[x] != -1){
            start = c[x];
            end = i;
            break;
        }else{
            c[x] = i;
        }
    }
    long long d = b;
    if (b > end){
        d = d - start;
        d = d % (end - start);
        d = d + start;
    }
    //cout << start << ' ' << end << endl;
    //cout << d << endl;
    for (int i = 0; i < n; i++){
        fout << all[i][d] << endl;
    }
    return 0;
}
/*
 5 20
 1
 0
 0
 0
 0
*/
