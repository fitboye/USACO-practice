//
//  main.cpp
//  permutation
//
//  Created by Jerry Cheng on 11/18/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int n, k, a[100], used[100], list[100];
void permutation(int x){
    if (x == k){
        for (int i = 0; i < k; i++){
            cout << list[i] << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < n; i++){
        bool y = true;
        for (int j = 0; j < k; j++){
            if (a[i] == list[j]){
                y = false;
            }
        }
        if (y){
            list[x] = a[i];
            permutation(x + 1);
            list[x] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    permutation(0);
    return 0;
}

