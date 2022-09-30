//
//  main.cpp
//  Insertion sort
//
//  Created by Jerry Cheng on 5/26/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[5000], b, c = 0;
    for (int i = 0; i < 5000; i++){
        a[i] = 0;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> b;
        if (i == 0){
            a[0] = b;
        }else{
            c = -1;
            for (int j = 0; (a[j] < b) && (a[j] != 0); j++){
                c = j;
            }
            c++;
            //cout << c << endl;
            for (int j = i; j >= c; j--){
                a[j + 1] = a[j];
            }
            a[c] = b;
        }
        for (int j = 0; j < i + 1; j++){
            cout << a[j] << endl;
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
