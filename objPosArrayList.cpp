#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = 200;
    listSize = 0;

    aList = new objPos[arrayCapacity];  // Instantiating aList on heap
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;  // clearing aList from heap
    aList = nullptr;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        // shifting all the elements to the right 
        for(int i = listSize; i > 0; i--)
        {
            aList[i].pos->x = aList[i - 1].pos->x;
            aList[i].pos->y = aList[i - 1].pos->y;
            aList[i].symbol = aList[i - 1].symbol;
        }

        // Inserting thisPos at the head of aList
        aList[0].pos->x = thisPos.pos->x;
        aList[0].pos->y = thisPos.pos->y;
        aList[0].symbol = thisPos.symbol;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        // Adding thisPos to the end of the list
        aList[listSize].pos->x = thisPos.pos->x;
        aList[listSize].pos->y = thisPos.pos->y;
        aList[listSize].symbol = thisPos.symbol;

        listSize++;
    }


}

void objPosArrayList::removeHead()
{
    if(listSize != 0)
    {
        // Shifting elements to the left (except for the first element)
        for(int i = 0; i < listSize; i++)
        {
            aList[i].pos->x = aList[i + 1].pos->x;
            aList[i].pos->y = aList[i + 1].pos->y;
            aList[i].symbol = aList[i + 1].symbol;
        }

        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    // Lazy delete
    if(listSize != 0)
    {
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    if(listSize != 0)
    {
        return aList[0];
    }

}

objPos objPosArrayList::getTailElement() const
{
    if(listSize != 0)
    {
        return aList[listSize - 1];
    }

}

objPos objPosArrayList::getElement(int index) const
{
    // Returns head element if index is negative value
    if(index < 0)
    {
        return aList[0];
    }
    // Returns tail element if index exceeds size of aList
    else if(index >= listSize && listSize != 0)
    {
        return aList[listSize - 1];
    }

    return aList[index];

}