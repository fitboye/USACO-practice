//
//  main.cpp
//  68
//
//  Created by Jerry Cheng on 10/17/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int distance[100];
    for (int i = 0; i < n; i++){
        distance[i] = -1;
    }
    queue<int> locations;
    distance[x] = 0;
    locations.push(x);
    while (locations.size() > 0){
        int current = locations.front();
        
        int newloc = current + a[current];
        if (newloc >= 0 && newloc < n && distance[newloc] == -1){
            locations.push(newloc);
            distance[newloc] = distance[current] + 1;
        }
        newloc = current - a[current];
        if (newloc >= 0 && newloc < n && distance[newloc] == -1){
            locations.push(newloc);
            distance[newloc] = distance[current] + 1;
        }
        locations.pop();
    }
    /*
    for (int i = 0; i < n; i++){
        cout << distance[i] << ' ';
    }
    cout << endl;
     */
    cout << distance[y] << endl;
    return 0;
}
