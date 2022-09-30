//
//  main.cpp
//  3
//
//  Created by Jerry Cheng on 5/19/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n = 0, a = 0, b = 0, c = 0;
    cin >> n;
    
    while (true){
        c = 10;
        for (int i = 0; i < b; i++){
            c = c * 10;
        }
        //cout << c << endl;
        if (n / c == 0){
            a = b;
            break;
        }
        b++;
    }
    
    //cout << a << endl;
    
    for (int i = a; i >= 0; i--){
        c = 1;
        for (int j = 0; j < i; j++){
            c = c * 10;
        }
        //cout << c << endl;
        cout << (n / c) % 10 << endl;
    }
    return 0;
}
