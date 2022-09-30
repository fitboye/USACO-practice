//
//  main.cpp
//  4
//
//  Created by Jerry Cheng on 5/19/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a[8], b = 0, x = 0, y = 0;
    
    while (a[b - 1] != -1){
        cin >> a[b];
        b++;
    }
    
    y = 10;
    for (int i = 0; i < b - 3; i++){
        y = y * 10;
    }
    
    for (int i = 0; i < b - 1; i++){
        x = x + y * a[i];
        y = y / 10;
    }

    cout << x << endl;
    return 0;
}
