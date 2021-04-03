#include<bits/stdc++.h>
using namespace std;

string postorder[100],Inorder[100],Tree[100]= {};
int k=1,p;

void create_node(int pos,int start,int End)
{
    if(start>End)
        return;
    int i=start;
    p--;
    if(p>0)
    {
        while(Inorder[i] != postorder[p] && i<=End)
            i++;

        if(Inorder[i] == postorder[p])
        {
            Tree[pos]=Inorder[i];}
            create_node(pos*2+1,i+1,End);
            create_node(pos*2,start,i-1);

    }

}
int main(void)
{
    int j,length;
    cout<<"Enter the number of elements:";
    cin>>length;

    cout<<"Enter postorder:";
    for(j=1; j<=length; j++)
    cin>>postorder[j];

    cout<<"Enter Inorder:";
    for(j=1; j<=length; j++)
    cin>>Inorder[j];

    int i=1,position=1,end_Of_Tree=100;

    Tree[position] = postorder[length];
    while(Inorder[i] != postorder[length])
        i++;

    p=length;
    create_node(position*2+1,i+1,length);
    create_node(position*2,1,i-1);
    while(Tree[end_Of_Tree].empty())
        end_Of_Tree--;

    for(i=1; i<=end_Of_Tree; i++)
    {
        if(Tree[i].empty()) cout<<"-"<<" ";
        else cout<<Tree[i]<<" ";
    }
}
