//KULDEEP NATH
//19HCS4029
//SET IMPLEMENTATION

#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;

template <class Y>
class MySet
{
    Y *set ;
    int size;
    public : 
    MySet()
    {
        size = 0;
    }

// PARAMETERISED CONSTRUSTOR
    MySet(int n)
    {
        size = n;
        set = new Y[size];
        //input_set();
    }

// TO DISPLAY SET IN READABLE FORMAT 
    void display_set()
    {
        if(size>0)
        {
            cout<<"\n#S= {";
            for(int i=0;i<size;i++)
                cout<<set[i]<<( (i == size-1)?'}':',' );
        }
        else
            cout<<"\n#S = { }";
        
        cout<<endl;
    }

// TO INPUT SET
    MySet input_set()
    {
        if(size)
        {
        	cout<<"\n->Enter Elements of set  : \n";
	        for(int i=0;i<size;i++)
	            cin>>set[i];
	        remove_duplicate();
		}
        
        return *this;
    }
    
// TO REMOVE DUPLICATES
    void remove_duplicate()
    {
        for(int i=0;i<size;i++)
        {
            for(int j = 0 ;j<size;j++)
            {
                if( set[i] == set[j] && i!=j)
                {
                    size--;
                    for(int k=i;k<size;k++)
                        set[k] = set[k+1];
                    i--;
                }
            }
        }
    }
// TO RETURN CARDINALITY
    int get_cardinality()
    {
        return size;
    }
    void change_cardinality(int a)
    {
        size = a;
    }

//OVERLOADING

// OVERLOADING + FOR UNION
    MySet operator + ( MySet ob)
    {
        int n = ob.get_cardinality()+size;
        MySet temp(n);
        int j = 0;
        for(int i =0;i<n;i++)
        {
            if(i<ob.get_cardinality())
                temp.set[i] = ob.set[i];
            else
                temp.set[i] = set[j++];
        }
        temp.remove_duplicate();
        return temp;
    }

//OVERLOADING * FOR INTERSECTION
    MySet operator * ( MySet ob)
    {
        int n = (ob.get_cardinality()<size) ? ob.get_cardinality() : size;
        MySet temp(n);
        int k = 0;
        for(int i =0;i<ob.get_cardinality();i++)
        {
            for(int j=0;j<size;j++)
            {
                if(ob.set[i] == set[j] )
                temp.set[k++] = set[j];
            }
        }
        temp.change_cardinality(k);
        temp.remove_duplicate();
        return temp;
    }

//OVERLOADING - FOR DIFFERENCE
    MySet operator - (MySet ob)
    {
    	int k=0;
    	MySet temp(size);
		for(int i=0;i<size;i++)
		{
			int f=0;
			for(int j=0;j<ob.size;j++)
				if(set[i]==ob.set[j])
				{
					f=1;	
					break;		
				}
				
			if(!f)
				temp.set[k++]=set[i];
		 } 
		temp.change_cardinality(k);
        return temp;
    }

//OVERLOADING ^ FOR SYMMETRIC DIFFERENCE
    MySet operator ^ (MySet ob)
    {
		MySet temp(size+ob.size);
		temp = (*this + ob) - (*this * ob);
		return temp;
    }

//OVERLOADING == FOR EQUALITY
bool operator == (MySet ob)
	{	
		
		if(size==ob.size)
		{
			int f1=0;
		    int f2=1;
	      	for(int i=0;i<size&&f2;i++)
			{
				f1=0;
				for(int j=0;j<size;j++)	
					if(set[i]==ob.set[j])
			  	    {   
						 f1=1;	
						 break; 
			   		}

				if(f1==0)
					f2=0;
		}
			if(f2)
				return true;
			else
				return false;
		}
		else
			return false;
	}

//OVERLOADING = AS ASSIGNMENT OPERATOR
	MySet &operator= (const MySet& ob)
	{
		size = ob.size;
		set = new Y[size];
		for(int i=0;i<size;i++)
			set[i] = ob.set[i];
			
		return *this;
	}

// POWER SET    
    void genpowerset(int size)
	{
		cout<<"\n->S= {";
		for(int i=0;i<pow(2,size);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<size;j++)
			{
				if(t&1)
				{
					cout<<set[j]<<" ";
				}
				t=t>>1;
				
			}
			cout<<"}";
			cout<<((i<pow(2,size)-1)?',':'}');
		}
		cout<<"\nThe cardianality of power set is: "<<pow(2,size)<<endl;	
	}
	
//	COPY CONSTRUCTOR
	MySet (const MySet &ob)
	{
		size=ob.size;
		set = new Y[size];
		for(int i=0;i<size;i++)
			set[i]=ob.set[i];
	}
};

/*

void functions(int choice,Y typevar)
{
	
	
	switch(choice)
	{
		case 1:
			{
				
			}
			break;
		case 2:
		
			break;
		case 3:
			{
				
			}
			break;
		case 4:
			{
			
			}
			break;
		case 6:
			{
				
			}
			break;
	}
}
*/

template <typename Y>
void menu(Y typevar)
{
	
	system("cls");
	cout<<"\n";
	int elements;
	cout<<"\n->Enter no of elements for 1st set : ";
	cin>>elements;
	MySet<Y> ob1(elements);
	ob1.input_set();
	ob1.display_set();
	
	
	cout<<"\n->Enter no of elements for 2nd set : ";
	cin>>elements;
	MySet<Y> ob2(elements);
	ob2.input_set();
	ob2.display_set();
	
	while(1)
	{
		system("cls");
		cout<<"\n\n#####################  MENU  ##########################";
		cout<<"\n1. Union";
		cout<<"\n2. Intersecton";
		cout<<"\n3. Difference";
		cout<<"\n4. Set Difference";
		cout<<"\n5. Compare";
		cout<<"\n6. Power Set";
		cout<<"\n7. Exit";
		cout<<"\n\n->Enter your choice :- ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"\nUnion : ";
					MySet<Y> result=ob2+ob1;
					result.display_set();
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 2:
				{
					cout<<"\nIntersection : ";
					MySet<Y> result=ob1*ob2;
					result.display_set();
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 3:
				{
					cout<<"\nDifference : ";
					MySet<Y> result=ob1-ob2;
					result.display_set();
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 4:
				{
					cout<<"\nSymmetric Difference  : ";
					MySet<Y> result=ob1^ob2;
					result.display_set();
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 6:
				{
					system("cls");
					cout<<"\n";
					int elements;
					cout<<"\n->Enter no of elements for the set : ";
					cin>>elements;
					MySet<char> ob(elements);
					ob.input_set();
					ob.display_set();
					cout<<"\nPower Set : ";
					ob.genpowerset(ob.get_cardinality());
					
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 5:
				{
					if(ob1 == ob2)
						cout<<"\nEQUAL SET";
					else
						cout<<"\nUNEQUAL SET";
						
					cout<<"\n\n-->Press Enter to continue....";
					getch();
				}
				break;
			case 7:
				exit(0);
			default :
				break;
		}
		
	}
}

int main()
{
	while(1)
	{
		int choice;
    
    	int i;
    	char c;
    	float f;
    	
    	cout<<"################ SELECT TYPE OF ELEMENTS ####################  \n";
    	cout<<"\n1.INT";
    	cout<<"\n2.CHAR";
    	cout<<"\n3.FLOAT";
    	cout<<"\n4.EXIT THE PROGRAM";
    	cout<<"\n->Enter your choice :-";
    	cin>>choice;
    	
    	switch(choice)
    	{
    		case 1: 
				menu(i);
    				break;
    				
    		case 2: 
				menu(c);
    				break;
    				
    		case 3: 
				menu(f);
    				break;
    		case 4:
				exit(0);
				break;		
    		default: cout<<"Invalid choice!!!";
  		
		}
	}
    return 0;
}
