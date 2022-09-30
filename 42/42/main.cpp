//
//  main.cpp
//  42
//
//  Created by Jerry Cheng on 2/8/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[100001], b;
    cin >> b;
    a[0] = 0;
    a[1] = b;
    for (int i = 2; i <= n; i++){
        cin >> b;
        a[i] = a[i - 1] + b;
    }
    /*
    for (int i = 0; i <= n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
     */
    
    map<int, int> c;
    int ans = 0;
    for (int i = 0; i <= n; i++){
        ans = ans + c[a[i] % m];
        //cout << c[a[i] % m] << endl;
        c[a[i] % m]++;
    }
    cout << ans << endl;
    return 0;
}

/*
 4 2
 3 2 4 1
*/

