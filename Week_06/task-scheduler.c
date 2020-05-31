int getMaxIndex(int* temp)
{
    int i = 0;
    int maxTempIndex = 0;
    int maxValue = temp[0];
    for (i=0;i<26;i++)
    {
        if (temp[i] > maxValue)
        {
            maxTempIndex = i;
            maxValue = temp[i];
        }
    }
    return maxTempIndex;
}


int leastInterval(char* tasks, int tasksSize, int n){

    int * temp = (int*)malloc(sizeof(int)*26);
    memset(temp,0,sizeof(int)*26);
    
    int  i = 0;

    if (n == 0)
    {
        return tasksSize;
    }
     
    if (tasksSize == 1)
    {
        return tasksSize;
    }

    for(i=0; i<tasksSize;i++)
    {
        temp[tasks[i]-'A']++;
    }
    
    int maxCnt =0;
    int maxIndex = 0;
    for (i=0; i<26;i++)
    {
       if (temp[i]>maxCnt)
       {
           maxCnt=temp[i];
           maxIndex = i;
       }
    }
    
    if (maxCnt < 2)
    {
        return tasksSize;
    }

    char** arrayTemp = (char**)malloc(sizeof(char*)*maxCnt);
    for (i=0;i<maxCnt;i++)
    {
        arrayTemp[i] = (char*)malloc(sizeof(char)*(n+2));
        memset(arrayTemp[i],0,(n+2));
    }
    printf("eneter\n");

     for (i=0; i<maxCnt-1; i++)
     {
         memset(arrayTemp[i],'@',(n+1));
     }


    for (i=0;i<maxCnt;i++)
    {
       arrayTemp[i][0]  = maxIndex + 'A';    
    }
    printf("eneter\n");
    temp[maxIndex] = 0;

    int flag = 0;
    int maxTempIndex = getMaxIndex(temp);
    if (temp[maxTempIndex] == maxCnt)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    int j = 0;
    printf("eneter2\n");
    for (j=1;j<(n+1);j++)
    {  
        if (temp[maxTempIndex] == 0)
        {
            maxTempIndex = getMaxIndex(temp);
            if (temp[maxTempIndex] == maxCnt)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            if (temp[maxTempIndex] == 0)
            {
                break;
            }
        }
        for (i=0;i<maxCnt;i++)
        {
            if (flag !=1)
            {
                if (i==maxCnt-1)
                {
                    break;
                }
            }
            
            if (temp[maxTempIndex] == 0)
            {
                maxTempIndex = getMaxIndex(temp);
                if (temp[maxTempIndex] == maxCnt)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                if (temp[maxTempIndex] == 0)
                {
                    break;
                }
            }
            arrayTemp[i][j] =  maxTempIndex + 'A';
            temp[maxTempIndex]--;
        } 
    }
    int sum =0;
    for (i = 0; i<maxCnt; i++)
    {
        sum += strlen(arrayTemp[i]);
    }
    printf("maxCnt = %d\n",maxCnt);
    if (maxCnt >=2)
    {
        if (arrayTemp[maxCnt-2][n] != '@')
        {
            return tasksSize;
        }
    }
    return sum;
}