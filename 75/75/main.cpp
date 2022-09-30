//
//  main.cpp
//  75
//
//  Created by Jerry Cheng on 11/28/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[100001];
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int b[100000];
    for (int i = 0; i < n; i++){
        b[i] = a[i + 1] - a[i];
    }
    
    for (int i = 0; i < q; i++){
        int c, l, r, y;
        cin >> c;
        if (c == 1){
            cin >> l >> y;
            r = l;
        }else{
            cin >> l >> r >> y;
        }
        b[l - 1] = b[l - 1] + y;
        b[r] = b[r] - y;
    }
    
    int c[100000];
    c[0] = b[0];
    cout << c[0] << ' ';
    for (int i = 1; i < n; i++){
        c[i] = c[i - 1] + b[i];
        cout << c[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
