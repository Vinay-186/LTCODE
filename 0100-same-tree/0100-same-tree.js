/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
   let queue = [[p,q]];
   while(queue.length != 0){
       let [node1,node2] = queue.shift();
       if(node1 === null && node2 === null) return true;
       if(node1 === null || node2 === null || node1.val !== node2.val) return false;
       if(node1.left !== null || node2.left != null) queue.push([node1.left,node2.left]);
       if(node1.right !== null || node2.right !== null) queue.push([node1.right, node2.right]);
   }
    return true;
};