//
//  main.cpp
//  94
//
//  Created by Jerry Cheng on 2/27/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int  flag[100001];
vector<int> b[100001];
vector<int> a[100001];
set<int> c;
void search(int loc, int start){
    if (flag[loc] != 0){
        return;
    }
    flag[loc] = start;
    for (int i = 0; i < a[loc].size(); i++){
        //cout << loc << endl;
        c.insert(a[loc][i]);
    }
    
    for (int i = 0; i < b[loc].size(); i++){
        search(b[loc][i], start);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    
    for (int i = 0; i <= n; i++){
        flag[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        if (flag[i] == 0){
            c.clear();
            search(i, i);
            cout << i << ' ' << c.size() << endl;
            for (int x: c){
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
/*
 4 2
 3 1 2 3
 2 3 4
 3 1 4 5
 1 6
 1 2
 4 2
*/
