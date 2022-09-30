//
//  main.cpp
//  Marathon
//
//  Created by Jerry Cheng on 8/4/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
    int n, a[100000], b[100000], totaldistance = 0, distance = 0, smallestdistance = 1000000000;
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i];
    }
    for (int i = 0; i < n - 1; i++){
        if (a[i] > a[i + 1]){
            totaldistance = totaldistance + a[i] - a[i + 1];
        }else{
            totaldistance = totaldistance + a[i + 1] - a[i];
        }
        //fout << 'a' << totaldistance << endl;
        
        if (b[i] > b[i + 1]){
            totaldistance = totaldistance + b[i] - b[i + 1];
        }else{
            totaldistance = totaldistance + b[i + 1] - b[i];
        }
        //fout << totaldistance << endl;
    }
    
    for (int i = 1; i < n - 1; i++){
        distance = 0;
        if (a[i] > a[i - 1]){
            distance = distance - (a[i] - a[i - 1]);
        }else{
            distance = distance - (a[i - 1] - a[i]);
        }
        if (b[i] > b[i - 1]){
            distance = distance - (b[i] - b[i - 1]);
        }else{
            distance = distance - (b[i - 1] - b[i]);
        }
        if (a[i] > a[i + 1]){
            distance = distance - (a[i] - a[i + 1]);
        }else{
            distance = distance - (a[i + 1] - a[i]);
        }
        if (b[i] > b[i + 1]){
            distance = distance - (b[i] - b[i + 1]);
        }else{
            distance = distance - (b[i + 1] - b[i]);
        }
        
        if (a[i - 1] > a[i + 1]){
            distance = distance + (a[i - 1] - a[i + 1]);
        }else{
            distance = distance + (a[i + 1] - a[i - 1]);
        }
        if (b[i - 1] > b[i + 1]){
            distance = distance + (b[i - 1] - b[i + 1]);
        }else{
            distance = distance + (b[i + 1] - b[i - 1]);
        }
        if (totaldistance + distance < smallestdistance){
            smallestdistance = totaldistance + distance;
        }
    }
    
    fout << smallestdistance << endl;
    return 0;
}
