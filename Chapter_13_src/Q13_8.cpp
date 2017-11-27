typedef map<Node*, Node*> NodeMap;
Node* copy_recursive(Node *cur, NodeMap *nodeMap){
    if(cur == NULL){
        return NULL;
    }
    NodeMap::iterator i = nodeMap.find(cur);
    if(i != nodeMap.end()){
        return i->second;
    }
    Node *node = new Node;
    nodeMap[cur] = node;
    node->ptr1 = copy_recursive(cur->ptr1, nodeMap);
    node->ptr2 = copy_recursive(cur->ptr2, nodeMap);
    return node;
}
