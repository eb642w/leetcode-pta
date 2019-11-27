#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX 300

using namespace std;

vector<int>

struct Node
{
    int data;
    int layer;
    Node* lchild;
    Node* rchild;
};

Node* rebulid(int in_L, int in_R, int post_L, int post_R, vector<int>& in, vector<int>& post)
{
    int k = 0;
    static int layer = 1;
    if(post_L > post_R)
        return nullptr;
    Node* root = new Node;
    root->data = post[post_R];
    for(int i = in_L;i <= in_R;++i)
    {
        if(in[i] == post[post_R])
        {
            k = i;
            break;
        }
    }
    int num_left = k - in_L;

    root->rchild = root->lchild = nullptr;
    root->layer = layer;

    layer++;
    root->lchild = rebulid(in_L, k-1,post_L,post_L+num_left-1,in, post);
    root->rchild = rebulid(k+1, in_R, post_L + num_left, post_R - 1, in, post);
    layer--;

    return root;
}

void BFS(Node* root)
{

    /*if(root == nullptr)
        return;
    if(flag)
    {
        flag = false;
        cout << root->data;
    }
    else
    {
        cout <<" "<<root->data;
    }

    if(root->layer % 2)
    {
        BFS(root->lchild);
        BFS(root->rchild);
    }
    else
    {
        BFS(root->rchild)
    }*/
}

int main()
{
    int n;
    cin >> n;
    vector<int> in(n,0);
    vector<int> post(n,0);
    for(int i = 0;i < n;++i)
    {
        cin >> in[i];
    }

    for(int i = 0;i < n;++i)
    {
        cin >> post[i];
    }

    Node* root = rebulid(0,n-1,0,n-1,in,post);
    BFS(root);
    return 0;
}
