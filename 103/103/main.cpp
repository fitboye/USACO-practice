//
//  main.cpp
//  103
//
//  Created by Jerry Cheng on 4/3/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100001];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int dp[100001][2][2];
    for (int i = 0; i < 100001; i++){
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
        dp[i][1][0] = 0;
        dp[i][1][1] = 0;
    }
    if (a[1] % 2){
        dp[1][1][1] = 1;
    }else{
        dp[1][0][1] = 1;
    }
    for (int i = 2; i <= n; i++){
        dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
        dp[i][1][0] = dp[i - 1][1][0] + dp[i - 1][1][1];
        if (a[i] % 2){
            dp[i][0][1] = dp[i - 2][1][0] + dp[i - 2][1][1];
            dp[i][1][1] = dp[i - 2][0][0] + dp[i - 2][0][1];
        }else{
            dp[i][0][1] = dp[i - 2][0][0] + dp[i - 2][0][1];
            dp[i][1][1] = dp[i - 2][1][0] + dp[i - 2][1][1];
        }
    }
    for (int i = 0; i <= n; i++){
        cout << dp[i][1][0] << ' ';
    }
    cout << endl;
    
    cout << dp[n][1][0] + dp[n][1][1] << endl;
    return 0;
}
/*
 4
 1 2 2 2
 
*/
