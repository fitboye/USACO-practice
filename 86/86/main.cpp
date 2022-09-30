//
//  main.cpp
//  86
//
//  Created by Jerry Cheng on 1/23/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;
    int asum = 0, bsum = 0, z;
    cin >> z;
    a.push(z);
    cout << 0 << endl;
    asum = z;
    for (int i = 1; i < q; i++){
        int x;
        cin >> x;
        if (x < a.top()){
            a.push(x);
            asum += x;
        }else{
            b.push(x);
            bsum += x;
        }
        while (a.size() > (i + 1)/2){
            b.push(a.top());
            bsum += a.top();
            asum -= b.top();
            a.pop();
        }
        while (a.size() < (i + 1)/2){
            a.push(b.top());
            asum += b.top();
            bsum -= b.top();
            b.pop();
        }
        //cout << a.top() << ' ' << b.top() << endl;
        cout << b.top() * a.size() - asum + bsum - b.top() * b.size() << endl;
    }
    
    return 0;
}
/*
 6
 5
 10
 100
 2
 1
 15
*/
