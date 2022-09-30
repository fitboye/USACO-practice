//
//  main.cpp
//  14
//
//  Created by Jerry Cheng on 8/4/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    string a;
    int x, y, flag = 0;
    getline(cin, a);
    x = 0;
    y = a.length() - 1;
    while (x < y - 1){
        if ((((47 < int(a[x])) && (int(a[x]) < 58)) || ((64 < int(a[x])) && (int(a[x]) < 91))) || ((96 < int(a[x])) && (int(a[x]) < 123))){
            if ((((47 < int(a[y])) && (int(a[y]) < 58)) || ((64 < int(a[y])) && (int(a[y]) < 91))) || ((96 < int(a[y])) && (int(a[y]) < 123))){
                if (a[x] != a[y]){
                    if (int(a[x]) > 96){
                        if ((a[y] != a[x]) && (a[y] != a[x] - 32)){
                            //cout << a[x] << ' ' << a[y] << ' ' << x << ' ' << y << endl;
                            cout << "No" << endl;
                            flag = 1;
                            break;
                        }
                    }else{
                        if ((a[y] != a[x]) && (a[y] != a[x] + 32)){
                            //cout << a[x] << ' ' << a[y] << ' ' << x << ' ' << y << endl;
                            cout << "No" << endl;
                            flag = 1;
                            break;
                        }
                    }
                }
                x++;
                y = y - 1;
            }else{
                y = y - 1;
            }
        }else{
            x++;
        }
    }
    
    if (flag == 0){
        cout << "Yes" << endl;
    }
    return 0;
}
