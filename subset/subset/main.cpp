//
//  main.cpp
//  subset
//
//  Created by Jerry Cheng on 11/10/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int n, a[100], b[100];
void subset(int x, bool y){
    if (x == n - 1){
        if (y == true){
            b[x] = a[x];
        }else{
            b[x] = -1;
        }
        for (int i = 0; i < n; i++){
            if (b[i] >= 0){
                cout << b[i] << ' ';
            }
        }
        cout << endl;
        return;
    }
    if (y == true){
        b[x] = a[x];
    }else{
        b[x] = -1;
    }
    subset(x + 1, false);
    subset(x + 1, true);
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    subset(0, true);
    subset(0, false);
    return 0;
}
