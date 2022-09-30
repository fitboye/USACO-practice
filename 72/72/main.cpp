//
//  main.cpp
//  72
//
//  Created by Jerry Cheng on 11/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[100], b[100], c[100], d[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        c[b[i]] = i;
    }
    
    d[n - 1] = c[a[n - 1]];
    for (int i = n - 2; i >= 0; i--){
        d[i] = min(d[i + 1], c[a[i]]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (c[a[i]] > d[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
