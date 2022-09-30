//
//  main.cpp
//  93
//
//  Created by Jerry Cheng on 2/20/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int in;
    cin >> in;
    a.push_back(in);
    for (int i = 1; i < n; i++){
        cin >> in;
        if (in != a[a.size() - 1]){
            a.push_back(in);
        }
    }
    //a.push_back(a[a.size() - 2]);
    
    map<int, int> b;
    for (int i = 0; i < int(a.size()) - 2; i++){
        if (a[i] == a[i + 2]){
            b[a[i + 1]]++;
        }
    }
    for (int i = 0; i < a.size(); i++){
        b[a[i]]++;
    }
    int x = 0;
    for (auto i : b){
        if (b[x] < i.second){
            x = i.first;
        }
    }
    cout << x << endl;
    
    int ans = 0, y = a[0];
    if (y == x && a.size() > 1){
        y = a[1];
    }
    for (int i = 0; i < a.size(); i++){
        if (a[i] != x && a[i] != y){
            y = a[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
 8
 1 2 1 3 1 4 1 5
*/
