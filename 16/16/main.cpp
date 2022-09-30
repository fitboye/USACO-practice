//
//  main.cpp
//  16
//
//  Created by Jerry Cheng on 12/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//
int n, k, a[100], total = 0, b[100], all[100], length = 0;
#include <iostream>
using namespace std;

void ab(int x, int pos){
    if (x == k){
        int t = 0;
        for (int i = 0; i < k; i++){
            cout << b[i] << ' ';
            t = t + b[i];
        }
        cout << endl;
        
        bool d = true;
        for (int i = 0; i < length; i++){
            if (t == all[i]){
                d = false;
            }
        }
        if (d){
            t = 0;
            for (int i = 0; i < k; i++){
                t = t + b[i];
            }
            all[length] = t;
            length++;
            total++;
        }
        return;
    }
    
    for (int i = pos; i < n; i++){
        bool c = true;
        for (int j = 0; j < x; j++){
            if (a[i] == b[j]){
                c = false;
            }
        }
        if (c){
            b[x] = a[i];
            pos = i;
            ab(x + 1, pos);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ab(0, 0);
    for (int i = 0; i < length; i++){
        cout << all[i] << ' ';
    }
    cout << endl;
    cout << total << endl;
    return 0;
}
