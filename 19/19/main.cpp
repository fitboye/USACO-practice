//
//  main.cpp
//  19
//
//  Created by Jerry Cheng on 8/17/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k, a[100000];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    
    int j0 = n - 1, j1 = n - 1, x = 0;
    for (int i = 0; i < n; i++){
        while ((j0 >= 0) && (a[j0] >= k - a[i])){
            j0--;
        }
        while ((j1 > 0) && (a[j1] > k - a[i])){
            j1--;
        }
        x = x + j1 - j0;
        cout << a[i] << ' ' << j0 << ' ' << j1 << endl;
    }
    cout << x << endl;
    return 0;
}
/*
 10 4
 1 1 1 2 2 2 3 3 3 3
 */
