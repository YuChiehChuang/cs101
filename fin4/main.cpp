#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class freqFile {
    private:
        string filename;
        int alphfreq[26] = {0};
        char check;
    public:
        freqFile(string name) {
            filename = name;
        }
    void readFile() {
        ifstream read;
        read.open(filename);
        while (!read.eof()) {
            read.get(check);
            if (check >= 'A' && check <= 'Z')
                check = check + ('a' - 'A');
            if (check >= 'a' && check <= 'z')
                alphfreq[check-'a']++;
        }
        read.close();
    }
    void showFreq() {
        check = 'a';
        for (int i = 0; i < 26; i++) {
            cout << '[' << check << "] = " << alphfreq[i] << endl;
            check++;
        }
        check = '\0';
    }
};

int main() {
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();
}
