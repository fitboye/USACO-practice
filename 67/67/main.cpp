//
//  main.cpp
//  67
//
//  Created by Jerry Cheng on 10/17/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct location{
    int x;
    int y;
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    int a[100][100];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = -1;
        }
    }
    x--;
    y--;
    a[x][y] = 0;
    queue<location> b;
    location c;
    c.x = x;
    c.y = x;
    b.push(c);
    int xchange[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
    int ychange[8] = {1, 2, -1, -2, 1, 2, -1, -2};
    while(b.size() > 0){
        location current = b.front();
        for (int i = 0; i < 8; i++){
            location d = current;
            d.x = d.x + xchange[i];
            d.y = d.y + ychange[i];
            if (d.x >= 0 && d.x < n && d.y >= 0 && d.y < m && a[d.x][d.y] == -1){
                b.push(d);
                a[d.x][d.y] = a[current.x][current.y] + 1;
            }
        }
        b.pop();
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
