//
//  main.cpp
//  52
//
//  Created by Jerry Cheng on 5/2/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int a[1000];
void mergesort (int l, int r){
    if (l == r){
        return;
    }
    
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    
    int temp[r - l + 1], j = l, k = mid + 1;
    for (int i = 0; i < r - l + 1; i++){
        if (j <= mid && k <= r && a[j] < a[k]){
            temp[i] = a[j];
            j++;
        }else if (j <= mid && k <= r && a[j] > a[k]){
            temp[i] = a[k];
            k++;
        }else{
            if (k <= r){
                temp[i] = a[k];
                k++;
            }else{
                temp[i] = a[j];
                j++;
            }
        }
    }
    
    for (int i = l; i <= r; i++){
        a[i] = temp[i - l];
    }
}
/*
 5
 7 6 5 8 9
*/
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
