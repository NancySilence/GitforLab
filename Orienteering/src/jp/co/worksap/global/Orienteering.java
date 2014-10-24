package jp.co.worksap.global;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Orienteering {
	
		public static void main(String[] args) {
		// TODO: Implement your program

			Orienteering ort = new Orienteering();
			int FunctionReturn = ort.MatrixInitiation();
			
			if(FunctionReturn == -1)
			{
				System.out.println(ort.FinalDistance);
				return;
			}

			//Make sure every dis matrix is carefully initiated. 
			for(int i = 0;i<ort.CheckPointNumb+2;i++)
			{
				ort.SpecialPoints[i].ToOtherDis = new int[ort.CheckPointNumb+2];
				for(int j = 0;j<ort.CheckPointNumb+2;j++)
					ort.SpecialPoints[i].ToOtherDis[j] = Integer.MAX_VALUE;
				ort.SpecialPoints[i].ToOtherDis[i] = 0;
			}
			
			//Calculate every two points'distance in SpecialPoints set
			for(int i = 0;i<ort.CheckPointNumb+2;i++)
			{
				FunctionReturn = ort.CalcTwoPointsDistance(i);
				if(FunctionReturn == -1)
				{
					System.out.println(ort.FinalDistance);
					return;
				}
			}
			
			ort.FindDistance();
			
			System.out.println(ort.FinalDistance);
				
			return;
 			
		}
		
		
		public 
		int height;
		int width;
		int CheckPointNumb;
		int FinalDistance;
		
		//0:Start; 1:End; 2-(CheckPointNumb+1): checkpoint
		Point[] SpecialPoints;
		//[width][height]
		Point[][] AllPoints;
		
		public int MatrixInitiation()
		{
			Scanner in =new Scanner(System.in); 
			width = in.nextInt();
			height = in.nextInt();
			if(width<1||width>100||height<1||height>100)
			{
				FinalDistance = -1;
				return -1;
			}
			
			CheckPointNumb = 0;
			
			//0:Start; 1:End; 2-(CheckPointNumb+1): checkpoint
			SpecialPoints = new Point[20];
			AllPoints = new Point [width][height];
			
			////////////Initiation//////////////
			int hi,wj;
			char temp;
			String templine;
			for(hi = 0;hi<height;hi++)
			{
				templine = in.nextLine();
				if(templine.isEmpty())
					templine = in.nextLine();
				for(wj = 0;wj<width;wj++)
				{
					temp = templine.charAt(wj);
					switch(temp)
					{
						case 'S':
							AllPoints[wj][hi] = new Point(wj,hi,0);
							SpecialPoints[0] = new Point(wj,hi,0);
							break;
						case 'G':
							AllPoints[wj][hi] = new Point(wj,hi,1);
							SpecialPoints[1] = new Point(wj,hi,1);
							break;
						case '@':
							AllPoints[wj][hi] = new Point(wj,hi,2);
							if(CheckPointNumb+2>=20)
							{
								CheckPointNumb = 25;
								break;
							}
							SpecialPoints[CheckPointNumb+2] = new Point(wj,hi,2);
							CheckPointNumb++;
							break;
						case '.':
							AllPoints[wj][hi] = new Point(wj,hi,3);
							break;
						case '#':
							AllPoints[wj][hi] = new Point(wj,hi,4);
							break;						
					}
					if(CheckPointNumb>18)
						break;				
				}
				if(CheckPointNumb>18)
					break;
				
			}
			
			if(CheckPointNumb>18)
			{
				FinalDistance = -1;
				return -1;
			}
			
			return 0;
			
			
		}
		
		//Distances from SpecialPoints[OriginalIndex] to all the other specialpoints.  
		//BFS method
		public int CalcTwoPointsDistance(int OriginalIndex)
		{
			//Initiation the color and distance
			 for (int i=0;i<width;i++)
			 {
				 for(int j=0;j<height;j++)
				 {
					 AllPoints[i][j].color = 0;
					 AllPoints[i][j].distance = Integer.MAX_VALUE;
				 }				 
			 }
			 
			 int x =SpecialPoints[OriginalIndex].x;
			 int y = SpecialPoints[OriginalIndex].y;
			 
			 AllPoints[x][y].color = 1;
			 AllPoints[x][y].distance = 0;
			 
			 Queue<Pair> queue = new LinkedList<Pair>(); 
			 queue.clear();
			 queue.offer( new Pair(x,y));
			 while(queue.isEmpty()!=true)
			 {
				 Pair u = queue.poll();
				 //right left down up four direction
				 if((u.x+1<=width)&&(AllPoints[u.x+1][u.y].type!=4)&&(AllPoints[u.x+1][u.y].color == 0))
				 {
					 AllPoints[u.x+1][u.y].color = 1;
					 AllPoints[u.x+1][u.y].distance =AllPoints[u.x][u.y].distance +1;
					 queue.offer( new Pair(u.x+1,u.y));
				 }
				 if((u.x-1>=0)&&(AllPoints[u.x-1][u.y].type!=4)&&(AllPoints[u.x-1][u.y].color == 0))
				 {
					 AllPoints[u.x-1][u.y].color = 1;
					 AllPoints[u.x-1][u.y].distance =AllPoints[u.x][u.y].distance +1;
					 queue.offer( new Pair(u.x-1,u.y));
				 }
				 if((u.y+1<=height)&&(AllPoints[u.x][u.y+1].type!=4)&&(AllPoints[u.x][u.y+1].color == 0))
				 {
					 AllPoints[u.x][u.y+1].color = 1;
					 AllPoints[u.x][u.y+1].distance =AllPoints[u.x][u.y].distance +1;
					 queue.offer( new Pair(u.x,u.y+1));
				 }
				 if((u.y-1>=0)&&(AllPoints[u.x][u.y-1].type!=4)&&(AllPoints[u.x][u.y-1].color == 0))
				 {
					 AllPoints[u.x][u.y-1].color = 1;
					 AllPoints[u.x][u.y-1].distance =AllPoints[u.x][u.y].distance +1;
					 queue.offer( new Pair(u.x,u.y-1));
				 }
				 
				 //when it is black, set the final distance. 
				 AllPoints[u.x][u.y].color = 2;
			 }
			 

			 //move the distance to the SpecialPoints Array. 
			 for(int i = 0;i<CheckPointNumb+2;i++)
			 {
				 SpecialPoints[i].ToOtherDis[OriginalIndex] = AllPoints[SpecialPoints[i].x][SpecialPoints[i].y].distance;
				 SpecialPoints[OriginalIndex].ToOtherDis[i] = AllPoints[SpecialPoints[i].x][SpecialPoints[i].y].distance;
				 if(AllPoints[SpecialPoints[i].x][SpecialPoints[i].y].distance == Integer.MAX_VALUE)
				 {
					 FinalDistance = -1;
					 return -1;
				 }
			 
			 }
			 
			 return 0;
		}
		
		//Find the distance from start to goal. 
		public void FindDistance()
		{
			if(CheckPointNumb == 0)
			{
				if(SpecialPoints[0].ToOtherDis[1] == Integer.MAX_VALUE)
				{
					FinalDistance = -1;
				}
				else
					FinalDistance = SpecialPoints[0].ToOtherDis[1];
				return ;
			}
			else
			{
				FinalDistance = Integer.MAX_VALUE;
				
				//use arrangement method to make sure every order of the checkpoint is checked unless the checkpoint 
				//distance is larger than current finaldistance. 
				Arrange AllArrange = new Arrange(CheckPointNumb,SpecialPoints);  
				AllArrange.perm(0, CheckPointNumb-1);  

				FinalDistance = AllArrange.FinalDistance;
		        if(FinalDistance == Integer.MAX_VALUE)
		        {
		        	FinalDistance = -1;
		        }
		        return;
			}
		}
}


class Point{  

	public Point(int xi,int yi,int typei)
	{
		x = xi;
		y = yi;
		type = typei;
	}
public  
	//width and height
    int x;  
    int y;  
    
    // 0:start; 1:end; 2 checkpoint;3:go through; 4: cannot pass
    int type;
    
    //0:white ; 1:gray;2 :black;
    int color;
    
    //temp record from original for BFS use
    int distance;
    
    //record the special points distance between each others
    //Index is corresponding with SpecialPoints.
    int[] ToOtherDis;
    
}; 


//Used to queue the data.
class Pair{
	public Pair(int xi,int yi)
	{
		x = xi;
		y = yi;
	}
	int x;
	int y;
};

class Arrange {  
	  
    private Integer list[];
    private int Number;
    public Point[] SpecialPoints;
    public int FinalDistance;
  
    public Arrange(int Numb,Point[] Points) 
    {
    	Number = Numb;
    	SpecialPoints = Points;
    	list = new Integer [Numb];
    	FinalDistance = Integer.MAX_VALUE;
    	for(int i = 0;i<Numb;i++)
    	{
    		list[i] = i+2;
    	}
    }  
  
    private void swap(Integer list[], int k, int i) 
    {  
        Integer c3 = list[k];  
        list[k] = list[i];  
        list[i] = c3;  
    }  
  
    public void perm(int k,int m) 
    { 
    	if (k > m) 
    	{  
            Integer sb[] = new Integer[Number];  
            for (int i = 0; i <= m; i++)
            	sb[i] = list[i];  
            setdistance(sb);
        } 
    	else 
    	{  
    		for (int i = k; i <= m; i++) 
    		{  
    			swap(list, k, i);  
                perm(k + 1, m);  
                swap(list, k, i);  
            }  
        }  
    }
    
    //check whether the Order of orderlist is min in this case. 
	public void setdistance(Integer[] OrderList)
	{
		int tempDist = 0;
		int IndexBefore = 0;
		int IndexNow;
        
        for(int j = 0;j<Number;j++)
        {
        	IndexNow = OrderList[j];
        	int newDist = SpecialPoints[IndexBefore].ToOtherDis[IndexNow];
        	if(newDist == Integer.MAX_VALUE || tempDist > FinalDistance)
        	{
        		return;
        	}
        	else
        	{
        		tempDist +=newDist;
        		IndexBefore = IndexNow;
        	}
        }
        //Calculate to the goal point.
        IndexNow = 1;
        int newDist = SpecialPoints[IndexBefore].ToOtherDis[IndexNow];
    	if(newDist != Integer.MAX_VALUE )
    	{
    		tempDist +=newDist;
    		if(tempDist<FinalDistance)
    			FinalDistance = tempDist;
    	}
	}
  
  
};