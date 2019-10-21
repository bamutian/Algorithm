# -*- coding:utf-8 -*-
"""
5
(1,2)(5,3)(4,6)(7,5)(9,0)
output:
(4 6)(7 5)(9 0)
"""


def findpoints():
    # nums = input('total numbers:')
    # nums = int(nums)
    result = []
    # for i in range(0, nums):
    #     x = input('x:')
    #     y = input('y:')
    #     points.append((x, y))
    points = [(1, 2), (5, 3), (4, 6), (7, 5), (9, 0)]
    nums = len(points)
    points.sort()  # 排序，元组排序会先按第一个数排，再按第二个数排
    max_x2y = points[nums - 1][1]
    result.append(points[nums - 1])
    for i in range(0, len(points)):
        for j in range(i + 1, len(points)):
            if points[i][1] < points[j][1]:
                break
        if j == nums - 1 and points[i][1] > max_x2y:
            result.insert(0, points[i])  # 每次都插在头，最后自动有序
    print(result)


findpoints()
