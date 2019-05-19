K = 1
rows = 2
cols = 3

rectangle = []
points = []

# get rectangle table
for i in range(1,rows+1) :
    for j in range(1,cols+1) :
        rectangle.append([i, j])

# get x1, x2, y1, y2
for i in range(1,rows+1) :
    for j in range(1,rows+1) :
        for k in range(1,cols+1) :
            for l in range(1,cols+1) :
                points.append([i, j, k, l])    

points[1][0:1]

# Scoring in rectangle
for m in len(rectangle) :
    if min(points[m,0:1]>