//
//  main.cpp
//  20
//
//  Created by Jerry Cheng on 9/7/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, m;
    string a[2000];
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int r[2000];
    for (int i = 0; i < n; i++){
        r[i] = 0;
    }
    for (int i = 0; i < m; i++){
        int s = -1;
        bool b = true;
        for (int j = 0; j < n; j++){
            cout << a[j][i];
            if (a[j][i] == '1'){
                if (s != -1){
                    b = false;
                }
                s = j;
            }
        }
        cout << endl;
        if (b){
            r[s] = 1;
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if (r[i] == 0){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

/*
 4 5
 10010
 11001
 01010
 10101
*/



