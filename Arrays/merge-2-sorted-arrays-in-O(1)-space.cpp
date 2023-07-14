Class Solution{
    public:
        //Most optimal solution using Shell Sort technique (Gap method)
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int len=(n+m);
            
            int gap=(len/2)+(len%2);
            
            while(gap>0)
            {
                int left=0,right=gap;
                
                while(right<len)
                {
                    if(left<n && right>=n) // left->arr1 and right->arr2
                    {
                        swapGreater(arr1,arr2,left,right-n);
                    }
                    else if(left>=n) //left->arr2 and right->arr2
                    {
                        swapGreater(arr2,arr2,left-n,right-n);
                    }
                    else //left->arr1 and right->arr1
                    {
                        swapGreater(arr1,arr1,left,right);
                    }
                    
                    left++; right++;
                }
            
              if(gap==1) break;
            
              gap=(gap/2)+(gap%2); 
            }
        } 
    private:
        void swapGreater(long long arr1[],long long arr2[],int idx1,int idx2)
        {
              if(arr1[idx1]>arr2[idx2])
               {
                   swap(arr1[idx1],arr2[idx2]);
               }
        }
};