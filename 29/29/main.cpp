//
//  main.cpp
//  29
//
//  Created by Jerry Cheng on 9/28/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct p{
    int num, points, a;
};

bool compare(p a, p b){
    bool x;
    if (a.points == b.points){
        if (a.a != b.a){
            if (a.a > b.a){
                x = true;
            }else{
                x = false;
            }
        }else{
            if (a.num < b.num){
                x = true;
            }else{
                x = false;
            }
        }
    }else{
        if (a.points > b.points){
            x = true;
        }else{
            x = false;
        }
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    int a, b, c;
    p d[1000];
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        d[i].num = i + 1;
        d[i].points = a + b + c;
        d[i].a = a;
    }
    sort(d, d + n, compare);
    
    for (int i = 0; i < 5; i++){
        cout << d[i].num << ' ' << d[i].points << endl;
    }
    return 0;
}
