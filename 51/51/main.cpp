//
//  main.cpp
//  51
//
//  Created by Jerry Cheng on 5/2/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int power(int a, int x, int p){
    if (x == 0){
        return 1;
    }
    
    int b = power(a, x/2, p);
    if (x % 2 == 0){
        return 1ll * b % p * b % p;
    }else{
        return 1ll * b % p * b % p * a % p;
    }
}

int main() {
    int a, x, p;
    cin >> a >> x >> p;
    int b = power(a, x, p);
    cout << b << endl;
    return 0;
}
