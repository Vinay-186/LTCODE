class Solution:
    def ok(self,t : int, time : List[int], total : int) -> bool : 
        count = 0
        for i in time : 
            count += (t // i)
        return count >= total 
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        l = mini =  min(time)
        r = mini * totalTrips
        while l < r : 
            mid = (l + r) >> 1
            if self.ok(mid, time, totalTrips) : 
                r = mid
            else : 
                l = mid + 1
            
        return l