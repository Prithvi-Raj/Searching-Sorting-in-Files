#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char** argv) 
{
	int a,i;
	int count=0;
	string filename;
      	string search;
	string line;
  	vector<string> sV;/*vector for soritng*/
  	string word;
	const int N=80;
   	char s[N];
        int position=-1;
        fstream ifile;
	vector<string> strVec;/*vector for storing pattern for searching*/
	string str;
for(i=1;i<argc;++i)
{
cout<<"filename: "<<argv[i]<<endl;
cout<<"****contents of this file****"<<endl;
ifile.open(argv[i]);
if(!ifile)
    {
	cout<<"Error in opening file..!!";
	exit(0);
    }
	while(!ifile.eof())
    {
        ifile.getline(s, N);
        cout<<s<<"\n";
    }
ifile.close();
}

cout<<"\n";
int size;
int j=1;
cout<<" "<<"Enter the words to search for:"<<endl;
cout<<"Enter # to quit \n\n";
while (str!="#")
    {  
        cout<<"Input text No. "<<j<<" here > ";
        cin>>str ;
        strVec.push_back(str);
	j++;
    } 
strVec.pop_back();
int sno=0;
ofstream sfile;
sfile.open("outputsort.txt");
ofstream outfile;
outfile.open("outputraw.txt", ios::app);/*output file*/
for(int d=0;d<150;d++)
{
cout<<"*";
outfile<<"*";
}
cout<<left<<setw(15)<<setfill(' ')<<"S.No"<<" |"<<setw(15)<<"Line No."<<" |"<<setw(15)<<"keyword"<<" |"<<setw(15)<<"Line Data"<<" |"<<setw(15)<<"File Name"<<endl;
outfile<<endl<<left<<setw(15)<<setfill(' ')<<"S.No"<<" |"<<setw(15)<<"Line No."<<" |"<<setw(15)<<"keyword"<<" |"<<setw(15)<<"Line Data"<<" |"<<setw(15)<<"File Name"<<endl;
for(int l=0;l<150;l++)
{
cout<<"*";
outfile<<"*";
}
for(int m=1;m<argc;++m)
{
int count =0;
ifile.open(argv[m]);
if (ifile.is_open())
{	
         while (!ifile.eof())
           { 	     
            getline(ifile,line);
 	    count++;
            for(i=0;i<strVec.size();i++)
            {
              while((position=line.find(strVec[i])) != string::npos)
               {
		sno++;
		cout<<left<<setw(15)<<setfill(' ')<<sno;
		cout<<" |"<<setw(15)<<count<<" |"<<setw(15)<<strVec[i]<<" |"<<setw(15)<<line<<"  |"<<setw(15)<<argv[m]<<endl;
		outfile<<endl<<left<<setw(15)<<setfill(' ')<<sno;
		outfile<<" |"<<setw(15)<<count<<" |"<<setw(15)<<strVec[i]<<" |"<<setw(15)<<line<<"  |"<<setw(15)<<argv[m]<<endl;
		sfile<<left<<setw(15)<<setfill(' ')<<strVec[i]<<setw(15)<<line<<setw(15)<<argv[m]<<endl;
	       break;               
               }
      	     }
           }
ifile.close();
}
}
outfile.close();
cout<<"\n";
cout<<"##Do you want to sort this file##"<<endl<<"* 1 for yes"<<endl<<"* 0 for no"<<endl<<"= ";
cin>>a;
if(a==1)
{
ifstream sfile;
sfile.open("outputsort.txt");
while(!sfile.eof())
{
getline(sfile, line);
sV.push_back(line);
}
     
  cout << "Unsorted words:" << endl;
  for(i = 0; i < sV.size(); i++)
    cout << sV[i] << endl;
  
  cout << "---------------" << endl;
    
  cout << "Sorted words:" << endl;
  sort( sV.begin(), sV.end() );
  for(int i = 0; i < sV.size(); i++)
    cout << sV[i] << endl;
}
else if(a==0)
{
cout<<"file is unsorted"<<endl;
}  
cin.get();
sfile.close();
cout<<"\n";
cout<<endl<<endl<<endl<<endl<<"Important Note:: Please Delete outputsort.txt and outputraw.txt after use"<<endl;
cout<<endl<<endl<<"Your output is in outputraw.txt and sorted content is shown here"<<endl;
cout<<endl<<endl<<endl<<"Thanks for using this program"<<endl<<endl<<endl;
return(0);
}
