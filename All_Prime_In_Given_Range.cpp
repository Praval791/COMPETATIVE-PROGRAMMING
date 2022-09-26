// ! Date :- 24-07-2022

// * https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1

class IsPrime
{
public:
    // * A simple solution is to iterate through all numbers from 2 to n-1 and for every number check if it divides n
    // ! TC :- O(n)
    bool isPrime1(int n)
    {
        if (n <= 0)
            return false;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    // * Similar approach as isPrime1 By Recursion
    // ! TC :- O(n)
    // ! SC :- O(n)
    bool isPrime2(int n)
    {
        static int i = 2;
        // base condition 1 :-
        if (n <= 1)
            return false;
        // base condition 2 :- [same as end of loop]
        if (n == i)
            return true;
        // termination condition :- [if n divides i, 2 <= i < n]
        if (n % i == 0)
            return false;
        i++;
        return isPrime2(n);
    }
    // * Instead of checking till n, we can check till √n because
    /**
     * * If a number n is not a prime, it can be factored into two factors a and b
     * * Now a and b can't be both greater than the square root of n,
     * * since then the product a * b would be greater than sqrt(n) * sqrt(n) = n.
     * * So in any factorization of n, at least one of the factors must be smaller than the square root of n,
     * * and if we can't find any factors less than or equal to the square root, n must be a prime.
     */
    // ! TC :- O(sqrt(n))
    bool isPrime3(int n)
    {
        if (n <= 0)
            return false;
        int sqrt_n = sqrt(n);
        for (int i = 2; i <= sqrt_n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    // *  It is based on the fact that all primes greater than 3 are of the form 6k ± 1, where k is any integer greater than 0.
    // ! TC :- O(sqrt(n))
    bool isPrime4(int n)
    {
        // base condition 1 :-
        if (n == 2 || n == 3)
            return true;
        // base condition 2 :-
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;
        int sqrt_n = sqrt(n);
        // To check through all numbers of the form 6k ± 1
        // from 5 to √n
        for (int i = 5; i <= sqrt_n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) // first for 6k-1 and then 6k+1
                return false;

        return true;
    }
};

class AllPrime
{
    inline bool inValidRange(int low, int high) { return high > low; }

public:
    // ! TC :- O(n²)
    vector<int> Naive_Approach(int low, int high)
    {
        vector<int> result;
        if (isValidRange(a, high))
            return result;

        for (int i = low; i <= high; i++)
        {
            IsPrime isPrime;
            if (isPrime.isPrime3(i))
                result.push_back(i);
        }
        return result;
    }
    // ! TC :- O(n*log(log(n)))
    // ! SC :- O(n)
    vector<int> SieveOfEratosthenes(int low, int high)
    {
        // first of all find all the prime numbers till high
        vector<int> result;
        vector<bool> markPrime(high + 1, true);
        int sqrt_high = sqrt(high);
        for (int p = 2; p <= sqrt_high; p++)
            // If prime[p] is not changed, then it is a prime
            if (markPrime[p])
                // Update all multiples of p greater than or
                // equal to the square of it.
                // numbers which are multiple of p and are less than p^2
                // have already been marked.
                for (int i = p * p; i <= high; i += p)
                    markPrime[i] = false;

        // Now traverse from low to end in markPrime
        for (int i = max(low, 2); i <= high; i++)
            if (markPrime[i])
                result.push_back(i);

        return result;
    }
};
