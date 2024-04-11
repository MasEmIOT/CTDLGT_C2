#include<bits/stdc++.h>
using namespace std;
int PrimeCheck(int n) // Kiểm tra số nguyên tố
{
    int count = 0;
    for (int i = 2; i <= n; i++){

        if (n % i == 0) {
            count++;
        }
        if (count == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void BlumCheck(int n) // Kiểm tra số nửa nguyên tố Blum
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n))
            {
                cout << n << " la so Blum: " << n << " = " << i << "*" << n / i << endl;
                return;
            }
        }
    }
    cout << n << " khong phai so Blum" << endl;
}

bool BlumCheck2 (int n) // Kiểm tra số nửa nguyên tố Blum
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{    
    int N;
    cout<<" nhap vao N:";
    cin>>N;
    for(int i=1; i <= N; i++)
    {
        for(int j=i; j <= N; j++)
        {   
            if(BlumCheck2(i) && BlumCheck2(j) && BlumCheck2(i+j) && (i+j)<= N)
            {
                cout <<" (" <<i << ";" << j << ") la cap so blum va tong la: " << i+j << " la so Blum." << endl;
            }
        }
    }
    int M;
    cout<<" nhap vao so M: ";
    cin>>M;
    BlumCheck(M);
    return 0;
}