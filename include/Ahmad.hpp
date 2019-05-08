//
// Created by ahmadmageed on 5/1/19.
//

#ifndef SBE201_2019_FINAL_PROJECT_SBE201_2021_TEAM06_AHMAD_HPP
#define SBE201_2019_FINAL_PROJECT_SBE201_2021_TEAM06_AHMAD_HPP


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include <fstream>

//This is a Namespace contains the struct that stores a word and its frequency
// and a struct of a vector of this struct which contains all methods used to
//make a set wordCounts of words and their frequencies

namespace WordTree
{
    struct wordCount
    {
        std::string word  ;
        int number ;

        wordCount()
        {
            word = '\0';
            number = 0 ;
        }
        wordCount(std::string s , int i)
        {
            word = s;
            number = i ;
        }
    };


    struct Wordvector
    {
        std::vector<wordCount> buffer ;

        // A utility function that counts the frequecy of a word in a certain text file

        static int Counter (std::vector<std::string> v , std::string  word)
        {
            int count = 0 ;
            for (const auto & Word : v )
            {
                if (Word == word )
                {
                    ++ count ;
                }
            }
            return count ;
        }

        bool find (wordCount  W)
        {
            if (buffer.empty()) {return false ; }
            else
            {
                for (int i = 0 ; i < buffer.size() ; i++)
                {
                    if (buffer[i].word == W.word) {return true ; }
                }
                return false ;
            }
        }

        // The main function that creates a vector of wordCounts (words and their frequencies)
        void create (std::vector<std::string> V )
        {
            for (int i = 0 ; i < V.size()  ; ++i)
            {
                int count = Counter (V , V[i]) ;
                wordCount W = {V[i] , count } ;

                if (!find(W))
                {
                    buffer.push_back(W) ;
                }
            }
        }
    };
}

// This namespace contains all structs and methods used to make a huffman tree

namespace Huffman
{
    //The huffman tree Node structure
    // pointer to huffman node(left)|wordcount|Frequency| pointer to huffman node (right)|pointer to huffman node (top)
    //and the code to the word
    struct HuffNode
    {
        WordTree::wordCount W;
        HuffNode * left = nullptr;
        HuffNode * right = nullptr;
        HuffNode * top = nullptr;
        int F = 0  ;
        std::string code  ;
        HuffNode(WordTree::wordCount  w, HuffNode * l  , HuffNode * r , HuffNode * t , int freq , std::string V = "\0" )
        {
            W = w;
            left = l;
            right = r;
            top = t;
            F = freq;
            code = V ;
        }
    };

    //An operator struct that defines our minimum heap its function is to reutrn a min heap from make_heap function
    struct condition
    {
        bool operator() (const HuffNode * k, HuffNode  * j)
        {
            return k->F > j->F;
        }
    };

    //Main Structure of the tree

    struct HuffmanTree
    {
        std::vector<HuffNode*> buffer; // For storing the nodes
        std::ofstream myfile  ;       // For Output file


        void HEAP()
        {
            std::make_heap(buffer.begin(), buffer.end(), condition());
        }

        void POP ()
        {
            std::pop_heap(buffer.begin(), buffer.end(), condition());
            buffer.pop_back();
        }

        //THe main method that builds the tree

        HuffNode* build (WordTree::Wordvector V )
        {
            while (!V.buffer.empty())
            {
                //Creating huffman nodes from wordCounts

                HuffNode* N = new HuffNode (V.buffer.front(), nullptr, nullptr, nullptr, V.buffer.front().number );
                buffer.push_back(N);
                V.buffer.pop_back();
            }

            //Heaping the buffer
            HEAP();

            while (buffer.size()!=  1)
            {
                // Forming the tree of huffman nodes

                HuffNode *n1 = buffer.front();
                POP();
                HuffNode *n2 = buffer.front();
                POP() ;
                HuffNode *n = new HuffNode ( WordTree::wordCount(),n1 ,n2 ,nullptr,n1->F+n2->F );
                buffer.push_back(n) ;
            }
            return buffer.front() ;
        }

        bool ISleaf (HuffNode *M)
        {
            return M->left == nullptr && M->right == nullptr ;
        }

        //Recursive
        //This function finds a certain word in the Tree

        HuffNode* find (std::string Word ,  HuffNode* Root)
        {
            HuffNode*Current = Root ;
            if (Current != nullptr )
            {
                //if(W.number < Current->left->F) return find(W,Word,Current->left) ;

                if ( !ISleaf(Current))
                {
                    if (Current->left) return find(Word , Current->left) ;
                    if (Current->right) return find(Word , Current->right) ;
                }
                if (Current->W.word == Word && ISleaf(Current))
                {
                    return Current;
                }
            }
        }

        //RECURSIVE
        // This function generates the codes from the tree root

        void compress (std::vector<std::string> vec)
        {

            HuffNode * X = nullptr;
            HuffNode * Y = buffer.front() ;

            for ( int i = 0 ; i < vec.size() ; ++i)
            {
                X = find(vec[i],Y) ;
                if (X != nullptr) myfile << X->code << " ";
            }
        }



        //The function that generates the code to each word

        void Generate ( HuffNode * N, std::string  path="")
        {
            if (ISleaf(N))
            {
                std::cout << path << " " ;

                N->code = path ;
            }
            else {
                Generate(N->left , path+'0') ;
                Generate(N->right,path+'1') ;
            }
        }


        // Interface function of previous two funtions

        void Make (WordTree::Wordvector  V , std::vector<std::string> Y)
        {
            HuffNode * root =  build(V) ;

            myfile.open("Compressed.txt",std::fstream::out) ;
            Generate(root) ;
            compress(Y) ;
            myfile.close();
        }

    };
}







#endif //SBE201_2019_FINAL_PROJECT_SBE201_2021_TEAM06_AHMAD_HPP
