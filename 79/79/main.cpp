//
//  main.cpp
//  79
//
//  Created by Jerry Cheng on 12/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long x;
    cin >> x;
    long long y = x;
    vector<long long> ans;
    for (long long i = 2; i*i <= x; i++){
        while (y % i == 0){
            y = y / i;
            ans.push_back(i);
        }
    }
    
    if (y != 1){
        ans.push_back(y);
    }
    for (int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] << '*';
    }  
    cout << ans[ans.size() - 1] << endl;
    return 0;
}
