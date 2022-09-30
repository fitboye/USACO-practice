//
//  main.cpp
//  21
//
//  Created by Jerry Cheng on 9/7/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, p[1000];
    string d[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i] >> d[i];
        if (d[i].length() == 3){
            d[i] = "ABC";
        }else if (d[i].length() == 2){
            if (d[i][0] > d[i][1]){
                char swap = d[i][0];
                d[i][0] = d[i][1];
                d[i][1] = swap;
            }
        }
    }
    
    int a[7];
    for (int i = 0; i < 7; i++){
        a[i] = 1000000;
    }
    for (int i = 0; i < n; i++){
        if (d[i] == "A"){
            if (p[i] < a[0]){
                a[0] = p[i];
            }
        }else if (d[i] == "B"){
            if (p[i] < a[1]){
                a[1] = p[i];
            }
        }else if (d[i] == "C"){
            if (p[i] < a[2]){
                a[2] = p[i];
            }
        }else if (d[i] == "AB"){
            if (p[i] < a[3]){
                a[3] = p[i];
            }
        }else if (d[i] == "BC"){
            if (p[i] < a[4]){
                a[4] = p[i];
            }
        }else if (d[i] == "AC"){
            if (p[i] < a[5]){
                a[5] = p[i];
            }
        }else if (d[i] == "ABC"){
            if (p[i] < a[6]){
                a[6] = p[i];
            }
        }
    }
    for (int i = 0; i < 7; i++){
        cout << a[i] << endl;
    }
    
    int b[8];
    b[0] = a[0] + a[1] + a[2];
    b[1] = a[3] + a[2];
    b[2] = a[4] + a[0];
    b[3] = a[5] + a[1];
    b[4] = a[3] + a[4];
    b[5] = a[4] + a[5];
    b[6] = a[3] + a[5];
    b[7] = a[6];
    sort (b, b + n);
    if (b[0] == 1000000){
        cout << -1 << endl;
    }else{
        cout << b[0] << endl;
    }
    return 0;
    
}


/*
 4
 5 B
 16 CBA
 6 C
 4 A
*/


