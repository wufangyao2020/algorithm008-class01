/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findMatchSubNodeCnt(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode **returnNode) 
{
   if (root == NULL) {
       return 0;
   }
   int matchCnt = 0;
   if ((root->val == p->val) || (root->val == q->val)) {
       matchCnt++;
   }  
   matchCnt += findMatchSubNodeCnt(root->left, p, q, returnNode);
   matchCnt += findMatchSubNodeCnt(root->right, p, q, returnNode);

   if (matchCnt == 2) {
        if (*returnNode == NULL){
            (*returnNode) = root;
        }
   }
   return matchCnt;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode ** returnNode = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *returnNode = NULL;
    findMatchSubNodeCnt(root, p, q, returnNode);
    return (*returnNode);
}