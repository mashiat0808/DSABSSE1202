#include<bits/stdc++.h>
using namespace std;

char tree[100],new_tree[100];
int preorder[100], inorder[100], postoder[100];

int root(char key)
{
    if(tree[0] != '\0') printf("Tree already had root");
    else tree[0] = key;
    return 0;
}

int set_left_child(char key, int parent)
{
    if(tree[parent] == '\0')
        printf("Can't set child at position %d, no parent found\n",2*parent+1);
    else
        tree[(parent*2)+1] = key;
    return 0;
}

int set_right_child(char key, int parent)
{
    if(tree[parent] == '\0')
        printf("Can't set child at position %d, no parent found\n",2*parent+2);
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}

int print_tree()
{
    for(int i=0; i<pow(2,2+1)-1; i++)
    {
        if(tree[i] != '\0')
            printf("%d ",tree[i]);
        else
            printf("_ ");
    }
    return 0;
}

void inorder_traversal(int total , int temp)
{
    if(temp >= total) return;
	if(new_tree[temp] == -1) return;

	inorder_traversal(total,2*temp);
	printf("%d ",new_tree[temp]);
	inorder_traversal(total,2*temp+1);

}

void postorder_traversal(int total , int temp)
{
    if(temp >= total) return;
	if(new_tree[temp] == -1) return;

	postorder_traversal(total,2*temp);
	postorder_traversal(total,2*temp+1);

	printf("%d ",new_tree[temp]);
}

void preorder_traversal(int total , int temp)
{
    if(temp >= total) return;
	if(new_tree[temp] == -1) return;

	printf("%d ",new_tree[temp]);

	preorder_traversal(total,2*temp);
	preorder_traversal(total,2*temp+1);
}
int main()
{
    root(1);
    set_left_child(3,0);
    set_right_child(2, 0);
    set_left_child(5, 1);
    set_right_child(4, 1);
    //set_left_child(7,2);
    set_right_child(6, 2);
    printf("Binary tree represented by array: ");
    print_tree();
    printf("\n");

    int i,j=1, count_with_null=1, count_without_null=0;
    int just = pow(2,2+1)-1;
    for(i=0; i<just; i++)
    {
        new_tree[j] = tree[i];
        if(new_tree[j] != '_') count_with_null++;
        else count_without_null++;
        j++;
    }

    printf("Pre Order form:");  preorder_traversal(count_with_null ,1);     printf("\n");
    printf("In Order form:");  inorder_traversal(count_with_null, 1);      printf("\n");
    printf("Post Order form:");  postorder_traversal(count_with_null, 1);    printf("\n");

}
