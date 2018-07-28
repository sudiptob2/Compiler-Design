#include<bits/stdc++.h>

using namespace std;

int isKeyword(char buffer[])
{
    int m=35,n=10;
    char keywords[m][n] = {"auto","break","case","char","const","continue","default",
                           "do","double","else","enum","extern","float","for","goto",
                           "if","int","long","register","return","short","signed",
                           "sizeof","static","struct","switch","typedef","union",
                           "unsigned","void","volatile","while","include","main","stdio"
                          };
    int i, flag = 0;

    for(i = 0; i < m; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
bool isSpecial(char ch)
{
    char specialChar[] = "(){}.#<>!,&\"";
    int l = 13;
    for(int i=0; i<l; i++)
    {
        if(ch==specialChar[i])
            return true;
    }
    return false;

}
bool isOperator(char ch)
{
    char  operators[] = "+-*/%=";
    int l = 6;
    for(int i=0; i<l; i++)
    {
        if(ch==operators[i])
            return true;
    }
    return false;

}
int main()
{
    char ch, buffer[15];
    ifstream fin("program.txt");
    int i,j=0;

    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }


    string s = "";
    int l =1;
    while(!fin.eof())
    {
        string s ;
        getline(fin,s);
        s+="\n";

        cout<<"LINE:  "<<l++<<endl;
        cout<<"CONTENTS:        "<<s<<endl;
        cout<<"TOKENS:"<<endl;

        for(int k=0; k<s.size(); k++)
        {
            ch = s[k];

            if(isOperator(ch))
                cout<<ch<<"\t\t----> OPERATOR\n";

            if(isSpecial(ch))
                cout<<ch<<"\t\t----> SPECIAL CHARACTER\n";

            if(isalnum(ch)||ch=='_')
            {
                buffer[j++] = ch;
            }
            else if((ch == ' ' || ch == '\n'||isSpecial(ch))||isOperator(ch) && (j != 0))
            {
                buffer[j] = '\0';
                j = 0;

                if(isKeyword(buffer) == 1)
                    cout<<buffer<<"\t\t----> KEYWORD\n";
                else if(isdigit(buffer[0]))
                    cout<<buffer<<"\t\t\----> CONSTANT\n";
                else if(buffer[0]=='\0')
                    continue;
                else
                    cout<<buffer<<"\t\t\----> IDENTIFIER\n";
            }

        }
        cout<<"----------------------------------------------------------"<<endl;

    }



    fin.close();

    return 0;
}
