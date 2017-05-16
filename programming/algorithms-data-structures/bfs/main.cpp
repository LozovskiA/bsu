//
// Created by Drapegnik on 20.01.14.
//
#include <fstream>
#include <queue>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int s,n,a[100][100],d[100]={},p[100];
    bool us[100];
    queue <int> q;
    fin>>n>>s;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            fin>>a[i][j];

    for (int i=0;i<n;i++)
        us[i]=false;

    q.push(s);
    us[s]=true;
    p[s]=-1;

    while(!q.empty())
    {
        int num=q.front();
        q.pop();
        for (int j=0;j<n;j++)
        {
            if (a[num][j]!=0)
                if (!us[j])
                {
                    us[j]=true;
                    q.push(j);
                    d[j]=d[num]+1;
                    p[j]=num;
                }
        }
    }

    return 0;
}
