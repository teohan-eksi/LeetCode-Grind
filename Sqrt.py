


class Solution:
    def mySqrt(self, x: int) -> int:
        # Haluk Beker Style, R.I.P
        # sx = 0
        # while (x - ((sx+1) * (sx+1))) >= 0:
        #     sx += 1
        
        # return sx

        i = 2
        sx = int(x/i)
        while 1:            
            if x - (sx*sx) < 0:
                i += 1
                sx = int(sx/i)
            else:
                break

        i = 2
        while 1:
            if(x - ((sx+(int(sx/i) + 1))*(sx+(int(sx/i) + 1)))) < 0:
                break
            else:
                i+=1
                sx += int(sx/i) + 1    

        while 1:
            if(x - ((sx+1)*(sx+1))) < 0:
                break
            else:
                sx += 1 

        return sx

sol = Solution()
testIOMap = [[0, 0], [1,1], [2,1], [3,1], [4,2], [8,2], [10,3], [36,6], [254289018, 15946]]

for test in testIOMap:
    print(sol.mySqrt(test[0]), test[1])
