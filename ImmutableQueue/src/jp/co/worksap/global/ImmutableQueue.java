package jp.co.worksap.global;
import java.util.NoSuchElementException;

/**
* The Queue class represents an immutable first-in-first-out (FIFO) queue of objects.
* @param <E>
*/
public class ImmutableQueue<E> {
	
	public 
	EachNode<E> HeadNode;
	EachNode<E> TailNode;
	int QueueSize;
	
	/**
	* requires default constructor.
	*/
	public ImmutableQueue() 
	{
		QueueSize = 0;
		HeadNode = null;
		TailNode = null;
		// modify this constructor if necessary, but do not remove default constructor
	
	}
	
	//Constructor by another EachNode element
	public ImmutableQueue(E oneNode) 
	{
		if(oneNode == null)
		{
			HeadNode = null;
			TailNode = null;
			QueueSize = 0;
		}
		else
		{
			HeadNode = new EachNode<E>(oneNode);
			TailNode = HeadNode;
			QueueSize = 1;
		}
	}
	
	//Constructor by another ImmutableQueue
	public ImmutableQueue(ImmutableQueue<E> formerQueue)
	{
		if(formerQueue == null || formerQueue.HeadNode == null)
		{
			HeadNode = null;
			TailNode = null;
			QueueSize = 0;
		}
		else
		{
			QueueSize = formerQueue.size();
			HeadNode = new EachNode<E>(formerQueue.HeadNode.element);
			
			EachNode<E> Iteration = new EachNode<E>();
			Iteration = formerQueue.HeadNode;
			TailNode = HeadNode;
			
			if(formerQueue.HeadNode != formerQueue.TailNode)
			{
				while(Iteration.next!=formerQueue.TailNode)
				{
					Iteration = Iteration.next;
					TailNode.next = new EachNode<E>(Iteration.element);
					TailNode = TailNode.next;
				}
				TailNode.next = new EachNode<E>(Iteration.next.element);
				TailNode = TailNode.next;
			}
		}
	}
	
	// add other constructors if necessary
	
	
	/**
	* Returns the queue that adds an item into the tail of this queue without modifying this queue.
	* <pre>
	* e.g.
	* When this queue represents the queue (2, 1, 2, 2, 6) and we enqueue the value 4 into this queue,
	* this method returns a new queue (2, 1, 2, 2, 6, 4)
	* and this object still represents the queue (2, 1, 2, 2, 6) .
	* </pre>
	* If the element e is null, throws IllegalArgumentException.
	* @param e
	* @return
	* @throws IllegalArgumentException
	*/
	public ImmutableQueue<E> enqueue(E e) 
	{
		if(e == null)
			throw new IllegalArgumentException();
		ImmutableQueue<E> AdderQueue;
		if(this.HeadNode == null)
		{
			AdderQueue = new ImmutableQueue<E>(e);
		}
		else
		{
			AdderQueue = new ImmutableQueue<E>(this);
			AdderQueue.TailNode.next = new EachNode<E>(e);
			AdderQueue.TailNode = AdderQueue.TailNode.next;			
		}
		AdderQueue.QueueSize = this.size()+1;
		return AdderQueue;		
	}
	
	/**
	* Returns the queue that removes the object at the head of this queue without modifying this queue.
	* <pre>
	* e.g.
	* When this queue represents the queue (7, 1, 3, 3, 5, 1) ,
	* this method returns a new queue (1, 3, 3, 5, 1)
	* and this object still represents the queue (7, 1, 3, 3, 5, 1) .
	* </pre>
	* If this queue is empty, throws java.util.NoSuchElementException.
	* @return
	* @throws java.util.NoSuchElementException
	*/
	
	public ImmutableQueue<E> dequeue() 
	{
		ImmutableQueue<E> DeleQueue;
		if(this == null || this.TailNode == null || this.HeadNode == null)
			throw new java.util.NoSuchElementException();
		else
		{
			DeleQueue = new ImmutableQueue<E>(this);
			
			EachNode<E> toBeDelete = DeleQueue.HeadNode;
			if(DeleQueue.size() == 1)
			{
				DeleQueue.HeadNode = null;
				DeleQueue.TailNode = null;
				DeleQueue.QueueSize= this.size()-1;
			}
			else
			{
				DeleQueue.HeadNode = DeleQueue.HeadNode.next;
				DeleQueue.QueueSize = this.size() -1;
			}
			toBeDelete = null;
		}	
		return DeleQueue;		
	}

	/**
	* Looks at the object which is the head of this queue without removing it from the queue.
	* <pre>
	* e.g.
	* When this queue represents the queue (7, 1, 3, 3, 5, 1),
	* this method returns 7 and this object still represents the queue (7, 1, 3, 3, 5, 1)
	* </pre>
	* If the queue is empty, throws java.util.NoSuchElementException.
	* @return
	* @throws java.util.NoSuchElementException
	*/

	public E peek() 
	{
		if(this == null || this.TailNode == null || this.HeadNode == null)
			throw new java.util.NoSuchElementException();
		else
		{
			return this.HeadNode.element;
		}
	}

	/**
	* Returns the number of objects in this queue.
	* @return
	*/

	public int size() 
	{
		return QueueSize;
	}
}

//Queue basic element
class EachNode<E> 
{
	E element;
	EachNode<E> next;  
	public EachNode(){}  
	public EachNode(E e){  
        this.element = e; 
        this.next = null;  
    }  
};
