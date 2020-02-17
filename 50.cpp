// max number of consecutive primes that sum up to a prime < N;
// max number of consecs ki.....run two loops....one from sstarting...the other from end;
// starting loop emo...keeps track from start...inner loop emo from the right end;
// basic ga inner loop start ayyedi...after knowing that sum till i isnt a prime;
// so now since u already know that the sequence consistsd of n numbers...u start searching from j=i-n-1 from right end;
// as u havent found any new sequence with i...search for a sequence >n from right end;
// bavundi;

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6;

int32_t main()
{
    vector<bool> seive(N,true);
    for(int i=4;i<=N;i+=2)
    {
        seive[i]=false;
    }

    for(int i=3;i*i<=N;i+=2)
    {
        if(seive[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                seive[j]=false;
            }
        }
    }

    vector<int> primes={2};
    for(int i=3;i<=N;i+=2)
    {
        if(seive[i])
        {
            primes.push_back(i);
        }
    }

    vector<int> sum(primes.size(),0);
    sum[0]=2;
    for(int i=1;i<primes.size();i++)
    {
        sum[i]=sum[i-1]+primes[i];
    }

    int n=0,ans=0;
    for(int i=0;i<sum.size();i++)
    {
        if(binary_search(primes.begin(),primes.end(),sum[i]))
        {
            n=i;
            ans=sum[i];
            continue;
        }
        for(int j=i-n-1;j>=0;j--)
        {
            if(sum[i]-sum[j]>N) break; //most imp
            if(binary_search(primes.begin(),primes.end(),sum[i]-sum[j]))
            {
                n=i-j;
                ans=sum[i]-sum[j];
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
