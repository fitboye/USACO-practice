//
//  main.cpp
//  91
//
//  Created by Jerry Cheng on 2/20/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int b[100000], c[100000], minimum = a[0], maximum = a[n - 1];
    b[0] = 0;
    for (int i = 1; i < n; i++){
        minimum = min(minimum, a[i]);
        b[i] = max(b[i - 1], a[i] - minimum);
    }
    c[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--){
        maximum = max(maximum, a[i]);
        c[i] = max(c[i + 1], maximum - a[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, b[i] + c[i]);
    }
    cout << ans << endl;
    return 0;
}
