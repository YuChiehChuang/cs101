#include <iostream>
using namespace std;

class myArray{
    public:
        int n;
        int* array;
        int size;
        
        myArray(int size){
            this->size = size;
        }
        
        void recInput(int array[], int n){
            this->array = &array[0];
            this->n = n; 
        }
        
        int recMax(int n){
            if(n == 1){
                return array[0];
            }
            
            return max(recMax(n-1), array[n-1]);
        }
        
        int recSum(int n){
            if(n == 1){
                return array[0];
            }
            
            return recSum(n-1) + array[n-1];
        }
        
        float recAve(int n){
            return recSum(n)/(float)n;
        }
};

int main(){
    int size = 5;
    int array[] = {500,1,2,3,4};
    myArray A(size);
    A.recInput(array, size);
    cout << "The max is: " << A.recMax(size) << endl; 
    cout << "The sum is: " << A.recSum(size) << endl; 
    cout << "The avr is: " << A.recAve(size) << endl; 
    return 0;
}
