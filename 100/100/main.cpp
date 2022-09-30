//
//  main.cpp
//  100
//
//  Created by Jerry Cheng on 3/20/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int a[301][90001];
int main() {
    int n, coins[301];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    
    a[0][0] = 1;
    for (int i = 1; i <= 90000; i++){
        a[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 90000; j++){
            if (a[i - 1][j]){
                a[i][j] = 1;
                if (j <= 90000 - coins[i]){
                    a[i][j + coins[i]] = 1;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= 90000; i++){
        ans += a[n][i];
        //cout << a[n][i] << endl;
    }
    cout << ans << endl;
    return 0;
}
