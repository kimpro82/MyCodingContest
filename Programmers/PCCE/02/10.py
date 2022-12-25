# there must be more efficient code than this crazy one ……
# maybe it'll be better to use range() somehow

def solution(n, board, position):

    answer = []

    for a, b in position:

        # Count each cell's neighbors
        sum = 0
        if a > 0 and a < len(board) - 1:
            sum += board[a-1][b]
            sum += board[a+1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a+1][b-1]
                sum += board[a-1][b+1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a-1][b+1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a+1][b-1]
        elif a == 0 and a < len(board) - 1:
            sum += board[a+1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a][b-1]
                sum += board[a+1][b-1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a][b-1]
                sum += board[a+1][b-1]
        elif a > 0 and a == len(board) - 1:
            sum += board[a-1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a-1][b+1]
                sum += board[a][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a-1][b+1]
                sum += board[a][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
        else:
            if b > 0 and b < len(board) - 1:
                sum += board[a][b-1]
                sum += board[a][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a][b-1]

        # Determine if survive
        if board[a][b] == 1 and (sum <=2 or sum >= 5):
            answer.append(0)
        elif board[a][b] == 0 and sum == 2:
            answer.append(1)
        else:
            answer.append(board[a][b])
    
    return answer