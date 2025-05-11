// int i=0,j=0,addnum=2;
        // char dianmeans=" "
        // while(i<s.length()){
        //     if(s[i]==p[j] || p[j]=='.'){
        //         if(p[j]=='.'){
        //             dianmeans=s[i]
        //         }
        //         i++;
        //         j++;
        //     }else if(p[j]=='*'){
        //         j=j-1;
        //         addnum=2;
        //         while(p[j]==p[j+addnum] || p[j+addnum]=='*'){
        //             addnum++;
        //         }
        //     }else if(p[j+1]=='*'){
        //         j=j+addnum;
        //     }else{
        //         return false;
        //     }
        // }
        // if(p[j]=='*'){
        //     j--;
        // }
        // while(j!=p.length()){
        //     //不含.
        //     //x*可消去
        //     if(p[j+1]=='*'){
        //         j++;
        //         j++;
        //     }
        //     else if(p[j]=='.'){
        //         j++;
        //     }
        //     else{
        //         int de=j-1;
        //         while(j>1 && j<p.length() && de>0){
        //             while (de>0 && p[de]=='*' && p[de-1]==p[j]){
        //                 de-=2;
        //             }
        //             while(p[j]==p[de+1]){
        //                 j++;
        //             }
        //         }
                
        //     }  
        // }
        // if(j!=p.length())
        //     return false;
        // else{
        //     return true;
        // }