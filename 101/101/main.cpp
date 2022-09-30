//
//  main.cpp
//  101
//
//  Created by Jerry Cheng on 3/27/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[101][51][5001];
int main() {
    int n, a[101], sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 5001; j++){
            dp[0][i][j] = 0;
        }
    }
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n/2; j++){
            for (int k = 0; k < 5001; k++){
                dp[i][j][k] = dp[i-1][j][k];
                if (j - 1 >= 0 && k - a[i] >= 0){
                    if (dp[i][j][k] == 0){
                        dp[i][j][k] = dp[i-1][j-1][k-a[i]];
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 20; i++){
        //cout << i << ' ' << dp[3][2][i] << endl;
    }
    
    int l, r;
    double ans = -1;
    if (sum % 2 == 0){
        if (dp[n][n/2][sum/2] == 1){
            ans = 0;
        }else{
            l = sum / 2 - 1;
            r = sum / 2 + 1;
        }
    }else{
        l = sum / 2;
        r = sum / 2 + 1;
    }
    
    while (ans == -1){
        if (dp[n][n/2][l] == 1){
            ans = double(sum)/2 - l;
        }
        if (dp[n][n/2][r] == 1){
            ans = r - double(sum)/2;
        }
        l--;
        r++;
    }
    
    cout << ans << endl;
    return 0;
}
