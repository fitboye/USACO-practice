//
//  main.cpp
//  43
//
//  Created by Jerry Cheng on 2/8/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> a, b;
    int in;
    for (int i = 0; i < n; i++){
        cin >> in;
        if (a.count(in) == 0){
            a.insert(in);
        }else{
            a.erase(in);
        }
        /*
        for (int j : a){
            cout << j << ' ';
        }
        cout << endl;
         */
        
        if (a.size() == 1){
            int x;
            for (int j : a){
                x = j;
            }
            b.insert(x);
        }
    }
    cout << b.size() << endl;
    return 0;
}
