//
//  main.cpp
//  54
//
//  Created by Jerry Cheng on 5/30/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

long long lengths[51];

long long f(int n, long long x){
    if (n == 0){
        return 0;
    }
    
    if (x == 0){
        return 0;
    }else if (x <= lengths[n - 1] + 2){
        return 1 + f(n - 1, x - 1);
    }else if (x <= lengths[n - 1] * 2 + 2){
        return lengths[n-1] / 3 * 2 + f(n - 1, x - lengths[n - 1] - 2) + 1;
    }else{
        return lengths[n-1] / 3 * 4 + 2;
    }
}

int main() {
    long long n, x;
    cin >> n >> x;
    long long ex = 1;
    for (int i = 0; i < 50; i++){
        lengths[i] = 1ll * 3 * (ex - 1);
        ex = ex * 2;
        //cout << lengths[i] << endl;
    }
    
    for (int i = 0; i < 22; i++){
        cout << i << ' ' << f(n, i) << endl;
    }
     
    cout << f(n, x) << endl;
    return 0;
}
//50 1688849860263934
