//
//  main.cpp
//  helpcross
//
//  Created by Jerry Cheng on 9/12/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct cow{
    int start, end;
};

bool compare(cow a, cow b){
    return a.end < b.end;
}

int main() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    int n, c;
    fin >> c >> n;
    int chickens[20000];
    cow cows[20000];
    bool a[20000];
    for (int i = 0; i < c; i++){
        fin >> chickens[i];
    }
    for (int i = 0; i < n; i++){
        fin >> cows[i].start >> cows[i].end;
        a[i] = true;
    }
    sort(chickens, chickens + c);
    sort(cows, cows + n, compare);
    
    int ans = 0;
    for (int i = 0; i < c; i++){
        int l = -1, r = n - 1, m;
        while (r - l > 1){
            m = (l + r)/2;
            
            if (chickens[i] > cows[m].end){
                l = m;
            }else{
                r = m;
            }
            //cout << r << endl;
        }
        //cout << i << ' ' << r << endl;
        for (int j = r; j < n; j++){
            if (cows[j].start <= chickens[i] && a[j]){
                ans++;
                a[j] = false;
                break;
            }
        }
    }
    fout << ans << endl;
    return 0;
}
