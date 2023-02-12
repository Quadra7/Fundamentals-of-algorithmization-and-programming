#include <iostream>  
#include <unordered_map>  
#include <string.h>  
 
using namespace std;  
  
int main() 
{  
    int n, t, k; 
    int length, count = 0, index = 0;  
    char symbol; 
    unordered_map<int, char*> arr;  
     
    cin >> n;  
     
    for (int i = 0; i < n; i++) 
    {  
        cin >> t >> k;  
        switch (t) 
        {  
            case 0:
            {  
                arr[index] = (char*)malloc(k + 1);  
                cin >> arr[index];  
                index++;  
                break; 
            }   
            case 1:
            {  
                free(arr[k]);  
                arr.erase(k);  
                break;  
            }  
            case 2:
            { 
                cout << arr[k] << endl;  
                break;  
            } 
            case 3:
            {  
                count = 0; 
                length = strlen(arr[k]);  
                cin >> symbol; 
                for (int j = 0; j < length; j++)
                { 
                    if (arr[k][j] == symbol) 
                    {
                        count++;  
                    }
                }
                cout << count << endl;  
            }  
        }  
    }  
    return 0; 
}