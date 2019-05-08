//
// Created by ahmadmageed on 5/2/19.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#ifndef PROJECT_FADY_HPP
#define PROJECT_FADY_HPP
namespace file_read
{
void readLegalWords(std::string filepath, std::vector<std::string> &wordsArray);

{
    std::ifstream file;
    file.open(filepath);
    if (!file)
    {
        std::cout << "Unable to open file datafile.txt";
        exit(1); // call system to stop
    }
    std::string str;
    int index = 0; //counter
    while (std::getline(file, str))
    {
        if (str.size() > 0)
            wordsArray.push_back(str);
        //std::getline(file, wordsArray[index]);
        //std::cout << wordsArray.front();
        index++;
    }
    file.close();
}
} // namespace file_read
std::string decode_Huffman_Data(MinHeapNode *root, string binaryCoded)
{
    std::string data_decoded = ""; //string for storing the decoded data we need
    MinHeapNode *current = root;
    std::ofstream out = ("data_decompressed.txt"); // for the  text file we will store in
    for (int i = 0; i < binaryCoded.size(); i++)   //iterate on the whole minheap
    {
        if (binaryCoded[i] == '0')
            current = current->left;
        else
            current = current->right;
        if (current->left == nullptr && current->right == nullptr) //reached leaf node
        {
            data_decoded += current->data;
            current = root;
        }
    }
    return data_decoded; // pass it to the function
    out << data_decoded; // store it in the file
    out.close();         // close it
}

#endif //PROJECT_FADY_HPP
