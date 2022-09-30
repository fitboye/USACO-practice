//
//  main.cpp
//  17
//
//  Created by Jerry Cheng on 12/22/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
