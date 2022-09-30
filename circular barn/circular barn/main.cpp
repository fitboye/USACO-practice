//
//  main.cpp
//  circular barn
//
//  Created by Jerry Cheng on 06/01/2018.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n, a[1000], b[1000], x = 0, y = 60000000;
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i];
    }
    for (int i = 0; i < n; i = i + 1){
        x = 0;
        for (int j = 0; j < n - i; j = j + 1){
            b[j] = a[j + i];
        }
        for (int j = 0; j < i; j = j + 1){
            b[j + n - i] = a[j];
        }
        for (int j = 0; j < n; j = j + 1){
            x = x + b[j] * j;
        }
        if (x < y){
            y = x;
        }
    }
    fout << y << endl;
    return 0;
}
