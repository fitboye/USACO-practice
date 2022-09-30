//
//  main.cpp
//  reduce
//
//  Created by Jerry Cheng on 9/7/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    int n, x[50000], y[50000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> x[i] >> y[i];
    }
    
    int sx = 100000, lx = 0, sy = 100000, ly = 0;
    int a[4];
    for (int i = 0; i < n; i++){
        if (x[i] < sx){
            sx = x[i];
            a[0] = i;
        }
        if(x[i] > lx){
            lx = x[i];
            a[1] = i;
        }
        if(y[i] < sy){
            sy = y[i];
            a[2] = i;
        }
        if(y[i] > ly){
            ly = y[i];
            a[3] = i;
        }
    }
    
    
    int largest = 0, smallest = 100000, tempx, tempy;
    long long area = 10000000000000;
    for (int i = 0; i < 4; i++){
        cout << a[i] << endl;
        tempx = x[a[i]];
        tempy = y[a[i]];
        x[a[i]] = -1;
        y[a[i]] = -1;
        largest = 0;
        smallest = 100000;
        for (int j = 0; j < n; j++){
            if ((x[j] < smallest) && (x[j] != -1)){
                smallest = x[j];
            }
            if ((x[j] > largest) && (x[j] != -1)){
                largest = x[j];
            }
        }
        int xdif = largest - smallest;
        
        largest = 0;
        smallest = 100000;
        for (int j = 0; j < n; j++){
            if ((y[j] < smallest)  && (y[j] != -1)){
                smallest = y[j];
            }
            if ((y[j] > largest)  && (y[j] != -1)){
                largest = y[j];
            }
        }
        int ydif = largest - smallest;
        if (xdif * ydif < area){
            area = xdif * ydif;
        }
        x[a[i]] = tempx;
        y[a[i]] = tempy;
    }
    fout << area << endl;
    return 0;
}




