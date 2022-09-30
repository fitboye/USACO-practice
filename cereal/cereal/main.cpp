//
//  main.cpp
//  cereal
//
//  Created by Jerry Cheng on 3/29/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

bool compare(int a, int b){
    return a < b;
}

int main() {
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");
    int n, m;
    cin >> n >> m;
    int f[100000], s[100000];
    priority_queue<int, vector<int>, greater<int>> a[100001];
    for (int i = 0; i < n; i++){
        cin >> f[i] >> s[i];
        a[f[i]].push(i);
        a[s[i]].push(i);
    }
    int num = 0, cows[100000];
    for (int i = 0; i < n; i++){
        cows[i] = -1;
    }
    for (int i = 1; i <= m; i++){
        while (cows[a[i].top()] != -1 && i == s[a[i].top()]){
            a[i].pop();
        }
        if (cows[a[i].top()] != f[a[i].top()]){
            cows[a[i].top()] = i;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (cows[i] != -1){
            num++;
        }
    }
    cout << num << endl;
    
    
    for (int i = 0; i < n; i++){
        a[f[i]].pop();
        while(a[f[i]].size() > 0){
            if (a[f[i]].top() == )
        }
    }
    return 0;
}

/*
 5 3
 1 2
 1 2
 2 3
 3 1
 1 2
 
 0 1 3 4
 0 1 2 4
 2 3
 
 
 for (int j = 1; j <= m; j++){
 cout << a[j].top() << ' ';
 }
 cout << endl;
 cout << num << endl;
 cows[i] = -1;
 a[f[i]].pop();
 if (a[f[i]].size() == 0){
 num--;
 }
 if (i < n - 1){
 a[s[i + 1]].pop();
 //next secondary cereal type == secondary cereal type of the top cow
 while (s[i + 1] == s[a[s[i + 1]].top()] && a[s[i + 1]].size() > 0){
 cout << 'a' << s[i + 1] << endl;
 a[s[i + 1]].pop();
 }
 if (a[s[i + 1]].top() == f[a[s[i + 1]].top()]){
 int x;
 x = s[a[s[i + 1]].top()];
 while (x == s[a[x].top()] && a[x].size() > 0){
 cout << 'b' << s[x] << endl;
 a[x].pop();
 }
 }
 if (a[s[i + 1]].size() == 0){
 num--;
 }
 }
 cout << 'c' << endl;
*/
