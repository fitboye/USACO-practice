//
//  main.cpp
//  pairup
//
//  Created by Jerry Cheng on 12/28/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct milk{
    int cows, time;
};

bool compare(milk x, milk y){
    return x.time < y.time;
}

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    int n;
    milk a[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i].cows >> a[i].time;
    }
    sort(a, a + n, compare);
    
    /*
    for (int i = 0; i < n; i++){
        cout << a[i].cows << a[i].time << endl;
    }
     */
    
    int i = 0, j = n - 1, max = 0, time;
    while (i <= j){
        //cout << i << ' ' << j << endl << a[i].cows << ' ' << a[j].cows << endl << endl;
        time = a[i].time + a[j].time;
        if (time > max){
            max = time;
        }
        if (a[i].cows == a[j].cows){
            i++;
            j--;
        }else if (a[i].cows < a[j].cows){
            a[j].cows = a[j].cows - a[i].cows;
            i++;
        }else{
            a[i].cows = a[i].cows - a[j].cows;
            j--;
        }
    }
    fout << max << endl;
    return 0;
}
