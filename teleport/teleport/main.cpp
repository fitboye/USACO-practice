//
//  main.cpp
//  teleport
//
//  Created by Jerry Cheng on 2/24/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("teleport.in");
    ofstream fout ("teleport.out");
    int a, b, c = 0, x, y, z = 1000000000;
    fin >> a >> b >> x >> y;
    
    //no teleporter used
    if (a > b){
        c = a - b;
    }else if (a < b){
        c = b - a;
    }else{
        c = 0;
    }
    if (c < z){
        z = c;
    }
    c = 0;
    
    //go from a - x then y - b
    if (a < x){
        if (b < y){
            c = (x - a) + (y - b);
        }else if (b > y){
            c = (x - a) + (b - y);
        }else{
            c = (x - a);
        }
    }else if (a > x){
        if (b < y){
            c = (a - x) + (y - b);
        }else if (b > y){
            c = (a - x) + (b - y);
        }else{
            c = (a - x);
        }
    }else{
        if (b < y){
            c = (y - b);
        }else if (b > y){
            c = (b - y);
        }else{
            c = 0;
        }
    }
    if (c < z){
        z = c;
    }
    c = 0;
    
    // go from a - y then x - b;
    if (a < y){
        if (b < x){
            c = (y - a) + (x - b);
        }else if (b > x){
            c = (y - a) + (b - x);
        }else{
            c = (y - a);
        }
    }else if (a > y){
        if (b < x){
            c = (a - y) + (x - b);
        }else if (b > x){
            c = (a - y) + (b - x);
        }else{
            c = (a - y);
        }
    }else{
        if (b < x){
            c = (x - b);
        }else if (b > x){
            c = (b - x);
        }else{
            c = 0;
        }
    }
    if (c < z){
        z = c;
    }
    
    fout << z << endl;
    return 0;
}













