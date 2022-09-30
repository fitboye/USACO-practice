//
//  main.cpp
//  Testing
//
//  Created by Jerry Cheng on 4/3/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> a[10];
    a[0].push(1);
    a[0].push(2);
    a[0].push(3);
    a[1].push(3);
    a[1].push(2);
    for (int i = 0; i < 10; i++){
        while (a[i].size() > 0){
            cout << a[i].top() << ' ';
            a[i].pop();
        }
        cout << endl;
    }
    return 0;
}

