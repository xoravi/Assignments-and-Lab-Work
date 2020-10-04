--Name: Ravi Sahni
--Faculty No.: 17 COB 085
--Enrol. No.: GJ 7718
--Assignment: Design and simulate a 5-bit Odd-Down Counter

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity oddcounter is 
port
(	C, CLR : in  std_logic;  
        Q : out std_logic_vector(4 downto 0)
);  
end oddcounter; 

architecture bhv of oddcounter is  
	signal tmp: std_logic_vector(4 downto 0); 
	begin  
      		process (C, CLR) 
        		begin  
          		if (CLR='1') then  
            			tmp <= "11111";  
          		elsif (C'event and C='1') then  
            			tmp <= tmp - 2; 
          		end if;  
      		end process; 
      Q <= tmp;  
end bhv;
