//
//  main.cpp
//  74
//
//  Created by Jerry Cheng on 11/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[10];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    
    queue<long long> numbers;
    for (int i = 0; i < n; i++){
        if (a[i] != 0){
            numbers.push(a[i]);
        }
    }
    
    int x;
    for (int i = 0; i < k; i++){
        x = numbers.front();
        for (int j = 0; j < n; j++){
            numbers.push(x * 10 + a[j]);
        }
        numbers.pop();
    }
    cout << x << endl;
    return 0;
}
