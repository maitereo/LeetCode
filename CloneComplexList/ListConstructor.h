#include <iostream>
#include <vector>
#ifndef RANDOMLIST_H
#define RANDOMLIST_H
#include "RandomList.h"
#endif

class RandomList
{
    void createNode(RandomListNode* node, int seq[], int iter, int size)
    {
        if(iter == size) return;
        node->next = new RandomListNode(seq[iter]);
        createNode(node->next, seq, iter+1, size);
    }

    void connectRandom(RandomListNode* phead, int randSeq[])
    {
        RandomListNode *pnode = phead, *prand;
        int index = 0;
        while(pnode)
        {
            if(randSeq[index])
            {
                prand = phead;
                for(int i = 1; i < randSeq[index]; ++i)
                    prand = prand->next;
                pnode->random = prand;
            }
            pnode = pnode->next;
            index++;
        }
        
    }

    public:
    RandomListNode* construct(int seq[], int randSeq[], int size)
    {
        RandomListNode* head = new RandomListNode(seq[0]);
        createNode(head, seq, 1, size);
        connectRandom(head, randSeq);
        return head;
    }
};