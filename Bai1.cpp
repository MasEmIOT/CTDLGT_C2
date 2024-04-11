#include<bits/stdc++.h>
using namespace std;

void Partition(int A[], int first, int last){
	if (first>=last) return;
	int c=A[first];
	int i=first+1,j=last;
	while (i<=j){
		while (A[i]<=c && i<=j) i++;
		while (A[j]>c && i<=j) j--;
		if (i<j) swap(A[i],A[j]);
	}
	swap(A[first],A[j]);
	Partition(A, first,j-1);
	Partition(A, j+1,last);
}
void QuickSort(int A[], int N){
	Partition(A,0,N-1);
	
}
void MergeArrays(int A[],int m, int n, int p){
	int i=m,j=n+1;
	while (i<j && j<=p){
		if (A[i]<=A[j]) i++;
		else {
			int x=A[j];
			for (int k=j-1;k>=i;k--) 
				A[k+1]=A[k];
			A[i]=x;
			i++; j++;
		}
	}
}

void Split_Merg(int A[], int first, int last){
	if (first>=last) return;
	int m=(first+last)/2;
	Split_Merg(A,first,m); 
	Split_Merg(A,m+1,last); 
	MergeArrays(A,first,m,last); 
}

void MergeSort(int A[], int N){
	if (N<2) return;
	Split_Merg(A,0,N-1);
}
void printsort( int a[], int n)
{
    for( int i =0; i<n; i++)
      {
        cout<< a[i]<<" ";
      }
   
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for( int i =0; i<n; i++)
       {
        cin>>a[i];
       }
    QuickSort(a, n);
    printsort(a,n);
}