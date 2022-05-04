/*
Author: Davi Augusto Neves Leite
Date: 03/05/2022

Compile with args: -O2 -Wall -Wextra
Execute with args: < input.txt > output.txt

In terminal for Compile (code = name of file): g++ -O2 -Wall -Wextra code.cpp
~ If you want to generate the output file with the same name of your source code, just put (code = name of file): g++ -O2 -Wall -Wextra code.cpp -o code

In terminal for Execute: ./a.out < input.txt > output.txt
~ If you generate the output file with the same name of your source code, remove the ".out" in execution command above.
*/

//#pragma comment(linker, "/stack: 200000000")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define read_file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> tlll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<tlll> vtlll;
typedef vector<string> vs;

#define MAX 100005
#define MOD 1000000007LL
#define inf 1e9
#define INF 1e16
#define EPS 1e-9
#define PI acos(-1)
#define MEMS(x,y) memset (x, y, sizeof (x))
#define MP make_pair
#define PB push_back
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define for_inc(i,a,b) for (int i=(a); i<(b); i++)
#define for_dec(i,a,b) for (int i=(a); i>=(b); i--)
#define FOR_INC(i,a,b) for (ll i=(a); i<(b); i++)
#define FOR_DEC(i,a,b) for (ll i=(a); i>=(b); i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define out(a) cout<<a<<endl
#define out_pair(a) cout<<a.first<<" "<<a.second<<endl
#define DEBUG1 cout<<"Chegou aqui"<<endl
#define DEBUG2(a,b) cout<<a<<": "<<b<<endl

/* Direction Array */
// int fx[]={1, -1, 0, 0};
// int fy[]={0, 0, 1, -1};
// int fx[]={0, 0, 1, -1, -1, 1, -1, 1};
// int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};

/***************** END OF DEFAULT HEADER *****************/



int main(){
    //fast_io;
    //read_file;

    int a;
    cin >> a;

    out(a);
    DEBUG1;
    DEBUG1;
    DEBUG1;

    return 0;
}