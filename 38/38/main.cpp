//
//  main.cpp
//  38
//
//  Created by Jerry Cheng on 11/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
void permutation(int a[], int n, int k, int d, bool used[], int b[]){
    if (d == k){
        for (int i = 0; i < k; i++){
            cout << b[i] << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (!used[i]){
            used[i] = true;
            b[d] = a[i];
            permutation(a, n, k, d + 1, used, b);
            used[i] = false;
        }
    }
}

int main() {
    int n, k, a[100], c[100];
    bool b[10];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = false;
    }
    permutation(a, n, k, 0, b, c);
    return 0;
}
