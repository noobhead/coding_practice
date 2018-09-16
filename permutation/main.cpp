#include <iostream>

using namespace std;

void permute(char inp[], int i)
{
    if(inp[i]=='\0')
    {
        cout<<inp<<endl;
        return;
    }
    else
    {
        for (int j=i;inp[j]!='\0';j++)
        {
            swap(inp[i], inp[j]);
            permute(inp, i+1);
            swap(inp[j], inp[i]);
        }

    }
}

int main()
{
    char text[100];
    cin>>text;
    permute(text, 0);
    return 0;
}
