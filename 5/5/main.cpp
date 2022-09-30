//
//  main.cpp
//  5
//
//  Created by Jerry Cheng on 5/19/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a = 0, b = 0, c, flag = 0, d;
    cin >> n;
    
    while (true){
        c = 10;
        for (int i = 0; i < b; i++){
            c = c * 10;
        }
        //cout << c << endl;
        if (n / c == 0){
            a = b + 1;
            break;
        }
        b++;
    }
    
    d = 1;
    for (int i = 0; i < a - 1; i++){
        d = d * 10;
    }
    
    cout << d << endl;
    for (int i = 0; i < a / 2; i++){
        if (n % 10 != n / d){
            flag = 1;
        }
        n = n - (n / d) * d;
        n = n - n % 10;
        n = n / 10;
        cout << n << endl;
        d = d / 100;
    }
    
    if (flag == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
