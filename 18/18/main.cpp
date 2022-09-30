//
//  main.cpp
//  18
//
//  Created by Jerry Cheng on 8/17/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, k, a[10000], b[10000];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a, a + n);
    sort (b, b + m);
    
    int j0 = 0, j1 = 0, x = 0;
    for (int i = 0; i < n; i++){
        while ((j0 < m) && (b[j0] < a[i] - k)){
            j0++;
        }
        while ((j1 < m) && (b[j1] <= a[i] + k)){
            j1++;
        }
        x = x + j1 - j0;
    }
    cout << x << endl;
    return 0;
}
