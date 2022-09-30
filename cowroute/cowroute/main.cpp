//
//  main.cpp
//  cowroute
//
//  Created by Jerry Cheng on 4/13/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");
    int a, b, n;
    fin >> a >> b >> n;
    int c[500], cost, cities, d[10000], e[10000], min = 1000000;
    for (int i = 0; i < 10000; i++){
        d[i] = -1;
        e[i] = -1;
    }
    for (int i = 0; i < n; i++){
        fin >> cost >> cities;
        int ca = -1, cb = -1;
        for (int j = 0; j < cities; j++){
            fin >> c[j];
            if (c[j] == a){
                ca = j;
            }else if (c[j] == b){
                cb = j;
            }
        }

        if ((ca != -1) && (cb != -1)){
            if (ca < cb){
                if (cost < min){
                    min = cost;
                }
            }
        }
        if (ca != -1){
            for (int j = ca + 1; j < cities; j++){
                if (d[c[j] - 1] == -1){
                    d[c[j] - 1] = cost;
                }else{
                    if (d[c[j] - 1] > cost){
                        d[c[j] - 1] = cost;
                    }
                }
            }
        }
        if (cb != -1){
            for (int j = 0; j < cb; j++){
                if (e[c[j] - 1] == -1){
                    e[c[j] - 1] = cost;
                }else{
                    if (e[c[j] - 1] > cost){
                        e[c[j] - 1] = cost;
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++){
            cout << d[i] << ' ' << e[i] << endl;
        }
        cout << endl;
    }
    
    for (int i = 0; i < 10000; i++){
        if ((d[i] != -1) && (e[i] != -1)){
            if (d[i] + e[i] < min){
                min  = d[i] + e[i];
            }
        }
    }
    if (min == 1000000){
        fout << -1 << endl;
    }else{
        fout << min << endl;
    }
    return 0;
}

/*
 1 2 3
 3 3
 3 2 1
 4 4
 1 2 3 4
 8 5
 4 1 7 8 2
 
*/
