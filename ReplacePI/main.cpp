#include <iostream>

using namespace std;

void replacePI(char* s, int i)
{
    if (s[i+1] == '\0') return;
    else
    {
        if ((s[i] == 'p')&&(s[i+1] == 'i'))
        {
            int j = i;
            while(s[j]){j++;}
            while(j>=i)
            {
                s[j+2] = s[j];
                j--;
            }
            s[i]= '3';
            s[i+1] = '.';
            s[i+2] = '1';
            s[i+3] = '4';
            replacePI(s, i+4);
        }
        else
        {
            replacePI(s, i+1);
        }
    }
}

int main()
{
    char text[100];
    cin>>text;
    replacePI(text, 0);
    cout<<text;
}
