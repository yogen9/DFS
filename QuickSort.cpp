#include<iostream>
using namespace std;

quicksort(int a[], int low , int high)
{
    cout<<"\nlow : "<<low<<" | ";
    cout<<"high : "<<high<<endl;
    int pivot=low;
    int d=low;
    int u=high;

    while(1)
    {
        if((high-low)<1)
        {
             cout<<"\n ------break------- \n";
             break;
        }

        if(a[u] <= a[pivot])
        {
            if(a[d]>a[pivot])
            {
                if(d>=u)
                {
                    cout<<"\n\nCross Over :\n";
                    cout<<"\nBefore Swap :"<<endl;
                    for(int i=low;i<=high;i++)
                        cout<<a[i]<<" ";

                    swap(a[u],a[pivot]);
                    pivot=u;
                    cout<<"\nAfter Swap :"<<endl;
                    for(int i=low;i<=high;i++)
                        cout<<a[i]<<" ";
                    cout<<"\n\n -------break------- \n";
                    quicksort(a,low,pivot-1);
                    quicksort(a,pivot+1,high);

                    break;
                }
                else
                {
                    cout<<"\nBefore Swap :"<<endl;
                    for(int i=low;i<=high;i++)
                        cout<<a[i]<<" ";

                    swap(a[d],a[u]);
                    cout<<"\nAfter Swap :"<<endl;
                    for(int i=low;i<=high;i++)
                        cout<<a[i]<<" ";
                    cout<<endl;
                }
            }
            else
                d++;
        }
        else
             u--;
    }
}
int main()
{
    int n;
    cout<<"Enter the Number of values : ";
    cin>>n;
    int a[n]={};
    cout<<"Enter the Values : ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    cout<<endl<<endl;
    cout<<"RESULT : ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
