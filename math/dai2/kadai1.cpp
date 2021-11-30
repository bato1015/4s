#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <stdio.h>

std::vector<char> text;             //テキストファイルの文字列格納
std::ofstream ofs("./textout.txt"); //出力ファイル
void juging();
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

    juging();
    return 0;
}
void juging()
{
    int n = 0;
    // for (int i = 0; i < text.size(); i++)
    for (int i = 0; n <10; i++)
    {

        if (isalpha(text[i]))
            ofs << text[i];
        else if (text[i] == 0x10)
            ofs << ' ';
        else if (text[i] == '\n')
        {
            ofs << '\n';
            n++;
        }
        else
            ofs << ' ';
    }
}
