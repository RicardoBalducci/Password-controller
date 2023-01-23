#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
void ltra (char ar[10]);
void num (char *K, char *R);
void constan (char C[10]);
void resp (char ar[10]);
int Num, N=0, Y=1, Verd=0, Fals=0;
int tam;
int main()
{
	char s[10], d[20],c[20];
	cout<<"\n--------------------PASSWORD CONTROLLER---------------------\n";
	cout<<"\n-----------------------INSTRUCTIONS-------------------------\n";
	cout<<"\nEnter a password which you must have:\n 1. It must be between 8 and 15 letters.\n 2. Must contain a lowercase letter.\n 3. Must contain a capital letter.\n 4. Must have at least 3 numbers regardless of position.\n 5. It must have a special character, among which are allowed: *, %, #, &, $\n";
	system("pause");
	system("cls");
		while (N==0||Y==0)
		{
			ltra (s);
			num (s, d);
			constan (d);
		}
		resp (s);
	cout<<"\n\nFailed attempts:  \n\n"<<Fals<<endl;
    cout<<"\n\nSuccessful attempts:  \n\n"<<Verd<<endl;
}
void ltra (char ar[10])
{
	int a=0,b=0,c=0,d=0, e=0;
	char f;
	while(a==0 || b==0)
		{
			cout<<"\n\nenter password\n"<<endl;
    		cin>>ar;
		  	tam=strlen(ar);
		  		while(tam<8 || tam>15)
				{
		  			tam=strlen(ar);
		  			cout<<"\nThe password must contain between 8 and 15 characters\n"<<endl;
		    		cout<<"\n\nEnter another password\n\n"<<endl;
		    		cin>>ar;
				}
				for(int i=0; i<=tam;i++)
					{
 						if((ar[i] >= 'a') && (ar[i] <= 'z'))
							{
        						c=1;
							}	
    					if ((ar[i] >= 'A') && (ar[i] <= 'Z'))
							{
        						d=1;
							}
			    		if((ar[i]=='&')||(ar[i]=='$')||(ar[i]=='*')||(ar[i]=='%')||(ar[i]=='#'))
							{  
    		    				b=1;
							}	
					}
				if(c==1 && b==1)
				{
			   		a=1;
				}
			    if(a==0)
				{
			    	cout<<"\n The password must contain at least one uppercase letter and one lowercase letter. \n";
				}
			    if (b==0)
				{
			    	cout<<"\n Password Must have one of these characters (*,%,#,&,$) \n";
			    }
		}
}
void num (char *K, char *R)
{
	int t=0, o;
	
	tam=strlen(K);
	
	 	for (o=0;o<tam;o++)
		{
			
			if (K[o]=='0'||K[o]=='1'||K[o]=='2'||K[o]=='3'||K[o]=='4'||K[o]=='5'||K[o]=='6'||K[o]=='7'||K[o]=='8'||K[o]=='9')
			{
              R[t]=K[o];
              
              t++;
			}
		R[o] = '\0';
		}
    	Num=strlen(R);
    	if (Num<3)
		{
        cout<<"Password must have at least 3 numbers"<<endl<<endl;N=0;Y=0;
        }
        else
		{
		N=1;Y=1;
		}
}
void constan (char C[10])
{
	int w=0, d=0;
		for( d=0; d<=Num;d++)
		  	{
  				if(1+C[d] == C[d+1])
				{
					w++;
				}
        	}
		if (w>=1)
		{	
			cout<<"Password cannot have consecutive numbers"<<endl;Y=0;
		}
}
void resp (char ar[10])
{
	int z,m=0,as=0;
    char uy[20];
    
    	while(as<3)
		{
    		cout<<"confirm your password"<<endl;
    		cin>>uy;
    		z=strlen(uy);
    		for (int in=0; in<tam; in++)
			{
        		if(uy[in]==ar[in])
				{
        			m++;
				}
			}
    		if(m>=tam)
			{
        		as=5;
        		Verd++;
			}
    		else
			{
    			as++;
    			cout<<"The password does not match the one registered, I try"<<as<<" of 3"<<endl;
			}
    		if(as==3)
			{
				Fals++;
    			cout<<"You exhausted your Attempt Numbers"<<endl;
			}	
	}
}
