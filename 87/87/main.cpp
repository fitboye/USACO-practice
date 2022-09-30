//
//  main.cpp
//  87
//
//  Created by Jerry Cheng on 1/23/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<int, map<int, vector<int>>> paths;
set<int> d;
int ans;
int n, m;
void search (int colour, int loc, int last){
    if (loc == n){
        cout << colour << endl;
        ans++;
    }
    
    for (int i = 0; i < paths[colour][loc].size(); i++){
        if (d.count(paths[colour][loc][i]) == 0){
            d.insert(paths[colour][loc][i]);
            search(colour, paths[colour][loc][i], loc);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        paths[c][a].push_back(b);
    }
    
    for (auto x : paths){
        d.clear();
        search(x.first, 1, -1);
    }
    cout << ans << endl;
    return 0;
    
}
/*
 5 7
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 5 2
 1 3 3
 2 5 3
 */
