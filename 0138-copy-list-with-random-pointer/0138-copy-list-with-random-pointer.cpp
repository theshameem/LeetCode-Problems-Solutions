/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        unordered_map<Node*, Node*> maps;
        while(temp != NULL){
            maps[temp] = temp->random;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            Node* nxt = temp->next;
            temp->next = newNode;
            newNode->next = nxt;
            temp = nxt;
        }

        temp = head;
        while(temp != NULL){
            if(maps.find(temp) != maps.end()){
                Node* rand = maps[temp];
                if(rand == NULL){
                    temp->next->random = NULL;
                }
                else{
                    temp->next->random = rand->next;
                }
            }
            temp = temp->next;
        }

        temp = head;
        temp = temp->next;
        Node* temp2 = head;
        Node* ans = temp;
        while(temp && temp->next){
            temp2->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = NULL;
        return ans;
    }
};