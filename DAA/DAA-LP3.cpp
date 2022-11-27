//Fibonacci number using recursion

/*
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n==0){
		return 0;
	}
	
	if(n==1){
		return 1;
	}
	
	int smalloutput1 = fib(n-1);
	int smalloutput2 = fib(n-2);
	return smalloutput1 + smalloutput2;
}

int main(){
	int n, i=0;
	cout<<"\nEnter Number : ";
	cin>>n;
	cout<<"\nFibonacci Series : ";
	
	while(i<n){
		cout<<" "<<fib(i);
		i++;
	}
	
	return 0;		
}
*/


//Fibonacci number using iteration


/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"\nEnter Number : ";
	cin>>n;
	
	cout<<"\nFibonacci : ";
	int t1=0, t2=1, t=0;
	for(int i=1; i<=n; i++){
		
		if(i==1){
			cout<<t1<<" ";
			continue;
		}
		
		if(i==2){
			cout<<t2<<" ";
			continue;
		}
		
		t=t1+t2;
		t1=t2;
		t2=t;
		
		cout<<t<<" ";
	}
	return 0;
}
*/


//N-Queen


/*
#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){
  // Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
  //Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }
  // Upper Right Diagonal
  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;
}

void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << board[i][j] << " ";
      }
    }
    cout<<endl;
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){
    if(isPossible(n,row,j)){
      board[row][j] = 1;
      nQueenHelper(n,row+1);
      board[row][j] = 0;
    }
  }
  return;

}

void placeNQueens(int n){
  memset(board,0,11*11*sizeof(int));
  nQueenHelper(n,0);
}

int main(){
  placeNQueens(4);
  return 0;
}
*/


//Fractional Knapsack

/*

#include<bits/stdc++.h>
using namespace std;

struct Item{
	int value,weight;
};

bool compare(struct Item a,struct Item b){
	double value1 = ((double)a.value/(a.weight));
	double value2 = ((double)b.value/(b.weight));
	
	return value1 > value2;
}

double fKnapsack(struct Item arr[],int W,int n){
	sort(arr,arr+n,compare);
	
	int currW = 0;
	double fValue = 0;
	
	for(int i=0;i<n;i++){
		if(currW + arr[i].weight <= W){
			currW += arr[i].weight;
			fValue += arr[i].weight;
		}
		else{
			int rWeight = W - currW;
			fValue += arr[i].value * ((double)rWeight/arr[i].weight);
			break;
		}
	}
	return fValue;
}

int main(){
	int W = 70;
	Item arr[] = {{60,20}, {70,15}, {80,40}};
	cout<<"Maximum value is "<<fKnapsack(arr,W,3);
	return 0;
}
*/

//Huffman Coding


//Time Complexity  : O(nlogn)   
//Space Complexity : O(n)
/*
#include<bits/stdc++.h>
using namespace std;

class Node
{
	private:
		char data;
		int freq;
		Node *lchild, *rchild;
	public:
		Node(char d, int f=-1)
		{
			data = d;
			freq = f;
			lchild = rchild = NULL;
		}
		Node(Node *lc, Node *rc)
		{
			data = 0;
			freq = lc->freq + rc->freq;
			lchild = lc;
			rchild = rc;
		}
		void traverse(string code="") const
	    {
			if(lchild != NULL)
			{
				lchild->traverse(code+'0');
				rchild->traverse(code+'1');
			}
			else
			{
				cout<<"\n\t"<<setw(10)<<data<<setw(10)<<freq<<setw(15)<<code<<endl;
			}
	    }
		bool operator<(const Node &a) const		//Note:- greater number has priority in pq by default, we have to compare two nodes
		{										// hence, return true if left node has max freq than right node when compare using   
			return freq > a.freq;				// < operator, bcz it will sort priority queue in ascending order
		}
};

void huffman_encoding(string str)
{
	priority_queue<Node> pq;
	vector<int> frequency(256, 0);

	for(int i=0; i<str.size(); i++)
	{
		frequency[str[i]]++;
	}
	for(int i=0; i<256; i++)
	{
		if(frequency[i] > 0)
		{
			pq.push(Node(i, frequency[i]));
		}
	}
	while(pq.size() >1)
	{
		Node *lc = new Node(pq.top());
		pq.pop();
		Node *rc = new Node(pq.top());
		pq.pop();
		pq.push(Node(lc, rc));
	}
	cout<<"\n\t The Huffman Code "<<endl;
	cout<<"\n\t"<<setw(10)<<"Data\t"<<setw(10)<<"Frequency"<<setw(15)<<"Huffman Code"<<endl;
	pq.top().traverse();
}

int main()
{
	string str;

	cout<<"\n\t Enter String to find Huffman Codes : ";
	cin>>str;

	huffman_encoding(str);
}
*/