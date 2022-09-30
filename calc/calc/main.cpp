//
//  main.cpp
//  calc
//
//  Created by Jerry Cheng on 6/25/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int calc(int a, int b, char c){
    if (c == '+'){
        return a + b;
    }else if (c == '-'){
        return a - b;
    }else if (c == '*'){
        return a * b;
    }else if (c == '/'){
        return a / b;
    }else{
        return a % b;
    }
}

int main() {
    cout << calc(2, 3, '+') << endl;
    return 0;
}
