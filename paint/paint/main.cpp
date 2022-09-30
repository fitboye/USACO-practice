//
//  main.cpp
//  paint
//
//  Created by Jerry Cheng on 2/16/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct point{
    int pos, a;
};

bool compare(point a, point b){
    return a.pos < b.pos;
}

int main() {
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int n, k, a[100000];
    fin >> n >> k;
    char b[100000];
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i];
    }
    
    int start = 0, end;
    point c[100000], d[100000];
    for (int i = 0; i < n; i++){
        if (b[i] == 'L'){
            end = start - a[i];
        }else{
            end = start + a[i];
        }
        if (start < end){
            c[i].pos = start;
            d[i].pos = end;
        }else{
            c[i].pos = end;
            d[i].pos = start;
        }
        c[i].a = 0;
        d[i].a = 1;
        start = end;
    }
    
    point e[200000];
    for (int i = 0; i < n; i++){
        e[i] = c[i];
    }
    for (int i = n; i < 2 * n; i++){
        e[i] = d[i - n];
    }
    sort(e, e + 2 * n, compare);
    
    int layers = 0, total = 0;
    for (int i = 0; i < 2 * n; i++){
        if (e[i].a == 0){
            layers++;
        }else{
            layers--;
        }
        if (layers >= k){
            total = total + (e[i + 1].pos - e[i].pos);
        }
    }
    fout << total << endl;
    return 0;
}
