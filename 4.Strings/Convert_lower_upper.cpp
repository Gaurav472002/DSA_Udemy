#include <iostream>
using namespace std;

void convert_alpha(char name[])
{
    int LOWER, UPPER=0;
    for (int i = 0; name[i]; i++)
    {
        if (name[i] >= 65 && name[i] <= 90) // convert upper to lower
        {
            name[i] += 32;
            LOWER++;
        }
        

        else if (name[i] >= 97 && name[i] <= 122)
        { // convert upper to lower
            name[i] -= 32;
            UPPER++;
        }
        
    }
    cout << name << endl;
    if (UPPER)
    {
        cout<<"Converted to upper format"<<endl;
    }
    else{
        cout<<"Converted to lower format"<<endl;
    }
    
    
    
}

int main()
{
    char name[] = "GAURAV";
    char name1[] = "gaurav";

    convert_alpha(name);
    convert_alpha(name1);

    return 0;
}