--Name: Ravi Sahni
--Faclty No.: 17 COB 085
--Enrol. No.: GJ 7718

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity mux4 is
port(
	A,B,C,D: in STD_LOGIC;
	X,Y: in STD_LOGIC;
	Z: out STD_LOGIC
);
end mux4;

architecture Basic of mux4 is
begin 
	Z <= (NOT X AND NOT Y AND A) OR (NOT X AND Y AND B) OR (X AND NOT Y AND C) OR (X AND Y AND D);
end architecture basic; 
