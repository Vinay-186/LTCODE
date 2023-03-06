class Solution:
    
    def sortArray(self, nums: List[int]) -> List[int]:
        def divide(l : int , r : int) : 
            if l >= r : 
                return 
            mid = (l + r) // 2
            divide(l, mid)
            divide(mid+1,r)
            merge(l, mid, r)
        
        def merge(l : int , mid : int, r : int) : 
            s1, s2, n1, n2 = l, mid+1, mid - l + 1, r - mid
            for i in range(n1) : 
                temp[s1 + i] = nums[s1 + i]
            for i in range(n2) : 
                temp[s2 + i] = nums[s2 + i]
            
            i , j , k = 0 , 0, l
            while i < n1 and j < n2 : 
                if temp[s1 + i] <= temp[s2 + j] : 
                    nums[k] = temp[s1 + i]
                    i+= 1
                else : 
                    nums[k] = temp[s2 + j]
                    j+= 1
                k += 1
            while i < n1 : 
                nums[k] = temp[s1 + i]
                k+=1
                i+=1
            while j < n2 : 
                nums[k] = temp[s2 + j]
                k+=1
                j+=1
        temp = [0] * len(nums)  
        divide(0, len(nums) -1)
        return nums
        