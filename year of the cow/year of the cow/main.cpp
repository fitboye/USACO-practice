//
//  main.cpp
//  year of the cow
//
//  Created by Jerry Cheng on 2/28/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool c (int a, int b){
    return a > b;
}

int main() {
    int n, k, a[100000];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        //a[i]--;
    }
    sort(a, a + n);
    
    int savings[100000];
    savings[0] = a[0]/12;
    for (int i = 0; i < n - 1; i++){
        savings[i + 1] = a[i + 1]/12 - a[i]/12 - 1;
        //cout << savings[i] << endl;
    }
    sort(savings, savings + n, c);
    
    int ans = (a[n - 1]/12 + 1)* 12;
    //cout << ans << endl;
    for (int i = 0; i < k - 1; i++){
        if (savings[i] <= 0){
            break;
        }
        //cout << savings[i] << endl;
        ans = ans - savings[i] * 12;
    }
    cout << ans << endl;
    return 0;
}
/*
4 1
23
35
47
59
*/
