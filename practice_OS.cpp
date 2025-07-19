#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// void calwt(vector<vector<int>>&v,int &avgwt)
// {
// 	wt[0]=0;
// 	for(int i=1;i<n;i++)
// 	{
// 		wt[i]+=(tat[i]-bt[
// }
void calct(vector<vector<int>>&bt,int ct[5],float &avgct)
{
	ct[0]=bt[0][1];
	for(int i=1;i<bt.size();i++)
	{
        // cout<<bt[i][1]<<endl;
		ct[i]=ct[i-1]+bt[i][1];
	}
    avgct=0;
	for(int i=0;i<5;i++)
	{
        avgct+=ct[i];
    }
	avgct/=bt.size();
}
bool val(vector<int>&num1,vector<int>&num2)
{
    if(num1[1]<num2[1])return 1;
    if(num1[1]==num2[1])
    {
        if(num1[0]<num2[0])return 1;
        return 0;
    }
    return 0;
}
bool val2(int num1[2],int num2[2])
{
    if(num1[1]<num2[1])return 1;
    if(num1[1]==num2[1])
    {
        if(num1[0]<num2[0])return 1;
        return 0;
    }
    return 0;
}
// void TAT(int *&ct,int *&t,int *&at,int &avgtat,int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		t[i]+=(ct[i]-at[i]);
// 		avgtat+=t[i];
// 	}
// 	avgtat/=n;
// }
int main(int argc, char const *argv[])
{
    // vector<vector<int>> v;
    // v.push_back({1,2});
   
    // v.push_back({3,4});
    // v.push_back({0,5});
    //  v.push_back({1,3});
    
    // for (int i = 0; i < v.size(); i++)
    // {
    //     /* code */
    //     for(int j=0;j<v[0].size();j++)
    //     {
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> v {{6,2},{2,5},{8,1},{3,0},{4,4}};
    int arr[5][2]={{6,2},{2,5},{8,1},{3,0},{4,4}};
    sort(v.begin(),v.end(),val);
    sort(arr,arr+5,val2);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    int ct[5];float avgct=0;
    calct(v,ct,avgct);
    cout<<avgct<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
