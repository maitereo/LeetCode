#include <iostream>
#ifndef RANDOMLIST_H
#define RANDOMLIST_H
#include "RandomList.h"
#endif


class Solution {
public:
    RandomListNode* Clone(RandomListNode* phead1)
    {
        if(!phead1) return NULL;
        RandomListNode *temp, *phead2, *piter;
        for(piter = phead1; piter != NULL; piter = piter->next->next) // insert
        {
            temp = new RandomListNode(piter->label);
            temp->next = piter->next;
            piter->next = temp;
        }

        for(piter = phead1; piter != NULL; piter = piter->next->next) // connect random 
            if(piter->random) piter->next->random = piter->random->next;

        phead2 = phead1->next;
        for(piter = phead1; piter != NULL; piter = piter->next) // split
        {
            temp = piter->next;
            piter->next = temp->next;
            if(piter->next) temp->next = piter->next->next;
            else
            {
                temp->next = NULL;
                piter->next = NULL;
            }
        }
        return phead2;
    }
};