#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <random>
#include <string.h>
#include <algorithm>
#include <set>
std::vector<char> text;         //テキストファイルの文字列格納
std::vector<char> select_text;  //条件似合ったテキストの格納
std::vector<char> alfa;         //アルファベット小文字格納
std::vector<char> ALFA;         //アルファベット大文字格納
std::vector<int> alfa1(100, 0); //頻出頻度の格納
void alfa_init();
void num();
void display();
void select();
void collect_alfa();
int space = 0;
void sort_alfa(std::vector<std::string> *c);
std::random_device rnd;

int main()
{
    char ch;   //テキスト文字
    int i = 0; //格納回数
    const char *fileName = "./textout.txt";
    std::ifstream ifs(fileName);
    alfa_init();
    if (!ifs)
        std::cout << "ファイルオープンに失敗" << std::endl;
    else
        std::cout << "ファイルオープン" << std::endl;

    while (ifs.get(ch))
        text.push_back(ch);
    select();
    collect_alfa();

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
void collect_alfa()
{
    std::vector<std::string> text2;
    std::ofstream ofs("./textout2.txt"); //出力ファイル
    struct comb
    {
        std::string str;
        long value;
        bool operator<(const comb &rhs)
            const
        {
            if (str < rhs.str)
                return true;
            return false;
        }
        bool operator==(const comb &rhs)
        {
            if (str == rhs.str)
                return true;
            return false;
        }
    };
    std::vector<comb> count;
    /*2文字配列を作る*/
    for (int i = 0; i < select_text.size() - 1; i++)
    {
        std::string str;
        for (int n = 0; n < 2; n++)
            str.push_back(select_text[n + i]);
        text2.push_back(str);
    }
    /*2文字配列の頻出頻度を格納*/
    for (int i = 0; i < text2.size(); i++)
    {
        /*auto itr = std::find(count.begin(), count.end(), text[i]);
        if (itr != count.end())
        {
            count.erase(itr);
        }*/

        comb a = {text2[i], std::count(text2.begin(), text2.end(), text2[i])};
        count.push_back(a);
        // ofs << count[i].str << count[i].value << std::endl;
    }

    //std::set<comb> s(count.begin(), count.end());
    //std::vector<comb> count1(s.begin(), s.end());

    for (int m = 0; m < count.size(); m++)
    {
        std::sort(count.begin(), count.end());
        auto a = std::unique(count.begin(), count.end());
        count.erase(a, count.end());
        ofs << count[m].str << count[m].value << std::endl;
    }
    //for (int m = 0; m < text2.size(); m++)
    //ofs << text2[m] << ',';
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
void select()
{
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
}