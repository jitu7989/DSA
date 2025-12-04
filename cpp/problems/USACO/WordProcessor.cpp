#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");

    int n,k;
    fin >> n >> k;

    string str;

    int temp = 0;
    for (int i = 0; i < n; i++) {
        fin >> str;
        temp += str.length();
        if (temp>k) {
            fout << '\n';
            temp = str.length();
        }
        if (temp!=str.length()) {
            fout << ' ';
        }
        fout << str;
    }


    return 0;
}