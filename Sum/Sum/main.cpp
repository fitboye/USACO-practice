//
//  main.cpp
//  Sum
//
//  Created by Jerry Cheng on 6/16/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int sum(int a[], int n){
    int b = 0;
    for (int i = 0; i < n; i++){
        b = b + a[i];
    }
    return b;
}
int main() {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << sum(a, n) << endl;
    return 0;
}
