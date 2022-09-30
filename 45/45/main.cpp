//
//  main.cpp
//  45
//
//  Created by Jerry Cheng on 3/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a[100000], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    
    int j = n - 1;
    long long total = 0;
    for (int i = 0; i < n; i++){
        while(1ll * a[i] * a[j] > m && i < j){
            j--;
        }
        if (i < j){
            total = total + j - i;
        }else{
            break;
        }
    }
    cout << total << endl;
    return 0;
}
