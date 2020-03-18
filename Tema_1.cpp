#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream tin("autom.txt");

vector<int> del[100][100];


map<char, int> trad;

bool fin[100];


bool evaluate(string k, int in)
{
    vector<int> sc, tmp;
    sc.push_back(in);
    int lc = -1;

    while(!sc.empty())
    {
        lc++;


        if(lc == k.length()-1)
        {
            for(int i=0; i<sc.size(); i++)
            {
                 for(int j=0; j<del[sc[i]][trad[k[lc]]].size(); j++)
                {
                    if(fin[del[sc[i]][trad[k[lc]]][j]]==1) return true;
                }
            }

            return false;
        }

        else
        {
            tmp.clear();
            for(int i=0; i<sc.size(); i++)
            {

                for(int j=0; j<del[sc[i]][trad[k[lc]]].size(); j++)
                {
                    tmp.push_back(del[sc[i]][trad[k[lc]]][j]);
                }

            }

            sc = tmp;
        }

    }

    return false;
}


int main()
{

    int n,m,q0,k,l,t,a,c,in=-1;
    char b,tt;

    tin>>n;
    tin>>m;

    for(int i=0; i<m; i++)
    {
        tin>>tt;

        if(t!='$') trad.insert(pair<char, int>(tt, ++in));

    }

    trad.insert(pair<char, int>('$', -1));

    tin>>q0;
    tin>>k;

    for(int i=0; i<k; i++)
    {
        tin>>t;
        fin[t]=1;
    }

    tin>>l;


    for(int i=0; i<l; i++)
    {
        tin>>a>>b>>c;
        del[a][trad[b]].push_back(c);
    }

    int p=0;
    string test;

    while(1)
    {
        cout<<"Testul "<<++p<<": ";
        cin>>test;
        cout<<(evaluate(test, q0) ? "Acceptat\n" : "Neacceptat\n")<<"\n";

    }
    return 0;
}
