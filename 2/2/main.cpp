//
//  main.cpp
//  2
//
//  Created by Jerry Cheng on 5/5/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, flag = 0, b = 10;
    cin >> n;
    for (int i = 0; flag != 1; i++){
        if (n / b == 0){
            flag = 1;
        }else{
            b = b * 10;
        }
    }
    //cout << b << endl;
    
    for (int i = 0; i < b; i++){
        b = b / 10;
        cout << n / b << endl;
        n = n % b;
    }
    return 0;
}
