//
//  main.cpp
//  cowqueue
//
//  Created by Jerry Cheng on 9/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct cow{
    int arrive, t;
};

bool compare (cow a, cow b){
    return a.arrive < b.arrive;
}
int main() {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int n;
    fin >> n;
    cow a[100];
    for (int i = 0; i < n; i++){
        fin >> a[i].arrive >> a[i].t;
    }
    sort(a, a + n, compare);
    
    int b[100];
    b[0] = a[0].arrive + a[0].t;
    for (int i = 1; i < n; i++){
        if (b[i - 1] > a[i].arrive){
            b[i] = b[i - 1] + a[i].t;
        }else{
            b[i] = a[i].arrive + a[i].t;
        }
    }
    fout << b[n - 1] << endl;
    return 0;
}
