//
//  main.cpp
//  99
//
//  Created by Jerry Cheng on 3/20/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int a[3001][3001];
int main() {
    int n, m;
    cin >> n >> m;
    int w[3001], v[3001];
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    
    a[0][0] = 0;
    for (int i = 1; i <= m; i++){
        a[0][i] = -1;
    }
    for (int j = 0; j <= m; j++){
        cout << a[0][j] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < w[i]; j++){
            a[i][j] = a[i - 1][j];
        }
        for (int j = w[i]; j <= m; j++){
            a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + v[i]);
        }
        
        
        for (int j = 0; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << a[n][m] << endl;
    return 0;
}
