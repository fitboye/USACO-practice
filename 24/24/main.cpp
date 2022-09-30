//
//  main.cpp
//  24
//
//  Created by Jerry Cheng on 9/21/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool c (char a, char b){
    return b < a;
}
int main() {
    string s, t;
    cin >> s >> t;
    char a[100], b[100];
    for (int i = 0; i < s.length(); i++){
        a[i] = s[i];
    }
    sort(a, a + s.length());
    for (int i = 0; i < t.length(); i++){
        b[i] = t[i];
    }
    sort(b, b + t.length(), c);
    
    int n, x = 0 ;
    if (s.length() < t.length()){
        n = s.length();
    }else{
        n = t.length();
    }
    for (int i = 0; i < n; i++){
        if (a[i] < b[i]){
            cout << a[i] << b[i] << endl;
            x = 1;
            break;
        }else if (b[i] < a[i]){
            x = 2;
            break;
        }
    }
    if (x == 0){
        if (s.length() < t.length()){
            x = 1;
        }else if (s.length() > t.length()){
            x = 2;
        }
    }
    if (x == 1){
        cout << "Yes" << endl;
    }else if (x == 2){
        cout << "No" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
