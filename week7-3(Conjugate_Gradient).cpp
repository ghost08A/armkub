#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,i,j,k,count=0;
	cin>>n;
	double arrA[n][n],arrX[n][2],arrB[n];
	double arrR[n][2],keep[n],arrD[n],ans_arrD[n];
	double sum=0,multi=0,start=0,kon,han,divide,lamda,cheak=-1,vac=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j==n)
			{
				cin>>arrB[i];
			}
			else
			{
				cin>>arrA[i][j];
			}
		}
	}
	
	//set x
	for(i=0;i<n;i++)
	{
		cout<<"start"<<i+1<<" = ";
		cin>>start;
		arrX[i][1]=start;
		arrR[i][1] = 25214;
	}
	cout<<endl;
	
	while(true)
	{
		count++;
		cheak = 0;
		for(i=0;i<n;i++)
		{
			multi = 0;
			multi = arrR[i][1]*arrR[i][1];
			cheak += multi;
		}
		cout<<"cheak"<<count<<" = "<<pow(cheak,1.0/2.0)<<endl;
		if(pow(cheak,1.0/2.0)<0.001)
		{
			break;
		}
		/*if(count>=10)
		{
			break;
		}*/
		
		//set 0
		for(j=0;j<n;j++)
		{
			arrX[j][0] = arrX[j][1];
			arrR[j][0] = arrR[j][1];
		}
		
		//RRRRRr
		for(i=0;i<n;i++)
		{
			sum = 0;
			for(j=0;j<n;j++)
			{
				multi = 0;
				multi = arrA[i][j]*arrX[j][0];
				sum += multi;
			}
			arrR[i][1] = sum-arrB[i];
		}
		
		/*for(i=0;i<n;i++)
		{			
			cout<<"R"<<i+1<<" = "<< arrR[i][1]<<endl;
		}*/
		
		//arrD
		if(count ==1)
		{
			for(i=0;i<n;i++)
			{
				arrD[i] = -1*arrR[i][1];
			}
		}
		else
		{
			// multi D1
			for(i=0;i<n;i++)
			{
				sum = 0;
				for(j=0;j<n;j++)
				{
					multi = 0;
					multi = arrR[j][1]*arrA[i][j];
					sum += multi;
				}
				keep[i] = sum;
			}
			
			//multi D2
			kon = 0;
			for(i=0;i<n;i++)
			{
				multi = 0;
				multi = keep[i]*arrD[i];
				kon += multi;
			}
			
			
			// divide D1
			for(i=0;i<n;i++)
			{
				sum = 0;
				for(j=0;j<n;j++)
				{
					multi = 0;
					multi = arrD[j]*arrA[i][j];
					sum += multi;
				}
				keep[i] = sum;
			}
			
			//divide D2
			han = 0;
			for(i=0;i<n;i++)
			{
				multi = 0;
				multi = keep[i]*arrD[i];
				han += multi;
			}
			vac = kon/han;
			//cout<<"vac = "<<vac<<endl;
		
			for(i=0;i<n;i++)
			{
				ans_arrD[i] = arrD[i]*vac;
				
			}
			
			for(i=0;i<n;i++)
			{
				arrD[i] =  (-1*arrR[i][1])+ans_arrD[i];
			}
			
			
		}
		/*for(i=0;i<n;i++)
		{
			cout<<"D = "<<arrD[i]<<endl;
		}*/
		
		//lamda multi
		kon=0;
		for(i=0;i<n;i++)
		{
			multi = 0;
			multi = arrD[i]*arrR[i][1];
			kon += multi;
		}
		
		//lamda divide1
		for(i=0;i<n;i++)
		{
			sum = 0;
			for(j=0;j<n;j++)
			{
				multi = 0;
				multi = arrD[j]*arrA[i][j];
				sum += multi;
			}
			keep[i] = sum;
		}
		
		//lamda divide2
		han = 0;
		for(i=0;i<n;i++)
		{
			multi = 0;
			multi = keep[i]*arrD[i];
			han += multi;
		}
		lamda = (-1*kon)/han;
		//cout<<"lamda = "<<lamda<<endl;
		
		//end lamda
		
		for(i=0;i<n;i++)
		{
			ans_arrD[i] = arrD[i]*lamda;
		}
		/*for(i=0;i<n;i++)
		{
			cout<<"ans_arrD = "<<ans_arrD[i]<<endl;
		}*/
		
		//arrX
		for(i=0;i<n;i++)
		{
			arrX[i][1] =  ans_arrD[i]+arrX[i][0];
		}
		
		//print x--
		cout<<count<<endl;
		for(i=0;i<n;i++)
		{			
			cout<<"X"<<i+1<<" = "<< arrX[i][1]<<endl;
		}
		cout<<"--------------------------------------------------------------------------"<<endl;
		cheak=0;
		for(i=0;i<n;i++)//chack
		{
			multi = 0;
			multi = arrR[i][0]*arrR[i][0];
			cheak += multi;
		}
	}
	
	return 0;
}
