


class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        res = []
        res = digits
        digitsLength = len(digits) 
        
        # add 1
        res[digitsLength -1] += 1

        for i in range(0, digitsLength):
            # after adding 1, look at each digit 
            # and do the carrying if necessary
            if(res[digitsLength -1 -i] == 10):
                res[digitsLength -1 -i] = 0

                # increment the next significant digit.
                # increase the size of the list if necessary
                if (digitsLength -1 -i -1) < 0:
                    res.insert(0,0)
                    res[0] = 1
                else:
                    res[digitsLength -1 -i -1] += 1                

        return res

sol = Solution()
testCases = [[0], [9], [1,9], [9, 9], [9,0,9], [9,1,0,9,9]]

for testCase in testCases:
    print(sol.plusOne(testCase))

