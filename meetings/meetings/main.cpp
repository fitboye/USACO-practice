//
//  main.cpp
//  meetings
//
//  Created by Jerry Cheng on 12/16/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct cow{
    int w, x, d, dbarn, collisions;
};

bool compare(cow a, cow b){
    return a.x < b.x;
}

bool c(cow a, cow b){
    return a.dbarn < b.dbarn;
}

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    int n, l;
    fin >> n >> l;
    cow a[50000];
    cow byx[50000];
    long long totweight = 0;
    for (int i = 0; i < n; i++){
        fin >> a[i].w >> a[i].x >> a[i].d;
        //cout << a[i].w << ' ' << a[i].x << ' ' << a[i].d << endl;
        totweight = totweight + a[i].w;
        if (a[i].d == -1){
            a[i].dbarn = a[i].x;
        }else{
            a[i].dbarn = l - a[i].x;
        }
        byx[i] = a[i];
    }
    sort(a, a + n, c);
    sort(byx, byx + n, compare);
    
    
    cout << totweight << endl;
    int time = 0, left = 0, right = n - 1;
    long long weight = 0;
    for (int i = 0; i < n; i++){
        //cout << a[i].w << ' ' << a[i].x << ' ' << a[i].d << ' ' << a[i].dbarn << endl;
        time = a[i].dbarn;
        if (a[i].d == -1){
            weight = weight + a[left].w;
            cout << a[left].w << endl;
            left++;
        }else{
            weight = weight + a[right].w;
            cout << a[right].w << endl;
            right--;
        }
        //cout << weight << endl;
        if (weight * 2 >= totweight){
            break;
        }
    }
    cout << time << endl;
    //time = 134847429;
    
    sort(a, a + n, compare);
    int ans = 0, count;
    for (int i = 0; i < n; i++){
        count = 0;
        //cout << a[i].w << ' ' << a[i].x << ' ' << a[i].d << ' ' << a[i].dbarn << endl;
        if (a[i].d == 1){
            for (int j = i; (j < n) && (a[i].x + time * 2 >= a[j].x); j++){
                if (a[j].d == -1){
                    ans++;
                    count++;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
