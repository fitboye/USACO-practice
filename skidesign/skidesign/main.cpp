/*
 ID: jerry.c1
 TASK: skidesign
 LANG: C++
 */
//  main.cpp
//  skidesign
//
//  Created by Jerry Cheng on 4/27/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    int n, a[1000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    
    int min = 1000000, b, total;
    for (int i = 0; i < 84; i++){
        b = i + 17;
        total = 0;
        for (int j = 0; j < n; j++){
            if (a[j] < i){
                total = total + (i - a[j]) * (i - a[j]);
            }else if (a[j] > b){
                total = total + (a[j] - b) * (a[j] - b);
            }
        }
        if (total < min){
            min = total;
        }
    }
    fout << min << endl;
    return 0;
}
