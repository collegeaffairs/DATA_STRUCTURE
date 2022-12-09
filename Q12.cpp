#include<iostream>
using namespace std;


template <typename T>
class Sorting
{		T n;
		T *arr;
	public:
		Sorting( int s)
    {
	    arr= new T[s];
	    n= s;
	
  }
		void input()
    {
      cout<<"\nENTER THE DATA YOU WANT TO SORT :";
	    for(int i = 0; i<n; i++)	
	    {
		    cin>>arr[i];
	    }
    }
		void display()
    {
      for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
      cout << endl;
    }
		void selectionSort()
    {
      T temp;
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
          if(arr[i]>arr[j])
          {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }
        }
      }
    }
		void bubbleSort()
    {	
      T temp;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n-i-1;j++)
        {
          if(arr[j]>arr[j+1])
          {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }
        }
      }
    } 

		void insertionSort()
    {
      T key;
      int i, j;  
       for (i = 1; i < n; i++) 
       {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
      }  
    }
};


int main()
{
	  int choice, n;

	  cout<<"\nHow many elements you wish to enter:  ";
  	cin>>n;
    
	  Sorting<int>st(n) ;
    st.input();
    cout << "Array before sorting: ";
    st.display();
  
    cout<<"~~~~Select~~~~~"<<endl;
    cout<<"1 - INSERTION SORTING"<<endl;
    cout<<"2 - BUBBLE SORTING"<<endl;
    cout<<"3 - SELECTION SORTING "<<endl;
    cout<<"4 - Exit"<<endl;

    bool flag = false;
	  while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	  cin >> select;
	  switch(select){
		  case 1:
        st.insertionSort();
        cout << "\nArray after Insertion Sorting:\n ";
        st.display();
        cout<<endl;
        break;

			case 2:
        st.bubbleSort();
   			cout << "\nArray after Bubble Sorting:\n ";
   			st.display();
   			cout<<endl;
        break;

      case 3: 
        st.selectionSort();
        cout << "\nArray after Selection Sorting: "<<endl;
        st.display();
        cout<<endl;
        break;

		  case 4:
		  	flag = true;
			  break;

		  default:
				cout << "Invalid Value";
        break;
							
	}
	
}
} 
