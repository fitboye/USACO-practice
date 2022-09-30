//
//  main.cpp
//  6
//
//  Created by Jerry Cheng on 5/26/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[5000], smallest, position, swap, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i ++){
        smallest = 10000000;
        position = 0;
        for (int j = b; j < n; j++){
            if (a[j] < smallest){
                smallest = a[j];
                position = j;
            }
        }
        //cout << smallest << endl;
        swap = a[b];
        a[b] = a[position];
        a[position] = swap;
        b++;
    }
    
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
