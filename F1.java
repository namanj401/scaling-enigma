import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
public class gglks2021g2
{
	static void merge(int arr[], int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
        int i = 0, j = 0; 
        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    static void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            int m = (l+r)/2; 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
            merge(arr, l, m, r); 
        } 
    } 
    public static int lowerBound(int[] array, int length, int value) 
	{
        int low = 0;
        int high = length;
        while (low < high) 
        {
            final int mid = (low + high) / 2;
            //checks if the value is less than middle element of the array
            if (value <= array[mid]) 
            {
                high = mid;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        return low;
    }
	public static int upperBound(int[] array, int length, int value) 
	{
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    static int gcd(int a, int b) 
    { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    } 
    static long power(long n,long m)
    {
    	if(m==0)
    		return 1;
    	long ans=1;
    	while(m>0)
    	{
    		ans=ans*n;
    		m--;
    	}
    	return ans;
    }
    static long[][] arrSorter(long arr[][])
    {
    	int n=arr.length;
    	for(int i=0;i<n;)
    	{
    		int j=i;
    		ArrayList<Long> arrli=new ArrayList<Long>();
    		while(j<n&&arr[j][0]==arr[i][0])
    		{
    			arrli.add(arr[j][1]);
    			j++;
    		}
    		Collections.sort(arrli);
    		for(int k=i;k<j;k++)
    		{
    			arr[k][1]=arrli.get(k-i);
    		}
    	}
    	return arr;
    }
    static long BinarySearch1(int arr[][]) 
    { 
        long l = -1000000000, r = 1000000000,m=0; 
        while (l <= r) { 
             m = (r + l) / 2;
            long dist1=0,dist2=0,dist3=0;
            for(int j=0;j<arr.length;j++)
            {
            	//dist1+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],m,0);
            	dist2+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],l,0);
            	dist3+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],r,0);
            }
            if (dist2 > dist3) 
                l = m + 1; 
            else
                r = m - 1; 
        } 
        return l; 
    }
    static long BinarySearch2(int arr[][]) 
    { 
        long l = -1000000000, r = 1000000000,m=0; 
        while (l <= r) { 
            m = (r + l) / 2;
            long dist1=0,dist2=0,dist3=0;
            for(int j=0;j<arr.length;j++)
            {
            	//dist1+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],m,0);
            	dist2+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],0,l);
            	dist3+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],0,r);
            }
            if (dist2 > dist3) 
                l = m + 1; 
            else
                r = m - 1; 
        } 
        return l; 
    }
    public static long dist(long x1,long y1,long x2,long y2,long posx,long posy)
    {
    	long ans=0;
    	if(posx<=x2&&posx>=x1)
    	{
    		if(posy>=y1&&posy<=y2)
    			return 0;
    		if(posy>y2)
    			return posy-y2;
    		return y1-posy;
    	}
    	if(posy<=y2&&posy>=y1)
    	{
    		if(posx>=x1&&posx<=x2)
    			return 0;
    		if(posx>x2)
    			return posx-x2;
    		return x1-posx;
    	}
    	long dist1=Math.abs(x1-posx)+Math.abs(y1-posy);
    	long dist2=Math.abs(x2-posx)+Math.abs(y1-posy);
    	long dist3=Math.abs(x1-posx)+Math.abs(y2-posy);
    	long dist4=Math.abs(x2-posx)+Math.abs(y2-posy);
    	ans=Math.min(dist1,Math.min(dist2,Math.min(dist3,dist4)));
    	return ans;
    }
    public static void main(String args[])throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
	    for(int i=1;i<=t;i++)
	    {
	    	//System.out.println(i);
	        int n=Integer.parseInt(br.readLine());
	        int arr[][]=new int[n][4];
	        for(int j=0;j<n;j++)
		    {
	        	String s=br.readLine();
		        String str[]=s.split(" ");
		        arr[j][0]=Integer.parseInt(str[0]);
		        arr[j][1]=Integer.parseInt(str[1]);
		        arr[j][2]=Integer.parseInt(str[2]);
		        arr[j][3]=Integer.parseInt(str[3]);
		    }
	        
	        int x=(int)BinarySearch1(arr);
	        int y=(int)BinarySearch2(arr);
	        long min=0;
	        for(int j=0;j<arr.length;j++)
               	min+=dist(arr[j][0],arr[j][1],arr[j][2],arr[j][3],x,y);
            int x1=x,y1=y;
	        for(int j=x-3;j<=x+3;j++)
	        {
	        	
	        	for(int k=y-3;k<=y+3;k++)
	        	{
	        		long dista=0;
	        		for(int l=0;l<n;l++)
	        		dista+=dist(arr[l][0],arr[l][1],arr[l][2],arr[l][3],j,k);
	        		//System.out.println(j+" "+k+" "+dista+" "+min);
	        		if(dista<min||(dista==min&&(j<x1||k<y1)))
	        		{
	        			min=Math.min(dista,min);
	        			x1=j;
	        			y1=k;
	        			//System.out.println(dista+" "+x1+" "+y1);
	        		}
	        	}
	        }
	        System.out.println("Case #"+i+": "+x1+" "+y1);
	    }
	}
}
