//
//  main.cpp
//  blist
//
//  Created by Jerry Cheng on 12/15/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int start[100], end[100], buckets[100], n;
    fin >> n;
    int totaltime = -1;
    for (int i = 0; i < n; i++){
        fin >> start[i] >> end[i] >> buckets[i];
        if (end[i] > totaltime){
            totaltime = end[i];
        }
    }
    
    int maximum = 0;
    for (int t = 0; t < totaltime; t++){
        int current = 0;
        for (int i = 0; i < n; i++){
            if ((start[i] <= t) && (end[i] >= t)){
                current = current + buckets[i];
            }
        }
        if (current > maximum){
            maximum = current;
        }
    }
    fout << maximum << endl;
    return 0;
}
