//
//  main.cpp
//  46
//
//  Created by Jerry Cheng on 3/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, a[5000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    
    long long total = 0;
    for (int i = 0; i < n; i++){
        int j = i + 1;
        for (int k = j + 1; k < n; k++){
            while (a[i] + a[j] <= a[k] && j < k){
                j++;
            }
            //cout << i << ' ' << j << ' ' << k << endl;
            total = total + k - j;
        }
    }
    cout << total << endl;
    return 0;
}
