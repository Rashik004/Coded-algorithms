//Rashik Hasnat;
///uva, a2oj:Rashik, codeforces, codechef, codemarshal:rashik004;
///git: https://g...content-available-to-author-only...b.com/Rashik004/Coded-algorithms
///LinkedIn:bd.linkedin.com/in/rashikhasnat
///Khulna University of Engineering & Technology (KUET), Khulna
///Bangladesh
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("input.txt","r",stdin)
#define write freopen("output2.txt","w",stdout)
#define vi vector<int>
#define MAX 10000+5
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define Tcase(t) for(int qq=1;qq<=t; qq++)
using namespace std;

#define MAXPAT (1000+5)
#define MAXELE (1000000+3)
char txt[MAXELE],pat[MAXELE];
int lps[MAXELE];
void computeLPSArray(int M);

// Prints occurrences of txt[] in pat[]
int KMPSearch()
{
    int M = strlen(pat);
    int N = strlen(txt);
    int match=0;
    // create lps[] that will hold the longest prefix suffix
    // values for pattern


    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(M);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
            if (j == M)
            {
                match++;
            }
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return match;
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(int M)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    int testCase,match;
    scanf("%d", &testCase);
    Tcase(testCase)
    {
        scanf("%s", txt);
        scanf("%s", pat);
        int match=KMPSearch();
        printf("Case %d: %d\n", qq, match);
    }
    return 0;
}
