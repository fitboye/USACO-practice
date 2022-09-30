//
//  main.cpp
//  moobuzz
//
//  Created by Jerry Cheng on 12/16/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    int n;
    fin >> n;
    
    long long l = 0, r = 10000000000000000, m;
    while (r - l >= 0){
        m = (l + r) / 2;
        //cout << l << ' ' << m << ' ' << r << endl;
        long long num = m - m/3 - m/5 + m/15;
        if (num < n){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    fout << l << endl;
    return 0;
}


/*
 915928 -305309 - 183185 + 61061
*/
