--Name: Ravi Sahni
--Faclty No.: 17 COB 085
--Enrol. No.: GJ 7718

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity Partial_FA is
Port ( A, B, Cin : in STD_LOGIC;
S, P, G : out STD_LOGIC);
end Partial_FA;
 
architecture Behavioral of Partial_FA is 
begin
S <= A xor B xor Cin;
P <= A xor B;
G <= A and B;
 
end Behavioral;

-----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity CLA is
Port ( A : in STD_LOGIC_VECTOR (4 downto 0);
B : in STD_LOGIC_VECTOR (4 downto 0);
Cin : in STD_LOGIC;
S : out STD_LOGIC_VECTOR (4 downto 0);
Cout : out STD_LOGIC);
end CLA;
 
architecture Behavioral of CLA is

component Partial_FA
Port ( A, B, Cin : in STD_LOGIC;
S, P, G : out STD_LOGIC);
end component;
 
signal c1,c2,c3,c4: STD_LOGIC;
signal P,G: STD_LOGIC_VECTOR(4 downto 0);
begin
 
PFA1: Partial_FA port map( A(0), B(0), Cin, S(0), P(0), G(0));
PFA2: Partial_FA port map( A(1), B(1), c1, S(1), P(1), G(1));
PFA3: Partial_FA port map( A(2), B(2), c2, S(2), P(2), G(2));
PFA4: Partial_FA port map( A(3), B(3), c3, S(3), P(3), G(3));
PFA5: Partial_FA port map( A(4), B(4), c4, S(4), P(4), G(4));
 
c1 <= G(0) OR (P(0) AND Cin);
c2 <= G(1) OR (P(1) AND G(0)) OR (P(1) AND P(0) AND Cin);
c3 <= G(2) OR (P(2) AND G(1)) OR (P(2) AND P(1) AND G(0)) OR (P(2) AND P(1) AND P(0) AND Cin);
c4 <= G(3) OR (P(3) AND G(2)) OR (P(3) AND P(2) AND G(1)) 
	OR (P(3) AND P(2) AND P(1) AND G(0)) OR (P(3) AND P(2) AND P(1) AND P(0) AND Cin);
Cout <= G(4) OR (P(4) AND G(3)) OR (P(4) AND P(3) AND G(2)) OR (P(4) AND P(3) AND P(2) AND G(1)) 
	OR (P(4) AND P(3) AND P(2) AND P(1) AND G(0)) OR (P(4) AND P(3) AND P(2) AND P(1) AND P(0) AND Cin);

end Behavioral;

