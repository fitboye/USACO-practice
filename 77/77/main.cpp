//
//  main.cpp
//  77
//
//  Created by Jerry Cheng on 12/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long a;
    cin >> a;
    vector<long long> ans;
    for (long long i = 1; i*i <= a; i++){
        if (a % i == 0){
            ans.push_back(i);
        }
    }
    int n = ans.size();
    for (int i = n - 1; i >= 0; i--){
        if (a/ans[i] != ans[i]){
            ans.push_back(a/ans[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
