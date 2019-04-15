/***************************************************
 *                Lab # - Exercise #               *
 *                 TITLE OF PROGRAM                *
 *                                                 *
 *                 What program does               *
 *                                                 *
 *                Author: Kyle Bibeault            *
 *            Created on: April 11, 2019           *
 ***************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

void loadVector(vector<string> &, ifstream &, string);
void printVector(const vector<string> &);

int main() {

    ifstream        inFile;
    
    string          fileName;
    string          name;
    
    vector<string>  winners;
    vector<string>  teams;
    
    cout << "\n\n\n";
    
    cout << setw(10) << "" << "Enter Team File Name: ";
    getline(cin, name);
    
    
    
    loadVector(teams, inFile, name);
    printVector(teams);
    
    cout << "\n\n\n";
    
    loadVector(winners, inFile, "WorldSeriesWinners.txt");
    printVector(winners);
    
    return 0;
}


void loadVector(vector<string> &v, ifstream &in, string fileName) {
    
    string name;
    
    in.open(fileName.c_str());
    if (!in) {
        cout << setw(10) << "" << "Error - could not open file";
        exit(0);
    }
    
    while(getline(in, name) || !in.eof()) {
        name.erase(remove(name.begin(), name.end(), '\r'), name.end() );
        v.push_back(name);
    }
    in.close();
    
}

void printVector(const vector<string> &v) {
    int counter = 0;
    
    cout << setw(10) << "";
    
    for (size_t i = 0; i < v.size(); i++) {
        cout << setw(30) << left << v[i];
        counter++;
        if (counter == 3) {
            cout << endl;
            counter = 0;
            cout << setw(10) << "";
        }
    }
}
