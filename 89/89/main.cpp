//
//  main.cpp
//  89
//
//  Created by Jerry Cheng on 2/6/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct point{
    int pos, type;
};

bool c(point a, point b){
    return a.pos < b.pos;
}

int main() {
    int n;
    cin >> n;
    vector<point> a;
    for (int i = 0; i < n; i++){
        point x, y;
        x.type = 1;
        y.type = -1;
        cin >> x.pos >> y.pos;
        a.push_back(x);
        a.push_back(y);
    }
    sort(a.begin(), a.end(), c);
    
    int layers = 0, ans = 0, maxlayers = -1;
    for (int i = 0; i < a.size(); i++){
        int j = i;
        while (a[i].pos == a[j].pos){
            layers += a[j].type;
            j++;
        }
        //last = a[i].pos;
        i = j - 1;
        if (layers > maxlayers){
            ans = 0;
            maxlayers = layers;
        }
        if (layers == maxlayers){
            ans = ans + a[i + 1].pos - a[i].pos;
            //cout << ans << endl;
        }
    }
    cout << maxlayers << ' ' << ans << endl;
    return 0;
}
/*
 5
 1 5
 3 6
 5 7
 2 4
 5 9
 
 3
 2
*/
