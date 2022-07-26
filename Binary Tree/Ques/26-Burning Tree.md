# [Burning Tree](https://practice.geeksforgeeks.org/problems/burning-tree/1)

```cpp
class Solution {
  public:
    Node * createParentMaping(Node * root, int target, map<Node *, Node*> &nodeToParent){
        nodeToParent[root] == NULL;
        Node * targetNode = NULL;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node * front = q.front(); q.pop();
            if(front -> data == target) targetNode = front;
            if(front -> left) {
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right) {
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return targetNode;
    }
    
    int burning(Node * targetNode, map<Node *, Node*> &nodeToParent){
        map<Node *, bool> visited;
        queue<Node *> q;
        q.push(targetNode);
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool insertedSomethingInQueue = false;
            
            for(int i = 0; i < size; i++)
            {
                Node * front = q.front(); q.pop();
                
                if(front -> left and !visited[front -> left]){
                    visited[front -> left] = true;
                    q.push(front -> left);
                    insertedSomethingInQueue = true;
                }
                
                if(front -> right and !visited[front -> right]){
                    visited[front -> right] = true;
                    q.push(front -> right);
                    insertedSomethingInQueue = true;
                }
                
                if(nodeToParent[front] and !visited[nodeToParent[front]]){
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                    insertedSomethingInQueue = true;
                }
            }
            
            if(insertedSomethingInQueue == true) time++;
        }
        
        return time;
    }
    int minTime(Node* root, int target) 
    {
        map<Node *, Node *> mp;
        Node * targetNode = createParentMaping(root, target, mp);
        
        return burning(targetNode, mp);
        
    }
};
```