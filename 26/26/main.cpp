//
//  main.cpp
//  26
//
//  Created by Jerry Cheng on 9/21/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    string s;
    int k, lowest = 99999999;
    cin >> s >> k;
    char a[100000];
    for (int j = 0; j < 3; j++){
        a[0] = char('A' + j);
        for (int i = 1; i < s.length(); i++){
            if (a[i - 1] == 'A'){
                a[i] = 'B';
            }else if (a[i - 1] == 'B'){
                a[i] = 'C';
            }else{
                a[i] = 'A';
            }
        }
        /*
        for (int i = 0; i < s.length(); i++){
            cout << a[i] << endl;
        }
        cout << endl;
         AABCC
         4
        */
        
        int changed = 0;
        for (int i = 0; i < k; i++){
            if (s[i] != a[i]){
                changed++;
            }
        }
        if (changed < lowest){
            lowest = changed;
            cout << lowest << endl;
        }
        for (int i = 1; i <= s.length() - k; i++){
            if (a[i - 1] != s[i - 1]){
                changed--;
            }
            if (a[i + k - 1] != s[i + k - 1]){
                changed++;
            }
            if (changed < lowest){
                lowest = changed;
                cout << lowest << endl;
            }
        }
    }
    cout << lowest << endl;
    return 0;
}
