#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class myString {};

class hello {
    public:
    void hi() {
        cout << "Hello" << endl;
    }
};

class bbb {};

class readClass {
    public:
    string filename = "./main.cpp";
    void showclass() {
        ifstream target;
        target.open(filename);
        bool state = false;
        string word;
        vector<string> vec = {};
        while(!target.eof())  {
            target >> word;
            if (word == "class") {
                state = true;
                continue;
            }
            if (state) {
                vec.push_back("class " + word);
                state = false;
                continue;
            }
        }

        cout << "Found " << vec.size() << " classes in" + filename << endl;
        for (auto &line : vec) {
            cout << line << endl;
        }

        target.close();
    };
};

int main() {
    readClass rfile;
    rfile.showclass();
    return 0;
}