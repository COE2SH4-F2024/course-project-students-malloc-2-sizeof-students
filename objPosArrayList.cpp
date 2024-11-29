#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = 200;
    listSize = 0;

    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
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
        for(int i = listSize; i > 0; i--)
        {
            aList[i].pos->x = aList[i - 1].pos->x;
            aList[i].pos->y = aList[i - 1].pos->y;
            aList[i].symbol = aList[i - 1].symbol;
        }

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
    if(index < 0)
    {
        return aList[0];
    }
    else if(index >= listSize && listSize != 0)
    {
        return aList[listSize - 1];
    }

    return aList[index];

}
