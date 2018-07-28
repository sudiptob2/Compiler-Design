#include<bits/stdc++.h>
using namespace std;
bool found(string r)
{

    string G[] = {"E+E","E-E","-E","(E)","id" };
    int n = (sizeof(G)/sizeof(*G)) ;
    for(int i=0; i<n; i++)
    {
        if(r==G[i])
            return true;
    }
    return false;
}
string sub(string s, int i,int j)
{
    string r ="";
    while(i<=j)
    {
        r+=s[i++];
    }
    return r;

}
int main()
{
    stack<string> printStack;
    string s,temp;
    cin>>s;
    temp=s;
    int l = s.size();
    for(int i=0; i<l; i++)
    {
        if(isalnum(s[i]))
            s[i]='E';
    }
    printStack.push(s);
    int prev = l;
flag:
    while(l>1)
    {
        l = s.size();
        // Two loops are used to get every possible substring of the input
        for(int i=0; i<l; i++)
        {
            for(int j=i; j<l; j++)
            {
                string r = sub(s,i,j);
                //cout<<"Sub: "<<r<<endl;
                if(found(r))
                {

                    s.replace(i,j-i+1,"E");
                    printStack.push(s);
                    l=s.size();


                    goto flag;

                }

            }
            l=-1;


        }
    }
    string str="";
    if(l>0) //l= -1 if it is rejected
    {
        while(!printStack.empty())
        {
            str = printStack.top();
            printStack.pop();
            cout<<str<<endl;
        }
        for(int i=0; i<str.size(); i++)
        {
            for(int j=0; j<str.size(); j++)
            {
                if(i==j&&str[j]=='E')
                    str[j]=temp[j];
            }
            if(isalnum(str[i]))
                cout<<str<<endl;
        }
    }
    else
        cout<<"expression rejected!!"<<endl;



}
