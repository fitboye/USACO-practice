//
//  main.cpp
//  36
//
//  Created by Jerry Cheng on 10/27/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct person{
    string name;
    int p;
};

bool compare(person a, person b){
    return a.name < b.name;
}

int main() {
    person a[100000];
    int n, q;
    string qu[100000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].p;
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> qu[i];
    }
    sort (a, a + n, compare);
    
    
    for (int i = 0; i < q; i++){
        int l = 0, r = n - 1, m = (l + r) / 2;
        while (r - l >= 0){
            m = (l + r) / 2;
            if (a[m].name == qu[i]){
                l = m;
                break;
            }else if (a[m].name < qu[i]){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        //cout << m << endl;
        if (a[l].name != qu[i]){
            cout << -1 << endl;
        }else{
            cout << a[l].p << endl;
        }
    }
    return 0;
}

/*
 3
 AAA 100
 BBB 88
 CCC 59
 6
 BBB
 ABC
 DDD
 AAA
 A
 CCC
*/
