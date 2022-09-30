//
//  main.cpp
//  12'
//
//  Created by Jerry Cheng on 7/28/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a[100], n, x = 0, k, l, r, y = 0, z = 0;
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] < k){
            x++;
        }
    }
    
    for (int i = 0; i < x - 1; i++){
        l = i + 1;
        r = x - 1;
        while (r - l > 0){
            if (a[i] + a[(r - l) / 2 + l] > k){
                r = (r - l) / 2 + l - 1;
            }else if (a[i] + a[(r - l) / 2 + l] < k){
                l = (r - l) / 2 + l + 1;
            }else{
                y = a[i];
                z = a[r];
                break;
            }
            cout << i << ' ' << l << ' ' << r << endl;
        }
    }
        
    cout << y << ' ' << z << endl;
    return 0;
}
