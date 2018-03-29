#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll p,q;
    cout<<"Enter two large prime numbers"<<endl;
    cin>>p>>q;
    ll n=p*q;
    ll n1=(p-1)*(q-1);
    ll e;
    for(ll i=2;i<=n1;i++) //finding e using gcd(e,n1)=1
    {
        if(__gcd(i,n1)==1)
        {
            e=i;
            break;
        }


    }
    ll d;
    for(ll i=2;i<=n1;i++) // finding d using (d*e)modn1 =1
    {
        ll temp=((i%n1)*(e%n1))%n1;
        if(temp==1)
        {
            d=i;
            break;
        }

    }
    cout<<"cipher key is: {"<<e<<" , "<<n1<<" }"<<endl<<endl;
    cout<<"decipher key is: {"<<d<<" , "<<n1<<" }"<<endl<<endl;
    cout<<"Enter a text to encrypt"<<endl<<endl;
    string str;
    cin>>str;
    cout<<endl;
    ll len=str.length();
    vector<ll> v;
    for(ll i=0;i<len;i++) // calculating Q=P^e mod n
    {
        ll k=str[i];
        ll res=1;
        for(ll t=1;t<=e;t++)
        {
            res=((res%n)*(k%n))%n;

        }
        res=res%n;

        v.push_back(res);
    }
    ll siz=v.size();
    cout<<"encrypted text is"<<endl;
    for(int i=0;i<siz;i++)
    {
        char c=(char)v[i];
        cout<<c;
    }
    cout<<endl<<endl;

    cout<<"Decrypted text is"<<endl;

     for(ll i=0;i<siz;i++)// Calculating P=Q^d mod n
    {
        ll k=v[i];
        ll res=1;
        for(ll t=1;t<=d;t++)
        {
            res=((res%n)*(k%n))%n;

        }

        char c=(char)res;
        cout<<c;

    }
    cout<<endl;



    return 0;
}












