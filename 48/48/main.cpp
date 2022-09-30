//
//  main.cpp
//  48
//
//  Created by Jerry Cheng on 3/28/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    string s;
    int q;
    cin >> s >> q;
    int l[100000], r[100000];
    for (int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
    }
    
    int a[26][100002];
    for (int j = 0; j < 26; j++){
        a[j][0] = 0;
    }
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < 26; j++){
            a[j][i + 1] = a[j][i];
        }
        a[int(s[i]) - int('a')][i + 1]++;
    }
    
    for (int i = 0; i < q; i++){
        int x = 0;
        for (int j = 0; j < 26; j++){
            if (a[j][r[i]] - a[j][l[i] - 1] > 0){
                x++;
            }
        }
        cout << x << endl;
    }
    return 0;
}
/*
 abcacbda
 4
 1 8
 3 6
 4 5
 3 7
*/
