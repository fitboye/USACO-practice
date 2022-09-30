//
//  main.cpp
//  cowdance
//
//  Created by Jerry Cheng on 2/15/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct compare{
    bool operator() (int a, int b){
        return a > b;
    }
};

int main() {
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    int n, t, a[10000];
    fin >> n >> t;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    int l = 0, r = n, mid = 0;
    while(r - l > 1){
        mid = (l + r)/2;
        int time = 0;
        priority_queue<int, vector<int>, compare> stage;
        for (int i = 0; i < mid; i++){
            stage.push(a[i]);
        }
        for (int i = mid; i < n; i++){
            time = stage.top() + a[i];
            stage.pop();
            stage.push(time);
        }
        for (int i = 0; i < mid; i++){
            time = stage.top();
            stage.pop();
        }
        //cout << mid << ' ' << time << endl;
        if (time <= t){
            r = mid;
        }else{
            l = mid;
        }
    }
    fout << r << endl;
    return 0;
}
