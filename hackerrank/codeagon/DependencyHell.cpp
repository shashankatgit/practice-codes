#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;
vector<int> result;
queue<int> q;
int degree[20001]={0};

set<int> requiredPrograms;
int countNeeded;


void topologicalSort(vector<int> graph[] , int n) {
    /* Find in degree of each vertices */
    for(int i=1;i<=n;i++) {
        for(int j=0;j<graph[i].size() ; j++) {
            int x=graph[i][j];
            degree[x]++;
        }
    }

//    for(int i=1;i<=n;i++) printf("\ndeg %d = %d", i, degree[i]);
    /* Enqueue 0 degree vertices */
    for(int i=1;i<=n;i++) {
        if(degree[i]==0) {
            q.push(i);
            if(requiredPrograms.size()>0)
            {
                if(requiredPrograms.find(i) != requiredPrograms.end())
                {
                    requiredPrograms.erase(i);
                    //printf("Erased %d\n",i);
                }
            }

            else
                break;

            countNeeded++;
        }
    }

//    /* If there is no vertices having degree 0 then graph has cycle*/
//    if(q.empty()){
//        printf("Sort isnot possible\n");
//        return;
//    }

    while(!q.empty()) {
        int x=q.front();
        q.pop();
        result.push_back(x);

        /* As x node is deleted from graph decrement adjacent node's degree by 1 */
        for(int i=0;i<graph[x].size() ; i++) {
            int y=graph[x][i];
            degree[y]--;
            if(degree[y]==0)
            {
                q.push(y);

                if(requiredPrograms.size()>0)
                {
                    if(requiredPrograms.find(y) != requiredPrograms.end())
                    {
                        requiredPrograms.erase(y);
                        //printf("Erased %d\n",y);
                    }
                }

                else break;

                countNeeded++;
            }
        }
    }
}

int main()
{

    int q;
    int n, m, d;

    register int nCounter, mCounter, dCounter;
    int dependency;

    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %d", &n, &m);

        vector<int> graph[n+1];

        for(nCounter=1; nCounter<=n; nCounter++)
        {
            scanf("%d", &d);

            for(dCounter=1; dCounter<=d; dCounter++)
            {
                scanf("%d", &dependency);
                graph[dependency].push_back(nCounter);
            }
        }

        int req;
        for(mCounter=1; mCounter<=m; mCounter++)
        {
            scanf("%d", &req);
            requiredPrograms.insert(req);
        }

//        for(set<int>::iterator it = requiredPrograms.begin(); it!=requiredPrograms.end(); it++)
//        {
//            printf("%d, ", *it);
//        }

        topologicalSort(graph , n);

        printf("%d\n", countNeeded);
        for(int i=0;i<countNeeded ; i++)
        {
            printf("%d ", result[i]);
        }

    }

}
