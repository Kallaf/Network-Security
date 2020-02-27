#include<iostream>
#define m 1
using namespace std; 

char start(char c)
{
    return c < 'A'?'0':'A'-10;
}

string c[] = {"AEDE0273C4C0DA3477F919018A05DA71A2530F5A0020E4E0ACA80FF2DE",
              "A8C80426C2DEC16D31F90D1497129475A45447561D74EEF1B8BF0FFCDC",
              "A9D30426D3C7CB202EB8050E9717C734A5484A13126CE0FDABA212FBDF",
              "B49B166FDAC58E2A25F90A159914D134B84E0F551677A7FFB6A512FBC1",
              "B49B126ED7C5C26D20EA07149D40C771B2555D565373E8F4ADBC07E1D7",
              "B3DE1763C489DC2822EB0B40970ED134A54942565370E6F6F9A003EAC1",
};

string findKey()
{
    string key = "";
    for(int i=0;i<58;i+=2)
    {
        int keyFound = 0;
        for(char k=0;k<256&&keyFound < m;k++)
        {
            bool all = true;
            for(int j=0;j<6&&all;j++)
            {
                char c1 = c[j][i+1] - start(c[j][i+1]);
                c1 += (c[j][i] - start(c[j][i]))  * 16;
                char c = ((char)k)^c1;
                if(i)all = ('a' <= c && c <= 'z') || (c == ' ');
                else all = ('A' <= c && c <= 'Z') || (c == ' ');
            }
            if(all){
                keyFound++;
                if(keyFound == m)key.push_back((char)k);
            }
        }
        if(!keyFound)
        {
            cout << "cann't found key at: " << (i/2) << endl;
            key.push_back('#');
        }
    }
    return key;
}

string decrypte(int idx,string key)
{
    string message = "";
    for(int i=0;i<58;i+=2)
    {
        char c1 = c[idx][i+1] - start(c[idx][i+1]);
        c1 += (c[idx][i] - start(c[idx][i]))  * 16;
        char c = c1 ^ key[i/2];
        message.push_back(c);
    }
    return message;
}

int main() 
{ 
    string k = findKey();
    for(int i=0;i<6;i++)
        cout << decrypte(i,k) << endl;
    return 0; 
}
