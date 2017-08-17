//Hackerrank in a string

#include<bits/stdc++.h>

int main() {

    int q;
    scanf("%d",&q);

    const char string[] = "hackerrank";

    char input[10001];
    for(int i=0;i<q;i++)
    {
        scanf("%s",input);
        int stringCtr=0;
        int flag=0;
        for(int j=0;j<strlen(input);j++)
        {
            if(input[j]==string[stringCtr])
            {
                stringCtr++;
                if(stringCtr==10)
                    {
                        flag=1;
                        break;
                    }
            }
        }

        if(flag)    printf("YES\n");
        else        printf("NO\n");
    }

}
