//
//  main.cpp
//  8
//
//  Created by Jerry Cheng on 6/30/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[100], largest = -1, b[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    if (a[0] > a[1]){
        b[n - 2] = a[0];
    }else{
        b[n - 2] = a[1];
    }
    
    for (int i = 2; i < n; i++){
        if (a[i] > b[n - i]){
            b[n - i - 1] = a[i];
        }else{
            b[n - i - 1] = b[n - i];
        }
    }
    
    for (int i = 0; i < n - 1; i++){
        cout << b[i] << endl;
    }
    
    return 0;
}
