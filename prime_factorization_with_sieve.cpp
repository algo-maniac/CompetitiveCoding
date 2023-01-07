// Prime Factorization of any number in O(log n) time with a precomputed sieve

void primeSieveFactorization(vector<ll> &sieve){

	for(ll i=1; i<=N; i++){
		sieve[i] = i;
	}

	//start from 2 to N
	for(ll i=2; i*i<=N; i++){
		//whether a no is prime 
		if(sieve[i]==i){

			for(ll j= i*i; j<=N; j = j + i){
				//mark of them if they are already not marked with the value i
				if(sieve[j]==j){
					sieve[j] = i;
				}
			}
		}
	}

}


ll getFactorisation(ll number, vector<ll> &sieve){
	vector<ll> factors;
	ll cpy=number;
	unordered_map<ll, ll> mp;
	while(number!=1){
		if(mp[sieve[number]]==0){
			factors.push_back(sieve[number]);
			mp[sieve[number]]++;
		}

		number = number/sieve[number];
	}
	if(sieve[cpy]==cpy){
		if(cpy==1){
			return 1;
		}
		else{
			return 2;
		}
	}
	return factors.size();
}
