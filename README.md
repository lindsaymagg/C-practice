# C-practice
January 2019, CS250 (Computer Architecture) HW#1 

HoopsStats: Read in a file. The file is a series of player stats, where each player entry is 4 input lines long. The first line is the player’s last name, the second line is his jersey number (an int), the third line is his average points per game (a float), and the fourth line is his year of graduation (an int). The last line is the string “DONE”. Outputs a number of lines equal to the number of players, and each line is the player’s name and his jersey number and his year of graduation. The lines are sorted in descending order of average points per game, and I wrote my own sorting function.

divby7or11: Prints out the first N numbers that are divisible by either 7 or 11.

recurse: Computes f(N), where N is an integer greater than zero that is input to the program. f(N) = 4N+[2f(N-1)] + 3. The base case is f(0)=5. Code is recursive, and it follows proper MIPS calling conventions.
