#include<bits/stdc++.h>
using namespace std;
bool comp( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[1] < v2[1];
}
vector<vector<int>> routePairs(int target, vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	int maxSum=-1;
    sort(arr1.begin(),arr1.end(),comp);
    sort(arr2.begin(),arr2.end(),comp);
    int i=0,j=arr2.size()-1;
    int n1=arr1.size(),n2=arr2.size();
    vector<vector<int>>res;

    while(i<n1 && j>=0){    
        int val=arr1[i][1]+arr2[j][1];
        if (val>target)
            j-=1;
        else{
            if (val>=maxSum){

                if (val>maxSum){
                    maxSum=val;
                    res.clear();
                }
                res.push_back({arr1[i][0],arr2[j][0]});
                int temp=j;
                while( j>=0 and arr2[j][1]==arr2[temp-1][1]){
                    res.push_back({arr1[i][0],arr2[temp-1][1]});
                    temp-=1 ;
                }
            }
            i+=1;
        }
    } 
    return res;
	
}
int main()
{
	auto result = routePairs(10000,{{1,3000}, {2,5000}, {3,7000}, {4,10000}}, {{1,2000}, {2,3000}, {3,4000}, {4,5000}});

	for(auto vec: result)
	{
		for(auto num : vec)
			cout<<num<<"\t";
		cout<<"\n";
	}
}