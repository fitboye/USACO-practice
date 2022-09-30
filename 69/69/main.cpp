//
//  main.cpp
//  69
//
//  Created by Jerry Cheng on 10/24/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int n, k, a[10000];
void find(int l, int r){
    cout << l << ' ' << r << endl;
    cout << 'a';
    for (int i = l; i < r; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    if (r - l <= 1){
        cout << a[l] << endl;
        return;
    }
    
    int splitpoint = a[l];
    int j = r - 1;
    int i = l;
    for (i = l + 1; i < r; i++){
        if (a[i] > splitpoint){
            while (j > i && a[j] > splitpoint){
                j--;
            }
            if (i >= j){
                break;
            }
            int x = a[i];
            a[i] = a[j];
            a[j] = x;
        }
        cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << endl;
        cout << 'a';
        for (int i = l; i < r; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        if (i >= j){
            break;
        }
    }
    int x = a[i];
    a[i] = a[l];
    a[l] = x;
    if (k < i){
        find(l, i);
    }else if (k == i){
        cout << a[l] << endl;
    }else{
        find(i + 1, r);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    k = k - 1;
    find(0, n);
    
    return 0;
}
/*
 6 3
 4 3 5 6 1 2
 */
