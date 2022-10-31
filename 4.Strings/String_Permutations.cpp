//Function for printing all the permutations of a string

#include <iostream>
using namespace std;

void string_permutations(char str1[], int k){ // Time complexity  O(n^2)

    static int arr1[10]={0};

    static char result_arr[10];

    if (str1[k]=='\0')
    {   
        cout<<result_arr<<" ";
    }
    else{
        for (int i = 0; str1[i]; i++)
        {
            if (arr1[i]==0)
            {
                result_arr[k]=str1[i];
                arr1[i]=1;
                string_permutations(str1,k+1);
                arr1[i]=0;
            }
            
        }
        
    }
    

}

void string_swap_permu(char str1[], int low , int high){ // Time complexity O(n*n!)
    int i;
    if(low==high){
        cout<<str1<<" "<<endl;
    }
    else{
        for ( i = low; i <= high; i++)
        {   
            cout<<"the value of i is "<<i<<endl;
            swap(str1[low],str1[i]);
            cout<<"the value of ->i is "<<i<<endl;
            string_swap_permu(str1,low+1,high);
            swap(str1[low],str1[i]); // To form the original string again
        }
        
    }
}

int main(){

    char str1[]= "ABC";
    // string_permutations(str1,0);

    string_swap_permu(str1,0,2);
    cout<<endl;
    cout<<str1<<endl;
    
    return 0 ;
}