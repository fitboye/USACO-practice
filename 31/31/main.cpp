//
//  main.cpp
//  31
//
//  Created by Jerry Cheng on 9/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool comp (char a, char b){
    return a < b;
}

bool compare (string a, string b){
    return a < b;
}

int main() {
    int n;
    cin >> n;
    string a[100000];
    char c[10];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < a[i].length(); j++){
            c[j] = a[i][j];
        }
        sort(c, c + a[i].length(), comp);
        for (int j = 0; j < a[i].length(); j++){
            a[i][j] = c[j];
        }
    }
    sort (a, a + n, compare);
    
    int b = 0;
    long long total = 0;
    for (int i = 0; i < n - 1; i++){
        if (a[i] == a[i + 1]){
            b++;
        }else{
            while (b > 0){
                total = total + b;
                b--;
            }
        }
    }
    while (b > 0){
        total = total + b;
        b--;
    }
    cout << total << endl;
    return 0;
}

/*
 4
 abcd
 bcda
 dacb
 ccaa
*/
