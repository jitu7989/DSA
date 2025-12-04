#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin("promote.in");
    std::ofstream fout("promote.out");

    long long bronze_before, bronze_after;
    long long silver_before, silver_after;
    long long gold_before, gold_after;
    long long platinum_before, platinum_after;

    fin >> bronze_before >> bronze_after;
    fin >> silver_before >> silver_after;
    fin >> gold_before >> gold_after;
    fin >> platinum_before >> platinum_after;

    long long gold_to_platinum = platinum_after - platinum_before;

    long long silver_to_gold = (gold_after - gold_before) + gold_to_platinum;

    long long bronze_to_silver = (silver_after - silver_before) + silver_to_gold;

    fout << bronze_to_silver << std::endl;
    fout << silver_to_gold << std::endl;
    fout << gold_to_platinum << std::endl;

    return 0;
}