//
//  main.cpp
//  80
//
//  Created by Jerry Cheng on 12/12/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int x = a[0], y;
    for (int i = 1; i < n; i++){
        y = a[i];
        while (x != 0 && y != 0){
            if (x > y){
                x = x % y;
            }else{
                y = y % x;
            }
        }
        x = max(x, y);
    }
    cout << x << endl;
    return 0;
}
