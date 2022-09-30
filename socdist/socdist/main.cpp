//
//  main.cpp
//  socdist
//
//  Created by Jerry Cheng on 3/29/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct interval{
    long long a, b;
};

bool compare(interval x, interval y){
    return x.a < y.b;
}

int main() {
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    int n, m;
    interval g[100000];
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        fin >> g[i].a >> g[i].b;
    }
    sort(g, g + m, compare);
    
    long long l = 0, r = 1000000000000000000, mid;
    while (r - l > 1){
        mid = (l + r)/2;
        
        int currentinterval = 0;
        long long currentloc = g[0].a;
        //cout << 'm' << mid << endl;
        int i = 1;
        while (i < n){
            //cout << currentloc << endl;
            while (currentloc + mid > g[currentinterval].b){
                currentinterval++;
                if (currentinterval == m){
                    break;
                }
            }
            if (currentloc + mid > g[m - 1].b){
                break;
            }
            if (currentloc + mid < g[currentinterval].a){
                currentloc = g[currentinterval].a;
            }else{
                currentloc = currentloc + mid;
            }
            i++;
        }
        if (i >= n){
            //can fit cows in
            l = mid;
        }else{
            //cannot fit cows in
            r = mid;
        }
        //cout << l << ' ' << r << endl;
    }
    fout << l << endl;
    return 0;
}
