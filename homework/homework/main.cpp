//
//  main.cpp
//  homework
//
//  Created by Jerry Cheng on 10/13/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    int n, a[100000], smallest, sum, counter;
    double averages[99999];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    if (a[n - 1] > a[n - 2]){
        smallest = a[n - 2];
        sum = a[n - 1];
    }else{
        smallest = a[n - 1];
        sum = a[n - 2];
    }
    averages[n - 2] = sum;
    counter = 1;
    for (int i = n - 3; i >= 0; i--){
        if (a[i] < smallest){
            sum = sum + smallest;
            smallest = a[i];
        }else{
            sum = sum + a[i];
        }
        counter++;
        averages[i] = double(sum) / counter;
        //cout << averages[i] << endl;
    }
    
    double largest = -1;
    for (int i = 1; i < n - 1; i++){
        if (averages[i] > largest){
            largest = averages[i];
        }
    }
    
    for (int i = 1; i < n - 1; i++){
        //cout << 'a' << averages[i] << endl;
        if (averages[i] == largest){
            fout << i << endl;
        }
    }
    return 0;
}


/*
 6
 9 7 5 8 6 4
*/
