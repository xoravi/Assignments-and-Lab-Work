--Name: Ravi Sahni
--Faculty No.: 17 COB 085
--Enrol. No.: GJ 7718
--Assignment: Design and simulate a 5-bit Majority Circuit.

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY bit5_Majority IS
PORT(
a, b, c, d, e : IN STD_LOGIC;
res : OUT STD_LOGIC);
END bit5_Majority;

ARCHITECTURE basic OF bit5_Majority IS
BEGIN
res <= 	((a and b and c)
	or (a and b and d)
	or (a and b and e)
	or (a and c and d)
	or (a and c and e)
	or (a and d and e)
	or (b and c and d)
	or (b and c and e)
	or (b and d and e)
	or (c and d and e));	

END basic; 

