class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        def ok(t : int, time : List[int], total : int) : 
            count = 0
            for i in time : 
                count += (t // i)
            return count >= total 
        
        l = 0
        mini = min(time)
        r = mini * totalTrips
        while l < r : 
            mid = (l + r) >> 1
            if ok(mid, time, totalTrips) : 
                r = mid
            else : 
                l = mid + 1
            
        return l