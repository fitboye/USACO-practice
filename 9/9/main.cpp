//
//  main.cpp
//  9
//
//  Created by Jerry Cheng on 7/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int power(int b, int n){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return b;
    }else{
        return b * power(b, n - 1);
    }
}

int basek2base10(int n, int k){
    int x = 0, y = 1, z = 0;
    while (n > 0){
        x = x + n % 10 * power(k, z);
        n = n / 10;
        y = y * 10;
        z++;
        //cout << x << ' ' << n << ' ' << y << ' ' << z << endl;
    }
    return x;
}

int main() {
    cout << basek2base10(111, 5) << endl;
    return 0;
}
