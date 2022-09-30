//
//  main.cpp
//  diamond2
//
//  Created by Jerry Cheng on 7/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n, k;
    int a[50000];
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    int amts[50000], j = 0;
    for (int i = 0; i < n; i++){
        //cout << a[i] << endl;
        while (j < n && a[j] <= a[i] + k){
            j++;
        }
        amts[i] = j - i;
    }
    int maxamts[50001], largest = 0;
    for (int i = n - 1; i >= 0; i--){
        if (largest < amts[i]){
            largest = amts[i];
        }
        maxamts[i] = largest;
    }
    maxamts[n] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        //cout << i << ' ' << a[i] << ' ' << maxamts[i] << endl;
        if (ans < amts[i] + maxamts[i + amts[i]]){
            //cout << i << ' ' << amts[i] << ' ' << maxamts[i + amts[i] - 1] << endl;
            ans = amts[i] + maxamts[i + amts[i]];
            //cout << ans << endl;
        }
    }
    
    
    fout << ans << endl;
    return 0;
}
