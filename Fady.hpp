//
// Created by ahmadmageed on 5/2/19.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#ifndef PROJECT_FADY_HPP
#define PROJECT_FADY_HPP
namespace file_read {
    void readLegalWords();
{
    td::vector<std::string> wordsArray;
    std::ifstream file;
    file.open ("/home/fady/sbe201-2019-final-project-sbe201-2021-team06/carl_sagan.txt");
    if (!file)
    {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
    }
std::string str;
int index = 0; //counter
while (std::getline(file, str))
    {
    if(str.size() > 0)
    wordsArray.push_back(str);
//std::getline(file, wordsArray[index]);
    std::cout << wordsArray.front();
    index++;
    file.close();
    }
}
#endif //PROJECT_FADY_HPP
