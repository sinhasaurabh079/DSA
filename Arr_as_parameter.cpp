#include<iostream>
using namespace std;

/*void func( int *a,int n){

    for(int i=0;i<5;i++)
     *(a+i)+=1;
    for(int i=0;i<5;i++)
    cout<<*(a+i)<<" ";
}
 
 int main()
 {
    int arr[]={1,2,3,4,5};
    for(int x:arr) //  for each loop is only valid in array not in pointer
    {
        cout<<x<<" "<<endl;
    }

    func(arr,5);
    return 0;
 }*/
 int * fun(int N){ // creating dynamic array in Heap
    int *p;
    p=new int[N];

    for(int i=0;i<N;i++){
        p[i]=i+1;
    }
    return p;
 }
 int main(){
    int *ptr,size=5;
    ptr=fun(size);
    for(int i=0;i<size;i++)
    cout<<ptr[i]<<" ";
 }