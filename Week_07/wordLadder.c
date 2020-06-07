bool isOneDiff(char* src, char* dst) {
    int i;
    int count = 0;
    int len = strlen(src);
    for (i = 0; i < len; i++) {
        if (src[i] != dst[i]) {
            count++;
            if (count > 1) {
                return false;
            }
        }
    }
    if (count == 1) {
        return true;
    } else {
        return false;
    }
}
int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int* queue = (int*)malloc(sizeof(int) * (wordListSize + 1));
    int* visit = (int*)malloc(sizeof(int) * wordListSize);
    memset(visit, 0, sizeof(int) * wordListSize);
    int i;
    int rear = 1;
    int front = 0;
    queue[0] = -1;
    int step = 0;
    int qSize;
    int loop;
    int tmpIndex;
    while(rear > front) {
        qSize = rear - front;
        loop = 0;
        while (loop < qSize) {
            tmpIndex = queue[front];
            front++;
            loop++;
            if (tmpIndex == -1) {
                for (i = 0; i < wordListSize; i++) {
                    if (isOneDiff(beginWord, wordList[i])) {
                        visit[i] = 1;
                        queue[rear] = i;
                        rear++;
                    }
                }
            } else {
                if (strcmp(wordList[tmpIndex], endWord) == 0) {
                    return step + 1;
                }
                for (i = 0; i < wordListSize; i++) {
                    if ((visit[i] == 0) && (isOneDiff(wordList[tmpIndex], wordList[i]))) {
                        visit[i] = 1;
                        queue[rear] = i;
                        rear++;
                    }
                }
            }
        }
        step++;
    }
    return 0;
}