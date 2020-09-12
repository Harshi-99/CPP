#include<bits/stdc++.h>
using namespace std;
class Hash
{
    int Bucket;
    list<int>*hashTable;

    public:
        
        Hash(int Bucket);

         void insert(int key);
         void Delete(int key);
         void display();
         int hashFunction(int x)
        {
            return(x%Bucket);
        }   
};
Hash::Hash(int Bucket)
{
    this->Bucket = Bucket;
    hashTable = new list<int>[Bucket];
}
void Hash::insert(int key)
{
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}
void Hash::Delete(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for(i = hashTable[index].begin(); i != hashTable[index].end(); i++)
        if(*i == key)
            break;
        if(i != hashTable[index]. end())
            hashTable[index].erase(i);
        
}
void Hash::display()
{
    list<int>::iterator i;
    for(int it = 0; it<Bucket; it++)
    {
        cout<<it;
        for(i = hashTable[it].begin(); i!= hashTable[it].end(); i++)
            cout<<"-->"<<*i;
            cout<<"\n";
    }
}
int main()
{
    Hash h(7);
    int arr[] = {15, 11, 27, 8, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        h.insert(arr[i]);
    h.Delete(12);
    h.display();
    return 0;
}
