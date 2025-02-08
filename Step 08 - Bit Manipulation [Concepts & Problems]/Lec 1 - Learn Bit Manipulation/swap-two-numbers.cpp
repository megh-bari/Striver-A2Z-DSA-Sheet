pair<int, int> get(int a, int b){
    int temp;
    temp = a;
    a= b;
    b = temp;
    return {a,b};
}


// without 3rd variable 

pair<int, int> get(int a, int b){
    a = a+b;
    b = a -b;
    a = a- b;
    return {a,b};
}


// using xor 

pair<int, int> get(int a, int b){
    a = a^b;
    b = a ^b;
    a = a^b;
    return {a,b};
}