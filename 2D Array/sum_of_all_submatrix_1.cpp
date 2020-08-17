#include<iostream>
using namespace std;
//solution is wrong
int main(){
int arr[100][100];
int m,n;
cin>>m;
cin>>n;

for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>arr[i][j];
}
}

int sum=0;
int li,lj,bi,bj;

for(li=0;li<m-1;li++){
for(lj=0;lj<n-1;lj++){
for(bi=li;bi<m-1;bi++){
for(bj=lj;bj<n-1;bj++){
for(int k=li;k<=bi;k++){
for(int l=lj;l<=bj;l++){
sum+=arr[k][l];
}
}
}
}
}
}
cout<<sum;
}