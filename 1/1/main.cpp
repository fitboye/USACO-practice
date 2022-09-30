//
//  main.cpp
//  1
//
//  Created by Jerry Cheng on 5/5/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[10], m, b = 0, c;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    cin >> c;
    
    n = n + 1;
    for (int i = n; i > m; i--){
        a[i] = a[i - 1];
    }
    a[m] = c;
    
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}
