//
//  main.cpp
//  40
//
//  Created by Jerry Cheng on 1/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> a;
    while (true){
        int b;
        cin >> b;
        if (b == 1){
            cin >> b;
            a.push(b);
        }else if (b == 2){
            if (a.size() == 0){
                cout << "None" << endl;
            }else{
                cout << a.top() << endl;
                a.pop();
            }
        }
    }
    return 0;
}
