//
//  main.cpp
//  41
//
//  Created by Jerry Cheng on 2/1/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> a;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        a.push(b);
    }
    
    for (int i = 0; i < k; i++){
        int x = a.top() / 2;
        a.pop();
        a.push(x);
    }
    
    int total = 0;
    for (int i = 0; i < n; i++){
        total = total + a.top();
        a.pop();
    }
    cout << total << endl;
    return 0;
}
