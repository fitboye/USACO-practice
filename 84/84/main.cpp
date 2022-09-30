//
//  main.cpp
//  84
//
//  Created by Jerry Cheng on 1/9/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int l = -1, ans = 0;
    map<int, int> b;
    for (int i = 0; i < n; i++){
        if (b.count(a[i]) && b[a[i]] > l){
            ans = max(i - l - 1, ans);
            l = b[a[i]];
            b[a[i]] = i;
        }
        
        b[a[i]] = i;
    }
    ans = max(n - l - 1, ans);
    cout << ans << endl;
    return 0;
}
/*
12
1 2 5 3 4 6 7 8 9 5 1 5
*/
