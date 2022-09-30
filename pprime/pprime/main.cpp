/*
 ID: jerry.c1
 TASK: pprime
 LANG: C++
 */
//  main.cpp
//  pprime
//
//  Created by Jerry Cheng on 12/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct num{
    int value;
    int digits;
};

bool prime(int x){
    bool p = true;
    for (int i = 2; i*i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a, b, ans[100000], loc = 0;
    fin >> a >> b;
    for (int i = 1; i <= 9999; i++){
        int x = i, y = i/10, digits = 10;
        while (i / digits != 0){
            digits = digits * 10;
            x = x * 10 + y % 10;
            y = y / 10;
        }
        
        if (x >= a && x <= b && prime(x)){
            ans[loc] = x;
            loc++;
        }
        
        x = i;
        y = i;
        digits = 1;
        while (i / digits != 0){
            digits = digits * 10;
            x = x * 10 + y % 10;
            y = y / 10;
        }
        if (x >= a && x <= b && prime(x)){
            ans[loc] = x;
            loc++;
        }
    }
    
    sort(ans, ans + loc);
    for (int i = 0; i < loc; i++){
        fout << ans[i] << endl;
    }
    return 0;
}
//sort(a.begin(), a.end());
