//
//  main.cpp
//  slowdown
//
//  Created by Jerry Cheng on 5/18/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("slowdown.in");
    ofstream fout("slowdown.out");
    int n;
    int times[10001], distances[10001], tcount = 0, dcount = 0;
    fin >> n;
    char a;
    for (int i = 0; i < n; i++){
        fin >> a;
        if (a == 'T'){
            fin >> times[tcount];
            tcount++;
        }else{
            fin >> distances[dcount];
            dcount++;
        }
    }
    distances[dcount] = 1000;
    dcount++;
    sort(distances, distances + dcount);
    sort(times, times + tcount);
    int t = 0, d = 0, speedm = 1;
    double distance = 0.0, time = 0.0;
    while ((d < dcount) && (t < tcount)){
            if (1.0 * (times[t] - time)/speedm + distance > distances[d]){
                time = time + 1.0 * (distances[d] - distance) * speedm;
                distance = distances[d];
                speedm++;
                d++;
            }else{
                distance = distance + 1.0 * (times[t] - time)/speedm;
                time = times[t];
                speedm++;
                t++;
            }
        cout << time << ' ' <<  distance << endl;
    }
    while (d < dcount){
        time = time + 1.0 * (distances[d] - distance) * speedm;
        distance = distances[d];
        speedm++;
        d++;
    }
    while (t < tcount){
        distance = distance + 1.0 * (times[t] - time)/speedm;
        time = times[t];
        speedm++;
        t++;
    }
    fout << int(time + 0.5) << endl;
    return 0;
}
/*
double time = 0;
for (int i = 0; i < 1000; i++){
    while ((distances[d] == i) && (d < dcount)){
        cout << 'd' << distances[d] << endl;
        speedm++;
        d++;
        }
        double c;
        while ((times[t] < time) && (t < tcount)){
            cout << times[t] << endl;
            time = time + 1.0/speedm * (time - times[t]);
            cout << 1.0/speedm * (time - times[t]) << endl;
            time = times[t];
            i--;
            speedm++;
            t++;
        }
        time = time + speedm;
        cout << time << ' ' << speedm << endl;
        }

3
T 991
T 996
T 1004
*/
