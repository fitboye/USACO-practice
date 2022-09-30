//
//  main.cpp
//  102
//
//  Created by Jerry Cheng on 3/27/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
long long dp1[301][90001], dp2[301][90001];
int main() {
    long long n, m, sum = 0;
    cin >> n >> m;
    long long items[2][301];
    for (int i = 1; i <= n; i++){
        cin >> items[0][i] >> items[1][i];
        sum += items[1][i];
    }
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 90001; j++){
            dp1[i][j] = -1;
            dp2[i][j] = -1;
        }
    }
    dp1[0][0] = 0;
    dp2[0][0] = 0;
    
    long long a = 300000000000;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 90001; j++){
            long long x, y;
            if (j - items[1][i] >= 0 && dp1[i - 1][j - items[1][i]] != -1){
                x = dp1[i - 1][j - items[1][i]] + items[0][i];
            }else{
                x = a;
                //cout << x << endl;
            }
            if (dp1[i - 1][j] != -1){
                y = dp1[i - 1][j];
            }else{
                y = a;
            }
            if (x != a || y != a){
                //cout << x << ' ' << y << endl;
                dp1[i][j] = min(x, y);
            }
        }
        for (int j = 0; j < 90001; j++){
            long long x, y, z;
            if (j - items[1][i] >= 0 && dp1[i - 1][j - items[1][i]] != -1){
                x = dp1[i - 1][j - items[1][i]] + items[0][i]/2;
            }else{
                x = a;
            }
            if (dp2[i - 1][j] != -1){
                y = dp2[i - 1][j];
            }else{
                y = a;
            }
            if (j - items[1][i] >= 0 && dp2[i - 1][j - items[1][i]] != -1){
                z = dp2[i - 1][j - items[1][i]] + items[0][i];
            }else{
                z = a;
            }
            if (x != a || y != a){
                dp2[i][j] = min(min(x, y), z);
            }
        }
    }
    for (int i = 0; i <= sum; i++){
        cout << dp2[2][i] << ' ';
    }
    cout << endl;
    
    int ans = 0;
    for (int i = 0; i <= sum; i++){
        if (dp2[n][i] <= m && dp2[n][i] != -1){
            ans = max(ans, i);
        }
    }
    cout << m << endl;
    cout << ans << endl;
    return 0;
}
/*
 4 6
 6 3
 2 1
 2 1
 2 1
 
 */

