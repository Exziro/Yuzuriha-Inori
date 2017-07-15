pair<Node<int>*, bool> IsExitsLoop(Node<int>* head)
{
    assert(head);
    Node<int>* fast = head;
    Node<int>* slow = head;
    while (fast&&fast->_next)
    {
        fast = fast->_next->_next;
        slow = slow->_next;
        if (fast == slow)  //�н���Ļ� ˵���л�
            return make_pair(fast, true);
    }
    //������˵������������ֱ�ӷ���
    return make_pair(fast, false);
}