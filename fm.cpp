#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    for (char c : str) {
        if (c == delimiter) {                                                                                                  tokens.push_back(token);
            token = "";
        } else {
            token += c;
        }
    }
    tokens.push_back(token);                                                                                           return tokens;
}

int main(int argc, char* argv[]) {
        // argv[i];
        int p = 0;
        string line;
        ifstream myfile(argv[1]);

        if (myfile.is_open()) {
        while (getline(myfile, line)) {
            // Split text
                vector<string> ln1 = split(line, ' ');
                for (const auto& element : ln1) {
                        if (p==0){
                                if (element == "-print")
                                {
                                        p=1;
                                }
                        }
                        else if (p==1)
                        {
                                if (element == ";")
                                {
                                        p=0;
                                        cout << endl;
                                }
                                else if (element == ";;")
                                {
                                        p = 0;
                                }
                                else
                                {
                                        cout << element << " ";
                                }
                        }

                }
        }
        myfile.close();
        } else {
        cout << "Unable to open file" << endl;
        }


        return 0;
}