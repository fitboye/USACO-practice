//
//  main.cpp
//  maxcross
//
//  Created by Jerry Cheng on 4/3/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    int n, b, k, a[100000];
    fin >> n >> k >> b;
    for (int i = 0; i < b; i++){
        fin >> a[i];
    }
    sort(a, a + b);
    
    for (int i = 0; i < b; i++){
        //cout << a[i] << endl;
    }
    
    int smallest = 100000;
    int current = 0, j = 0;
    while ((j < b) && (a[j] <= k)){
        j++;
    }
    current = j;
    if (current < smallest){
        smallest = current;
    }
    
    for (int i = 0; i < b; i++){
        if (a[i] + k > n){
            break;
        }
        while ((j < b) && (a[j] - a[i] <= k)){
            j++;
        }
        j--;
        cout << i << ' ' << j << endl;
        current = j - i;
        if (current < smallest){
            smallest = current;
        }
    }
    fout << smallest << endl;
    return 0;
}

/*
5 5 5
1
2
3
4
5
*/
