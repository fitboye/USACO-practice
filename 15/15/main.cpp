//
//  main.cpp
//  15
//
//  Created by Jerry Cheng on 9/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int b[100], length;
    string a;
    cin >> a;
    b[0] = a[0] - 48;
    length = 1;
    for (int i = 1; i < a.length(); i++){
        if ((length > 0) && ((a[i] == '1') && (b[length - 1] == 0))){
            length--;
        }else{
            b[length] = a[i] - 48;
            length++;
        }
    }
    
    //cout << length << endl;
    
    for (int i = 0; i < length; i++){
        cout << b[i] << endl;
    }
    return 0;
}


/*
0001111
*/
