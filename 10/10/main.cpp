//
//  main.cpp
//  10
//
//  Created by Jerry Cheng on 7/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int power(int b, int n){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return b;
    }else{
        return b * power(b, n - 1);
    }
}

int basek2base10(string n, int k){
    int x = 0, y = 1;
    for (int i = n.length() - 1; i >= 0; i--){
        if ((int(n[i]) > 47) && (int(n[i]) < 58)){
            x = x + (int(n[i]) - 48) * y;
        }else{
            x = x + (int(n[i]) - 55) * y;
        }
        y = y * k;
    }
    return x;
}

int main() {
    cout << basek2base10("12A", 12) << endl;
}
