pair<Node<int>*, bool> IsExitsLoop(Node<int>* head)
{
    assert(head);
    Node<int>* fast = head;
    Node<int>* slow = head;
    while (fast&&fast->_next)
    {
        fast = fast->_next->_next;
        slow = slow->_next;
        if (fast == slow)  //有交点的话 说明有环
            return make_pair(fast, true);
    }
    //到这里说明，不带环，直接返回
    return make_pair(fast, false);
}
int length(Node<int>* head)
{
    assert(head);
    if (!IsExitsLoop(head).second)
        return 0;
    Node<int>* node=IsExitsLoop(head).first;
    Node<int>* cur = node->_next;
    int count = 1;
    while (cur != node)
    {
        count++;
        cur = cur->_next;
    }
    return count;
}
Node<int>* FindLoopPort(Node<int>* head)
{
    assert(head);
    Node<int>* node = IsExitsLoop(head).first;
    Node<int>* cur = head;
    while (cur != node)
    {
        cur = cur->_next;
        node=node->_next;
    }
    return cur;
}