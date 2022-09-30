//
//  main.cpp
//  22
//
//  Created by Jerry Cheng on 9/14/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int q, l[100000], r[100000];
    string s;
    cin >> s;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
    }
    
    int a[100001];
    a[0] = 0;
    for (int i = 1; i < s.length() + 1; i++){
        if ((s[i - 1] == 'A') && (s[i] == 'C')){
            a[i] = a[i - 1] + 1;
        }else{
            a[i] = a[i - 1];
        }
    }
    
    for (int i = 0; i < s.length() + 1; i++){
        cout << a[i] << endl;
    }
    
    for (int i = 0; i < q; i++){
        cout << a[r[i]] - a[l[i] - 1] << endl;
    }
    return 0;
}

/*
 ACCCAACEFRWAC
 2
 1 13
 2 12
*/



