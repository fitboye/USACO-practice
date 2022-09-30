//
//  main.cpp
//  photo
//
//  Created by Jerry Cheng on 6/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct pairs{
    int a, b;
};

bool compare(pairs x, pairs y){
    return x.b < y.b;
}


int main() {
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    int n, k;
    fin >> n >> k;
    pairs a[1000];
    for (int i = 0; i < k; i++){
        fin >> a[i].a >> a[i].b;
        if (a[i].a > a[i].b){
            int swap = a[i].a;
            a[i].a = a[i].b;
            a[i].b = swap;
        }
    }
    sort(a, a + k, compare);
    for (int i = 0; i < k; i++){
        cout << a[i].a << ' ' << a[i].b << endl;
    }
    
    int cuts = 0;
    for (int i = 0; i < k; i++){
        if (a[i].a != -1){
            for (int j = i; j < k; j++){
                if (a[j].a != -1){
                    if ((a[j].a < a[i].b) && (a[i].b < a[j].b)){
                        a[j].a = -1;
                        //cout << i << ' ' << j << endl;
                    }
                }
            }
            a[i].a = -1;
            cuts++;
        }
    }
    fout << cuts + 1 << endl;
    return 0;
}
/*
 
*/
