# SlidingPuzzle
4x4数字华容道求解程序，使用广度优先搜索算法（BFS），最新版本v1.1

## 输入示例
```
11 13 0 2
14 5 1 12
10 4 3 8
7 15 9 6
```

## 输出示例
```
info depth 1 nodes 5 score 0 time 0 nps 5000
info depth 2 nodes 11 score 0 time 1 nps 5500
info depth 3 nodes 25 score 1 time 2 nps 8333
info depth 4 nodes 57 score 2 time 2 nps 19000
info depth 5 nodes 123 score 2 time 3 nps 30750
info depth 6 nodes 257 score 2 time 4 nps 51400
info depth 7 nodes 537 score 2 time 6 nps 76714
info depth 8 nodes 620 score 3 time 7 nps 77500
info depth 9 nodes 776 score 3 time 9 nps 77600
info depth 10 nodes 1064 score 4 time 11 nps 88666
info depth 11 nodes 1672 score 4 time 15 nps 104500
info depth 12 nodes 2839 score 5 time 21 nps 129045
info depth 13 nodes 3747 score 5 time 31 nps 117093
info depth 14 nodes 4975 score 6 time 40 nps 121341
info depth 15 nodes 5731 score 6 time 45 nps 124586
info depth 16 nodes 6543 score 7 time 52 nps 123452
info depth 17 nodes 7837 score 7 time 64 nps 120569
info depth 18 nodes 8127 score 7 time 70 nps 114464
info depth 19 nodes 8630 score 7 time 78 nps 109240
info depth 20 nodes 9196 score 7 time 83 nps 109476
info depth 21 nodes 10171 score 7 time 93 nps 108202
info depth 22 nodes 11197 score 7 time 106 nps 104644
info depth 23 nodes 12837 score 7 time 145 nps 87924
info depth 24 nodes 14514 score 8 time 192 nps 75202
info depth 25 nodes 16821 score 8 time 223 nps 75093
info depth 26 nodes 17431 score 8 time 229 nps 75786
info depth 27 nodes 18298 score 8 time 238 nps 76560
info depth 28 nodes 19250 score 8 time 245 nps 78252
info depth 29 nodes 20890 score 8 time 261 nps 79732
info depth 30 nodes 22695 score 8 time 281 nps 80478
info depth 31 nodes 25253 score 8 time 303 nps 83069
info depth 32 nodes 27871 score 8 time 330 nps 84202
info depth 33 nodes 31775 score 9 time 393 nps 80647
info depth 34 nodes 36387 score 9 time 451 nps 80502
info depth 35 nodes 43296 score 9 time 506 nps 85396
info depth 36 nodes 51453 score 9 time 589 nps 87208
info depth 37 nodes 63895 score 9 time 701 nps 91018
info depth 38 nodes 79759 score 10 time 879 nps 90635
info depth 39 nodes 93257 score 10 time 990 nps 94103
info depth 40 nodes 100619 score 10 time 1061 nps 94744
info depth 41 nodes 110940 score 10 time 1151 nps 96302
info depth 42 nodes 123785 score 11 time 1327 nps 93211
info depth 43 nodes 139053 score 11 time 1581 nps 87896
info depth 44 nodes 144418 score 11 time 1639 nps 88059
info depth 45 nodes 151078 score 11 time 1716 nps 87989
info depth 46 nodes 158265 score 11 time 1776 nps 89063
info depth 47 nodes 168019 score 11 time 1872 nps 89705
info depth 48 nodes 178589 score 12 time 1970 nps 90608
info depth 49 nodes 192425 score 12 time 2094 nps 91849
info depth 50 nodes 207209 score 12 time 2226 nps 93044
info depth 51 nodes 226775 score 12 time 2400 nps 94450
info depth 52 nodes 247623 score 13 time 2611 nps 94802
info depth 53 nodes 263322 score 13 time 3035 nps 86733
info depth 54 nodes 269614 score 13 time 3087 nps 87310
info depth 55 nodes 277585 score 13 time 3261 nps 85096
info depth 56 nodes 286572 score 13 time 3355 nps 85390
info depth 57 nodes 298580 score 13 time 3493 nps 85455
info depth 58 nodes 310646 score 13 time 3619 nps 85813
info depth 59 nodes 325378 score 13 time 3768 nps 86330
info depth 60 nodes 339248 score 13 time 3907 nps 86808
info depth 61 nodes 356080 score 13 time 4068 nps 87510
info depth 62 nodes 373176 score 13 time 4254 nps 87702
info depth 63 nodes 394094 score 13 time 4443 nps 88680
info depth 64 nodes 414885 score 13 time 4658 nps 89050
info depth 65 nodes 440488 score 13 time 4970 nps 88611
info depth 66 nodes 465486 score 13 time 5227 nps 89037
info depth 67 nodes 495943 score 13 time 5546 nps 89407
info depth 68 nodes 527587 score 13 time 6820 nps 77347
info depth 69 nodes 566673 score 14 time 7398 nps 76587
info depth 70 nodes 606534 score 14 time 8286 nps 73191
info depth 71 nodes 622641 score 14 time 8481 nps 73407
info depth 72 nodes 633961 score 14 time 8604 nps 73673
info depth 73 nodes 647011 score 14 time 8758 nps 73868
info depth 74 nodes 660086 score 14 time 8937 nps 73851
info depth 75 nodes 674398 score 14 time 9112 nps 74003
bestmove ↑↑←↓→↑→→↓←↓←←↑→↑↑→→↓↓↓←←←↑→↑→↓→↑←↑→↓↓←←↑→↓→↑←↓←↑→↓↓←←↑↑ →↓↓→↑↑←←↑→↓←↓→↑→↓←↑↑←
steps: 76
steps (merged): 57
```