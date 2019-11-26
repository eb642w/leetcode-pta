#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <algorithm>

#define MAX 300

using namespace std;
bool isMirror = false;


struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* creatNode(int preL, int preR, int inL, int inR, const vector<int>& pre, const vector<int>& in)
{
    if(preL > preR)
    {
        return nullptr;
    }

    node* root = new node;
    root->data = pre[preL];
    root->lchild = root->rchild = nullptr;
    int i;
    for(i = inL;i <= inR;++i)
    {
        if(pre[preL] == in[i])
        {
            if(isMirror)
            {
                for(int j = i+1;j <= inR;++j)
                {
                    if(in[j] == in[i])
                        i = j;
                    else
                        break;
                }
            }

            break;
        }
    }
    int numLeft = i - inL;


    root->lchild = creatNode(preL+1, preL+numLeft,inL,i-1,pre,in);
    root->rchild = creatNode(preL+numLeft+1,preR, i+1,inR,pre,in);

    return root;

}

void post_order(const node* root, vector<int>& out)
{
    if(root == nullptr) return;
    post_order(root->lchild, out);
    post_order(root->rchild, out);

    out.push_back(root->data);
}


/*void check(int root, int endd, vector<int>& pre, vector<int>& in)
{
    if(root > endd) return;
    int p = root + 1;

}*/

int main()
{
    int n;
    vector<int> pre;
    vector<int> in;
    vector<int> out;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    //out.resize(n);

    for(int i = 0;i < n;++i)
    {
        cin >> pre[i];
    }
    in = pre;

    if(in[0] >= in[1])
    {
        sort(in.begin(),in.end());
    }
    else
    {
        isMirror = true;
        sort(in.begin(),in.end(),greater<int>());
    }


    node* root = creatNode(0,n-1,0,n-1,pre,in);

    post_order(root, out);
    if(out.size() != n)
    {
        cout << "NO";
    }
    else{
        cout << "YES" <<"\n";
        for(int i = 0;i < out.size();++i)
        {
            if(i)
                cout <<" "<<out[i];
            else
                cout <<out[i];
        }
    }

    //for(int i = 0;i < out.size();)
    return 0;

}
