//
//  main.cpp
//  70
//
//  Created by Jerry Cheng on 11/14/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> a[100];
    int n, m;
    cin >> n >> m;
    int connectionsto[100];
    int distance[100];
    for (int i = 0; i < 100; i++){
        connectionsto[i] = 0;
        distance[i] = 0;
    }
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        connectionsto[y]++;
    }
    
    queue<int> b;
    int ans[100], anspos = 0;
    for (int i = 1; i <= m; i++){
        if (connectionsto[i] == 0){
            b.push(i);
            distance[i] = 0;
        }    }
    
    while (b.size() > 0){
        int x = b.front();
        b.pop();
        for (int i = 0; i < a[x].size(); i++){
            connectionsto[a[x][i]]--;
            if (connectionsto[a[x][i]] == 0){
                b.push(a[x][i]);
            }
            distance[a[x][i]] = max(distance[a[x][i]], distance[x] + 1);
        }
        ans[anspos] = x;
        anspos++;
    }
    
    if (anspos < m){
        cout << -1 << endl;
    }else{
        for (int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    int maxdistance = 0;
    for (int i = 1; i <= m; i++){
        maxdistance = max(distance[i], maxdistance);
    }
    cout << maxdistance << endl;
    return 0;
}
/*
 9 9
 1 2
 4 2
 2 3
 8 3
 2 5
 3 6
 6 9
 5 7
 6 7
 */
