class Solution {
    struct trienode{
        bool wordEnd = false;
        unordered_map<string,trienode*>child;
    };
    // insertion
    void trieInsert(const string&folder, trienode*curr){
        int i = 1;
        while(i<folder.size()){
            string name;
            // extract folder name
            while(i<folder.size() && folder[i] != '/'){
                name.push_back(folder[i]);
                i++;
            }
            // stop if parent folder already exits
            if(curr->wordEnd) return;
            
            // make a newnode if the path doesnot exist
            if(!curr->child.count(name))
            curr->child[name] = new trienode;
                curr = curr->child[name];
                i++;
        }
        curr->wordEnd = true;
    }
    // Traverse the trie to collect result
    void searchTrie(trienode*curr, vector<string>&res, string path){
        if(!curr) return;
        if(curr->wordEnd){
            // remove '/'
            path.pop_back();
            //add path save it
            res.push_back(path);
            return;
        }
        for(auto&[name,child] : curr->child){
            searchTrie(child,res,path+name+"/");
        }
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        trienode* root = new trienode;
        // Insert all folders into the trie
        for(const string& folder: folder){
            trieInsert(folder, root);
        }
        vector<string>res;
        searchTrie(root,res,"/");
        return res;
    }
};