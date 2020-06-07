##
双向DFS模板总结.

'''
startQueue.add(startNode);
endQueue.add(endNode);
while ((!startQueue.isEmpty()) && (!endQueue.isEmpty())) {
    //选择size更小的进行扩散.
    if (startQueue.size() > endQueue.size()) {
        swap(startQueue, endQueue);
    }
    qSize = startQueue.size();
    loop = 0;
    for (loop < qSize) {
        loop++;  
        tmpNode =  startQueue.front();
        if (tmpNode in endQueue) {
            return step;
        }
        startQueue.add(getNeighbor(tmpNode)));
    }
    step++; 
}
'''
