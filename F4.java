import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
public class cdf725c
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
    static int BinarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
            if (arr[m] == x) 
                return m; 
            if (arr[m] < x) 
                l = m + 1; 
            else
                r = m - 1; 
        } 
        return -1; 
    }
    public static void main(String args[])throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
	    for(int i=1;i<=t;i++)
	    {
	        int n=Integer.parseInt(br.readLine());
	        int arr[]=new int[n];
	        String s=br.readLine();
	        String str[]=s.split(" ");
	        for(int j=0;j<n;j++)
	        arr[j]=Integer.parseInt(str[j]); 
	        sort(arr,0,n-1);
	        
	        System.out.println();
	    }
	}
}
