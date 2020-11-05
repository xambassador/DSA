#include<bits/stdc++.h>
using namespace std;
 
bool isSubSequence(char str1[], char str2[], int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return false; 
    if (n == 0) return true; 
  
    // If last characters of two strings are matching 
    if (str2[n-1] == str1[m-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    // If last characters are not matching 
    return isSubSequence(str1, str2, m-1, n); 
} 


int main()
{
    char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
    int m = strlen(large); 
    int n = strlen(small); 
	bool x=isSubSequence(large , small,m,n);

	if(x)
		cout<<"true";
	else
		cout<<"false";
}