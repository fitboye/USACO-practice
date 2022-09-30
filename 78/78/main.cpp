//
//  main.cpp
//  78
//
//  Created by Jerry Cheng on 12/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

bool a[10000001];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++){
        a[i] = true;
    }
    for (int i = 2; i*i <= n; i++){
        if (a[i]){
            int x = i + i;
            while(x <= n){
                a[x] = false;
                x = x + i;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (a[i]){
            cout << i << endl;
        }
    }
    return 0;
}
