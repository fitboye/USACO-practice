//
//  main.cpp
//  57
//
//  Created by Jerry Cheng on 6/6/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int n, k;
long long a[10000], total;
void mergesort (int l, int r){
    if (l == r){
        return;
    }
    
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    
    int j = mid + 1;
    for (int i = l; i <= mid; i++){
        while (j <= r && a[j] <= a[i] + k){
            j++;
        }
        total = total + j - mid - 1;
    }
    
    long long temp[r - l + 1], m = mid + 1;
    j = l;
    for (int i = 0; i < r - l + 1; i++){
        if (j > mid){
            temp[i] = a[m];
            m++;
        }else if (m > r){
            temp[i] = a[j];
            j++;
        }else{
            if (a[j] < a[m]){
                temp[i] = a[j];
                j++;
            }else{
                temp[i] = a[m];
                m++;
            }
        }
        //cout << j << ' ' << m << endl;
        cout << temp[i] << ' ';
    }
    cout << endl;
    
    for (int i = l; i <= r; i++){
        a[i] = temp[i - l];
    }
}

int main() {
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
        cout << a[i] << endl;
    }
    
    mergesort(0, n);
    for (int i = 0; i <= n; i++){
        cout << a[i] << endl;
    }
    cout << total << endl;
    return 0;
}
