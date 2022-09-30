//
//  main.cpp
//  32
//
//  Created by Jerry Cheng on 9/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

struct ab{
    double ratio;
    int a, b;
};

bool compare(ab a, ab b){
    if (a.ratio == b.ratio){
        return a.b < b.b;
    }else{
        return a.ratio < b.ratio;
    }
}

int main() {
    int a, b, l;
    cin >> a >> b >> l;
    int length = 0;
    ab c[10000];
    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= l; j++){
            if (double(i) / double(j) >= double(a) / double(b)){
                c[length].ratio = double(i) / double(j);
                c[length].a = i;
                c[length].b = j;
                length++;
            }
        }
    }
    sort(c, c + length, compare);
    cout << c[0].a << ' ' << c[0].b << endl;
    return 0;
}
