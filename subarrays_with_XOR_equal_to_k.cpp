// Number of subarrays with Xor value m

ll subarrayXor(ll arr[], ll n, ll m)
{
      //declaring the hashtable
      //and initializing it with a count of 1
      //for 0
    unordered_map <ll, ll> HashTable;
    HashTable[0] = 1;
    ll count = 0, curSum = 0;
    for (ll i = 0; i < n; i++)
    {
        curSum ^= arr[i];
        if (HashTable[curSum ^ m] > 0)
            count += HashTable[curSum ^ m];
        HashTable[curSum]++;
    }
    return(count);
}

