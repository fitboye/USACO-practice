//
//  main.cpp
//  63
//
//  Created by Jerry Cheng on 7/25/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct segment{
    int a, b;
};

bool compare (segment a, segment b){
    return a.a < b.a;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    segment a[100000];
    for (int i = 0; i < n; i++){
        cin >> a[i].a >> a[i].b;
    }
    sort(a, a + n, compare);
    
    int largest = 0, ans = 1;
    for (int i = 0;largest < r; i++){
        if (i == n){
            ans = -1;
            break;
        }
        if (a[i].a > l){
            if (largest <= l){
                ans = -1;
                break;
            }else{
                ans++;
                l = largest;
            }
        }
        
        if (a[i].a <= l && a[i].b > largest){
            largest = a[i].b;
        }
        cout << largest << ' ' << i <<  ' ' << l << endl;
    }
    
    cout << ans << endl;
    return 0;
}

/*
9 2 20
1 10
2 8
2 4
2 11
3 13
10 16
14 21
18 30
20 25
 
 7 1 20
 1 10
 2 8
 2 4
 2 11
 11 13
 12 16
 16 21
*/





