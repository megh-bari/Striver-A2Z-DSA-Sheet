// * sliding window / 2 pointer 

//? there are 4 types of pattern 

//! 💡 Key formula: r - l + 1 (or j - i + 1) for window size

1) Constant Windown (not much asked!)

Pseudocode:

first loop through l and r 

int maxSum = 0;
int sum = 0;
int l = 0, r = k - 1;

while (r < n - 1) {
    sum += arr[l];  
    l++, r++;       
    sum += arr[r];  
    maxSum = max(maxSum, sum);
}


2) Longest Subarray/Substring where <condition>  (mostly asked!)

- brute : generate all the subarrays

Pseudocode:

int maxlen = 0;
for (int i = 0; i < n; i++) {  
    int sum = 0;
    for (int j = i; j < n; j++) {  
        sum += arr[j];  
        if (sum <= k)  
            maxlen = max(maxlen, j - i + 1);  
        else  
            break;  
    }
}

TC:O(n^2)
SC:O(1)


- better: shrink and exapand approach

Pseudocode:

int l = 0, r = 0;
int sum = 0, maxlen = 0;

while (r < n) {
    sum += arr[r];   // expand window 

    while (sum > k) {   // Shrink window if invalid
        sum -= arr[l];
        l++;
    }

    maxlen = max(maxlen, r - l + 1);  
    r++;  
}
return maxlen;

TC:O(2n)
SC:O(1)


- optimal:  Approach (Using if Instead of while)

Pseudocode:

int l = 0, r = 0;
int sum = 0, maxlen = 0;

while (r < n) {
    sum += arr[r];   // expand window 


    if (sum > k) {  
        sum -= arr[l];  // Shrink window if invalid
        l++;
    }

    maxlen = max(maxlen, r - l + 1);
    r++; 
}
return maxlen;

TC:O(n)
SC:O(1)


3) No.of subarray where <condn> -- using pattern 2

divide into two part: x= (no.of subarray where sum<=k) and y =(no.of subarray where (sum<=k-1))
so result in (x-y)


4) shortest/minimum window/length <cond>

shrink->shrink-> until it's valid - shortest one windows which is valid and then you shrink to figure out smaller part