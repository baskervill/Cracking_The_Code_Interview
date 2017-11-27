int count2(int n){
    int count = 0;
    while(n > 0){
        if(n % 10 == 2){
            ++count;
        }
        n /= 10;
    }
    return count;
}
int count2s1(int n){
    int count = 0;
    for(int i = 0;i < n;i++){
        count += count2(i);
    }
    return count;
}
int count2s(int n){
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n / factor != 0){
        low = n - (n / factor) * factor;
        cur = (n / factor) % 10;
        high = n / (factor * 10);
        switch(cur){
            case 0:
            case 1:
                count += high * factor;
                break;
            case 2:
                count += high * factor + low + 1;
                break;
            default:
                count += (high + 1) * factor;
                break;
        }
        factor *= 10;
    }
    return count;
}