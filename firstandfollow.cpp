#include<bits/stdc++.h>
using namespace std;
string G[100];//Grammar
set<char> nonTerminals;
set<char> terminals;
set<char>::iterator it;
char findFirst(char nt,int c)
{
    //cout<<"Nt: "<<nt<<endl;
    string s;
    for(int i=0; i<c; i++)
    {
        s = G[i];
        //Finding the production for nt
        if(s[0]==nt)
        {
            cout<<s[2]<<endl;
            if(isupper(s[2]))
            {
                findFirst(s[2],c);
            }
            else
            return s[2];

        }


    }


}

int main()

{
    ifstream fin("grammar.txt");
    set<char> nonTerminals;
    set<char> terminals;
    set<char>::iterator it;
    int c=0;

    while(!fin.eof())
    {
        string s;
        getline(fin,s);
        G[c++]=s;

    }
    for(int i=0; i<c; i++)
    {
        string s = G[i];
        for(int j=0; j<s.size(); j++)
        {
            if(isupper(s[j]))
                nonTerminals.insert(s[j]);
            else if(s[j]=='=')
                continue;
            else
                terminals.insert(s[j]);
        }
    }
    /*cout<<"Nonterminals:"<<endl;
    for (it=nonTerminals.begin(); it!=nonTerminals.end(); ++it)
        cout << ' ' << *it;
    cout<<"\nterminals:"<<endl;
    for (it=terminals.begin(); it!=terminals.end(); ++it)
        cout << ' ' << *it;*/

    for (it=nonTerminals.begin(); it!=nonTerminals.end(); ++it)
    {

        char f = findFirst(*it,c);
        cout<<"First of "<<*it<<" :"<<f<<endl;

    }



}















