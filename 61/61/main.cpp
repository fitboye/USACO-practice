//
//  main.cpp
//  61
//
//  Created by Jerry Cheng on 7/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> a[100001];
vector<int> all[100001];
int fil[100000], counter = 0;

void floodfill(int loc, int fillnum){
    counter++;
    fil[loc] = fillnum;
    
    for (int i = 0; i < a[loc].size(); i++){
        int next = a[loc][i];
        if (fil[next] == 0){
            floodfill(next, fillnum);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x[100000], y[100000], z[100000];
    for (int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> z[i];
        if (z[i] == 1){
            a[x[i]].push_back(y[i]);
            a[y[i]].push_back(x[i]);
        }
        all[x[i]].push_back(y[i]);
        all[y[i]].push_back(x[i]);
    }
    for (int i = 0; i <= n; i++){
        fil[i] = 0;
    }
    int fillnum = 1, ans = 0, fillcounter[100000];
    for (int i = 1; i <= n; i++){
        if (fil[i] == 0){
            floodfill(i, fillnum);
            fillcounter[fillnum] = counter;
            fillnum++;
            //cout << counter << endl;
            ans = ans + (counter * (counter - 1)) / 2;
        }
    }
    for (int i = 1; i <= n; i++){
        int minus = 0;
        for (int j = 0; j < all[i].size(); j++){
            if (fil[i] == fil[all[i][j]]){
                minus++;
            }
        }
        //minus = 0;
        cout << fillcounter[fil[i]] - minus - 1<< endl;
    }
    return 0;
}
/*
 5 4
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 
 4 4
 1 2 1
 1 3 1
 2 3 2
 2 4 1
*/
