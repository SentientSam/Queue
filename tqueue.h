/*
Samuel lamb
COP 3330p
4/26/2019
tqueue.h
*/

#ifndef _TQUEUE_H
#define _TQUEUE_H

namespace fsu
{
    template<typename T>
    class Queue
    {
    public:
      
        void     Push     (const T& t);
        T        Pop      ();
        T&       Front    ();
        const T& Front    () const;
        size_t   Size     () const;
        bool     Empty    () const;
        void     Clear    ();
        void     Append   (const Queue& q);           
        size_t   Capacity () const;                   
        void     Release  ();                      
        Queue   ();
        explicit Queue   (char ofc); 
        Queue   (const Queue&);
        ~Queue  ();
        Queue& operator = (const Queue&);

    public:
        void     Display    (std::ostream& os) const; // output queue contents through os - depends on ofc_
        void     SetOFC     (char ofc);
        void     Dump       (std::ostream& os) const; // output all private data (for development use only)
    
    private:
        char    ofc_;

    private:
        class Link
        {
        Link (const T& t) : element_(t), next_(nullptr){}
        T      element_;
        Link * next_;
        friend class Queue;
        };

        Link * firstUsed_; // head of queue
        Link * firstFree_; // one past last item in queue

        static Link* NewLink (const T& t);
    };
    template <typename T>
    std::ostream& operator << (std::ostream& os, const Queue<T>& q)
    {
    q.Display(os);
    return os;
    };
}
#endif

using namespace fsu;

 
    template <typename T>
    void Queue<T>::Push(const T& t)
    {
      Link *newLink = new Link(t);
      if(!Empty())
      {
        firstFree_ -> next_ = newLink;
      }
      else
      {
        firstUsed_ = newLink;
      }
      firstFree_ = newLink;
    }

 
    template <typename T>
    T Queue<T>::Pop()
    {
      if(Empty())
      {
        std::cerr << "** Queue error: 'Pop()' called on a Empty Queue\n";
      }
      else if(firstUsed_ != firstFree_)
      {
        firstUsed_ = firstUsed_ -> next_;
        return firstUsed_ -> element_;
      }
      else
      {
        T prevElement = firstUsed_ -> element_;
        firstUsed_ = 0;
        firstFree_ = 0;
        return prevElement;
      }
    }


    template <typename T>
    void Queue<T>::SetOFC(char ofc)
    {
      ofc_=ofc;
    }

    
    template <typename T>
    T& Queue<T>::Front()
    {
        if(Empty())
        {
        std::cerr << "** Queue error: 'Front()' called on a Empty Queue\n";
        }
        else
        {
            return firstUsed_ -> element_;
            
        }
    }

  
    template <typename T>
    const T& Queue<T>::Front() const
    {
        if(Empty())
        {
        std::cerr << "** Queue error: 'Front()' called on a Empty Queue\n";
        }
        else
        {
            return firstUsed_ -> element_;
            
        }
    }

 
    template <typename T>
    size_t Queue<T>::Size()const
    {
      Link *lpointer = firstUsed_;
      size_t size = 0;

      while(lpointer != firstFree_)
      {
        size += 1;
        lpointer = lpointer -> next_;
      }
        return size;
    }


    template <typename T>
    bool Queue<T>::Empty()const
    {
        if(firstUsed_ == 0)
        {
          return true;
        }
        else
        {
          return false;
        }
    }

    template <typename T>
    void Queue<T>::Clear()
    {
      Release();
    }

  
    template <typename T>
    void Queue<T>::Release()
    {
      while(!Empty())
      {
        Pop();
      }
    }
  
 
    template <typename T>
    void Queue<T>::Append(const Queue&)
    {
       Queue::Link *lpointer = firstUsed_ -> next_;
       Queue::Link *linkEnd = firstFree_;
       while(lpointer != 0)
       {
         Push(lpointer -> element_);
         lpointer = lpointer -> next_;
         firstFree_ = linkEnd;
       }
    }


    template <typename T>
    Queue<T>::Queue() : ofc_('\0'), firstUsed_(nullptr), firstFree_(nullptr)
    {}

    template <typename T>
    Queue<T>::Queue(char ofc) : ofc_(ofc), firstUsed_(nullptr), firstFree_(nullptr)
    {}

    template <typename T>
    Queue<T>::Queue(const Queue& q) : ofc_(q.ofc_),  firstUsed_(q.firstUsed_), firstFree_(q.firstFree_)
    {
      Append(q);
    }

    template <typename T>
    Queue<T>::~Queue()
    {
      Release();
      delete firstUsed_;
      delete firstFree_;
    }


	template <typename T>
	Queue<T>& Queue<T>::operator=(const Queue& q)
	{
	  firstUsed_ = q.firstUsed_;
	  firstFree_ = q.firstFree_;
	  ofc_=q.ofc_;
    Append(q);
	  return *this;
  }

 
  template <typename T>
	void Queue<T>::Display(std::ostream& os)const
  {
    if (firstUsed_ != 0)
    {
    Queue::Link *lpointer = firstUsed_;
    while (lpointer != firstFree_)
      {
        os << ofc_ << lpointer -> element_;
        lpointer = lpointer -> next_;
      }
    os << ofc_ << lpointer -> element_;
    }
  }

	template <typename T>
	void Queue<T>::Dump(std::ostream& os) const
	{
    if(Empty())
    {
      return;
    }
    Queue::Link *lpointer = firstUsed_;
    Queue::Link *linkEnd = firstFree_;
    if(ofc_ != '\0')
    {
      while(lpointer != nullptr)
      {
        os << ofc_ << lpointer -> element_;
        lpointer = lpointer -> next_;
      }
    }
    else
    {
      while(lpointer != nullptr)
      {
        os << lpointer -> element_;
        lpointer = lpointer -> next_;
      }
    }
    os << ofc_;
    os << linkEnd -> element_;
	}
