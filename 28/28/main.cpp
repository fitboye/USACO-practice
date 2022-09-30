//
//  main.cpp
//  28
//
//  Created by Jerry Cheng on 9/28/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i <= n; i++){
        cin >> a[i];
    }
    
    int b = n;
    if (a[0] == 1){
        cout << "x^" << b;
    }else if (a[0] == -1){
        cout << "-x^" << b;
    }else{
        cout << a[0] << "x^" << b;
    }
    b--;
    for (int i = 1; i <= n; i++){
        if ((i <= n - 2) && (a[i] != 0)){
            if (a[i] == 1){
                cout << " + " << "x^" << b;
            }else if (a[i] == -1){
                cout << "- x^" << b;
            }else if (a[i] < 0){
                cout << a[i] << "x^" << b;
            }else{
                cout << " + " << a[i] << "x^" << b;
            }
        }else if ((i == n - 1) && (a[i] != 0)){
            if (a[i] == 1){
                cout << " + " << "x";
            }else if (a[i] == -1){
                cout << "- x";
            }else if (a[i] < 0){
                cout << a[i] << "x";
            }else{
                cout << " + " << a[i] << "x";
            }
        }else{
            if (a[i] != 0){
                if (a[i] < 0){
                    cout << a[i] << endl;
                }else{
                    cout << " + " << a[i] << endl;
                }
            }
        }
        b--;
    }
    return 0;
}
