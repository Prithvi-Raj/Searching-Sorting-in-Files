#include<iostream>
#include<math.h>
#include<iomanip>
#include<fstream>
#include<bits/stdc++.h>
#include<time.h>
#include<ctime>
#include<string>
#include<chrono>
using namespace std;
using namespace std::chrono;

class one
{
public:
void selectionSort(int arr[], int n)
{
cout<<endl<<"******Selection Sort******";
    int i,j,loc,temp,min;    
 
    for(i=0;i<n-1;i++)
    {
        min=arr[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                loc=j;
            }
        }
 
        temp=arr[i];
        arr[i]=arr[loc];
        arr[loc]=temp;
    }
 
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
cout<<endl;
}

void bubbleSort(int a[], int n)
{
cout<<endl<<"******Bubble Sort******";
int i,j,temp;
   for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
    
    cout<<"\nArray after bubble sort:\n";
    for(i=0;i<n;++i)
        cout<<" "<<a[i];

cout<<endl;
}

void insertionSort(int a[], int n)
{
cout<<endl<<"******Insertion Sort******";
int i,j,temp;

    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
 
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];   
            j=j-1;
        }
 
        a[j+1]=temp;    
    }
 
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
     }
cout<<endl;
}

void shellSort(int a[],int n)
{
cout<<endl<<"******Shell Sort******";
    int gap,i,j,temp;
 
    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i+=1)
        {
            temp=a[i];
            for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
                a[j]=a[j-gap];
            
            a[j]=temp;
        }
    }
cout<<"\nArray after shell sort:\n";
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";

cout<<endl;
}

void quickSort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quickSort(a,l,j-1);
        quickSort(a,j+1,u);
    }
}
 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}

void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
   if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void radixsort(int *input, int n)
{
  int i;
  int maxNumber = input[0];
  for (i = 1; i < n; i++)
  {
    if (input[i] > maxNumber)
      maxNumber = input[i];
  }
  int exp = 1;
  int *tmpBuffer = new int[n];
  while (maxNumber / exp > 0)
  {
    int decimalBucket[10] = {  0 };
    for (i = 0; i < n; i++)
      decimalBucket[input[i] / exp % 10]++;
    for (i = 1; i < 10; i++)
      decimalBucket[i] += decimalBucket[i - 1];
    for (i = n - 1; i >= 0; i--)
      tmpBuffer[--decimalBucket[input[i] / exp % 10]] = input[i];
    for (i = 0; i < n; i++)
      input[i] = tmpBuffer[i];
    exp *= 10;
  }
}

void bucketSort(int a[], int n) 
{
   int SIZE=100; 
   int i, j, k, buckets[SIZE];
    
    for(i = 0; i < SIZE; ++i)
        buckets[i] = 0;
    
    for(i = 0; i < n; ++i)
        ++buckets[a[i]];
        
    for(i = 0, j = 0; j < SIZE; ++j)
        for(k = buckets[j]; k > 0; --k)
            a[i++] = j;
}

int getNextGap(int gap)
{
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

void pigeonholeSort(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; 
    vector<int> holes[range];
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);
     int index = 0;  
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}

void cycleSort (int arr[], int n)
{
    int writes = 0;
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;
        if (pos == cycle_start)
            continue;
        while (item == arr[pos])
            pos += 1;
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }
        while (pos != cycle_start)
        {
            pos = cycle_start;
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;
            while (item == arr[pos])
                pos += 1;
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}
};

int main()
{
    int n = 0;     
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
    one sort;
clock_t t,t1,t2,t3,t4,t5,t6,t7,t8;
t=clock();
    sort.selectionSort(arr , n);
t=clock()-t;
double time_taken =((double)t)/CLOCKS_PER_SEC;
printf("\n Selection Sort took %f seconds to execute \n", time_taken);
t1=clock();
    sort.bubbleSort(arr , n);	
t1=clock()-t1;
double time_taken1 =((double)t1)/CLOCKS_PER_SEC;
printf("\n Bubble Sort took %f seconds to execute \n", time_taken1);

t2=clock();
    sort.insertionSort(arr , n);
t2=clock()-t2;
double time_taken2 =((double)t2)/CLOCKS_PER_SEC;
printf("\n Insertion Sort took %f seconds to execute \n", time_taken2);

t3=clock();
    sort.shellSort(arr , n);
t3=clock()-t3;
double time_taken3 =((double)t3)/CLOCKS_PER_SEC;
printf("\n Shell Sort took %f seconds to execute \n", time_taken3);

t4=clock();
cout<<endl<<"******Quick Sort******"; 
    sort.quickSort(arr, 0 , n-1);
    cout<<"\nArray after sorting:";    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
cout<<endl;
t4=clock()-t4;
double time_taken4 =((double)t4)/CLOCKS_PER_SEC;
printf("\n Quick Sort took %f seconds to execute \n", time_taken4);

int b[n];
t5=clock();
cout<<endl<<"******Merge Sort******";
    sort.mergesort(arr , b , 0 , n-1);
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
t5=clock()-t5;
double time_taken5 =((double)t5)/CLOCKS_PER_SEC;
printf("\n Merge Sort took %f seconds to execute \n", time_taken5);

t6=clock();
cout<<endl<<"******Heap Sort******";
    sort.heapSort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
t6=clock()-t6;
double time_taken6 =((double)t6)/CLOCKS_PER_SEC;
printf("\n Heap Sort took %f seconds to execute \n", time_taken6);

t7=clock();
cout<<endl<<"******Radix Sort******";
    sort.radixsort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
t7=clock()-t7;
double time_taken7 =((double)t7)/CLOCKS_PER_SEC;
printf("\n Radix Sort took %f seconds to execute \n", time_taken7);

t8=clock();
cout<<endl<<"******Comb Sort******";
    sort.combSort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
t8=clock()-t8;
double time_taken8 =((double)t8)/CLOCKS_PER_SEC;
printf("\n Comb Sort took %f seconds to execute \n", time_taken8);

int start_s=clock();
cout<<endl<<"******Bucket Sort******";
    sort.bucketSort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
int stop_s=clock();
double time_taken9 = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 ;
cout << "\nTime taken by Bucket Sort: " << time_taken9 <<" mili seconds "<< endl;

int start_s1=clock();
cout<<endl<<"******Pigeonhole Sort******";
    sort.pigeonholeSort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
int stop_s1=clock();
double time_taken10 = (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 ;
cout << "\nTime taken by Pigeonhole Sort: " << time_taken10 <<" mili seconds "<< endl;


cout<<endl<<"******Cycle Sort******";
    sort.cycleSort(arr , n );
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
     {
     cout<<arr[i]<<" ";
      }
cout<<endl;
return 0;
}
