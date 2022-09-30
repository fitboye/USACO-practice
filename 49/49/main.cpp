//
//  main.cpp
//  49
//
//  Created by Jerry Cheng on 4/4/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int a = 2 * m - 2;
    int b = n / (k * a);
    int c[100000];
    c[0] = b * k;
    for (int i = 1; i < m - 1; i++){
        c[i] = 2 * b * k;
    }
    c[m - 1] = b * k;
    n = n % (a * k);
    int i = 0;
    while (i < m && n - k > 0){
        c[i] = c[i] + k;
        n = n - k;
        i++;
    }
    if (n - k < 0){
        c[i] = c[i] + n;
    }else{
        i = m - 2;
        while (i > 0 && n - k > 0){
            c[i] = c[i] + k;
            n = n - k;
            i--;
        }
        c[i] = c[i] + n;
    }
     
    for (int j = 0; j < m; j++){
        cout << c[j] << endl;
    }
    return 0;
}
