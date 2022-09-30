//
//  main.cpp
//  wormsort
//
//  Created by Jerry Cheng on 11/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct wormhole{
    int destination, width;
};
int a[100001];
int b[100001];
vector<wormhole> w[100001];

void floodfill(int loc, int fill, int minwidth){
    if (b[loc] == 0){
        b[loc] = fill;
    }else{
        return;
    }
    
    for (int i = 0; i < w[loc].size(); i++){
        if (w[loc][i].width >= minwidth){
            floodfill(w[loc][i].destination, fill, minwidth);
        }
    }
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < m; i++){
        int x;
        wormhole y;
        fin >> x >> y.destination >> y.width;
        w[x].push_back(y);
        int swap;
        swap = x;
        x = y.destination;
        y.destination = swap;
        w[x].push_back(y);
    }
    
    int l = -1, r = 1000000001, mid;
    while (r - l > 1){
        mid = (l + r)/2;
        for (int i = 0; i <= n; i++){
            b[i] = 0;
        }
        
        int fillnum = 1;
        for (int i = 1; i <= n; i++){
            if (b[i] == 0){
                floodfill(i, fillnum, mid);
                fillnum++;
            }
        }
        
        bool works = true;
        for (int i = 1; i <= n; i++){
            //cout << mid << ' ' << b[i] << endl;
            if (b[i] != b[a[i]]){
                works = false;
                break;
            }
        }
        
        if (works){
            l = mid;
        }else{
            r = mid;
        }
    }
    if (l == 1000000000){
        fout << -1 << endl;
    }else{
        fout << l << endl;
    }
    return 0;
}
