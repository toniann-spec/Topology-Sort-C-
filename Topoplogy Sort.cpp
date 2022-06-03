#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <algorithm>


using namespace std;

string scStepList[9] = {"5. Eyecream","Remover","Sunscreen",  "Toner", "Serum","Cleanser","Lipbalm","Exfoliate","Moisturizer\n"};


void printSteps()//function to print steps
{
	int a, b, stepNum=9;

	cout << "\nSkincare Steps: ";
	for (a = 0; a < stepNum; a++)
	{
		cout << "\n";
		cout << "" << scStepList[a];

	}
}
// Class That represent a graph
class Graph 
{
	
	int V; // # of vertices'

	// Pointer to an array containing
	// adjacency listsList
	list<int>* adj;

public:
	// Constructor
	Graph(int V);

	// Function to add an edge to graph
	void addEdge(int u, int v);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}


void Graph::topologicalSort() // The function to do Top Sort
{
	// Create a vector to store indegrees of all vertices and initializes all indegrees as 0.
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists to fill indegrees of vertices.
	for (int u = 0; u < V; u++) 
	{
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	// Creates a queue and enqueue all vertices with indegree 0 after initializing at 0.
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	int cnt = 0;

	// Create a vector to store result (A topological ordering of the vertices)
	vector<int> top_order;
	// while loop dequeue vertices from queue and enqueue adjacents if indegree of adjacent becomes 0
	while (!q.empty()) 
	{
		// Remove front of queue and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// Iterate through all its neighbouring nodes of dequeued node "u" and decrease their in-degreeby 1
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)

			// If function to check if in-degree becomes zero, if so it will be added it to queue
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++; // increment count of visted vertices 
	}

	// to check if there is a cycle in graph
	if (cnt != V) {
		cout << "There exists a cycle in the graph\n";
		return;
	}

	// Print topological order
	for (int i = 0; i < top_order.size(); i++)
		cout << top_order[i] << " ";
	cout << endl;
}


// Driver program to test above functions
 int main()
{
	int choice;
	// Creates a graph for the drawn diagram
	Graph g(9); //nodes
	//Adjacency list
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 6);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);
	
	
	system("cls");
	
	cout << "\t\t\t\t****************************************"<< endl;
    cout << "\t\t\t\t Welcome to Marva's Skincare Routine" << endl;
    cout << "\t\t\t\t****************************************"<< endl;
    cout<<"Select your choice : "<<endl;
    cout<<"1. View Products"<<endl;
    cout<<"2. View Steps"<<endl;
    cout<<"3. About us"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Your Choice is: ";
	cin>>choice;
	
	while (choice!=4) // used to create a user interface
	{	
		 switch(choice)
		 {
		 case 1:
		 system("cls");
		 cout << "\t\t\t\t****************************************"<< endl;
   		 cout << "\t\t\t Welcome to Marva's Skincare Routine" << endl;
         cout << "\t\t\t\t****************************************"<< endl;
         cout <<"This is a list of our Products"<< endl;
         printSteps();
         break;
         
	     case 2:
	     system("cls");
	     cout << "\t\t\t\t****************************************"<< endl;
	   	 cout << "\t\t\t Welcome to Marva's Skincare Routine" << endl;
	     cout << "\t\t\t\t****************************************"<< endl;
	     cout <<"This is a list of our prouducts in Steps"<< endl;
	     printSteps();
	     cout <<"Order of use: Please Enjoy\n"<< endl;
	     g.topologicalSort();
	     break;
	     
	     case 3:
	     system("cls");
	     cout << "\t\t\t\t****************************************"<< endl;
	   	 cout << "\t\t\t Welcome to Marva's Skincare Routine" << endl;
	     cout << "\t\t\t\t****************************************"<< endl;
	     cout << "____________________________________\n";
		 cout << "Group Members\n";
		 cout << "Tavauhni Grant 1901357\n"; 
		 cout << "Toniann Osbourne 1704288\n"; 
		 cout << "____________________________________\n";  
	     break;
	     
	     case 4:
		 system("cls");
	     cout << "Hate to see you leave... PLEASE COME AGAIN  \n"; 
	     break;
	     
	     default:
	     system("cls");
	     cout<< "Choice not available \n";
	     cout<< "Please Enter a Operation\n";
	    }
	}
	char ans;
	cout<< "Do you want to continue (Y/N)?\n";
    cout<< "You must type a 'Y' or an 'N' :";
    cin >> ans;
	
	if ((ans =='Y')or(ans =='y'))
    {
        system("cls");
		main();
	}  
	else{
    	system("cls");
    	exit(1);	
	}
	return 0;
}
                                                                                                                                                                               	                                                                                                 
