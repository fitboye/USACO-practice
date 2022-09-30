//
//  main.cpp
//  whatbase
//
//  Created by Jerry Cheng on 6/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int kto10(string a, int base){
    int x = 0;
    x = x + int(a[2] - 48);
    x = x + int(a[1] - 48) * base;
    x = x + int(a[0] - 48) * base * base;
    return x;
}

int main() {
    ifstream fin("whatbase.in");
    ofstream fout("whatbase.out");
    int k, x, y, n;
    string a, b;
    fin >> k;
    for (int i = 0; i < k; i++){
        int alla[15001], allb[15001];
        fin >> a >> b;
        for (int j = 10; j <= 15000; j++){
            alla[j] = kto10(a, j);
            allb[j] = kto10(b, j);
        }
        int l = 10, m = 10;
        while ((alla[l] != allb[m]) && ((l < 15000) && (m < 15000))){
            if (alla[l] < allb[m]){
                l++;
            }else{
                m++;
            }
        }
        if (alla[l] == allb[m]){
            fout << l << ' ' << m << endl;
        }
    }
    
    return 0;
}
