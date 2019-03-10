class Solution {
public:
    int maxDepth(Node* root) {
      if(!root)
        return 0;
      queue<Node *> q;
      q.push(root);
      int level = 0;
      while(!q.empty()){
        int lc = q.size();
        while(lc--){
          Node *cur = q.front();
          q.pop();
          for(auto ch : cur->children){
            q.push(ch);
          }
        }
        level++;
      }
      
      return level;
    }
};
