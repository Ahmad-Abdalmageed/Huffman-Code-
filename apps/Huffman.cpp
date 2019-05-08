#include <iostream>
#include "Fady.hpp"
#include <string>
#include "Ahmad.hpp"
#include <algorithm>
#include <fstream>


//Application function that takes a text file from arguments and compress it

int main(int argc , char ** argv)
{
    // Input
    std::vector<std::string> V ;

    file_read::readLegalWords(argv[1], V) ;

    // Turn to Word Count
    WordTree::Wordvector v ;

    v.create(V);

    for (int i =0 ; i < v.buffer.size() ; ++i )
    {
        std::cout << v.buffer[i].word << ":" << v.buffer[i].number << "\n" ;
    }

    //Compression
    Huffman::HuffmanTree Tree ;

    Tree.Make(v ,V) ;

/*
    if ( argc == 2 )
    {
        //Decompression
        std::vector<std::string> compressed ;
        file_read::readLegalWords(argv[2] ,compressed ) ;

        file_decode::decode_Huffman_Data(Tree.buffer.front() ,) ;
    }
*/
}