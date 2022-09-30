//
//  main.cpp
//  notlast
//
//  Created by Jerry Cheng on 3/31/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    int n, a[100], d[7], x = 0, smallest = 1000000, smallest1 = 1000000, flag, e = 0;
    string b[7] = {"Bessie", "Maggie", "Elsie", "Henrietta", "Gertie", "Daisy", "Annabelle"}, c[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> c[i] >> a[i];
    }
    for (int i = 0; i < 7; i = i + 1){
        d[i] = 0;
    }
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < 7; j = j + 1){
            if (b[j] == c[i]){
                d[j] = d[j] + a[i];
            }
        }
    }
    
    for (int i = 0; i < 7; i = i + 1){
        //cout << d[i] << endl;
    }
    for (int i = 0; i < 7; i = i + 1){
        if (d[i] < smallest){
            smallest = d[i];
        }
    }
    
    for (int i = 0; i < 7; i = i + 1){
        if ((d[i] < smallest1) && (d[i] > smallest)){
            smallest1 = d[i];
            e = i;
        }
    }
    
    //cout << smallest1 << ' ' << e << endl;
    flag = 0;
    for (int i = 0; i < 7; i = i + 1){
        if ((d[i] == smallest1) && (i != e)){
            flag = 1;
        }
    }
    
    if (smallest1 == 1000000){
        flag = 1;
    }
    
    if (flag == 1){
        fout << "Tie" << endl;
    }else{
        fout << b[e] << endl;
    }
    return 0;
}
