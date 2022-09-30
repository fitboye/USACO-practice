//
//  main.cpp
//  39
//
//  Created by Jerry Cheng on 12/21/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int ans = 0, n, m;
char a[7][7];
void maze(int b, int c){
    if ((b == n) && (c == m)){
        ans++;
        cout << 'a' << endl;
        return;
    }else if (((a[b + 1][c] != '.') && (a[b - 1][c] != '.')) && ((a[b][c + 1] != '.') && (a[b][c - 1] != '.'))){
        /*
        cout << b << ' ' << c << endl;
        for (int i = 0; i <= n + 1; i++){
            for (int j = 0; j <= n + 1; j++){
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
         */
        return;
    }
    
    if (a[b + 1][c] == '.'){
        a[b + 1][c] = '#';
        maze(b + 1, c);
        a[b + 1][c] = '.';
    }
    if (a[b - 1][c] == '.'){
        a[b - 1][c] = '#';
        maze(b - 1, c);
        a[b - 1][c] = '.';
    }
    if (a[b][c + 1] == '.'){
        a[b][c + 1] = '#';
        maze(b, c + 1);
        a[b][c + 1] = '.';
    }
    if (a[b][c - 1] == '.'){
        a[b][c - 1] = '#';
        maze(b, c - 1);
        a[b][c - 1] = '.';
    }

}

/*
 4 4
 ..#.
 #...
 ....
 .#..
*/

int main() {
    cin >> n >> m;
    for (int i = 0; i <= m; i++){
        a[0][i] = '#';
        a[n + 1][i] = '#';
    }
    for (int i = 0; i <= n; i++){
        a[i][0] = '#';
        a[i][m + 1] = '#';
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    a[1][1] = '#';
    
    maze(1, 1);
    cout << ans << endl;
    return 0;
}
