//
//  main.cpp
//  59
//
//  Created by Jerry Cheng on 6/27/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

char c[2002][2002];
long long total;
void fill(int a, int b, char last){
    if (c[a][b] == '0'){
        return;
    }
    if (c[a][b] == last){
        return;
    }
    total++;
    char ch = c[a][b];
    c[a][b] = '0';
    
    fill(a + 1, b, ch);
    fill(a - 1, b, ch);
    fill(a, b + 1, ch);
    fill(a, b - 1, ch);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++){
        c[i][0] = '0';
        c[i][m + 1] = '0';
    }
    for (int i = 0; i <= m + 1; i++){
        c[0][i] = '0';
        c[n + 1][i] = '0';
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (c[i][j] != '0'){
                total = 0;
                fill(i, j, 'a');
                ans = ans + (total - 1) * total / 2;
                
                for (int k = 0; k <= n + 1; k++){
                    for (int l = 0; l <= m + 1; l++){
                        cout << c[k][l];
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
 3 3
 #.#
 .#.
 ###
 */
