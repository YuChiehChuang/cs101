#include <iostream>
using namespace std;

class MMmanger{
    private:
        int num_of_space;
        int* g_mm;
        int** calloced_p;
    public:
        MMmanger(int size){
            num_of_space = size;
            g_mm = (int*)malloc(num_of_space * sizeof(int));
            calloced_p = (int**)malloc(num_of_space * sizeof(int*));
            for(int i = 0; i < size; i++){
                calloced_p[i] = 0;
            }
        }
        ~MMmanger(){
            free(g_mm);
            free(calloced_p);
        }
        int get_MMCapacity(){
            int num_of_unallocated_space = 0;
            for(int i = 0; i < num_of_space; i++) {
                if(!calloced_p[i]) {
                    num_of_unallocated_space++;
                }
            }
            return num_of_unallocated_space;
        }
        void print_calloc_array(int flag, int size){
            cout << "Capacity:" << get_MMCapacity() << " - ";
            for(int i = 0; i < num_of_space; i++){
                (calloced_p[i])? (cout << "1") : (cout <<"0");
            }
            if(!flag){
                cout << " <- Out of space : demand " << size;
            }
            if(get_MMCapacity() == 0)cout << " <- No space";
            cout << endl;
        }
        int* alloc_MM(int size){
            int index,av_size = 0;
            for(index = 0; index < num_of_space; index++){
                (!calloced_p[index])?(av_size++):(av_size = 0);
                if(av_size == size){
                    index -= size-1;
                    break;
                }
            }
            if(av_size < size){
                print_calloc_array(0,size);
                return NULL;
            }
            for(int i = 0; i < size; i++){
                calloced_p[index+i]=&g_mm[index];
            }
            print_calloc_array(1,0); 
            return &g_mm[index];
        }
        void free_MM(int* p){
            for(int i = 0; i < num_of_space; i++){
                if(calloced_p[i] == p){
                    calloced_p[i] = NULL;
                }
            }
            print_calloc_array(1,0);
        }     
};


int main(){
    MMmanger mmer(10);
    int* p1 = mmer.alloc_MM(1);
    int* p2 = mmer.alloc_MM(2);
    int* p3 = mmer.alloc_MM(3);
    int* p4 = mmer.alloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int* p5 = mmer.alloc_MM(6);
    return 0;
}
