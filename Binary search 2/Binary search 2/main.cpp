//
//  main.cpp
//  Binary search 2
//
//  Created by Jerry Cheng on 6/16/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int r = n, l = -1, middle;
    while (r - l > 1){
        middle = (l + r) / 2;
        if (a[middle] % 2 == 0){
            l = middle;
        }else{
            r = middle;
        }
    }
    
    cout << r << endl;
    return 0;
}
