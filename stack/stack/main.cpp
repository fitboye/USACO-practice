//
//  main.cpp
//  stack
//
//  Created by Jerry Cheng on 9/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, length;
    string a;
    char b[100];
    cin >> a;
    length = -1;
    for (int i = 0; i < a.length(); i++){
        length++;
        if (a[i] == 'B'){
            if (length != 0){
                length = length - 2;
            }else{
                length = length - 1;
            }
        }else{
            b[length] = a[i];
        }
    }
    
    for (int i = 0; i <= length; i++){
        cout << b[i] << endl;
    }
    return 0;
}
