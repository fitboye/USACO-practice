//
//  main.cpp
//  47
//
//  Created by Jerry Cheng on 3/28/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

char a[2002][2002];
int b[2002][2002];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++){
        a[i][0] = '#';
        a[i][m + 1] = '#';
    }
    for (int i = 0; i <= m + 1; i++){
        a[0][i] = '#';
        a[n + 1][i] = '#';
    }
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    
    int x = 0;
    for (int i = 1; i < n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            if (a[i][j] == '#'){
                x = -1;
            }
            b[i][j] = b[i][j] + x;
            x++;
        }
    }
    x = 0;
    for (int i = 1; i < n + 1; i++){
        for (int j = m + 1; j >= 0; j--){
            if (a[i][j] == '#'){
                x = -1;
            }
            b[i][j] = b[i][j] + x;
            x++;
        }
    }
    x = 0;
    for (int j = 1; j < m + 1; j++){
        for (int i = 0; i <= n + 1; i++){
            if (a[i][j] == '#'){
                x = -1;
            }
            b[i][j] = b[i][j] + x;
            x++;
        }
    }
    x = 0;
    for (int j = 1; j < m + 1; j++){
        for (int i = n + 1; i >= 0; i--){
            if (a[i][j] == '#'){
                x = -1;
            }
            b[i][j] = b[i][j] + x;
            x++;
        }
    }

    
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    int ans = 0;
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++){
            if (a[i][j] != '#'){
                if (b[i][j] > ans){
                    cout << i << ' ' << j << endl;
                    ans = b[i][j];
                }
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
/*
 4 6
 ..##..
 .#...#
 ....#.
 #....#
 */
