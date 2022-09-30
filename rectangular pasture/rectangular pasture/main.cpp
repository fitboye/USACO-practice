//
//  main.cpp
//  rectangular pasture
//
//  Created by Jerry Cheng on 12/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct point{
    int x, y, pos;
};

bool c1 (point a, point b){
    return a.x < b.x;
}
bool c2 (point a, point b){
    return a.y < b.y;
}

int c[2501][2501], d[2501][2501];
int main() {
    int n;
    long long ans = 0;
    cin >> n;
    point a[2500], b[2500];
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, c1);
    for (int i = 0; i < n; i++){
        a[i].pos = i;
        b[i].x = i + 1;
    }
    sort(a, a + n, c2);
    for (int i = 0; i < n; i++){
        b[a[i].pos].y = i + 1;
    }
    sort(b, b + n, c1);
    
    
    for (int i = 0; i < 2500; i++){
        for (int j = 0; j < 2500; j++){
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        c[b[i].y][b[i].x] = 1;
    }
    /*
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
     */
    for (int i = 0; i < 2501; i++){
        for (int j = 1; j < 2501; j++){
            d[i][j] = d[i][j - 1] + c[i][j];
        }
    }
    for (int i = 0; i < 2501; i++){
        for (int j = 1; j < 2501; j++){
            d[j][i] = d[j][i] + d[j - 1][i];
        }
    }
    /*
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    */
    
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int left, right, top, bottom;
            left = b[i].x - 1;
            right = b[j].x;
            top = min(b[i].y, b[j].y);
            bottom = max(b[i].y, b[j].y) - 1;
            //cout << d[top][right] - d[top][left-1] << endl;
            //cout << d[2500][right] << ' ' << d[bottom][right] << ' ' << d[2500][left] << ' ' <<  d[bottom-1][left] << endl;
            ans = ans + (d[top][right] - d[top][left]) * (d[2500][right] - d[bottom][right] - d[2500][left] + d[bottom][left]);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
/*
 int a[n];
 int new_length = unique(a, a + n) - a;
 int b = lower_bound(a, a + n, x) - a;
 upper_nound
*/
