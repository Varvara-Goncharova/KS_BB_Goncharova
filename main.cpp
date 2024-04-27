#include "Parser.h"
#include "Solver.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    string input;
    string output;
    cin >> input >> output;
    ifstream fin(input.c_str());
    ofstream fout(output.c_str());
    BackPack back_pack;
    fin >> back_pack;
    auto answer = Solution(back_pack);
    fout << answer;
    fin.close();
    fout.close();
}