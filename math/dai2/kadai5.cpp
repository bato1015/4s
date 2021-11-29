#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <random>

std::vector<char> text;              //テキストファイルの文字列格納
std::ofstream ofs("./textout1.txt"); //出力ファイル
std::vector<char> select_text;       //条件似合ったテキストの格納
void select();
std::random_device rnd;

int main()
{
    char ch;   //テキスト文字
    int i = 0; //格納回数
    const char *fileName = "./txt1.txt";
    std::ifstream ifs(fileName);
    if (!ifs)
        std::cout << "ファイルオープンに失敗" << std::endl;
    else
        std::cout << "ファイルオープン" << std::endl;

    while (ifs.get(ch))
        text.push_back(ch);
    select();

    return 0;
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
    {
        int a, b;
        a = rnd() % select_text.size();
        b = a + 1;
        ofs << select_text[a] << select_text[a + 1];
        for (int n = a; n < select_text.size(); n++)
        {
            if (select_text[a] == select_text[i])
            {
                ofs << select_text[i + 1];
                break;
            }
        }
    }
}
