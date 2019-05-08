# sbe201-2019-final-project-sbe201-2021-team06
# Huffman Coding
This is an app for compressing and decompressing text files 
## Team No.6

> **Member1:** *Ahmed Abd elmegid*
>
> **Member2:** *Rawan Sayed Badr*
>
> **Member3:** *Toaa Mahmoud Abd elHakim*
>
> **Member4:** *Fady Tadrous Mikheal*

## Abstract
Here we seek to make a compressing and decompressing applications using huffman code.

## Our Implementation 
* First we made a struct containing a text and its frequency in a certain file 
* we made a Tree of Huffman nodes with members 
    1. Frequency
    2. Code
    3.  Pointers left , right and top 
* It iterates over a certain input text file, count words frequency and compress the text file in another text file with just ones and zeros. 

## Difficulties
First,We faced problems in using fstream library since we have no experience with it, then implementing huffman heap tree and its functions, we ran also to some problems when saving the text file compressed and extracting the compressed data from the file in decompressing phase. 
