import numpy as np

class Solution(object):
    def visiblePoints(self, points, angle, location):
        at_location = 0
        angles = []

        for x, y in points:
            if x == location[0] and y == location[1]:
                at_location += 1
            else:
                theta = np.arctan2(y - location[1], x - location[0]) % (2 * np.pi)
                angles.append(theta)

        angles.sort()
        extended = angles + [a + 2 * np.pi for a in angles]
        angle_rad = angle * np.pi / 180

        max_visible = 0
        left = 0

        for right in range(len(extended)):
            while extended[right] - extended[left] > angle_rad:
                left += 1
            max_visible = max(max_visible, right - left + 1)

        return max_visible + at_location
