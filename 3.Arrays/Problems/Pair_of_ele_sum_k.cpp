#include<bits/stdc++.h>
using namespace std;

void pairof_ele(int arr[], int n, int sum){

    int max = *max_element(arr,arr+n);

    int new_arr[max]={0};

    for (int i = 0; i < n; i++)
    {
        new_arr[arr[i]]++;
    }

    for (int i = 0; i < max; i++)
    {
        if(new_arr[i]!=0){

            for (int j = i+1; j <n ; j++)  {

                if (i+j ==sum){
                    cout<< "the pairs are "<< i <<" "<<  j<< endl;
                }
            }     
                
                
            
            
        }
    }

    
    
    
}



void pairofele_sorted(int arr[], int n, int k){

        int i=0, j=n-1;

        while(i<j){
            if(arr[i]+arr[j]==k){

                cout<< "the pairs are "<<arr[i]<< " "<< arr[j]<<endl;
                i++;
                j--;
            }
            else if( arr[i]+ arr[j]>k){
                j--;
            }
            else{
                j++;
            }
        }
    }

int main(){

    int arr[]={0,6,3,8,10,16,7,5,2,9,14};
    int arr2[]={1,2,3,4,5,6,7,8,9,10};

    int n= sizeof(arr)/sizeof(arr[0]);
    int n1= sizeof(arr2)/sizeof(arr2[0]);

    int sum=10;

    // pairof_ele(arr,n,sum);

    pairofele_sorted(arr2,n1,sum);
    
    return 0 ;
}