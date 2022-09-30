//
//  main.cpp
//  92
//
//  Created by Jerry Cheng on 2/20/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int z = 1000000007;
int power (int x){
    if (x == 0){
        return 1;
    }
    long long y;
    y = power(x/2);
    y = y * y % z;
    if (x % 2 == 1){
        y = y * 9 % z;
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    cout << power(n) << endl;
    return 0;
}
