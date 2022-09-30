//
//  main.cpp
//  odometer
//
//  Created by Jerry Cheng on 5/25/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("odometer.in");
    ofstream fout("odometer.out");
    long long x, y;
    fin >> x >> y;
    int count = 0;
    int a[9][9] = {10, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 23, 24, 25, 26, 27, 28, 29,
        30, 32, 31, 34, 35, 36, 37, 38, 39,
        40, 42, 43, 41, 45, 46, 47, 48, 49,
        50, 52, 53, 54, 51, 56, 57, 58, 59,
        60, 62, 63, 64, 65, 61, 67, 68, 69,
        70, 72, 73, 74, 75, 76, 71, 78, 79,
        80, 82, 83, 84, 85, 86, 87, 81, 89,
        90, 92, 93, 94, 95, 96, 97, 98, 91};

    
    long long x1 = x, b = 1, y1 = y;
    int digits = 0, digitsy = 0;
    while (x1 > 0){
        digits++;
        b = b * 10;
        x1 = x1 / 10;
    }
    b = b / 10;
    while (y1 > 0){
        digitsy++;
        y1 = y1 / 10;
    }
    
    b = x / b;
    long long c;
    cout << digits << ' ' << digitsy << endl;
    for (int m = digits; m <= digitsy; m++){
        for (int i = 0; i < 9; i++){
            for (int l = 0; l < 9; l++){
                for (int j = 0; j <= m - 2; j++){
                    c = a[i][l];
                    long long d = 100 * (i + 1);
                    for (int k = j; k < m - 2; k++){
                        c = c + d;
                        d = d * 10;
                    }
                    for (int k = 0; k < j; k++){
                        c = c * 10 + i + 1;
                    }
                    //cout << c << endl;
                    if ((c >= x) && (c <= y)){
                        cout << c << endl;
                        count++;
                    }
                }
                c = a[i][l];
                int e = a[i][l] % 10;
                for (int k = 0; k < m - 2; k++){
                    c = c * 10 + e;
                }
                if ((c >= x) && (c <= y)){
                    cout << c << endl;
                    count++;
                }
            }
        }
    }
    fout << count << endl;
    return 0;
}
//100 10000000000000000
