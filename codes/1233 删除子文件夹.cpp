class Solution {
public
    vectorstring removeSubfolders(vectorstring& folder) {
        vectorstring r;
        sort(folder.begin(),folder.end());
        for(int i=0;ifolder.size();i++){
            int j=i+1;
            while(jfolder.size() && folder[j].find(folder[i])==0 && (folder[j][folder[i].size()]=='' folder[j][folder[i].size()]=='0')){
                j++;
            }
            r.push_back(folder[i]);
            i=j-1;
        }
        return r;
    }
};
