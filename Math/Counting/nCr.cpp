typedef long long ll;
struct binomialCoefficient{
    static const int MAXN = 1003;
    ll comb [MAXN][MAXN];
    
    binomialCoefficient() {
        memset(comb,-1,sizeof comb);
    }
    
    //0. Pascal's Rule: recursive | (No Memoization O(2^n))
    ll nCr0(int n, int r) {
        return ((r == 0 || r == n) ? 1 : nCr0(n-1, r-1) + nCr0(n-1, r));
    }
    
    //1. Pascal's Rule: recursive | Top-down approach
    ll nCr1(int n, int k) {
        if(n < k)
            return 0;
        if(k == 0 || k == n)
            return 1;
        if(comb[n][k] != -1)
            return comb[n][k];
        if(n - k < k)
            return comb[n][k] = nCr1(n, n - k);
        return comb[n][k] = nCr1(n - 1, k - 1) + nCr1(n - 1, k);
    }

    //2. Pascal's Rule: iterative | Bottom-up approach
    void nCr2(int N) { // O(N^2) // if you use this you get nCr directly from the array
        memset(comb, 0, sizeof comb);
        comb[0][0] = 1;
        for (int i = 1; i < N; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++)
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
        }
    }

    //3. Multiplicative formula: recursive | Top-down approach
    ll nCr3(int n, int k) { // O(n * k)
        if(n < k)
            return 0;
        if(k == 0 || k == n)
            return 1;
        if(comb[n][k] != -1)
            return comb[n][k];
        if(n - k < k)
            return comb[n][k] = nCr3(n, n - k);	//reduce k to n - k
        return comb[n][k] = n * nCr3(n - 1, k - 1) / k;
    }

    //4. Multiplicative formula: iterative
    int nCr4(int N, int K) { // O(K)
        if(K > N)
            return 0;
        int res = 1;
        for(int i = 1; i <= K; ++i)
            res = (N - K + i) * res / i;
        return res;
    }
};
