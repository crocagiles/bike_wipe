# Dirty little script to generate map to go from linear array to "bike space". Paste output from this into the main .ino file.

# x indexes for position on frame
top_tube = list(range(0, 15))
top_tube_r = top_tube[::-1]

down_tube = list(range(0, 16))
down_tube_r = down_tube[::-1]

# seat_tube = 10 * [15]
seat_tube = [10, 9, 8, 7, 6, 5, 6, 7, 8, 9]

seat_stay = list(range(15, 28))
seat_stay_r = seat_stay[::-1]

chain_stay = list(range(16, 26))
chain_stay_r = chain_stay[::-1]

# Construct mapping for C file

print('// 1.) Left Downtube')
for i, p in enumerate(range(0, 16)):
    print(f'n[ {p} ] = {down_tube[i]};')

print('// 2.) Left Chain Stay')
for i, p in enumerate(range(16, 26)):
    print(f'n[ {p} ] = {chain_stay[i]};')

print('// 3.) Left Seat Stay')
for i, p in enumerate(range(26, 39)):
    print(f'n[ {p} ] = {seat_stay_r[i]};')

print('// 4.) Left Seat Tube')
for i, p in enumerate(range(39, 49)):
    print(f'n[ {p} ] = {seat_tube[i]};')

print('// 5.) Right Seat Tube')
for i, p in enumerate(range(49, 59)):
    print(f'n[ {p} ] = {seat_tube[i]};')

print('// 6.) Right Seat Stay')
for i, p in enumerate(range(59, 72)):
    print(f'n[ {p} ] = {seat_stay[i]};')

print('// 7.) Right Chain Stay')
for i, p in enumerate(range(72, 82)):
    print(f'n[ {p} ] = {chain_stay_r[i]};')

print('// 8.) Right Down Tube')
for i, p in enumerate(range(82, 98)):
    print(f'n[ {p} ] = {down_tube_r[i]};')

print('// 9.) Right Top Tube')
for i, p in enumerate(range(98, 113)):
    print(f'n[ {p} ] = {top_tube[i]};')

print('// 10.) Left Top Tube')
for i, p in enumerate(range(113, 128)):
    print(f'n[ {p} ] = {top_tube_r[i]};')
