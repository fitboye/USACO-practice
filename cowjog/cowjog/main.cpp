//
//  main.cpp
//  cowjog
//
//  Created by Jerry Cheng on 5/25/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct cow{
    int startpos, speed;
};

bool compare (cow a, cow b){
    return a.startpos > b.startpos;
}

int main() {
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    int n;
    cow a[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i].startpos >> a[i].speed;
    }
    sort(a, a + n, compare);
    
    int slowest = a[0].speed, groups = 0;
    for (int i = 0; i < n; i++){
        if (a[i].speed <= slowest){
            groups++;
            slowest = a[i].speed;
        }
    }
    fout << groups << endl;
    return 0;
}
