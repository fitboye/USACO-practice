//
//  main.cpp
//  97
//
//  Created by Jerry Cheng on 3/13/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int a[2000][2000];
int b[2000][2000];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < 2000; i++){
        for (int j = 0; j < 2000; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }
    
    b[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!a[i][j]){
                if (j != 0){
                    b[i][j] = (b[i][j] + b[i][j - 1]) % 1000000007;
                }
                if (i != 0){
                    b[i][j] = (b[i][j] + b[i - 1][j]) % 1000000007;
                }
            }else{
                b[i][j] = 0;
            }
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << b[n - 1][m - 1] << endl;
    return 0;
}
