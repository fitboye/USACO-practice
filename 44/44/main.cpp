//
//  main.cpp
//  44
//
//  Created by Jerry Cheng on 3/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main() {
    int n, m, k, a[100000], b[100000];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m, compare);
    
    for (int i = 0; i < n && i < k && i < m; i++){
        if (a[i] < b[i]){
            a[i] = b[i];
        }else{
            break;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + a[i];
    }
    cout << sum << endl;
    return 0;
}
