//
//  main.cpp
//  traffic
//
//  Created by Jerry Cheng on 8/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int n, type[100], minimum[100], maximum[100];
    string s[100];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> s[i] >> minimum[i] >> maximum[i];
    }
    int a = 0, b = 1000;
    for (int i = 0; i < n; i++){
        if (s[i] == "on"){
            a = a + minimum[i];
            b = b + maximum[i];
        }else if (s[i] == "off"){
            a = a - maximum[i];
            b = b - minimum[i];
            a = max(0, a);
            b = max(0, b);
        }else{
            a = max(minimum[i], a);
            b = min(maximum[i], b);
        }
    }
    
    int x = 0, y = 1000;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == "on"){
            x = x - maximum[i];
            y = y - minimum[i];
            x = max(0, x);
            y = max(0, y);
        }else if (s[i] == "off"){
            x = x + minimum[i];
            y = y + maximum[i];
        }else{
            x = max(minimum[i], x);
            y = min(maximum[i], y);
        }
    }
    
    fout << x << ' ' << y << endl;
    fout << a << ' ' << b << endl;
    return 0;
}
