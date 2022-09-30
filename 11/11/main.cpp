//
//  main.cpp
//  11
//
//  Created by Jerry Cheng on 7/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

string base10tobasek(int n, int k){
    int y = 1;
    string x;
    while (n / y > 0){
        if (n / y % k < 10){
            x = char(n / y % k + '0') + x;
        }else{
            x = char(n / y % k + 'A' - 10) + x;
        }
        y = y * k;
    }
    return x;
}

int main() {
    cout << base10tobasek(123, 2) << endl;
    return 0;
}
