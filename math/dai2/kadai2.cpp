#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <random>

std::vector<char> text;              //テキストファイルの文字列格納
std::ofstream ofs("./textout1.txt"); //出力ファイル
std::vector<char> alfa;              //アルファベット小文字格納
std::vector<char> ALFA;              //アルファベット大文字格納
std::vector<int> alfa1(100, 0);      //頻出頻度の格納
void alfa_init();
void num();
void display();
int space = 0;
std::random_device rnd;

int main()
{
    char ch;   //テキスト文字
    int i = 0; //格納回数
    const char *fileName = "./txt1.txt";
    std::ifstream ifs(fileName);
    alfa_init();
    if (!ifs)
        std::cout << "ファイルオープンに失敗" << std::endl;
    else
        std::cout << "ファイルオープン" << std::endl;

    while (ifs.get(ch))
        text.push_back(ch);
    num();
    display();

    return 0;
}

void alfa_init()
{
    for (int i = 0; i < 26; i++)
    {
        alfa.push_back('a' + i);
        ALFA.push_back('A' + i);
    }
}
void num()
{
    for (int i = 0; i < text.size(); i++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (alfa[n] == text[i] || ALFA[n] == text[i])
                alfa1[n]++;
        }
        if (text[i] == 0x20)
            space++;
    }
}

void display()
{
    for (int i = 0; i < alfa1.size(); i++)
    {
        if (alfa1[i] != 0)
            std::cout << alfa[i] << " " << alfa1[i] << std::endl;
    }
    std::cout << "space" << space << std::endl;
}
