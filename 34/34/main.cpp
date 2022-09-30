//
//  main.cpp
//  34
//
//  Created by Jerry Cheng on 10/19/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//



#include <iostream>
using namespace std;

int a[26][100000];
int main() {
    string s;
    char c[100000];
    int q1[100000], q;
    cin >> s >> q;
    for (int i = 0; i < q; i++){
        cin >> q1[i] >> c[i];
    }
    
    for (int i = 0; i < 26; i++){
        a[i][0] = -1;
    }
    for (int i = 1; i < s.length(); i++){
        for (int j = 0; j < 26; j++){
            a[j][i] = a[j][i - 1];
        }
        a[s[i - 1] - 'A'][i] = i;
        for (int j = 0; j < 26; j++){
            cout << a[j][i];
        }
        cout << endl;
    }
    
    for (int i = 0; i < q; i++){
        cout << a[c[i] - 'A'][q1[i] - 1] << endl;
    }
    return 0;
}
/*
ABCACCAB
3
6 A
5 B
2 B
*/
