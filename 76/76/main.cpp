//
//  main.cpp
//  76
//
//  Created by Jerry Cheng on 11/28/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, a[100001], c[100000];
    cin >> n >> m;
    a[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }
    for (int i = 1; i <= n; i++){
        a[i] = a[i - 1] + c[i - 1];
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        a[i] = (a[i]) % m;
        cout << a[i] << ' ';
    }
    cout << endl;
    
    int ans = 0;
    map<int, int> b;
    for (int i = 0; i < m; i++){
        b[a[i]]++;
        ans = ans + b[a[i]] - 1;
        cout << 'a' << ans << endl;
    }
    
    for (int i = m; i <= n; i++){
        b[a[i - m]]--;
        b[a[i]]++;
        ans = ans + b[a[i]] - 1;
        cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

/*
 4 4
  1 4 2 3
0 1 5 7 10
0 0 4 6 9
0 0 0 2 1
 
 4 3
   1 4 2 3
   0 3 1 2
 0 0 3 4 6
 0 0 0 1 0
 
 
 0 1 5 7 10
 0 0 4 6 9
 0 0 1 0 0
 1
 4
 1 4
 2 3
 
*/


