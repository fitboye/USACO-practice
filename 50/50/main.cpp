//
//  main.cpp
//  50
//
//  Created by Jerry Cheng on 4/25/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
bool compare(int a, int b){
    return a > b;
}
using namespace std;
int main() {
    int n, a[100001];
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, compare);
    a[n] = 0;
    long long sum = 0;
    int x, y, b;
    if (a[0] - a[1] > k){
        x = 1;
        y = a[0];
        b = y - k;
        
    }else{
        for (int i = 0; i < n; i++){
            k = k - 1ll * (i + 1) * (a[i] - a[i + 1]);
            if (k < 0){
                k = k + 1ll * (i + 1) * (a[i] - a[i + 1]);
                break;
            }
            sum = sum + 1ll * (i + 1) * (a[i] - a[i + 1]) * (a[i] + a[i + 1] + 1) / 2;
            cout << sum << endl;
            x = i + 2;
            y = a[i + 1];
        }
        b = y - k/x;
    }
    cout << x << ' ' << y  << ' ' << b << ' ' << k << endl;
    if (k > x && y > 0){
        sum = sum + 1ll * x * (y - b) * (y + b + 1) / 2;
        k = k - 1ll * (y - b) * x;
    }
    if (k > 0 && y > 0){
        sum = sum + 1ll * k * b;
    }
    cout << sum << endl;
    return 0;
}

/*
 5 5
 5 6 7 8 100

*/
