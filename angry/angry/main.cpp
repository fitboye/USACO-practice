//
//  main.cpp
//  angry
//
//  Created by Jerry Cheng on 11/24/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int n, k, a[50000];
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    
    int l = 0, r = a[n - 1], mid = 0;
    while (r - l > 1){
        mid = (l + r)/2;
        int cowcount = 0;
        for (int i = 0; i < n; i++){
            int end = i;
            for (int j = 0; (a[j] <= a[i] + 2 * mid && j < n); j++){
                end = j;
            }
            i = end;
            cowcount++;
        }
        //cout << mid << ' ' << l << ' ' << r << ' ' << cowcount << endl;
        if (cowcount > k){
            l = mid;
        }else{
            r = mid;
        }
    }
    fout << r << endl;
    return 0;
}
