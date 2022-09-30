//
//  main.cpp
//  81
//
//  Created by Jerry Cheng on 12/12/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>

struct factor{
    int num, power;
};
using namespace std;
int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans[100000];
    for (int i = 0; i < 100000; i++){
        ans[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        vector<factor> factors;
        for (long long j = 2; j * j <= a[i]; j++){
            factor x;
            bool y = false;
            if (a[i] % j == 0){
                x.num = j;
                x.power = 0;
                y = true;
            }
            while (a[i] % j == 0){
                a[i] = a[i] / j;
                x.power++;
            }
            if (y){
                factors.push_back(x);
            }
        }
        if (a[i] != 1){
            factor x;
            x.num = a[i];
            x.power = 1;
            factors.push_back(x);
        }
        for (int j = 0; j < factors.size(); j++){
            ans[factors[j].num] = max(ans[factors[j].num], factors[j].power);
        }
    }
    
    long long x = 1;
    for (int i = 2; i < 100000; i++){
        for (int j = 0; j < ans[i]; j++){
            x = x * i % 1000000007;
        }
    }
    cout << x << endl;
    return 0;
}
