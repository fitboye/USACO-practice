//
//  main.cpp
//  stuck in a rut
//
//  Created by Jerry Cheng on 12/21/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cow{
    int x, y, og;
    bool stopped;
};

bool nc (cow a, cow b){
    return a.x < b.x;
}
bool ec (cow a, cow b){
    return a.y < b.y;
}

vector<int> a[1001];
int ans[1001];

int search (int current){
    if (ans[current] != -1){
        return ans[current];
    }
    
    ans[current]++;
    for (int i = 0; i < a[current].size(); i++){
        ans[current] = ans[current] + 1 + search(a[current][i]);
    }
    return ans[current];
}

int main() {
    int n;
    cin >> n;
    vector<cow> north;
    vector<cow> east;
    for (int i = 0; i < n; i++){
        cow x;
        char d;
        cin >> d >> x.x >> x.y;
        x.og = i + 1;
        x.stopped = false;
        if (d == 'N'){
            north.push_back(x);
        }else{
            east.push_back(x);
        }
    }
    sort(north.begin(), north.end(), nc);
    sort(east.begin(), east.end(), ec);
    
    for (int i = 0; i < north.size(); i++){
        for (int j = 0; j < east.size(); j++){
            if (north[i].x > east[j].x && north[i].y < east[j].y && !east[j].stopped){
                //cout << north[i].og << ' ' << east[j].og << endl;
                if (east[j].y - north[i].y < north[i].x - east[j].x){
                    east[j].stopped = true;
                    a[north[i].og].push_back(east[j].og);
                }else if (east[j].y - north[i].y > north[i].x - east[j].x){
                    north[i].stopped = true;
                    a[east[j].og].push_back(north[i].og);
                    break;
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++){
        cout << 'i' << i << ' ';
        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
     */
    
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    for (int i = 1; i <= n; i++){
        cout << search(i) << endl;
    }
    return 0;
}
