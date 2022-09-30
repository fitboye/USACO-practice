//
//  main.cpp
//  33
//
//  Created by Jerry Cheng on 10/19/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[100000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[100001];
    b[0] = 0;
    for (int i = 1; i <= n; i++){
        b[i] = a[i - 1] + b[i - 1];
    }
    
    for (int i = 0; i <= n; i++){
        cout << b[i] << endl;
    }
    
    int j = 0, total = 0;
    for (int i = 0; i <= n; i++){
        while ((j <= n) && (b[j] - b[i] < k)){
            j++;
            cout << i << ' ' << j << ' ' << b[i] << ' ' << b[j] << endl;
        }
        total = total + n - j + 1;
        cout << total << ' ' << j << endl;
    }
    cout << total << endl;
    return 0;
}
