//
//  main.cpp
//  83
//
//  Created by Jerry Cheng on 1/9/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct bag{
    int a, b;
    long long c;
};

bool compare (bag a, bag b){
    return a.c > b.c;
}

int main() {
    int n;
    bag a[100000];
    cin >> n;
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i].a >> a[i].b;
        a[i].c = 1ll * 2 * a[i].a + a[i].b;
        total = total - a[i].a;
    }
    sort(a, a + n, compare);
    
    int i = 0;
    while (total <= 0){
        total = total + a[i].c;
        i++;
    }
    cout << i << endl;
    return 0;
}
