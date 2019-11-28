#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int a = 0) :data(a), lchild(nullptr), rchild(nullptr){}
};

vector<int> path;
bool isMaxHeap = true;
bool isMinHeap = true;
void insertt(Node* &root, int data, int number)
{
    static bool is_left = true;
    if(root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = nullptr;
        return;
    }
    else
    {
        if(number%2)
        {
            insertt(root->lchild, data, number);
        }
        else{
            insertt(root->rchild, data, number);
        }
    }
}





Node* creat(vector<int>& data, int index)
{

    Node* root = new Node(data[index++]);
    queue<Node*> out;
    out.push(root);
    while(index < data.size() and !out.empty())
    {
        Node* p = out.front();
        out.pop();
        p->lchild = new Node(data[index++]);
        out.push(p->lchild);

        if(index >= data.size()) break;
        p->rchild = new Node(data[index++]);
        out.push(p->rchild);
    }
    return root;
}



void dfs(Node* p)
{
    if(p == nullptr)
    {
        return;
    }
    path.push_back(p->data);
    if(p->rchild == nullptr and p->lchild == nullptr)
    {

        for(int i = 0;i < path.size();++i)
        {
            if(!i)
                cout << path[i];
            else
            {
                cout <<" " <<path[i];
                if(path[i] > path[i-1])
                    isMaxHeap = false;
                else if(path[i] < path[i-1])
                    isMinHeap = false;
            }
        }
        cout << "\n";
        //path.pop_back();
    }
    else
    {
        if(p->rchild != nullptr)
        {
            dfs(p->rchild);
            path.pop_back();
        }

        if(p->lchild != nullptr)
        {
            dfs(p->lchild);
            path.pop_back();
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> data(n,0);
    for(int i = 0;i < n;++i)
    {
        cin >> data[i];
    }

    Node* header = nullptr;
    header = creat(data, 0);
    dfs(header);
    if(isMaxHeap)
        cout << "Max Heap";
    else if(isMinHeap)
        cout << "Min Heap";
    else
        cout << "Not Heap";
    return 0;
}
