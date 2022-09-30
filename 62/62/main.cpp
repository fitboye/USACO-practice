//
//  main.cpp
//  62
//
//  Created by Jerry Cheng on 7/25/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct point{
    int loc;
    int type;
};

bool compare (point a, point b){
    if (a.loc == b.loc){
        return a.type > b.type;
    }else{
        return a.loc < b.loc;
    }
}

int main() {
    int n;
    cin >> n;
    point a[100000];
    for (int i = 0; i < n * 2; i++){
        int b;
        cin >> b;
        a[i].loc = b;
        a[i].type = i % 2;
    }
    sort(a, a + n * 2, compare);
    
    int firsta = -1, lastb = -1, segmentcount = 0, ans3 = 0, ans4 = 0;
    string ans1 = "no";
    for (int i = 0; i < n * 2; i++){
        if (a[i].type == 0){
            if (firsta == -1){
                firsta = a[i].loc;
            }
            segmentcount++;
        }else{
            lastb = a[i].loc;
            segmentcount--;
        }
        
        if (segmentcount >= 2){
            ans1 = "yes";
        }
        if (segmentcount == n){
            ans3 = a[i+1].loc - a[i].loc;
        }
        if (segmentcount >= 1){
            ans4 = ans4 + a[i+1].loc - a[i].loc;
        }
    }
    
    cout << ans1 << endl;
    cout << lastb - firsta << endl;
    cout << ans3 << endl;
    cout << ans4 << endl;
    return 0;
}
/*
5
1 10
2 10
3 10
4 10
5 10




*/

