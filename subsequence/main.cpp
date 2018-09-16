#include <iostream>

using namespace std;

void subsequence(char inp[], int i, char out[], int j)
{
    //base case is when input is empty
    if (inp[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
    }
    else //recursive case
    {
        //element selected
        out[j] = inp[i];
        subsequence(inp, i+1, out, j+1);
        //element not selected
        subsequence(inp, i+1, out, j);
    }

}


int main()
{
    char text[100], output[100];
    cin>>text;
    subsequence(text,0,output,0);
    cout<<output;
    return 0;
}
