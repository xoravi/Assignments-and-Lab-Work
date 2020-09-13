--Name: Ravi Sahni
--Faculty No.: 17 COB 085
--Enrol. No.: GJ 7718
--Assignment: 9 bit Comparator using 6 bit & 3 bit Comparators.

--6 bit Comparator
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bit6_comp is
Port ( 	a5,a4,a3,a2,a1,a0: in STD_LOGIC;
       	b5,b4,b3,b2,b1,b0: in STD_LOGIC;
	g,l,e : out STD_LOGIC);	
end bit6_comp;

architecture Behavioral of bit6_comp is 
begin

g<= (a5 and (not b5))
or  ((a5 xnor b5) and (a4 and (not b4)))
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 and (not b3))) 
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 and (not b2)))
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 xnor b2) and (a1 and (not b1)))
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 xnor b2) and (a1 xnor b1) and (a0 and (not b0)));

l<= (b5 and (not a5)) 
or  ((a5 xnor b5) and (b4 and (not a4)))
or  ((a5 xnor b5) and (a4 xnor b4) and (b3 and (not a3))) 
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (b2 and (not a2)))
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 xnor b2) and (b1 and (not a1)))
or  ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 xnor b2) and (a1 xnor b1) and (b0 and (not a0)));

e<= ((a5 xnor b5) and (a4 xnor b4) and (a3 xnor b3) and (a2 xnor b2) and (a1 xnor b1) and (a0 xnor b0));

end Behavioral;
----------------------------------------------------------------------------------------------------------
--3 bit Comparator
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bit3_comp is
Port ( 	a2,a1,a0: in STD_LOGIC;
       	b2,b1,b0: in STD_LOGIC;
	g,l,e : out STD_LOGIC);	
end bit3_comp;

architecture Behavioral of bit3_comp is 
begin

g<= (a2 and (not b2)) 
or  ((a2 xnor b2) and (a1 and (not b1))) 
or  ((a2 xnor b2) and (a1 xnor b1) and (a0 and (not b0)));

l<= (b2 and (not a2)) 
or  ((a2 xnor b2) and (b1 and (not a1))) 
or  ((a2 xnor b2) and (a1 xnor b1) and (b0 and (not a0)));

e<= ((a2 xnor b2) and (a1 xnor b1) and (a0 xnor b0));

end Behavioral;
----------------------------------------------------------------------------------------------------------
--9 bit comparator using 6 bit & 3 bit comparators

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bit9_comp is
Port ( A : in STD_LOGIC_VECTOR (8 downto 0);
B : in STD_LOGIC_VECTOR (8 downto 0);
G, L, E : out STD_LOGIC);
end bit9_comp;

architecture Behavioral of bit9_comp is

component bit6_comp
Port ( 	a5,a4,a3,a2,a1,a0: in STD_LOGIC;
       	b5,b4,b3,b2,b1,b0: in STD_LOGIC;
	g,l,e : out STD_LOGIC);	
end component;

component bit3_comp
Port ( 	a2,a1,a0: in STD_LOGIC;
       	b2,b1,b0: in STD_LOGIC;
	g,l,e : out STD_LOGIC);	
end component;

signal G6,L6,E6,G3,L3,E3: STD_LOGIC;

begin
B5C: bit6_comp port map(A(8), A(7), A(6), A(5), A(4), A(3), B(8), B(7), B(6), B(5), B(4), B(3), G6, L6, E6); 
B4C: bit3_comp port map(A(2), A(1), A(0), B(2), B(1), B(0), G3, L3, E3); 

G <= (G3 or (E3 and G6)); 
E <= (E3 and E6);
L <= (L3 or (E3 and L6));

end Behavioral;
