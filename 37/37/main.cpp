//
//  main.cpp
//  37
//
//  Created by Jerry Cheng on 11/24/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

int largest;
void a(int w[], int p[], int n, int m, int value, int d, int price){
    if ((price > m) || (d > n)){
        cout << 'a' << endl;
        return;
    }
    //cout << value << ' ' << d << ' ' << price << endl;
    cout << d << endl;
    a(w, p, n, m, value + w[d] * p[d], d + 1, price + p[d]);
    if ((value > largest) && (price <= m)){
        largest = value;
    }
    cout << value << endl;
    a(w, p, n, m, value, d + 1, price);
}

int main() {
    int w[100], p[100], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> w[i] >> p[i];
    }
    
    a(w, p, n, m, 0, 0, 0);
    cout << largest << endl;
    return 0;
}



/*
 5 1000
 1 500
 2 400
 3 300
 4 400
 5 100
 
 3 500
 1 300
 2 200
 3 50
*/
