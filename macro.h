#include <bits/stdc++.h>
using namespace std;



//------------------------- syntax shortening ----------------------
#define ll                  long long int
#define ull                 unsigned long long int
#define el                  cout<<"\n"
#define np                  nullptr
#define endl								"\n"
#define nothing_is              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define hard								int n, sum, res, i, j;
#define pb 									push_back
#define mp                  make_pair

//---------------------- common declaration macro ---------------
#define si(x)	            scanf("%d",&x)
#define sl(x)	            scanf("%lld",&x)
#define ss(s)	            scanf("%s",s)
#define ph(x)							printf("%s\n", "hello world!")
#define pi(x)	            printf("%d\n",x)
#define pl(x)	            printf("%lld\n",x)
#define ps(s)	            printf("%s\n",s)

#define decMatrix(r,c)      int **mat;   mat = new int *[r];   for(int i = 0; i <r; i++){ mat[i] = new int[c]; int j=0; fo(j,c) mat[i][j]=0; }

//---------------------- loop shortening macro ------------------
#define ff(i,n)             for(i;i<n;i++)
#define fr(i,n)             for(i; i>=0;i--)
#define ffr(i,j,n)          for(i,j; i<n, j>=0; i++,j--)
#define whltc(tc)           int tc; si(tc); while(tc--)

//--------------- debugging macro --------------------------
#define px(x)              cout << #x << "=" << x << endl;
#define pxln(x)         cout<< x <<" ";
#define pxy(x, y)          cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define pxyz(x,y,z)        cout << #x << "=" << x << ",\t" << #y << "=" << y << ",\t" << #z << "=" << z << endl;
#define pxyzw(x,y,z,w)     cout << #x << "=" << x << ",\t" << #y << "=" << y << ",\t" << #z << "=" << z << ",\t" << #w << "=" << w << endl;

#define pa(arr,n)        		cout<< #arr << "=" ; for(int i=0;i<n;i++) cout<< arr[i] <<" "; cout<< endl;
#define pm(mat,r,c)      		cout<< #mat << "=" << endl;  for(int i=0; i<r; i++){ for(int j=0; j<c;j++)   cout<<mat[i][j]<<" ";   cout<< endl; } cout<<endl;

#define pv(vec)          		cout<< #vec << "=" ; for(auto ele: vec)  cout<< ele <<" ";  cout<< endl;
#define pvp(vec)						cout<< #vec << "=\n" ; for(auto v: vec)	cout<< v.first <<":"<< v.second << endl;	 cout<< endl;
#define phsmp(map)       		cout<< #map << "=" ;  for(auto pair: map) cout<< pair.first<< " " << pair.second << "\n";  cout<< endl;

#define psep1()            cout<<"\n_________________________"<<" \n";
#define psep2()            cout<<"-------------------------"<<" \n";

//------------------ math macro --------------------------
#define max(a,b)            ((a)>(b)?(a):(b))
#define MIN(a,b)            ((a)<(b)?(a):(b))
#define ABS(a)              ((a)>(0)?(a):-(a))
#define mod                 1000000007
#define prec(x,y)           fixed<<setprecision(y)<<x;
//prec(ans,6)



//----------------------- boolean macro -------------------------
#define                     isKeyExist(hashtbl, key) (hashtbl.find(key)!=hashtbl.end())
#define stlUb(vec, ele)     vector<int>::iterator ub;

