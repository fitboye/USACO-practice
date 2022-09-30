//
//  main.cpp
//  13
//
//  Created by Jerry Cheng on 8/4/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a[100], b[100], m, n, d = 0, e = 0, c[200], f = 0, g = -1;
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    for (int i = 0; i < n + m; i++){
        cout << d << ' ' << e << ' ' << a[d] << ' ' << b[e] << ' ' << i << endl;
        if ((d < m) && (e < n)){
            if (a[d] > b[e]){
                c[i] = b[e];
                if (e < n){
                    e++;
                }
            }else{
                c[i] = a[d];
                if (d < m){
                    d++;
                }
            }
            f = i;
            if (d >= m){
                g = 0;
                break;
            }else if (e >= n){
                g = 1;
                break;
            }
        }
    }
    
    cout << d << ' ' << e << ' ' << g << endl;
    for (int i = f + 1; i < n + m; i++){
        if (g == 0){
            c[i] = b[e];
            e++;
        }else{
            c[i] = a[d];
            d++;
        }
    }
        
    for (int i = 0; i < n + m; i++){
        cout << c[i] << endl;
    }
    return 0;
}

/*
 8 6
 1 1 2 3 5 8 13 21
 2 4 8 16 32 64
*/
