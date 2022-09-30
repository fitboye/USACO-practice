//
//  main.cpp
//  73
//
//  Created by Jerry Cheng on 11/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[100000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    map<int, int> current;
    for (int i = 0; i < k; i++){
        current[a[i]]++;
    }
    cout << current.size() << endl;
    
    for (int i = 1; i <= n - k; i++){
        current[a[i - 1]]--;
        if (current[a[i - 1]] == 0){
            current.erase(a[i - 1]);
        }
        current[a[i + k - 1]]++;
        cout << current.size() << endl;
    }
    return 0;
}
