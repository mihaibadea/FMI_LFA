#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream tin("autom.in");

vector<int> del[100][100];

map<char, int> trad;

bool fin[100];

int n;

bool urm_lambda(int stare)
{
    return !del[stare][trad['$']].empty();
}

bool urm_alfa(int stare)
{
    for(int i=1; i<=n; i++)
    {
        if(!del[stare][i].empty()) return true;
    }

    return false;
}

bool evaluate(string k, int in)
{


    vector<int> sc, tmp,a;
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
                    if(fin[del[sc[i]][trad[k[lc]]][j]]) return true;

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

                for(int j=0; j<del[sc[i]][trad['$']].size(); j++)
                {
                    tmp.push_back(del[sc[i]][trad['$']][j]);
                }

            }

            int k=0;

            while(k<tmp.size())
            {
                if(urm_lambda(tmp[k]))
                {

                    for(int j=0; j<del[tmp[k]][trad['$']].size(); j++) tmp.push_back(del[tmp[k]][trad['$']][j]);

                    if(!urm_alfa(tmp[k])) tmp.erase(tmp.begin()+k);
                    else k++;

                }
                else k++;
            }

            sc = tmp;

        }

    }

    return false;
}


int main()
{

    int m,q0,k,l,t,a,c,in=0;
    char b,tt;

    tin>>n;
    tin>>m;

    for(int i=0; i<m; i++)
    {
        tin>>tt;
        if(t!='$') trad.insert(pair<char, int>(tt, ++in));
    }

    trad.insert(pair<char, int>('$', 0));

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
        cout<<(evaluate(test, q0) ? "Acceptat\n\n" : "Neacceptat\n\n");

    }
    return 0;
}
