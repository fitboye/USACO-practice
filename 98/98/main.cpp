//
//  main.cpp
//  98
//
//  Created by Jerry Cheng on 3/13/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, a[1000][1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            cin >> a[i][j];
        }
    }
    
    int b[1000];
    b[0] = 0;
    for (int i = 1; i < n; i++){
        int x = i - 1, minimum = 1000000001;
        for (int j = 0; j < i; j++){
            minimum = min(minimum, a[j][x] + b[j]);
            x--;
        }
        b[i] = minimum;
    }
    cout << b[n - 1] << endl;
    return 0;
}
/*
 4
 1 4 4
 1 4
 3
*/
