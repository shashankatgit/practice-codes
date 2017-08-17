#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

//queue<int> q;



int countNeeded;


vector<int> topologicalSort(vector<int> graph[] , int n, set<int> requiredPrograms) {
    /* Find in degree of each vertices */

    vector<int> result;
    set<int> zeroV;
    int degree[20001]={0};

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
            zeroV.insert(i);
        }
    }

//    /* If there is no vertices having degree 0 then graph has cycle*/
//    if(q.empty()){
//        printf("Sort isnot possible\n");
//        return;
//    }

    while(!zeroV.empty()) {

        int x=*zeroV.begin();
        for(set<int>::iterator i=requiredPrograms.begin(); i!= requiredPrograms.end(); i++)
        {
            //printf("f%d  ",*i);

            if(zeroV.find(*i)!=zeroV.end())
            {
                printf("f%d  ",*i);
                x=*i;
                requiredPrograms.erase(x);
                break;
            }
        }

        countNeeded++;

        zeroV.erase(x);

        result.push_back(x);

        if(requiredPrograms.size()<=0)
            {
            printf("OUT");
                break;
            }

        /* As x node is deleted from graph decrement adjacent node's degree by 1 */
        for(int i=0;i<graph[x].size() ; i++) {
            int y=graph[x][i];
            degree[y]--;
            if(degree[y]==0)
            {
                zeroV.insert(y);
            }
        }
    }

    return result;
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
        countNeeded = 0;
        set<int> requiredPrograms;

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

        vector<int> result = topologicalSort(graph , n, requiredPrograms);

        printf("%d\n", countNeeded);
        for(int i=0;i<countNeeded ; i++)
        {
            printf("%d ", result[i]);
        }

       if(q!=0) printf("\n");
    }

}
