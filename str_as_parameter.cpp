#include <iostream>
using namespace std;
struct rec
{
    int l;
    int b;
};
/*void fun(struct rec *p)  // anything happens inside fun will reflect
                         // if we not use ptr then changes doesnt reflect (struct rec
{
    p->l=20;
    p->b=10;
    cout<<p->l<<" "<<p->b<<endl;
}
int main(){
    rec r={10,5};
    fun(&r);
    cout<<r.l<<" "<<r.b<<endl;    // since r is varible we use dot operator to access data
    return 0;
}                        */
struct rec *fun() // fun as pointer to create object
{
    rec *p;
    p = new rec;
    // p= (struct rec*)malloc(sizeof(struct rect))  //in c language
    p->l = 15;
    p->b = 10;
    return p;
}
int main()
{
    rec *ptr = fun(); // fun ki value pointer m store kradiye
    cout << "len = " << ptr->l << " "
         << "breadth = " << ptr->b;
    return 0;
}