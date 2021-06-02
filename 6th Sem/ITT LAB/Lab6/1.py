# Provided
import re
states = "Mississippi Alabama Texas Massachusetts Kansas"
split_state = states.split(' ')
stateList = [" "]*len(split_state)

for state in split_state:
    if state[-3:] == "xas":
        stateList[0] = state 
    if re.search('^M.*s$', state):
        stateList[2] = state
    
print(stateList)