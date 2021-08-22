#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    int item =4; 
    int l=0;
    int h=n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(item>arr[m]){
             l=m+1;
            
        }else if(item<arr[m]){
            h=m-1;
        }else{
           cout<<m<<endl;
            break;
        }
    }
    
    return 0;
}
