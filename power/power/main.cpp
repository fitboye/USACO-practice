//
//  main.cpp
//  power
//
//  Created by Jerry Cheng on 6/25/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int power(int b, int n){
    if (n == 1){
        return b;
    }else{
        return b * power(b, n - 1);
    }
}

int main() {
    cout << power(3, 3) << endl;
    return 0;
}
