//
//  main.cpp
//  60
//
//  Created by Jerry Cheng on 7/4/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int q, x[1000];
    cin >> q;
    /*
    for (int i = 0; i < q; i++){
        cin >> x[i];
    }
     */
    for (int i = 0; i < q; i++){
        x[i] = i + 1;
    }
    
    
    for (int i = 0; i < q; i++){
        int a = 26, digits = 1;
        while(x[i] - a * digits > 0){
            x[i] = x[i] - a * digits;
            a = a * 26;
            digits++;
        }
        int c[20], d = (x[i] - 1)/ digits;
        a = a/26;
        for (int j = 0; j < digits; j++){
            c[j] = d / a;
            d = d % a;
            a = a / 26;
            //cout << c[j] << endl;
        }
        cout << char(c[(x[i] - 1) % digits] + int('A')) << endl;
    }
    return 0;
}
//ABCDEFGHIJKLMNOPQRSTUVWXYZ AAABACADAEAFAGAHAIAJAK
