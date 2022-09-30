//
//  main.cpp
//  lazy cow
//
//  Created by Jerry Cheng on 3/23/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct grass{
    int g, x;
};

bool c(grass a, grass b){
    return a.x < b.x;
}

int main() {
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");
    int n, k;
    grass a[100000];
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        fin >> a[i].g >> a[i].x;
    }
    sort(a, a + n, c);
    
    int current = 0, right = 0;
    int i = 0;
    while ((i < n) && (a[i].x <= a[0].x + k * 2)){
        current = current + a[i].g;
        i++;
        right = i;
    }
    
    int max = current, j = right;
    for (int i = 0; i < n; i++){
        current = current - a[i].g;
        cout << a[j].x << ' ' << a[i + 1].x << endl;
        while ((a[j].x <= a[i + 1].x + 2 * k) && (j < n)){
            cout << 'a' << endl;
            current = current + a[j].g;
            j++;
        }
        cout << current << endl;
        if (current > max){
            max = current;
        }
    }
    
    fout << max << endl;
    return 0;
}

/*
 4 3
 4 7
 10 13
 2 2
 5 3
*/
