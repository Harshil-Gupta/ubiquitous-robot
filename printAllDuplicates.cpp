#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

string printAll(Node* root, vector<string> v);
void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}
unordered_map<string,int> mp;
string printAll(Node* root,vector<string> v){
    
    if(root==NULL)
        return "o";

    string x,y;
    //if(root->left)
        x = printAll(root->left,v);
    //if(root->right)
        y = printAll(root->right,v);
    string temp = to_string(root->data) + " " + x + " " + y;
    v.push_back(temp);
    mp[temp]++;
    return temp;
}

void printAllDups(Node* root)
{
   1 5
10 20 L 20 25 L 10 30 R 30 20 L 20 25 L

    string str = printAll(root,v);
    cout << v.size() << " ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
        mp[v[i]]=0;
    }

}