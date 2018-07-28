#include<bits/stdc++.h>
using namespace std;
/*
This is the grammar
E=TA
A=+TA
T=FB
B=*FB
F=(E)
*/

// This is the parsing table # represent null
string table[5][6] =
{

    {"TK", "#", "#", "TK", "#", ""},
    {"#", "+TK", "#", "#", "", ""},
    {"FH", "#", "#", "FH", "#", "#"},
    {"#", "", "*FH", "#", "", ""},
    {"a", "#", "#", "(E)", "#", "#"}

};
string nonTerms[] = { "E", "K", "T", "H", "F"};
string terminals[] = {"a", "+", "*", "(", ")", "$"};
int indexOfinput = -1;
stack<string> stk;
string read(string input)
{
    indexOfinput++;
    return string(1,input[indexOfinput]);

}
bool isNonTerminal(string top)
{
    int n = (sizeof(nonTerms)/sizeof(*nonTerms)) ;
    for(int i=0; i<n; i++)
    {
        if(nonTerms[i]==top)
            return true;
    }
    return false;

}
bool isTerminal(string top)
{
    int n = (sizeof(terminals)/sizeof(*terminals)) ;
    for(int i=0; i<n; i++)
    {
        if(terminals[i]==top)
            return true;
    }
    return false;

}
int getIndexTer(string value)
{
    // cout<<"Val T: "<<value<<endl;

    int n = (sizeof(terminals)/sizeof(*terminals)) ;
    for(int i=0; i<n; i++)
    {
        if(terminals[i]==value)
            return i;
    }

    return -1;
}
int getIndexNonTer(string value)
{
    //cout<<"Val NT: "<<value<<endl;

    int n = (sizeof(nonTerms)/sizeof(*nonTerms)) ;
    for(int i=0; i<n; i++)
    {
        if(nonTerms[i]==value)
            return i;
    }

    return -1;
}
string getRule(string non,string term)
{
    int row = getIndexNonTer(non);
    int column = getIndexTer(term);
    //cout<<"Row"<<row<<"col"<<column<<endl;
    string rule = table[row][column];
    if(rule=="#")
    {
        cout<<"There is no Rule for , Non-Terminal(" + non + ") ,Terminal(" + term + ") "<<endl;
        cout<<"Expression is rejected!!"<<endl;
        exit(0);
    }
    return rule;
}
void pushRule(string rule)
{
    for (int i = rule.size()-1; i >= 0; i--)
    {
        string str = string(1,rule[i]);
        stk.push(str);
    }
}
void printStack()
{

    string a[100];
    int i=0;
    while( !stk.empty() )
    {
        clock_t start;
        start = clock();
        int pause=100;
        while( clock() < start + pause )
        {

        }

        cout << stk.top() << " ";

        a[i++] = stk.top();
        stk.pop();
    }
    for(int j=i-1; j>=0; j--)
    {
        stk.push(a[j]);
    }
    cout<<endl;



}
int main()
{
    string input;
    //cin>>input;
    input = "a+(a+a(a)+a)";
    int ilen = input.size();
    stk.push("$");
    stk.push(nonTerms[0]); //Pushing the first non terminal
    string token = string(1,input[++indexOfinput]); // advancing and returning from input
    string top = "";
    while(true)
    {
        printStack();
        top = stk.top();
        stk.pop();
        if(isNonTerminal(top))
        {

            string rule = getRule(top,token);

            pushRule(rule);



        }
        else if(isTerminal(top))
        {

            //2 things to do
            //1.top is a token so accept it
            //2.top is some unknown char so reject it
            if(top!=token)
            {
                cout<<"this token is not corrent , By Grammer rule . Token : (" + token + ")"<<endl;
                break;
            }
            else
            {
                cout<<"Matched Terminal : " <<token <<endl;
                token = string(1,input[++indexOfinput]);

            }


        }
        else
        {
            cout<<"Never Happens , Because top : ( " + top + " )"<<endl;
        }
        if(indexOfinput>=ilen)
            break;
    }
    while(!stk.empty())
    {
        printStack();
        stk.pop();

    }
    if(token == "$")
        cout<<"Input is Accepted by LL1"<<endl;
    else
        cout<<"Input is not Accepted by LL1"<<endl;





}
















