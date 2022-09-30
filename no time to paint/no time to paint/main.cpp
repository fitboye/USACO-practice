//
//  main.cpp
//  no time to paint
//
//  Created by Jerry Cheng on 1/23/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s;

    int a[100002];
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        a[i] = a[i - 1];
        if (int(s[i - 1]) < int(s[i])){
            a[i]++;
        }
    }
    a[n + 1] = a[n];
    
    int b[100002];
    set<char> c;
    for (int i = 1; i <= n; i++){
        c.insert(s[i]);
        for (int j = int(s[i]) + 1; j <= int('Z'); j++){
            c.erase(char(j));
        }
        b[i] = c.size();
        //cout << b[i] << ' ';
    }
    for (auto x : c){
        for (int i = n; i >= 0; i--){
            if (s[i] == x){
                break;
            }
            b[i]--;
        }
    }
    
    for (int i = 0; i < q; i++){
        int start, end, ans = a[n + 1];
        cin >> start >> end;
        ans = ans + b[end + 1];
        //cout << ans << ' ';
        ans = ans - (a[end + 1] - a[start - 1]);
        cout << ans << endl;
    }
    return 0;
}
/*
 8 2
 ABBAABCB
 1 1
 7 8
 */
