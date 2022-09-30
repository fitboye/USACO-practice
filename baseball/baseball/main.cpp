//
//  main.cpp
//  baseball
//
//  Created by Jerry Cheng on 4/3/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("baseball.in");
    ofstream fout("baseball.out");
    int n, a[1001];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    a[n] = 200000000;
    
    int total = 0;
    for (int i = 0; i < n; i++){
        int dist, l = i + 2, r = i + 2;
        for (int j = i + 1; j < n; j++){
            dist = a[j] - a[i];
            while (l < n && a[l] - a[j] < dist){
                l++;
            }
            while (r < n && a[r] - a[j] <= dist * 2){
                r++;
            }
            total = total + r - l;
            //cout << total << endl;
            //cout << a[i] << ' ' << a[j] << ' ' << a[l] << ' ' << a[r] << endl;
        }
    }
    fout << total << endl;
    return 0;
}
