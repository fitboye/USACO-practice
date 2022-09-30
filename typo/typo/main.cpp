//
//  main.cpp
//  typo
//
//  Created by Jerry Cheng on 2/15/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("typo.in");
    ofstream fout("typo.out");
    string s;
    fin >> s;
    int l = 0, r = 0;
    char a[100000];
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            l++;
        }else{
            r++;
        }
        a[i] = s[i];
    }
    //cout << l << ' ' << r << endl;
    
    if(l - r == 2){
        for (int i = 0; i < s.length(); i++){
            a[i] = s[s.length() - i - 1];
            if (a[i] == '('){
                a[i] = ')';
            }else{
                a[i] = '(';
            }
        }
    }
    /*
    for (int i = 0; i < s.length(); i++){
        cout << a[i];
    }
    cout << endl;
     */
    
    int ans;
    l = 0;
    r = 0;
    for (int i = 0; i < s.length(); i++){
        if (a[i] == '('){
            l++;
        }else{
            r++;
        }
        if (r - l == 1){
            ans = r;
            break;
        }
    }
    
    fout << ans << endl;
    return 0;
}

/*
 ((()())(()))))
 
 (()((())))
 
 ((((()()())(()())(((((()()()))()(((()(())))))()))()(())()())
 
 ( ( ( ( ) ) ( )
 1 2 3 4 3 2 3 2
-2-1 0 1 2 1 0 1
 
 ( ) ( ( ) ) ) )
 1 0 1 2 1 0 -1-2
 2 3 2 3 4 3 2 1
*/
