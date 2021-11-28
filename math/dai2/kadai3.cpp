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
void select();
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
    select();

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
void select()
{
    std::vector<char> select_text;
    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
            select_text.push_back(text[i]);
        else if (text[i] == 0x10)
            select_text.push_back(' ');
        else if (text[i] == '\n')
            select_text.push_back('\n');
        else
            select_text.push_back(' ');
    }
    for (int i = 0; i < 100; i++)
        ofs << select_text[rnd() % select_text.size()];
}
