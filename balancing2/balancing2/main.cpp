//
//  main.cpp
//  balancing2
//
//  Created by Jerry Cheng on 5/2/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct cow{
    int x, y;
};

bool comparex (cow a, cow b){
    return a.x < b.x;
}

bool comparey (cow a, cow b){
    return a.y > b.y;
}

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n;
    cow a[1000], b[1000], c[1000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i].x >> a[i].y;
        b[i] = a[i];
        c[i] = a[i];
    }
    sort(b, b + n, comparex);
    sort(c, c + n, comparey);
    
    int ans = 10000;
    for (int i = 0; i < n;){
        int d[4], xfence = c[i].y - 1;
        while (c[i].y > xfence && i < n){
            i++;
        }
        d[0] = 0;
        d[1] = i;
        d[2] = 0;
        d[3] = n - d[1];
        for (int j = 0; j < n;){
            int yfence = b[j].x + 1, lu = 0, ld = 0;
            while (b[j].x < yfence && j < n){
                if (b[j].y > xfence){
                    lu++;
                }else{
                    ld++;
                }
                j++;
            }
            d[0] = d[0] + lu;
            d[1] = d[1] - lu;
            d[2] = d[2] + ld;
            d[3] = d[3] - ld;
            //cout << d[0] << ' ' << d[1] << ' ' << d[2] << ' ' << d[3] << endl;
            int max = 0;
            for (int k = 0; k < 4; k++){
                if (d[k] > max){
                    max = d[k];
                }
            }
            //cout << max << endl;
            if (max < ans){
                ans = max;
            }
        }
    }
    fout << ans << endl;
    return 0;
}
