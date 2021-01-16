/**
Solution 1

Time: O(N)
Space: O(N)

Idea:
Allocate new node for every node of main list, then save it in map corresponding to main list.
Example:
main list ->
        0   1   2   3   4
val:    7   13  11  10  1
next:   13  11  10  1   NULL
random: N   0   4   2   0

newly allocated list ->
We'll allocate new address for every node in main list
Ex.-> new Node(7), new Node(13), new Node(11), new Node(10), new Node(1)

Then save in map, where key of map will be the node of main list
and value of map will be new allocated node
So map[7] = new Node(7), same for rest of the nodes

Now map[any_node] points to new allocated node.
So for setting next pointer, we'll traverse the main list, then set map of main list's next pointer in new list
Ex. ->
map[7]->next = map[7->next]
map[7] is actually newly allocated node of 7 and
map[7->next] is newly allocated node of 13 (7->next)

Same logic goes for random
map[7]->random = map[7->random]
*/

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
        if(!head) return NULL;
        map< Node*, Node*> mp;

        Node *curr = head;
        while(curr) {
            mp[curr] = new Node(curr->val); //creating new node & saving it in map, corresponding to main list
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};

/**
Solution 2

Time: O(N)
Space: O(N)
#Step1: We'll allocate new node for every node of main list, then save it next to the node of main list
Ex:
Assume we've a list like this: 1->2->3->NULL
We'll modify the list like this: 1->1(NAN)->2->2(NAN)->3->3(NAN)->NULL
"NAN - Newly Allocated Node"

#Step2: Then we'll set random pointers.
Consider this list: 1->1(NAN)->2->2(NAN)->3->3(NAN)->NULL
Assume, random of 1 points to node 3.
So we'll set, newly allocated node of 3 , as the random node of newly allocated node 1.
That means,
1(NAN)->random = 1->random->next
=>1(NAN)->random = 3->next
=>1(NAN)->random = 3(NAN)

#Step3: At last, we'll separate newly allocated nodes from list and bring back main given list as it was
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return NULL;
        Node *nextNode = NULL, *curr = head;

        // allocating new node for every node of main list, then saving it next to the node of main list
        while(curr) {
            nextNode = curr->next;

            curr->next = new Node(curr->val);
            curr->next->next = nextNode;

            curr = nextNode;
        }

        // now setting random pointer
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next; // "curr->random->next" node is new allocated node of "curr->random"
            }
            curr = curr->next->next;    // as "curr->next" is new allocated node of "curr"
        }

        // separate newly allocated nodes from list
        curr = head;
        Node *newHead = NULL;
        Node *newList = NULL;
        while(curr) {
            if(!newHead) {
                newHead = curr->next;
                newList = newHead;
                curr->next = curr->next->next;  // bring back main given list as it was
            }
            else {
                newList->next = curr->next;
                newList = newList->next;
                curr->next = curr->next->next;  // bring back main given list as it was
            }
            curr = curr->next;
        }

        return newHead;
    }
};
