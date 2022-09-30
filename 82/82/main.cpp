//
//  main.cpp
//  82
//
//  Created by Jerry Cheng on 12/19/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct query{
    int k, og, ans;
};

vector<int> a[100000];
vector<query> k[100000];
int path[100000], pathloc = 1;
void dfs(int parent, int current){
    for (int i = 0; i < k[current].size(); i++){
        if (pathloc - k[current][i].k - 1 >= 0){
            k[current][i].ans = path[pathloc - k[current][i].k - 1];
        }else{
            k[current][i].ans = -1;
        }
    }
    
    for (int i = 0; i < a[current].size(); i++){
        if (a[current][i] != parent){
            path[pathloc] = a[current][i];
            pathloc++;
            dfs(current, a[current][i]);
            pathloc--;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    for (int i = 0; i < q; i++){
        int x;
        query y;
        cin >> x >> y.k;
        y.og = i;
        k[x].push_back(y);
    }
    
    path[0] = 1;
    dfs(-1, 1);
    int ans[100000];
    for (int i = 0; i < 100000; i++){
        for (int j = 0; j < k[i].size(); j++){
            ans[k[i][j].og] = k[i][j].ans;
        }
    }
    
    for (int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
/*
 8 7
 1 2
 1 8
 2 6
 2 5
 5 4
 4 3
 8 7
 
 2 3
 3 3
 7 1
 3 1
 6 1
 6 2
 4 2
*/
