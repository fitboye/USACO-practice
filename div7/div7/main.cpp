//
//  main.cpp
//  div7
//
//  Created by Jerry Cheng on 1/12/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n, a[50000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    long long b[50000];
    b[0] = a[0];
    for (int i = 1; i < n; i++){
        b[i] = b[i - 1] + a[i];
    }
    
    int r[50001];
    r[0] = 0;
    for (int i = 1; i < n + 1; i++){
        r[i] = b[i - 1] % 7;
    }
    
    int max = 0;
    for (int i = 0; i < 7; i++){
        int start = 0, end = 0;
        for (int j = 0; j < n + 1; j++){
            if (r[j] == i){
                start = j;
                break;
            }
        }
        for (int j = n; j >= 0; j--){
            if (r[j] == i){
                end = j;
                break;
            }
        }
        if (end - start > max){
            max = end - start;
        }
    }
    fout << max << endl;
    return 0;
}
