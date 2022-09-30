//
//  main.cpp
//  reststops
//
//  Created by Jerry Cheng on 1/27/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct stop{
    int loc, taste;
};

bool c (stop a, stop b){
    return a.loc < b.loc;
}

int main() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    int l, n, f, b;
    fin >> l >> n >> f >> b;
    stop x[100000];
    for (int i = 0; i < n; i++){
        fin >> x[i].loc >> x[i].taste;
    }
    sort(x, x + n, c);
    int y[100000], largest = n - 1;
    y[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--){
        if (x[i].taste > x[largest].taste){
            largest = i;
        }
        y[i] = largest;
    }
    
    int i = y[0], lasti = 0;
    long long total = 0;
    long long bt = 1ll * x[i].loc * b;
    long long ft = 1ll * x[i].loc * f;
    total = total + 1ll * (ft - bt) * x[i].taste;
    cout << bt << ' ' << ft << ' ' << x[i].taste << endl;
    while (i < n - 1){
        lasti = i;
        i = y[i + 1];
        bt = 1ll * (x[i].loc - x[lasti].loc) * b;
        ft = 1ll * (x[i].loc - x[lasti].loc) * f;
        total = total + 1ll * (ft - bt) * x[i].taste;
        //cout << bt << ' ' << ft << ' ' << x[i].taste << endl;
    }
    
    fout << total << endl;
    return 0;
}



/*
 10 5 6 4
 3 2
 5 2
 7 2
 8 3
 9 1
*/
