//
//  main.cpp
//  58
//
//  Created by Jerry Cheng on 6/20/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct x{
    int a, b;
};

bool compare(x a, x b){
    if (a.a == b.a){
        return a.b > b.b;
    }else{
        return a.a < b.a;
    }
}
int n, ans;
x a[10000];
void merge(int l, int r){
    if (l == r){
        return;
    }
    
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    cout << l << ' ' << mid << ' ' << r << endl;
    int j = mid + 1;
    for (int i = l; i <= mid; i++){
        while (j <= r && a[i].b >= a[j].b){
            j++;
        }
        cout << i << ' ' << j << endl;
        ans = ans + r + 1 - j;
    }
    
    x temp[r - l + 1];
    int m = mid + 1;
    j = l;
    for (int i = 0; i < r - l + 1; i++){
        if (j > mid){
            temp[i] = a[m];
            m++;
        }else if (m > r){
            temp[i] = a[j];
            j++;
        }else{
            if (a[j].b < a[m].b){
                temp[i] = a[j];
                j++;
            }else{
                temp[i] = a[m];
                m++;
            }
        }
    }
    
    for (int i = l; i <= r; i++){
        a[i] = temp[i - l];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].a >> a[i].b;
    }
    sort(a, a + n, compare);
    
    
    merge(0, n - 1);
    cout << ans << endl;
    return 0;
}
/*
 4
 1 2
 3 4
 3 6
 5 6
 
 6
 1 2
 2 5
 3 4
 5 6
 7 8
 10 11
 
 5
 1 2
 3 4
 3 4
 3 6
 5 6
*/
