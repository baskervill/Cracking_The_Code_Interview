int shortestDist(string text[], int n, string word1, string word2){
    int min = kMaxInt / 2;
    int pos1 = -min;
    int pos2 = -min;
    for(int pos = 0;pos < n;pos++){
        if(text[pos] == word1){
            pos1 = pos;
            int dist = pos1 - pos2;
            if(dist < min){
                min = dist;
            }
        }
        else if(text[pos] == word2){
            pos2 = pos;
            int dist = pos1 - pos2;
            if(dist < min){
                min = dist;
            }
        }
    }
    return min;
}