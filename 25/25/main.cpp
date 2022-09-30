//
//  main.cpp
//  25
//
//  Created by Jerry Cheng on 9/21/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int count = 0;
    for (int i = 0; i < n; i++){
        while ((a[i] % 2 == 0) && (a[i] != 0)){
            a[i] = a[i] / 2;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
