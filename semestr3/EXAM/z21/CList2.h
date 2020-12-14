#pragma once
#include <iostream>

template <typename B> class MonoLinkedList
{
private:
    struct ListElement
        {
            B           unit;
            ListElement *nextElement;
        };
    ListElement *top;
public:
    MonoLinkedList()
    {
        top = nullptr;
    }
    MonoLinkedList( B const b )
    {
        top         = new ListElement();
        top->unit   = b;
    }
    MonoLinkedList( MonoLinkedList const &monoLinkedList )
    {
        if( nullptr == monoLinkedList->top )
        {
            top = nullptr;
            return;
        }
        ListElement *tmpElement     = monoLinkedList->top;
        ListElement *tmpElement2    = new ListElement();
        top                         = tmpElement2;
        while( nullptr != tmpElement->nextElement )
        {
            tmpElement2->unit           = tmpElement->unit;
            ListElement *tmpElement3    = new ListElement();
            tmpElement2->nextElement    = tmpElement3;
            tmpElement2 = tmpElement2->nextElement;
            tmpElement  = tmpElement->nextElement;
        }
        tmpElement2->unit           = tmpElement->unit;
        tmpElement2->nextElement    = nullptr;
    }
    ~MonoLinkedList()
    {
        while( nullptr != top )
        {
            ListElement *tmpElement = top;
            top                     = top->nextElement;
            delete tmpElement;
            tmpElement              = nullptr;
        }
    }

    void insertLast( B const b )
    {
        if( nullptr == top )
        {
            ListElement *tmpElement = new ListElement();
            tmpElement->unit        = b;
            top                     = tmpElement;
            return;
        }
        ListElement *tmpElement = top;
        while( tmpElement->nextElement != nullptr )
            tmpElement = tmpElement->nextElement;
        ListElement *tmpElement2    = new ListElement();
        tmpElement2->unit           = b;
        tmpElement->nextElement     = tmpElement2;
    }
    void insertFirst( B const b )
    {
        ListElement *tmpElement = new ListElement();
        tmpElement->unit        = b;
        if( nullptr == top )
        {
            tmpElement->nextElement = nullptr;
            top = tmpElement;
            return;
        }
        ListElement *tmpElement2    = top;
        top                         = tmpElement;
        tmpElement->nextElement     = tmpElement2;
    }
    /*const*/ bool insertAtPos( B const b, int const pos )
    {
        if( 1 > pos )
            return false;
        if( ( nullptr == top )&&( pos > 1) )
        {
            return false;
        }
        if( ( 1 == pos ) )
        {
            insertFirst( b );
            return true;
        }
        ListElement *tmpElement = top;
        for( int i = pos ; i > 2 ; --i )
        {
            if( nullptr == tmpElement->nextElement )
                return false;
            tmpElement = tmpElement->nextElement;
        }
        ListElement *tmpElement2    = new ListElement();
        tmpElement2->unit           = b;
        if( nullptr == tmpElement->nextElement )
        {
            tmpElement->nextElement = tmpElement2;
            return true;
        }
        tmpElement2->nextElement    = tmpElement->nextElement;
        tmpElement->nextElement     = tmpElement2;
        return true;
    }

    void deleteAtPtr( ListElement ptrElement )
    {
        if( nullptr == ptrElement )
            return;
        if( nullptr == ptrElement->nextElement )
        {
            ptrElement = nullptr;
            return;
        }
        ptrElement->unit = ptrElement->nextElement->unit;
        ListElement *tmpElement = ptrElement->nextElement->nextElement;
        delete ptrElement->nextElement;
        ptrElement->nextElement = tmpElement;
    }
    void deleteLast()
    {
        if( nullptr == top )
        {
            return;
        }
        ListElement *tmpElement = top;
        while( tmpElement->nextElement->nextElement != nullptr )
            tmpElement = tmpElement->nextElement;
        delete tmpElement->nextElement;
        tmpElement->nextElement = nullptr;
    }
    void deleteFirst()
    {
        if( nullptr == top )
        {
            return;
        }
        if( nullptr == top->nextElement )
        {
            delete top;
            top = nullptr;
            return;
        }
        ListElement *tmpElement = top;
        top = top->nextElement;
        delete tmpElement;
        tmpElement = nullptr;
    }
    /*const*/ bool deleteAtPos( int const pos )
    {
        if( 1 > pos )
            return false;
        if( nullptr == top )
        {
            return false;
        }
        if( ( 1 == pos ) )
        {
            deleteFirst();
            return true;
        }
        ListElement *tmpElement = top;
        for( int i = pos ; i > 2 ; --i )
        {
            if( ( nullptr == tmpElement->nextElement )||( nullptr == tmpElement ) )
                return false;
            tmpElement = tmpElement->nextElement;
        }
        if( ( nullptr == tmpElement->nextElement )||( nullptr == tmpElement ) )
            return false;
        ListElement *tmptmpElement = tmpElement->nextElement;
        tmpElement->nextElement = tmpElement->nextElement->nextElement;
        delete tmptmpElement;
        return true;
    }

    void clear()
    {
        while( nullptr != top )
        {
            ListElement *tmpElement = top;
            top                     = top->nextElement;
            delete tmpElement;
            tmpElement              = nullptr;
        }
    }

    const B getLast() const
    {
        if( isEmpty() )
            return 0;
        ListElement *tmpElement = top;
        while( nullptr != tmpElement->nextElement )
            tmpElement = tmpElement->nextElement;
        return tmpElement->unit;
    }
    const B getFirst() const
    {
            return top->unit;
    }

    /*const*/ bool isContains( B const b ) const
    {
        if( nullptr == top )
            return false;
        ListElement *tmpElement = top;
        while( nullptr != tmpElement->nextElement )
        {
            if( tmpElement->unit == b )
                return true;
            tmpElement = tmpElement->nextElement;
        }
        return ( tmpElement->unit == b );
    }
    /*const*/ bool isEmpty() const
    {
        return ( nullptr == top );
    }

    /*const*/ unsigned int size() const
    {
        unsigned int c = 0;
        ListElement *tmpElement = top;
        while( nullptr != tmpElement )
        {
            ++c;
            tmpElement = tmpElement->nextElement;
        }
        return c;
    }

    void print() const
    {
        if( isEmpty() )
            std::cout << "There aren't elements!";
        ListElement *tmpElement = top;
        while( nullptr != tmpElement )
        {
            std::cout << tmpElement->unit << std::endl;
            tmpElement = tmpElement->nextElement;
        }
    }
    ListElement& operator = ( ListElement const listElement )
    {
        this->unit = listElement->unit;
        return *this;
    }
};

