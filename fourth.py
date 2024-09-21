def greedy_word_wrap(words, line_width):
    current_line = []
    current_length = 0
    result = []
    
    for word in words:
        if current_length + len(word) + (1 if current_length > 0 else 0) <= line_width:
            if current_length > 0:
                current_line.append(' ')  # Add space between words
            current_line.append(word)
            current_length += len(word) + (1 if current_length > 0 else 0)
        else:
            result.append(''.join(current_line))  # Add the current line to the result
            current_line = [word]  # Start a new line with the current word
            current_length = len(word)
    
    if current_line:
        result.append(''.join(current_line))  # Add the last line
    
    return result