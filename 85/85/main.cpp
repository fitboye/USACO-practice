//
//  main.cpp
//  85
//
//  Created by Jerry Cheng on 1/9/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[100000], b[100000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    
    int ans = 0;
    if (a[0] >= m){
        b[0] = 1;
    }
    for (int i = 1; i < n; i++){
        if (a[i] < m && a[i - 1] >= m){
            ans++;
        }
        if (a[i] >= m){
            b[i] = 1;
        }
    }
    if (a[n - 1] >= m){
        ans++;
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        if (!b[x]){
            a[x] += y;
            if (a[x] >= m){
                b[x] = 1;
                int z = 0;
                if (x != 0 && b[x - 1] == 1){
                    z++;
                }
                if (x != n - 1 && b[x + 1] == 1){
                    z++;
                }
                if (z == 0){
                    ans++;
                }else if (z == 2){
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
5 5
1 1 1 1 1
4
1 1
1 5
3 5
2 5
*/
