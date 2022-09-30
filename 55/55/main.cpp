//
//  main.cpp
//  55
//
//  Created by Jerry Cheng on 5/30/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k, a[100000];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    
    long long l = 0, r = 1000000000000000000, mid;
    while (r - l > 1){
        mid = (l + r)/2;
        long long larger = 0;
        for (int i = 0; i < n; i++){
            int l1 = -1, r1 = n, m;
            while (r1 - l1 > 1){
                m = (l1 + r1)/2;
                //cout << m << endl;
                if (a[i] * a[m] < mid){
                    l1 = m;
                }else{
                    r1 = m;
                }
            }
            cout << i << ' ' << r1 << endl;
            larger = larger + n - r1;
            if (i >= r1){
                larger--;
            }
        }
        cout << mid << ' ' << larger << endl;
        larger = larger / 2;
        
        if (larger < k){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}
