#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int,string>mp;
    mp[2]="omar";
    mp[0]="nroton";
    map<int, string>::iterator it = mp.begin();
    cout<<it->first<<endl;
    map<string,int*>ex;
    int vet[5];
    vet[2]=12;
    ex["omar"]=vet;
    int *pont= ex["omar"];
    cout<<"exemplo\n";
    cout<<pont[2];
    cout<<pont[0]<<" "<<pont[1]<<pont[3];

