package jp.co.worksap.global;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ImmutableQueue<Integer>immutableQueue = new ImmutableQueue<Integer>(); 
		ImmutableQueue<Integer> immutableQueue2 = immutableQueue.enqueue(88); 
 
		EachNode<Integer>head =null; 
        System.out.println("First?///////////////////////////");
        for(head = immutableQueue.HeadNode;head!=null;head = head.next){ 
            System.out.println(head.element+" "); 
        }  
		//System.out.println("size: "+ immutableQueue.size()+" top: "+ immutableQueue.peek());
        //Test equeue 
        immutableQueue2 = immutableQueue2.enqueue(88); 
        //Test dequeue 
        
        immutableQueue2 = immutableQueue2.enqueue(32); 
        immutableQueue2 = immutableQueue2.enqueue(-25); 
        
        ImmutableQueue<Integer> immutableQueue3 = immutableQueue2.dequeue();
        immutableQueue3 = immutableQueue3.dequeue();
        immutableQueue3 = immutableQueue3.dequeue();
        //immutableQueue3 = immutableQueue3.dequeue();
        
        
         
       
        
        System.out.println("Second?///////////////////////////");
        for(head = immutableQueue2.HeadNode;head!=null;head = head.next){ 
            System.out.println(head.element+" "); 
        } 
        System.out.println("size: "+ immutableQueue2.size()+" top: "+ immutableQueue2.peek());
        
        
        System.out.println("Third?///////////////////////////");
        for(head = immutableQueue3.HeadNode;head!=null;head = head.next){ 
            System.out.println(head.element+" "); 
        } 
        //System.out.println("size: "+ immutableQueue3.size()+" top: "+ immutableQueue3.peek());
         
        
        System.out.println("First?///////////////////////////");
        for(head = immutableQueue.HeadNode;head!=null;head = head.next){ 
            System.out.println(head.element+" "); 
        } 
        //System.out.println("size: "+ immutableQueue.size()+" top: "+ immutableQueue.peek());
        
	}

}
