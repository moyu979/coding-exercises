class Solution {
    int max=2147483647,min=-2147483648,omax=214748364;
public:
    int reverse(int x) {
        char c[10]={0};
        unsigned int t,*px=(unsigned int*)&x;
        bool sign=false;
        unsigned int ans=0;
        char size=0;

        if(x<0){
            sign=true;
            t=~(*px)+0x1;
        }else{
            sign=false;
            t=x;
        }

        while(t!=0){
            c[size]=t%10;
            t=t/10;
            size++;
        }
        ans=c[0];
        for(int i=1;i<size;i++){
            if(i==size-1){
                if(ans>omax){
                    return 0;
                }
            } 
            ans=ans*10; 
            ans=ans+c[i];      
        }

        if(ans>max && !sign){
            return 1;
        }else if(ans>(unsigned int)max+1 && sign){
            return 2;
        }else{
            int k=ans;
            if(sign)
                k=-1*ans;
            return k;
        }
    }
};
