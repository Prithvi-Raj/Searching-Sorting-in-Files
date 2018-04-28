#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

class one
{
public:
    int linear_search(int arr[], int n, int x)
     {
       cout<<endl<<"******linear search******";
	for(int i=0;i<n;i++)
       {
		if(arr[i]==x)
		{
                  cout<<endl<<x<<" is found at "<<i<<endl;
		}
	}

      }
 int binarySearch(int arr[], int l, int r, int search)
 {  
cout<<endl<<"******Binary search******";    
       	int n, i,first, last, middle;
	first = 0;
	last = r-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		if(arr[middle] < search)
		{
		first = middle + 1;

		}
		else if(arr[middle] == search)
		{
			cout<<endl<<search<<" found at location "<<middle<<"\n";
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}

return 0;
}
int jumpSearch(int arr[], int n, int element)
{
   int jump_step,prev=0;
   jump_step=floor(sqrt(n));
   while(arr[prev]<element)
   {
       if(arr[jump_step]>element || jump_step>=n)
       {
            break;
       }
       else
       {
                prev=jump_step;
                jump_step=jump_step+floor(sqrt(n));
       }
   }
 
   while(arr[prev]<element)
   {
        prev++;
   }
 
   if(arr[prev]==element)
   {
        return prev+1;
   }
   else
   {
        return -1;
   }
 
}

int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            lo = pos + 1;

        else
        {
            hi = pos - 1;
        }
    }
    return -1;
}
int exponentialSearch(int arr[], int n, int x)
{
cout<<endl<<"******Exponential Search******";
cout<<endl<<"Returning to";
    if (arr[0] == x)
        cout<<endl<<"Element found";

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;

    return binarySearch(arr, i/2, min(i, n), x);
}

int ternarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;
 
        if (arr[mid1] == x)  return mid1;
 
        if (arr[mid2] == x)  return mid2;
 
        if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x);

        if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x);

        return ternarySearch(arr, mid1+1, mid2-1, x);
   }
   return -1;
}
};




int main()
{    
    int n = 0; 
    int num;
    int arr[100];
    int count;
    string filename;

    ifstream File;
    cout<<"Enter the filename(e.g num.txt) = ";
    cin>>filename;
    File.open(filename);
    while(!File.eof())
    {
        File >> arr[n];
        n++;
    }

    File.close();

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
int y;
cout<<endl<<"Enter a number to search for = ";
cin>>y;
one search;
clock_t t,t1,t2,t3,t4,t5;
t=clock();
search.linear_search( arr , n , y );
t=clock()-t;
double time_taken =((double)t)/CLOCKS_PER_SEC;
printf("\n Linear search took %f seconds to execute \n", time_taken);
t1=clock();
search.binarySearch( arr, 0 , n , y);
t1=clock()-t1;
double time_taken1 =((double)t1)/CLOCKS_PER_SEC;
printf("\n Binary search took %f seconds to execute \n", time_taken1);
t2=clock();
cout<<endl<<"******Jump search******";
int result=search.jumpSearch(arr, n , y);
      if(result==-1)
      {
            printf("\nElement is not found in the array !\n");
      }
      else
      {
            printf("\nElement %d is present at position %d \n",y,result-1);
      }
t2=clock()-t2;
double time_taken2 =((double)t2)/CLOCKS_PER_SEC;
printf("\n Jump search took %f seconds to execute \n", time_taken2);
int z=sizeof(arr)/sizeof(arr[0]);
t3=clock();
cout<<endl<<"******Interpolation Search******";
int index = search.interpolationSearch(arr, z , y);

    if (index != -1)
{
        printf("\n Element found at index %d \n", index);
}
   else
{
  printf("\n Element not found \n");
}
t3=clock()-t3;
double time_taken3 =((double)t3)/CLOCKS_PER_SEC;
printf("\n Interpolation search took %f seconds to execute \n", time_taken3);
t4=clock();
search.exponentialSearch(arr, z, y);
t4=clock()-t4;
double time_taken4 =((double)t4)/CLOCKS_PER_SEC;
printf("\n Exponential search took %f seconds to execute \n", time_taken4);
t5=clock();
int result1=search.ternarySearch( arr, 0 , n , y);
cout<<endl<<"******Ternary Search******";
if(result1==-1)
      {
            printf("\nElement is not found in the array !\n");
      }
      else
      {
            printf("\nElement %d is present at position %d \n",y,result-1);
      }
t5=clock()-t5;
double time_taken5 =((double)t5)/CLOCKS_PER_SEC;
printf("\n Ternary search took %f seconds to execute \n", time_taken5);
cout<<endl<<endl;
ofstream dfile;
dfile.open("Searchoutput.txt");
cout<<left<<setw(15)<<setfill(' ')<<"S.No"<<" |"<<setw(20)<<"Searching Algorithm"<<" |"<<setw(15)<<"Time taken"<<" |"<<setw(20)<<"Time Complexity"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"1"<<" |"<<setw(20)<<"Linear Search"<<" |"<<setw(15)<<time_taken<<" |"<<setw(20)<<"O(n)"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"2"<<" |"<<setw(20)<<"Binary Search"<<" |"<<setw(15)<<time_taken1<<" |"<<setw(20)<<"O(Log n)"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"3"<<" |"<<setw(20)<<"Jump Search"<<" |"<<setw(15)<<time_taken2<<" |"<<setw(20)<<"O(√n)"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"4"<<" |"<<setw(20)<<"Interpolation Search"<<" |"<<setw(15)<<time_taken3<<" |"<<setw(20)<<"O (log log n))"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"5"<<" |"<<setw(20)<<"Exponential Search"<<" |"<<setw(15)<<time_taken4<<" |"<<setw(20)<<"O(Log n)"<<endl;
cout<<left<<setw(15)<<setfill(' ')<<"6"<<" |"<<setw(20)<<"Ternary Search"<<" |"<<setw(15)<<time_taken5<<" |"<<setw(20)<<"O(Log3(n))"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"S.No"<<" |"<<setw(20)<<"Searching Algorithm"<<" |"<<setw(15)<<"Time taken"<<" |"<<setw(20)<<"Time Complexity"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"1"<<" |"<<setw(20)<<"Linear Search"<<" |"<<setw(15)<<time_taken<<" |"<<setw(20)<<"O(n)"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"2"<<" |"<<setw(20)<<"Binary Search"<<" |"<<setw(15)<<time_taken1<<" |"<<setw(20)<<"O(Log n)"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"3"<<" |"<<setw(20)<<"Jump Search"<<" |"<<setw(15)<<time_taken2<<" |"<<setw(20)<<"O(√n)"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"4"<<" |"<<setw(20)<<"Interpolation Search"<<" |"<<setw(15)<<time_taken3<<" |"<<setw(20)<<"O (log log n))"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"5"<<" |"<<setw(20)<<"Exponential Search"<<" |"<<setw(15)<<time_taken4<<" |"<<setw(20)<<"O(Log n)"<<endl;
dfile<<left<<setw(05)<<setfill(' ')<<"6"<<" |"<<setw(20)<<"Ternary Search"<<" |"<<setw(15)<<time_taken5<<" |"<<setw(20)<<"O(Log3(n))"<<endl;
dfile.close();
cout<<endl<<"Output can be found out in searchoutput.txt\n";
return 0;
}
