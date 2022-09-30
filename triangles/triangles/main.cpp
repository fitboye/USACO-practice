//
//  main.cpp
//  triangles
//
//  Created by Jerry Cheng on 2/23/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct loc{
    int x, y, original;
};

bool cx(loc a, loc b){
    if (a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cy(loc a, loc b){
    if (a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n, all[4][100000];
    loc byx[100001], byy[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> byx[i].x >> byx[i].y;
        all[0][i] = 0;
        all[1][i] = 0;
        all[2][i] = 0;
        all[3][i] = 0;
    }
    sort(byx, byx + n, cx);
    for (int i = 0; i < n; i++){
        byy[i] = byx[i];
        byy[i].original = i;
    }
    sort(byy, byy + n, cy);
    
    byx[n].x = 10000000;
    int last = 10000000, passed;
    for (int i = 0; i < n; i++){
        if (byx[i].x != last){
            passed = 0;
        }else{
            all[0][i] = all[0][i - 1] + all[0][i] + (byx[i].y - byx[i - 1].y) * passed;
        }
        last = byx[i].x;
        passed++;
    }
    last = 10000000;
    for (int i = n - 1; i >= 0; i--){
        if (byx[i].x != last){
            passed = 0;
        }else{
            all[1][i] = all[1][i + 1] + all[1][i] + (byx[i + 1].y - byx[i].y) * passed;
        }
        last = byx[i].x;
        passed++;
    }
    
    last = 10000000;
    for (int i = 0; i < n; i++){
        if (byy[i].y != last){
            passed = 0;
        }else{
            int location = byy[i].original;
            all[2][location] = all[2][byy[i - 1].original] + all[2][location] + (byy[i].x - byy[i - 1].x) * passed;
        }
        last = byy[i].y;
        passed++;
    }
    last = 10000000;
    for (int i = n - 1; i >= 0; i--){
        if (byy[i].y != last){
            passed = 0;
        }else{
            int location = byy[i].original;
            all[3][location] = all[3][byy[i + 1].original] + all[3][location] + (byy[i + 1].x - byy[i].x) * passed;
        }
        last = byy[i].y;
        passed++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++){
        //cout << all[0][i] << ' ' << all[1][i] <<  ' ' << all[2][i] << ' ' << all[3][i] << endl;
        //cout << ans << endl;
        ans = ans + 1ll * (all[0][i] + all[1][i]) * (all[2][i] + all[3][i]);
        ans = ans % 1000000007;
    }
    fout << ans << endl;
    return 0;
}













