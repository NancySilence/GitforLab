package jp.co.worksap.global;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Orienteering {
	
		public static void main(String[] args) {
		// TODO: Implement your program
			Scanner in =new Scanner(System.in); 
			int width = in.nextInt();
			int height = in.nextInt();
			if(width<1||width>100||height<1||height>100)
			{
				System.out.println("-1");
				return;
			}
			
			int CheckPointNumb = 0;
			//0:Start; 1:End; 2-(CheckPointNumb+1): checkpoint
			Point[] SpecialPoints = new Point[20];
			Point[][] AllPoints = new Point [width][height];
			
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
				System.out.println("-1");
				return;
			}

			//Make sure every dis matrix is carefully initiated. 
			for(int i = 0;i<CheckPointNumb+2;i++)
			{
				SpecialPoints[i].ToOtherDis = new int[CheckPointNumb+2];
				for(int j = 0;j<CheckPointNumb+2;j++)
					SpecialPoints[i].ToOtherDis[j] = Integer.MAX_VALUE;
				SpecialPoints[i].ToOtherDis[i] = 0;
			}
			
			
			
			in.nextLine();
			in.nextLine();
			
 			
		}
		
		int CalcTwoPointsDistance(int OriginalIndex, Point[][] AllPoints,Point[] SpecialPoints,int width,int height,int CheckPointNumb)
		{
			//Initiation
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
				 if((AllPoints[u.x][u.y].type!=4)&&(AllPoints[u.x][u.y].type!=3))
				 {
					 for(int s = 0;s<CheckPointNumb+2;s++)
					 {
						 if((SpecialPoints[s].x == u.x)  && (SpecialPoints[s].y == u.y))
						 {
							 SpecialPoints[s].ToOtherDis[OriginalIndex] = AllPoints[u.x][u.y].distance;
							 break;
						 }
					 }
				 }
			 }
			 
			 return -1;
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
    int x;  
    int y;  
    // 0:start; 1:end; 2 checkpoint;3:go through; 4: cannot pass
    int type;
    //0:white ; 1:gray;2 :black;
    int color;
    
    //temp record for BFS
    int distance;
    
    //record the special points distance between each others
    int[] ToOtherDis;
}; 


class Pair{
	public Pair(int xi,int yi)
	{
		x = xi;
		y = yi;
	}
	int x;
	int y;
};