#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "Bug.h"

void bugMain();

using namespace std;


int main() {
    srand (time(NULL));
    bugMain();
    return 0;
}

void bugMain(){
    vector<Bug*> bug_vector;
    string line;
    string delimiter = ";";
    ifstream fin("bugs.txt");
    if(fin)
    {
        while(!fin.eof()) {
            fin >> line;
            string type = line.substr(0,1);
            cout << type << endl;
            if(type == "C"){
                string id = line.substr(2,line.find(delimiter,2)-2);
                string x = line.substr(6,line.find(delimiter));
                string y = line.substr(8,line.find(delimiter));
                string dir = line.substr(10,line.find(delimiter));
                string size = line.substr(12,line.find(delimiter)+1);
                cout << size << endl;
            }

        }
        fin.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }
}