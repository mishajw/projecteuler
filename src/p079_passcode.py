characters = list(range(10))

with open("inputs/p079_keylog.txt") as f:
    logs = [[int(c) for c in l.strip()] for l in f]

forward_score_matrix = [[0] * len(characters)] * len(characters)
backward_score_matrix = [[0] * len(characters)] * len(characters)
for a, b, c in logs:
    forward_score_matrix[a][b] += 1
    forward_score_matrix[a][c] += 1
    forward_score_matrix[b][c] += 1
    backward_score_matrix[c][b] += 1
    backward_score_matrix[c][a] += 1
    backward_score_matrix[b][a] += 1


password = [1]
while \
        not all(i == 0 for row in forward_score_matrix for i in row) and \
        not all(i == 0 for row in backward_score_matrix for i in row):
    max_score = 0
    max_index = 0
    max_character = 0

    for c in characters:
        for i in range(len(password) + 1):
            total = 0
            for password_character in password[i:]:
                total += forward_score_matrix[c][password_character]
            for password_character in password[:i]:
                total += backward_score_matrix[c][password_character]
            if max_score < total:
                max_score = total
                max_index = i
                max_character = c

    print(max_score, max_index, max_character)
    password.insert(max_index, max_character)
    for password_character in password[max_index:]:
        forward_score_matrix[max_character][password_character] = 0
    for password_character in password[:max_index]:
        backward_score_matrix[max_character][password_character] = 0
    print(password)

