//
//  main.cpp
//  23
//
//  Created by Jerry Cheng on 9/14/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if (n % 2 == 0){
        cout << a[n / 2] - a[n / 2 - 1] << endl;
        cout << 'a' << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
