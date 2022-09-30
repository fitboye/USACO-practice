//
//  main.cpp
//  90
//
//  Created by Jerry Cheng on 2/6/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[4][100000];
    for (int i = 0; i < n; i++){
        cin >> a[0][i] >> a[1][i];
        a[2][i] = a[0][i] - a[1][i];
        a[3][i] = a[1][i] + a[0][i];
    }
    
    int ans = 0;
    map<int, int> b, c;
    map<pair<int, int>, int> d;
    for (int i = 0; i < n; i++){
        pair<int, int> p = {a[0][i], a[1][i]};
        ans = ans + b[a[2][i]] + c[a[3][i]] - d[p];
        b[a[2][i]]++;
        c[a[3][i]]++;
        d[p]++;
    }
    
    cout << ans << endl;
    return 0;
}
/*
4
1 2
1 2
0 2
2 0
*/
