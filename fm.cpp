#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unistd.h>
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
        int s = 0;
        int sl = 0;
        string line;
        string sy = "";
        ifstream myfile(argv[1]);

        if (myfile.is_open()) {
        while (getline(myfile, line)) {
            // Split text
                vector<string> ln1 = split(line, ' ');
                for (const auto& element : ln1) {
                                if (s==1)
                                {
                                        if (element == ";")
                                        {
                                                s=0;
                                                system(sy.c_str());                                                                                                sy="";                                                                                                     }
                                        else                                                                                                               {
                                        sy+=element+" ";
                                        }

                                }
                                if (sl==1)
                                {
                                        if (element == ";")
                                        {
                                                sl=0;
                                        }
                                        else
                                        {
                                        sleep(stoi(element));
                                        }
                                }
                        if (p==0)
                        {
                                if (element == "-print")
                                {                                                                                                                           p=1;                                                                                                       }
                                else if (element == "-exec")
                                {
                                        s=1;
                                }
                                else if (element == "-sleep")
                                {
                                        sl=1;
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
                                        cout.flush();

                                }
                                else
                                {
                                        if (element == "\\n")
                                        {
                                                cout << endl;
                                        }
                                        else
                                        {
                                        cout << element << " ";
                                        }
                                }
                        }
                }
        }
        myfile.close();
        } else {
        cout << "File not openable." << endl;
        }


        return 0;
}
