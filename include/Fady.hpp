//
// Created by ahmadmageed on 5/2/19.
//
#ifndef PROJECT_FADY_HPP
#define PROJECT_FADY_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Ahmad.hpp"

namespace file_read
{
void readLegalWords(std::string filePath, std::vector<std::string> &V)
{
    std::ifstream file;
    file.open(filePath);

    if (!file)
    {
        std::cout << "Unable to open file datafile.txt";
        exit(1); // call system to stop
    }

    std::string str;

    while (std::getline(file, str, ' '))
    {
        if (str.size() > 0)
            V.push_back(str);
    }
    file.close();
}

} // namespace file_read

namespace file_decode
{
std::string binary_code(std::string compressedfile)
{
    std::string stored;
    std::string str;
    std::ifstream file;
    file.open(compressedfile);
    if (!file)
    {
        std::cout << "Unable to open file datafile.txt";
        exit(1); // call system to stop
    }
    else
    {
        while (std::getline(file, str))
        {
            if (str.size() > 0)
                stored += str;

            return stored;
        }
    }
    file.close();
}
void decode_Huffman_Data(Huffman::HuffNode *root, std::string compressedfile)
{
    std::string binaryCoded = binary_code(compressedfile);
    std::string data_decoded; //string for storing the decoded data we need

    Huffman::HuffNode *current = root;
    std::ofstream out("data_decompressed.txt"); // for the  text file we will store in

    for (int i = 0; i < binaryCoded.size(); i++) //iterate on the whole minheap
    {
        if (binaryCoded[i] == '0')
            current = current->left;
        else
            current = current->right;
        if (current->left == nullptr && current->right == nullptr) //reached leaf node
        {
            data_decoded += current->W.word + " ";
            current = root;
        }
    }
    out << data_decoded; // store it in the file
    out.close();         // close it
}

} // namespace file_decode

#endif //PROJECT_FADY_HPP
