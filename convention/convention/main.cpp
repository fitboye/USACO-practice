//
//  main.cpp
//  convention
//
//  Created by Jerry Cheng on 5/16/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("convention.in");
    ofstream fout("convention.out");
    int n, m, c, a[100000];
    fin >> n >> m >> c;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    
    int l = 0, r = 1000000000, mid;
    while (r - l > 1){
        mid = (l + r)/2;
        
        int first_on_bus = 0, buses = 1;
        for (int i = 1; i < n; i++){
            if (a[first_on_bus] + mid < a[i] || i - first_on_bus >= c){
                buses++;
                first_on_bus = i;
            }
        }
        //cout << mid  << ' ' << buses << endl;
        if (buses > m){
            l = mid;
        }else{
            r = mid;
        }
    }
    fout << r << endl;
    return 0;
}
