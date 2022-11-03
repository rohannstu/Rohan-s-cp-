void seg_sieve(ll l,ll r)
{
    //sieve of eratosthenes
    vector<ll>prime;
    vector<char>isprime(MAX+1,true);
    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;

    for(ll i=3; i*i<=MAX; i+=2)
    {

        if(isprime[i])
        {
            for(ll j=i*i; j<=MAX; j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=MAX; i+=2)
    {
        if(isprime[i]==true)
        {
            prime.push_back(i);
        }

    }
    //sieve of eratosthenes

    vector<char>isPrime(r-l+1,true);

    for(ll i=0; prime[i]*prime[i]<=r; i++)
    {

        ll base,cp;
        cp=prime[i];
        base=(l/cp)*cp;
        if(base<l)
        {
            base=base+cp;
        }
        for(ll j=base; j<=r; j+=cp)
        {
            isPrime[j-l]=false;
        }
        if(base==cp)
        {
            isPrime[base-l]=true;
        }

    }
    if(l==1) isPrime[0]=false;
    for(ll i=0; i<r-l+1; i++)
    {
        if(isPrime[i]==true)
        {
            cout<<(i+l)<<endl;
        }


    }

}
