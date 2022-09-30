//
//  main.cpp
//  96
//
//  Created by Jerry Cheng on 3/6/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[1000], dp[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
