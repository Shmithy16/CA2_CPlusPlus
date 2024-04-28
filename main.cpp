#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Spinner.h"

void bugMain();
void displayVector();

using namespace std;


int main() {
    srand (time(NULL));
    bugMain();
    return 0;
}

int strToInt(string str) {
    // https://cplusplus.com/reference/string/stoi/
    return stoi(str);
}

void bugMain(){
    vector<Bug*> bug_vector;
    string line;
    string delimiter = ";";
    ifstream fin("bugs.txt");
    if(fin)
    {
        while(!fin.eof()) {
            getline(fin,line);
            if(line.length() > 0) {
                string type = line.substr(0,1);
                line = line.substr(2);

                string str = line.substr(0,line.find(";"));
                int id = strToInt(str);

                line = line.substr(line.find(";")+1, line.length());
                str = line.substr(0,line.find(delimiter));
                int x = strToInt(str);

                line = line.substr(line.find(";")+1, line.length());
                str = line.substr(0,line.find(delimiter));
                int y = strToInt(str);

                line = line.substr(line.find(";")+1, line.length());
                str = line.substr(0,line.find(delimiter));
                int dir = strToInt(str);

                line = line.substr(line.find(";")+1, line.length());
                str = line.substr(0,line.find(delimiter));
                int size = strToInt(str);

                if(type == "C"){
                   // bug_vector.push_back(new Crawler(id,x,y,dir,size));
                   Crawler *cr = new Crawler(id, x, y, dir, size);
                    cr->display();
                    bug_vector.push_back(cr);
                }
                else if(type == "H") {
                    line = line.substr(line.find(";")+1, line.length());
                    str = line.substr(0,line.find(delimiter));
                    int hopL = strToInt(str);

                    // bug_vector.push_back(new Hopper(hopL,id,x,y,dir,size));
                    Hopper *hp = new Hopper(hopL, id, x, y, dir, size);
                    hp->display();
                    bug_vector.push_back(hp);
                }else if(type == "S") {
                    Spinner *sp = new Spinner(id,x,y,dir,size);
                    sp->display();
                    bug_vector.push_back(sp);
                }
            }
        }
        int input;
            cout << "Input a number for an id: " << endl;
            cin >> input;
        vector<Bug*>::iterator it;
        for (it = bug_vector.begin(); it != bug_vector.end(); it++) {
            if((*it)->getId() == input) {
                (*it)->display();
            }
        }

        bool menu = true;
        string tap;
        while(menu) {
            cout << "Tap Board? " << endl;
            cin >> tap;
            if(tap == "yes" or tap == "Yes") {
                for (it = bug_vector.begin(); it != bug_vector.end(); it++) {
                    (*it)->move();
                }
            }else if(tap == "no" or tap == "No") {
                menu = false;
                for (it = bug_vector.begin(); it != bug_vector.end(); it++) {
                    (*it)->display();
                }
            }else {
                cout << "Invalid command" << endl;
            }
        }

        for (it = bug_vector.begin(); it != bug_vector.end(); it++) {
            list<pair<int,int>> path = (*it)->getPath();
            //https://stackoverflow.com/questions/50313906/can-elegant-way-to-print-all-pairs-in-a-list
            for ( const auto& token : path )
                cout << "(" <<token.first << "," << token.second << ") ";
                (*it)->display();
        }

        fin.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    ofstream fout("bugs_life_history_date_time.out.txt");
    if(fout)
    {
        vector<Bug*>::iterator it;
        for (it = bug_vector.begin(); it != bug_vector.end(); it++) {
            list<pair<int,int>> path = (*it)->getPath();
            for ( const auto& token : path )
                fout << "(" <<token.first << "," << token.second << ") ";
        }
        fout.close();
    }
    else
    {
        cout << "Unable to open file." <<endl;
    }
}