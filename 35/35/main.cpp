//
//  main.cpp
//  35
//
//  Created by Jerry Cheng on 10/19/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k, a[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    
    int smallest = 100000000;
    for (int i = 0; i < n; i++){
        int j = 0, l = n - 1;
        while ((j < n - 1) && (l > 0)){
            if (a[i] + a[j] + a[l] < k){
                j++;
            }else{
                l--;
            }
            //cout << i << ' ' << j << ' ' << l << endl;
            int b = k - a[i] - a[j] - a[l], c = k - a[i] - a[j] - a[l - 1];
            if (k - a[i] - a[j] - a[l] < 0){
                b = b * -1;
            }
            if (k - a[i] - a[j] - a[l - 1] < 0){
                c = c * -1;
            }
            if (b < smallest){
                smallest = b;
            }else if (c < smallest){
                smallest = c;
            }
        }
    }
    cout << smallest << endl;
    return 0;
}
/*
 6 20
 3 7 4 12 2 10
*/
