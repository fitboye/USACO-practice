//
//  main.cpp
//  88
//
//  Created by Jerry Cheng on 2/6/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int a[26][100001];
int main() {
    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i < 26; i++){
        int last = -1;
        a[i][s.length()] = -1;
        for (int j = s.length() - 1; j >= 0; j--){
            if (int(s[j]) - int('a') == i){
                last = j + 1;
            }
            a[i][j] = last;
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j <= s.length(); j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    long long ans = 0, last = 0;
    for (int i = 0; i < t.length(); i++){
        if (a[int(t[i])-int('a')][last] != -1){
            ans = ans + a[int(t[i])-int('a')][last] - last;
            last = a[int(t[i])-int('a')][last];
            cout << 'a' << ans << endl;
        }else{
            if (a[int(t[i])-int('a')][0] != -1){
                ans = ans + a[int(t[i])-int('a')][0] + s.length() - last;
                last = a[int(t[i])-int('a')][0];
                cout << 'b' << ans << endl;
            }else{
                ans = -1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
