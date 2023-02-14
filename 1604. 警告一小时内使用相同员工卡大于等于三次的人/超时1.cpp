// for(int i=0;i<keyName.size();i++){
        //     int minutetime=(keyTime[i][0]-'0')*10*60+(keyTime[i][1]-'0')*60+(keyTime[i][3]-'0')*10+(keyTime[i][4]-'0');
        //     t.push_back(minutetime);
        //     bool same=false;
        //     for(int j=0;j<pare.size();j++){
        //         if(pare[j].name==keyName[i]){
        //             pare[j].times.push_back(minutetime);
        //             same=true;
        //             break;
        //         }
        //     }
        //     if(!same){
        //         worker w=worker();
        //         w.name=keyName[i];
        //         w.times.push_back(minutetime);
        //         pare.push_back(w);
        //     }
        // }
        // for(int j=0;j<pare.size();j++){
        //     if(pare[j].times.size()<3){
        //         continue;
        //     }
        //     else if(pare[j].times.size()>24){
        //         retu.push_back(pare[j].name);
        //         continue;
        //     }
        //     else{
        //         sort(pare[j].times.begin(),pare[j].times.end());
        //         for(int i=0;i<pare[j].times.size()-2;i++){
        //             if(pare[j].times[i+2]-pare[j].times[i]<=60){
        //                 retu.push_back(pare[j].name);
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        // sort(retu.begin(),retu.end());