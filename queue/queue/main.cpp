//
//  main.cpp
//  queue
//
//  Created by Jerry Cheng on 9/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a[100], b[100], n, totaltime, time;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    totaltime = a[0];
    for (int i = 0; i < n; i++){
        //cout << totaltime << endl;
        if (totaltime - a[i] < 0){
            cout << 0 << endl;
            totaltime = a[i];
        }else{
            cout << totaltime - a[i] << endl;
        }
        totaltime = totaltime + b[i];
    }
    return 0;
}

/*
5
1 5
2 5
3 5
20 5
21 5
*/
