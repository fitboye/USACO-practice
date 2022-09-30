//
//  main.cpp
//  71
//
//  Created by Jerry Cheng on 11/14/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m, b[100], depth[100];
vector<int> a[100];

int search(int current, int d){
    depth[current] = d;
    
    for (int i = 0; i < a[current].size(); i++){
        if (depth[a[current][i]] == -1){
            b[current] = b[current] + search(a[current][i], d + 1);
        }
    }
    b[current]++;
    return b[current];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        depth[i] = -1;
    }
    
    b[1] = search(1, 0);
    
    for (int i = 1; i <= n; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << depth[i] << ' ';
    }
    cout << endl;
    return 0;
}
/*
 8 7
 1 4
 1 6
 4 8
 6 2
 6 7
 7 5
 7 3
 */
