//
//  main.cpp
//  7
//
//  Created by Jerry Cheng on 6/9/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, k, c, flag = 0, a = -1, b = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> c;
        if (c == k){
            if (a == -1){
                b = i;
                a = 0;
            }else{
                a = b;
                b = i;
                flag = 1;
            }
        }
    }
    
    cout << a << ' ' << b << endl;
    
    if (flag == 0){
        cout << -1 << endl;
    }else{
        cout << a + 1 << endl;
    }
    return 0;
}
