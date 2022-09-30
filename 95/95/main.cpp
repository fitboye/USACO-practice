//
//  main.cpp
//  95
//
//  Created by Jerry Cheng on 2/27/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct point{
    int x, p;
};

bool compare(point a, point b){
    return a.x < b.x;
}

int main() {
    int n, l, m, p;
    cin >> n >> l >> m >> p;
    point a[100002];
    a[0].x = -1;
    a[0].p = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].p;
    }
    a[n+1].x = l + 1;
    a[n+1].p = 0;
    sort(a, a + n + 2, compare);
    
    double left = 0, right = 1000000000, t;
    for (int i = 0; i < 60; i++){
        t = (left + right)/2;
        
        vector<pair<double, double>> b;
        for (int j = 0; j <= n; j++){
            long long x = a[j].x + a[j].p * t, y = a[j + 1].x - a[j + 1].p * t;
            if (x < y){
                b.push_back({x, y});
            }
        }
        
        double needed = 0, start = -1, end = -1;
        for (int i = 0; i < b.size(); i++){
            if (end < b[i].second){
                if (end < b[i].first){
                    start = b[i].first + (b[i].second - b[i].first-1)/(2*p*t) * 2*p*t;
                    needed += (b[i].second - b[i].first-1)/(2*p*t);
                }else{
                    needed += (b[i].second - end-1)/(2*p*t);
                    start = end + (b[i].second - end-1)/(2*p*t) * 2*p*t;
                }
                end = start + 2 * p * t;
                needed++;
            }
            cout << b[i].first << endl;
        }
        cout << t << ' ' << needed << endl;
        if (needed <= m){
            right = t;
        }else{
            left = t;
        }
    }
    cout << fixed << setprecision(6) << left << endl;
    return 0;
}

/*
1 10 1 1
1 1
*/
