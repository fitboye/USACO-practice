//
//  main.cpp
//  Binary search
//
//  Created by Jerry Cheng on 6/9/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, k, a[1000], b;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int range_high = n - 1, range_low = 0;
    while (true){
        b = (range_high + range_low) / 2;
        cout << b << ' '<< range_high << ' ' << range_low << endl;
        if (a[b] < k){
            range_low = b + 1;
        }else if (a[b] > k){
            range_high = b - 1;
        }else{
            cout << b + 1 << endl;
            break;
        }
        if (range_high == range_low){
            if (a[range_low] == k){
                cout << b + 1 << endl;
                break;
            }else{
                cout << -1 << endl;
                break;
            }
        }
    }
    return 0;
}

/*
6 5
1 2 3 4 5 6
*/
