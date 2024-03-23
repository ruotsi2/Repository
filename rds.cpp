#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
    char* buffer;
    char current, past;
    string path_to_file, path_to_new_file;

    cout << "Enter the path to the file to be corrected:";
    cin >> path_to_file;
    cout << "Enter the path to new file:";
    cin >> path_to_new_file;
    buffer = new char;
    ifstream infile(path_to_file, ios::binary);
    ofstream outfile(path_to_new_file, ios::binary);
    if (infile.is_open()) {
        if (outfile.is_open()) {
            infile.read(buffer, sizeof(char));
            while (!infile.eof()) {
                current = *buffer;
                if (current != past) {
                    past = *buffer;
                    outfile.write(buffer, sizeof(char));
                }
                infile.read(buffer, sizeof(char));
            }delete buffer;
            cout << "File corrected sucessfully";
            return 0;
        }else cout << "Can`t create or open the new file";
        return 1;
    }else cout << "Can`t open the file to be corrected";
    return 2;
}