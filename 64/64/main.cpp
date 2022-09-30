//
//  main.cpp
//  64
//
//  Created by Jerry Cheng on 8/15/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    
    stack<char> a;
    for (int i = 0; i < s.length(); i++){
        if (!a.empty() && a.top() == '(' && s[i] == ')'){
            a.pop();
        }else if (!a.empty() && a.top() == '[' && s[i] == ']'){
            a.pop();
        }else{
            a.push(s[i]);
        }
    }
    cout << a.empty() << endl;
    return 0;
}
