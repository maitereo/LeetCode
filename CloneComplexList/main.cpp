#include <iostream>
#include <vector>
#ifndef RANDOMLIST_H
#define RANDOMLIST_H
#include "RandomList.h"
#endif
#include "ListConstructor.h"
#include "Clone.h"

/* Idea: duplicate then split

    +---------+
    |         |
    |         v
    A -> B -> C -> D
         ^         |
         |         |
         +---------+
    
    +---------------------+
    |    +----------------+----+
    |    |                v    v
    A -> A' -> B -> B' -> C -> C' -> D -> D'
               ^    ^                |    |
               |    +----------------+----+
               +---------------------+

    +---------+
    |         |
    |         v
    A -> B -> C -> D
         ^         |
         |         |
         +---------+

    +---------+
    |         |
    |         v
    A'-> B'-> C'-> D'
         ^         |
         |         |
         +---------+

*/
int main()
{
    int seq[] = { 1,2,3,4,5,6,7,8 }, randSeq[] = { 5,7,1,6,4,2,3 };

    RandomList randomList;
    std::cout << "before construction\n";
    RandomListNode *phead = randomList.construct(seq, randSeq, sizeof(seq)/sizeof(int));
    std::cout << "Construction done\n";

    RandomListNode *pptr;
    std::cout << "randSeq\nlable\t  ptr\t\t  next\t\t random\n";
    for(pptr = phead; pptr != NULL; pptr = pptr->next)
        std::cout << pptr->label << "\t" << pptr << "\t" << pptr->next << "\t" << pptr->random << std::endl;

    pptr = phead;
    std::cout << "randSeq\nlable\t  ptr\t\t  next\t\t random\n";
    for(int i = 0; i < sizeof(seq)/sizeof(int); ++i)
    {
        std::cout << pptr->label << "\t" << pptr << "\t" << pptr->next << "\t" << pptr->random << std::endl;
        pptr = pptr->random;
    }
    std::cout << std::endl;

    Solution solution;
    RandomListNode* newHead = solution.Clone(phead);

    std::cout << "newlist\nlable\t  ptr\t\t  next\t\t random\n";
    for(pptr = newHead; pptr != NULL; pptr = pptr->next)
        std::cout << pptr->label << "\t" << pptr << "\t" << pptr->next << "\t" << pptr->random << std::endl;
}