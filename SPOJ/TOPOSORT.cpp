#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
const int MAX = 100000;

int inDegree[MAX];
vector<int> graph[MAX];
set<int> processSet;


int main()
{

    int n,m,x,y;

    register int i;
    scanf("%d%d",&n, &m);

    for(i=0; i<m; i++)
    {
        scanf("%d%d",&x, &y);
        graph[x].push_back(y);
        inDegree[y] += 1;
    }

    for(i=0;i<n;i++)
    {
        if(!inDegree[i]) //this vertex depends on no other one
        {
            processSet.insert(i);
        }
    }

    //topological sorting starts


    int order[MAX];
    int counter = 0;
    while(!processSet.empty())
    {
            x = *processSet.begin();
            processSet.erase(processSet.begin());

            for(i=0)

            order[counter++] = x;
    }
}

