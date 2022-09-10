// Segment tree for range sum
class Segment {
    vector<int>seg;
    public:
    Segment(int n)
    {
       seg.resize(4*n+1);
    }
    void build (int ind ,int arr[],int st,int en)
    {
        if(st==en)
        {
            seg[ind]=arr[st];
            return;
        }
        int mid=(st+en)/2;
        build(2*ind+1,arr,st,mid);
        build(2*ind+2,arr,mid+1,en);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    
    void update(int ind,int i,int val,int st,int en)
    {
        if(st==en)
        {
            seg[ind]=val;
            return;
        }
        int mid=(st+en)/2;
        if(i<=mid)
        update(2*ind+1,i,val,st,mid);
        else
        update(2*ind+2,i,val,mid+1,en);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
   
   int querry(int ind,int l,int r,int st,int en)
   {
     if(en<l||r<st)
     return 0;
     if(l<=st&&en<=r)
     return seg[ind];
     int mid=(st+en)/2;
     int leftq=querry(2*ind+1,l,r,st,mid);
     int rightq=querry(2*ind+2,l,r,mid+1,en);
     return (leftq+rightq);
   }
};
class Solution{
public:

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        Segment sg(n);
        sg.build(0,arr,0,n-1);
        vector<int>ans;
        for(int i=0;i+1<2*q;i+=2)
        {
            ans.push_back(sg.querry(0,queries[i]-1,queries[i+1]-1,0,n-1));
        }
        return ans;
    }
};
