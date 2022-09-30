//
//  main.cpp
//  27
//
//  Created by Jerry Cheng on 9/28/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int count = 0, length, a;
    if (s.length() > t.length()){
        length = s.length();
        a = s.length() - t.length();
        for (int i = length - 1; i >= a; i--){
            if (s[i] != t[i - a]){
                break;
            }else{
                count++;
                count++;
            }
        }
    }else{
        length = t.length();
        a = t.length() - s.length();
        for (int i = length - 1; i >= a; i--){
            cout << i << ' ' << i - a << endl;
            if (s[i - a] != t[i]){
                break;
            }else{
                count++;
                count++;
            }
        }
    }
    cout << s.length() + t.length() - count << endl;
    return 0;
}
