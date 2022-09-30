//
//  main.cpp
//  just green enough
//
//  Created by Jerry Cheng on 2/28/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, a[501][501], b[501][501], c[501][501];
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] >= 100){
                b[i][j] = 1;
            }else{
                b[i][j] = 0;
            }
            if (a[i][j] == 100){
                c[i][j] = 1;
            }else{
                c[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++){
        b[0][i] = 0;
        b[i][0] = 0;
        c[0][i] = 0;
        c[i][0] = 0;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            b[i][j] = b[i][j - 1] + b[i][j];
            c[i][j] = c[i][j - 1] + c[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            b[i][j] = b[i - 1][j] + b[i][j];
            c[i][j] = c[i - 1][j] + c[i][j];
        }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
