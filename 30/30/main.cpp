//
//  main.cpp
//  30
//
//  Created by Jerry Cheng on 9/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1000000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int count = 1, max = 0;
    for (int i = 0; i < n - 1; i++){
        if (a[i + 1] >= a[i]){
            count = 1;
        }else{
            count++;
        }
        if (count > max){
            max = count;
        }
    }
    cout << max << endl;
    return 0;
}
