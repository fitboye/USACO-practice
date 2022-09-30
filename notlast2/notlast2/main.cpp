//
//  main.cpp
//  notlast2
//
//  Created by Jerry Cheng on 4/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    int n, a[100], d[7], x = 0, smallest = 1000000, smallest1 = 1000000;
    string b[7] = {"Bessie", "Maggie", "Elsie", "Henrietta", "Gertie", "Daisy", "Annabelle"}, c[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> c[i] >> a[i];
    }
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            if (b[j] == c[i]){
                d[j] = d[j] + a[i];
            }
        }
    }
    
    for (int i = 0; i < 7; i = i + 1){
        if (d[i] < smallest){
            smallest = d[i];
        }
    }
    
    for (int i = 0; i < 7; i = i + 1){
        if ((d[i] < smallest1) && (d[i] > smallest)){
            smallest1 = d[i];
            x = i;
        }
    }
    fout << b[x] << endl;
    return 0;
}

