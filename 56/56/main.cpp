//
//  main.cpp
//  56
//
//  Created by Jerry Cheng on 6/6/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, k, a[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 0;
    
    int j = 0, sum = a[0], ans = 0;
    for (int i = 0; i < n; i++){
        if (j < i){
            j = i;
            sum = a[i];
        }
        while (j < n && sum <= k){
            j++;
            sum = sum + a[j];
        }
        cout << i << ' ' << j << endl;
        ans = ans + j - i;
        sum = sum - a[i];
    }
    
    cout << ans << endl;
    return 0;
}
