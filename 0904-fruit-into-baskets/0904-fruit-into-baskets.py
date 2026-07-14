 
class Solution(object):
    def totalFruit(self, fruit):
        left = 0
        ans = 0
        count = {}

        for right in range(len(fruit)):
            count[fruit[right]] = count.get(fruit[right], 0) + 1

            while len(count) > 2:
                count[fruit[left]] -= 1

                if count[fruit[left]] == 0:
                    del count[fruit[left]]

                left += 1

            ans = max(ans, right - left + 1)

        return ans
   