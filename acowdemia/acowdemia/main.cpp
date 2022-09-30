//
//  main.cpp
//  acowdemia
//
//  Created by Jerry Cheng on 4/5/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare (int a , int b){
    return a > b;
}

int main() {
    int n, k, l, c[100000];
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c, c + n, compare);
    
    int left = -1, right = n + 1, h;
    while (right - left > 1){
        int a[100000];
        for (int i = 0; i < n; i++){
            a[i] = c[i];
        }
        h = (left + right)/2;
        //cout << 'h' << h << endl;
        
        int start = 0;
        while (a[start] > h){
            start++;
        }
        int addon = 0, articles = 0;
        queue<int> expired;
        //cout << start << ' ' << start + l << endl;
        for (int i = start; i < start + l && i < n && i < h; i++){
            //cout << 'b' << endl;
            int newadd = h - (a[i] + addon);
            if (articles + newadd > k){
                newadd = k - articles;
            }
            articles+= newadd;
            expired.push(newadd);
            addon += newadd;
            a[i] += addon;
            
            for (int i = 0; i < n; i++){
                //cout << a[i] << ' ';
            }
            //cout << endl;
        }
        for (int i = start + l; i < n && i < h && expired.size() > 0; i++){
            addon -= expired.front();
            expired.pop();
            int newadd = h - (a[i] + addon);
            if (articles + newadd > k){
                newadd = k - articles;
            }
            articles+= newadd;
            expired.push(newadd);
            addon += newadd;
            a[i] += addon;
            
            for (int i = 0; i < n; i++){
                //cout << a[i] << ' ';
            }
            //cout << endl;
        }
        
        bool works = true;
        for (int i = 0; i < h; i++){
            if (a[i] < h){
                works = false;
                break;
            }
        }
        
        if (works){
            left = h;
        }else{
            right = h;
        }
    }
    
    cout << left << endl;
    return 0;
}
// 5, 7, 8, 10, 11, 12, 13, 16, 19, 20

/*
 6 0 0
 5 4 3 3 3 3
*/
