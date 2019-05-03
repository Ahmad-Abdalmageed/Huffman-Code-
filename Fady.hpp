//
// Created by ahmadmageed on 5/2/19.
//
#include <fstream>
#include <iostream>
#include <string>
#ifndef PROJECT_FADY_HPP
#define PROJECT_FADY_HPP
namespace file_read {
    void readLegalWords();
{
    std::vector<std::string> wordsArray;
    std::ifstream file;
    file.open ("/home/fady/sbe201-2019-final-project-sbe201-2021-team06/carl_sagan.txt");
    if (!file) {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
int index = 0; //counter
while (std::getline(file, wordsArray[index]))
{
file>>wordsArray[index];
std::cout << wordsArray[index];
index++;
file.close(); 
}
}
#endif //PROJECT_FADY_HPP
