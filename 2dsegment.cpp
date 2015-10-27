//start of jonathanirvings' template v2.0.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
jonathan ganteng banget;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v2.0.0 (BETA)

int T;
int data[3005][3005];
int tree[12005][12005];
int n;
int a[3005],b[3005],c,x,k;

void build1D(int ix,int ix2,int L,int R,int L2,int R2)
{
  if (L2 == R2)
  {
    tree[ix][ix2] = data[L][L2];
    return;
  }
  int M2 = (L2 + R2) >> 1;
  build1D(ix,ix2*2+1,L,R,L2,M2);
  build1D(ix,ix2*2+2,L,R,M2+1,R2);
  tree[ix][ix2] = max(tree[ix][ix2*2+1],tree[ix][ix2*2+2]);
}

void build2D(int ix,int L,int R)
{
  //debug("%d %d %d\n",ix,L,R);
  if (L == R)
  {
    build1D(ix,0,L,R,0,n-1);
    return;
  }
  int M = (L + R) >> 1;
  build2D(ix*2+1,L,M);
  build2D(ix*2+2,M+1,R);
  FORN(i,0,4*n) tree[ix][i] = max(tree[ix*2+1][i],tree[ix*2+2][i]);
}

int query1D(int ix,int ix2,int L,int R,int ya,int yb)
{
  if (ya <= L && R <= yb)
  {
    //debug("%d %d %d %d %d %d = %d\n",ix,ix2,L,R,ya,yb,tree[ix][ix2]);
    return tree[ix][ix2];
  }
  if (R < ya || yb < L) return -INF;
  int M = (L + R) >> 1;
  int temp1 = query1D(ix,ix2*2+1,L,M,ya,yb);
  int temp2 = query1D(ix,ix2*2+2,M+1,R,ya,yb);
  return max(temp1,temp2);
}

int query2D(int ix,int L,int R,int xa,int ya,int xb,int yb)
{
  //debug("%d %d %d %d %d %d %d\n",ix,L,R,xa,ya,xb,yb);
  if (xa <= L && R <= xb)
  {
    //debug("%d %d %d %d %d %d %d\n",ix,L,R,xa,ya,xb,yb);
    return query1D(ix,0,0,n-1,ya,yb);
  }
  if (R < xa || xb < L) return -INF;
  int M = (L + R) >> 1;
  int temp1 = query2D(ix*2+1,L,M,xa,ya,xb,yb);
  int temp2 = query2D(ix*2+2,M+1,R,xa,ya,xb,yb);
  return max(temp1,temp2);
}

int main()
{
  scanf("%d",&T);
  REPN(cases,T)
  {
    printf("Case #%d: ",cases);
    scanf("%d %d %d %d",&n,&k,&c,&x);
    REP(i,n) scanf("%d",&a[i]);
    REP(i,n) scanf("%d",&b[i]);
    REP(i,n) REP(j,n)
    {
      LL temp = (LL)a[i]*(i+1) + (LL)b[j]*(j+1) + c;
      data[i][j] = temp % x;
    }
    build2D(0,0,n-1);
    LL risan = 0;
    REP(i,n-k+1) REP(j,n-k+1)
    {
      int temp = query2D(0,0,n-1,i,j,i+k-1,j+k-1);
      risan += temp;
      //VALUE(temp);
    }
    printf("%lld\n",risan);
  }
  return 0;
}









