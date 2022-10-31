#include <iostream> // open hashing // closed addressing 

#define size 10
using namespace std;

int hashfunc(int key){

    return key%size;
}

int Quadratic_probe(int H[], int key){

    int index= hashfunc(key);

    int i=0;

    while (H[(index+i*i)% size]!=0)
    {
        i++;
    }
    return (index+i*i)%size;
    
}

void insert_into_hash(int H[], int key){

    int index= hashfunc(key);

    if (H[index]!=0)
    {
        index = Quadratic_probe(H,key); // finding the appropriate position 
        // for the key using the linear probe func if the index provided by the hashfunc is already filled
    }
    H[index]=key;
    
}


int Search(int H[], int key){
    int idx = hashfunc(key);
    int i = 0;
    while (H[(idx+i*i) % size] != key){
        i++;
        if (H[(idx + i*i) % size] == 0){
            return -1;
            
        }
    }
    return (idx + i) % size;
}
int main(){

    int H[size]={0};

    int arr[]={33,2,3,5,66,7,8,9,1,11};

    int n=sizeof(arr)/sizeof(arr[0]);

    for (int  i = 0; i < n; i++)
    {
        insert_into_hash(H,arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
    cout<<Search(H,66);
    
    


    return 0 ;
}