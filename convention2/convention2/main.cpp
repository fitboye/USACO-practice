//
//  main.cpp
//  convention2
//
//  Created by Jerry Cheng on 1/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

struct cow{
    int a, t, s;
    
    bool operator<(const cow & other) const{
        return s > other.s;
    }
};

bool comp(cow a, cow b){
    return a.a < b.a;
}

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int n;
    fin >> n;
    cow a[100000];
    for (int i = 0; i < n; i++){
        fin >> a[i].a >> a[i].t;
        a[i].s = i;
    }
    sort(a, a + n, comp);
    
    priority_queue<cow> b;
    int time = 0, ans = 0;
    for (int i = 0; i < n;){
        if (b.size() == 0){
            b.push(a[i]);
            time = a[i].a;
            i++;
        }else{
            int eatingtime = b.top().t;
            b.pop();
            while ((time + eatingtime > a[i].a) && (i < n)){
                b.push(a[i]);
                i++;
            }
            time = time + eatingtime;
            if (b.size() != 0){
                if (time - b.top().a > ans){
                    ans = time - b.top().a;
                }
            }
        }
    }
    fout << ans << endl;
    return 0;
}
