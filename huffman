#include<bits/stdc++.h>
using namespace std;

char str[1000];
set<char>character;
map<char,int>frequency;
map<char,string>encode;
map<string,char>decode;

struct node{
          char ch;
          int freq;
          struct node *left,*right;
};
struct node *pq[1000];

struct node* new_node(char a,int f,struct node *left_child,struct node *right_child)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->ch=a;
          temp->freq=f;
          temp->left=left_child;
          temp->right=right_child;
          return temp;

}

void encoding(struct node *temp,string strg)
{
          if(temp->left==NULL&&temp->right==NULL)
          {
                encode[temp->ch]=strg;
                decode[strg]=temp->ch;
                cout<<temp->ch <<":"<<strg<<endl;
                return;
          }
          encoding(temp->left,strg+"0");
          encoding(temp->right,strg+"1");
}

void decoding(string prefix_code)
{
          int i;
          string s;
          for(i=0;prefix_code[i]!='\0';i++)
          {
                s.push_back(prefix_code[i]);
                    if(decode[s]!='\0')
                        {
                            cout<<decode[s];
                            s="";
                        }
          }
}

void max_heapify(int n,int root)
{
          int l=root*2+1,r=root*2+2,largest=root;
          if(l<n&&pq[largest]->freq<pq[l]->freq)largest=l;
          if(r<n&&pq[largest]->freq<pq[r]->freq)largest=r;
          if(pq[largest]->freq!=pq[root]->freq)
          {
                    swap(pq[largest],pq[root]);
                    max_heapify(n,largest);
          }
}
void heap_sort(int n)
{
          int i;
          for(i=n/2-1;i>=0;i--)
                max_heapify(n,i);

          for(i=n-1;i>=0;i--)
          {
                swap(pq[0],pq[i]);
                max_heapify(i,0);
          }
}
void huffman_code()
{
          set<char>::iterator it;
          int i=0,n=character.size();
          for(it=character.begin();it!=character.end();it++)
          {
            pq[i]=new_node(*it,frequency[*it],NULL,NULL);
            i++;
          }
          heap_sort(n);

          while(n)
          {
            struct node *left_child = new node, *right_child = new node;
            left_child=pq[0];
            right_child=pq[1];
            swap(pq[0],pq[n-1]);
            swap(pq[1],pq[n-2]);
            pq[n-2]=new_node('\0',left_child->freq+right_child->freq,left_child,right_child);
            n--;
            heap_sort(n);
          }
          struct node *root=NULL;
          root=pq[0];
          encoding(root,"");
          string pre_code;
          cout<<"Encoded message is:"<<endl;
          for(i=0;str[i]!='\0';i++)
          {
            cout<<encode[str[i]];
            pre_code=pre_code+encode[str[i]];
          }
          cout<<endl;
          cout<<"Decoded message is:"<<endl;
          decoding(pre_code);
}
int main()
{
          FILE *file;
          file=fopen("sample.txt","r");
          char a;
          int i=0;
          while((a=fgetc(file))!=EOF)
          {
            str[i]=a;
            frequency[a]++;
            character.insert(a);
            i++;
          }
          
          huffman_code();
          puts(" ");
          cout<<"Actual message is:\n"<<str<<endl;
}
