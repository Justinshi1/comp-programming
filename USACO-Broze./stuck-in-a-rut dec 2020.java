import java.util.*;
public class StuckInARut {
static class cow{
public int xPos;
public int yPos;
public int idx;
public cow(int x, int y, int i) {
	xPos = x;
	yPos = y;
	idx = i;
	
}
public Integer getXPos() {
	return xPos;
}
public void set(cow other) {
	this.xPos = other.xPos;
	this.yPos = other.yPos;
	this.idx = other.idx;
}
public int distance(cow collisionPoint) {
	if(collisionPoint.xPos != xPos) {
		return collisionPoint.xPos - xPos;
	}
	else 
		return collisionPoint.yPos - yPos;   	
}

}


static class Ordered2DArr {
	public int arrIndex;
	public int x;
	public int y;
	public int val;
	
	public Ordered2DArr (int idx, int x1, int y1, int inputVal) {
		arrIndex = idx;
		x = x1;
		y = y1;
		val = inputVal;
	}
	
	public Integer getVal()  
    {  
        return Integer.valueOf(val);  
    }  
}

public static void main(String[] args) {
		// TODO Auto-generated method stub
	 Comparator<cow> c = new Comparator<cow>()  
     {  
         public int compare(cow u1, cow u2)  
         {  
        	 return (u1.getXPos()).compareTo(u2.getXPos());  
         }  
     };  
ArrayList<cow> northCows = new ArrayList<cow>();
ArrayList<cow> eastCows = new ArrayList<cow>();
Scanner sc = new Scanner(System.in);
int numCows = sc.nextInt();
int[] finalArr = new int[numCows];
for(int i = 0 ; i<finalArr.length; i++) {
	finalArr[i] = -1;
}
//input
//int j;
//int w;
for(int i = 0; i<numCows; i++) {
	char direction = sc.next().charAt(0);
	int x = sc.nextInt();
	int y = sc.nextInt();
	cow a = new cow(x, y, i);
	if(direction == 'E') {
		int index = Collections.binarySearch(eastCows, a, c);
		if(index< 0 ) {
			eastCows.add(Math.abs(index+1), a);
		}
		else {
			eastCows.add(index, a);
		}
		
		/*for(j = 0; j<eastCows.size(); j++) {
		if(a.xPos < eastCows.get(j).xPos) {
			break;
		}
		}*/
		
	}
	else {
		/*for(w = 0; w<northCows.size(); w++) {
			if(a.xPos < northCows.get(w).xPos) {
				break;
			}
			}*/
		int index = Collections.binarySearch(northCows, a, c);
		if(index< 0 ) {
			northCows.add(Math.abs(index+1), a);
		}
		else {
			northCows.add(index, a);
		}
	}
}
//bruhbruhbruhrbuhrbuhrbuhbrbuhruhruruhurhhruirUSSYYS
int[][] northDistance = new int[northCows.size()][eastCows.size()];
int[][] eastDistance = new int[northCows.size()][eastCows.size()];;
for(int n = 0; n<northCows.size(); n++) {	 
	 for(int e = 0; e<eastCows.size(); e++){
		 cow collisionPoint = new cow(northCows.get(n).xPos, eastCows.get(e).yPos, -1);
		 int distanceNorth = northCows.get(n).distance(collisionPoint);
		 int distanceEast = eastCows.get(e).distance(collisionPoint);
		 northDistance[n][e] = distanceNorth;
		 eastDistance[n][e] = distanceEast;
		 if(northDistance[n][e] < 0 || eastDistance[n][e] < 0 || northDistance[n][e] == eastDistance[n][e]){
			 //no collision
			 northDistance[n][e] = -1; 
			 eastDistance[n][e] = -1;
		 }
		 else if(northDistance[n][e]<eastDistance[n][e]) {
			 northDistance[n][e] = -1;
		 }
		 else {
			 eastDistance[n][e] = -1;
		 }

		 }
	 }



ArrayList <Ordered2DArr> ordered2D = new ArrayList<Ordered2DArr>();
 
Sort2DArray(northDistance, 0, ordered2D);
Sort2DArray(eastDistance, 1, ordered2D);

while (ordered2D.size() != 0){
	  // arrChoice = findMin(northDistance, eastDistance, minCow);
	
	Ordered2DArr item = ordered2D.get(0);
	
	if(item.arrIndex == 0) {
		//assign current distance val to final array 
		finalArr[northCows.get(item.x).idx] = northDistance[item.x][item.y];
		// int tem = northDistance[item.x][item.y];
		//northDistance[item.x][item.y] = -1; //remove
		ordered2D.remove(0);
		for (int i = 0; i < ordered2D.size(); i++) {
			//if (item.x == ordered2D.get(i).x && item.val != ordered2D.get(i).val) {
			if (item.x == ordered2D.get(i).x) {

				ordered2D.remove(i);
				i--;
			}
				
		}
		/*
		for(int i = 0; i<eastDistance[item.x].length; i++) { //remove
			if (tem != eastDistance[item.x][i] ) //remove
			eastDistance[item.x][i] = -1; //remove
		} *///remove
	}
	else {
		finalArr[eastCows.get(item.y).idx] = eastDistance[item.x][item.y];
		ordered2D.remove(0);
		for (int i = 0; i < ordered2D.size(); i++) {
			//if (item.y == ordered2D.get(i).y && item.val != ordered2D.get(i).val) {
			if (item.y == ordered2D.get(i).y) {
				ordered2D.remove(i);
				i--;
			}
				
		}
		/* int tem = eastDistance[item.x][item.y];
		eastDistance[item.x][item.y] = -1;
		for(int i = 0; i<northDistance[item.y].length; i++) {
			if (tem != northDistance[i][item.y])
			northDistance[i][item.y] = -1;
		} */
	}
	/*
	
	if(arrChoice == 0) {
		//assign current distance val to final array 
		finalArr[northCows.get(minCow.xPos).idx] = northDistance[minCow.xPos][minCow.yPos];
		int tem = northDistance[minCow.xPos][minCow.yPos];
		northDistance[minCow.xPos][minCow.yPos] = -1;
		for(int i = 0; i<eastDistance[minCow.xPos].length; i++) {
			if (tem != eastDistance[minCow.xPos][i] )
			eastDistance[minCow.xPos][i] = -1;
		}
	}
	else {
		finalArr[eastCows.get(minCow.yPos).idx] = eastDistance[minCow.xPos][minCow.yPos];
		int tem = eastDistance[minCow.xPos][minCow.yPos];
		eastDistance[minCow.xPos][minCow.yPos] = -1;
		for(int i = 0; i<northDistance[minCow.yPos].length; i++) {
			if (tem != northDistance[i][minCow.yPos])
			northDistance[i][minCow.yPos] = -1;
		}
	} */
};

     for(int i = 0; i<finalArr.length; i++) {
    	 if(finalArr[i] == -1) {
    		 System.out.println("Infinity");
    	 }
    	 else {
    		 System.out.println(finalArr[i]);
    	 }
     }
	}


static void Sort2DArray(int arr[][], int arrIdx, ArrayList <Ordered2DArr> arrList) {
	 Comparator<Ordered2DArr> c = new Comparator<Ordered2DArr>()  
     {  
         public int compare(Ordered2DArr u1, Ordered2DArr u2)  
         {  
        	 return (u1.getVal()).compareTo(u2.getVal());  
         }  
     };  
      
	for(int i = 0; i<arr.length; i++) {
		for(int j = 0; j<arr[i].length; j++) {
			if (arr[i][j] > 0) {
				Ordered2DArr tem = new Ordered2DArr(arrIdx, i, j, arr[i][j]);
				int index = Collections.binarySearch(arrList, tem, c);  
				if (index < 0) {
					index = Math.abs(index  + 1);
				}
				arrList.add(index, tem);
			}
		}
	}
	
}

/*
static void findMinSingle(int arr[][], cow minCow) {
	int min = Integer.MAX_VALUE;
	
	for(int i = 0; i<arr.length; i++) {
		for(int j = 0; j<arr[i].length; j++) {
			if(arr[i][j]<min && arr[i][j] >0) {
				min = arr[i][j];
				minCow.xPos = i;
				minCow.yPos = j;
				minCow.idx = min;
			} 

		}
	}
}

static int findMin(int arr[][], int arr1[][], cow minCow) {
	int arrIdx = 0;
	cow cow1 = new cow(-1, -1, -1);
	cow cow2 = new cow(-1, -1, -1);
	findMinSingle(arr, cow1);
	findMinSingle(arr1, cow2);
	
	if (cow1.idx > 0 && cow2.idx > 0) {
		if (cow1.idx < cow2.idx) {
			minCow.set(cow1);
			arrIdx = 0;
		} else  {
			minCow.set(cow2);
			arrIdx = 1;
		}
	} else if (cow1.idx > 0 && cow2.idx < 0){
		minCow.set(cow1);
		arrIdx = 0;
	} else if (cow1.idx < 0 && cow2.idx > 0) {
		minCow.set(cow2);
		arrIdx = 1;
	} else {
		minCow.set(cow1);
	}
	

	return arrIdx;
	
}
*/

}
