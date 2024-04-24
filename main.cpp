#include <iostream>
#include <fstream>
#include <vector>

#include "Bug.h"

void bugMain();

using namespace std;


int main() {
    srand (time(NULL));
    return 0;
}

void bugMain(){
    vector<Bug*> bug_vector;
    ifstream fin("bugs.txt");
    if(fin)
    {
        while(!fin.eof()) {

        }
        fin.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }
}