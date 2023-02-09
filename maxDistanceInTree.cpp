struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct Info{
     int height;
     int maxDistance;
     Info(int h, int m) : height(h), maxDistance(m) {}
 };

 int maxDiatance(TreeNode *head) {
     return process(head)->maxDistance;
 }

 Info *process(TreeNode *head) {
     if(!head) {
         return new Info(0, 0);
     }
     Info *leftInfo = process(head->left);
     Info *rightInfo = process(head->right);
     Info *info = new Info(max(leftInfo->height, rightInfo->height) + 1, 
     max(max(leftInfo->maxDistance, rightInfo->maxDistance), leftInfo->height + rightInfo->height + 1));
     return info;
 }