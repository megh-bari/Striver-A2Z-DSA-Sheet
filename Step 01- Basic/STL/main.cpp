#include <bits/stdc++.h>

using namespace std;

void printName()
{
    cout << "megh";
}

int sum(int a, int b)
{
    return a + b;
}

// * Containers and Iterators

void explainPair()
{
    pair<int, int> p = {1, 8};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].first << " " << arr[1].second;
}

void explainVector()
{
    vector<int> v;

    // added element to vector
    v.push_back(1);
    v.emplace_back(2);

    // define vector of pair dataType
    vector<pair<int, int>> vec;

    vec.push_back({1, 8});
    vec.emplace_back(1, 2);

    vector<int> vecc(5, 100);
    vector<int> v(5);

    vector<int> v1(5, 20);
    // vector<int>v2(v1); //copied of v1

    // how to access elements in vector

    // by normal method

    cout << vecc[0] << vecc.at(0);
    cout << vecc.back() << " ";

    // by iterator

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it += 2;
    cout << *(it) << " ";

    vector<int>::iterator it = v.end();

    //  vector printing using for loop

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // short way

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // for each

    for (auto it : v)
    {
        cout << it << " ";
    }

    // * Deletion of vector
    // 10,20,30,40
    v.erase(v.begin() + 1); // 10,30,40

    // 10,20,12,23,35
    v.erase(v.begin() + 2, v.begin() + 4); // 10,20,35

    // Insertion Function

    vector<int> v(2, 100);          //{100,100}
    v.insert(v.begin(), 300);       //{300,100,100}
    v.insert(v.begin() + 1, 2, 10); //{300,10,10,100,100}

    vector<int> copy(2, 50);                       //{50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    // {10,20}
    cout << v.size(); // 2

    //{10,20,30}
    v.pop_back(); // {10,20}

    // v1-> {10,20}
    // v2-> {30,40}
    vector<int> v2(30, 40);
    v1.swap(v2);
    // v1-> {30,40}
    // v2-> {10,20}

    v.clear(); // erase entire vector

    cout << v.empty();
    // if one element - false
    // if nothing - true
}

void explainList()
{

    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); //{5,2,4}

    ls.emplace_front(); //{2,4}

    // rest function same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDequeue()
{
    deque<int> dq;

    dq.push_back(1);     //{1}
    dq.emplace_back(2);  //{1,2}
    dq.push_front(9);    //{9,1,2}
    dq.emplace_front(8); //{8,9,1,2}
    dq.pop_back();       //{8,9,1}
    dq.pop_front();      ///{9,1}

    dq.back();
    dq.front();
    // rest function same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack()
{

    // LIFO - Last in, First Out
    stack<int> st;
    st.push(1);    //{1}
    st.push(2);    //{2,1}
    st.push(3);    //{3,2,1}
    st.push(4);    //{4,3,2,1}
    st.emplace(5); //{5,4,3,2,1}

    cout << st.top(); // prints 5

    st.pop(); // st look like {4,3,2,1}

    cout << st.top(); // 4

    cout << st.size(); // 4
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue()
{
    queue<int> q;
    q.push(1);    //{1}
    q.push(2);    //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5;

    cout << q.back(); // prints 9

    // Q is {1,2,9}
    cout << q.front(); // prints 1

    q.pop(); // {2,9}

    cout << q.front(); // print 2

    // size swap empty same as stack
}

void explainPQ()
{
    // Priority Queue

    priority_queue<int> pq;
    pq.push(5);  // 5
    pq.push(2);  // 5,2
    pq.push(8);  // 8,5,2
    pq.push(10); // 10,8,5,2

    cout << pq.top(); // 10
    pq.pop();         // {8,5,2}

    cout << pq.top(); // 8
    // size swap empty same as stack

    // minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     // 5
    pq.push(2);     // 2,5
    pq.push(8);     // 2,5,8
    pq.emplace(10); // 2,5,8,10

    cout << pq.top(); // 2
}

void explainSet()
{
    set<int> st;
    st.insert(1);  // 1
    st.emplace(2); // 1,2
    st.insert(2);  // 1,2,2
    st.insert(4);  // 1,2,3,4
    st.insert(3);  // 1,2,3,4

    // functionality of insert in vector
    // can be used also, that only increase
    // efficiency

    // begin, end, ebegin, rend, size
    // empty and swap are same as those of above

    // 1,2,3,4,5
    auto it = st.find(3);

    // 1,2,3,4,5
    auto it = st.find(6);

    // 1,4,5
    st.erase(5); // erase 5  // Takes logarithim Time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it);

    // 1,2,3,4,5
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase{1,4,5} {first, last}

    // lower_bound and upper_bound function works in same way
    // as in vector it does

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

void explainMultiSet()
{
    // Everything is same as set
    // only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1); // 1
    ms.insert(1); // 1,1
    ms.insert(1); // 1,1,1

    ms.erase(1); // alll 1's erased

    int cnt = ms.count(1);

    // only single one erased
    ms.erase(ms.find(1));

    // rest all functions are as set
}

void explainUSet()
{
    unordered_set<int> ust;
    // lower_bond and upper_bond function does not works, rest all functions are same
    // as above, it does not stores in any particular order
    // it has better complexity than set in most cases, expect some when collison happens
}

void explainMap()
{
    map<int, int> mpp1;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;

    mpp1[1] = 2;
    mpp1.emplace(3, 1);
    mpp1.insert({2, 4});
    mpp3[{2, 3}] = 10;

    for (auto it : mpp1)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp1[1];
    cout << mpp1[5];

    auto it1 = mpp1.find(3);
    // cout<<*(it1).second;

    auto it = mpp2.find(5);

    // this is the syntax
    auto it = mpp1.lower_bound(2);
    auto it = mpp2.upper_bound(3);
}

void explainMultiMap()
{
    multimap<int, int, int, int> mmp;
    // everything same as map, only it can store multiple keys
    // only mpp[key] cannot be used here
}

void explainUnorderdMap()
{
    unordered_map<int, int> umpp;
    // same as set and unordered_set difference
    // random stored and unique keys
}


// * Algorithms

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false; // swap
    //    if they are same

    if (p1.first > p2.first)
        return true;
    return false;
}


void explainExtra()
{

    sort(a, a + n);
    sort(v.begin(), v.end());

    sort(a_2, a + 4);
    sort(a, a + n, greater<int>);

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first elememt but in descending

    sort(a, a + n, comp);
    // {{4,1}, {2,1}, {1,2}}

    int num = 7;
    int cnt = __builtin_popcount();
    long long num = 1234566743373;
    int cnt = __builtin_popcountll();

    string s = "123";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    int maxx = *max_element(a, a + n);
}


int main()
{
    // printName();
    // int s;
    // s = sum(1, 2);
    // cout<<s;

    //* explainPair();

    return 0;
}